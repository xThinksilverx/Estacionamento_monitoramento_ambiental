
#include <DHT.h>

// Definições de pinos
#define TRIG_PIN 12
#define ECHO_PIN 11
#define DHT_PIN 2
#define BUZZER_PIN 10
#define LED_VERDE 13
#define LED_AMARELO A1
#define LED_VERMELHO A2

// Configuração do DHT11
#define DHT_TYPE DHT11
DHT dht(DHT_PIN, DHT_TYPE);

// Variáveis globais
unsigned long ultimoBeep = 0;
int intervaloBeep = 1000;

void setup() {
  Serial.begin(9600);
  
  // Configuração dos pinos
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  
  // Inicializa DHT11
  dht.begin();
  
  Serial.println("Sistema de Estacionamento Inteligente Iniciado!");
  Serial.println("-----------------------------------------------");
}

void loop() {
  // Lê distância do sensor ultrassônico
  long distancia = lerDistancia();
  
  // Lê temperatura e umidade
  float temperatura = dht.readTemperature();
  float umidade = dht.readHumidity();
  
  // Controla LEDs baseado na distância
  controlarLEDs(distancia);
  
  // Controla buzzer com beeps progressivos
  controlarBuzzer(distancia);
  
  // Exibe informações no monitor serial
  Serial.print("Distância: ");
  Serial.print(distancia);
  Serial.print(" cm | Temp: ");
  Serial.print(temperatura);
  Serial.print(" °C | Umidade: ");
  Serial.print(umidade);
  Serial.println(" %");
  
  delay(100);
}

// Função para ler distância do sensor ultrassônico
long lerDistancia() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  long duracao = pulseIn(ECHO_PIN, HIGH);
  long distancia = duracao * 0.034 / 2; // Converte para cm
  
  return distancia;
}

// Função para controlar LEDs baseado na distância
void controlarLEDs(long distancia) {
  // Verde: > 60cm (longe/seguro)
  // Amarelo: 30-60cm (atenção)
  // Vermelho: < 30cm (perigo)
  
  if(distancia > 60) {
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERMELHO, LOW);
  } else if(distancia > 30) {
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AMARELO, HIGH);
    digitalWrite(LED_VERMELHO, LOW);
  } else {
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERMELHO, HIGH);
  }
}

// Função para controlar buzzer com beeps progressivos
void controlarBuzzer(long distancia) {
  // Calcula intervalo entre beeps (quanto mais perto, mais rápido)
  if(distancia > 60) {
    intervaloBeep = 1000; // 1 segundo
  } else if(distancia > 50) {
    intervaloBeep = 800;
  } else if(distancia > 40) {
    intervaloBeep = 600;
  } else if(distancia > 30) {
    intervaloBeep = 400;
  } else if(distancia > 20) {
    intervaloBeep = 200;
  } else if(distancia > 10) {
    intervaloBeep = 100;
  } else {
    intervaloBeep = 50; // Muito rápido quando muito perto
  }
  
  // Gera beeps no intervalo calculado
  unsigned long tempoAtual = millis();
  if(tempoAtual - ultimoBeep >= intervaloBeep) {
    ultimoBeep = tempoAtual;
    
    // Beep curto com volume fixo
    tone(BUZZER_PIN, 2000, 50); // Frequência 2000Hz, duração 50ms
  }
}