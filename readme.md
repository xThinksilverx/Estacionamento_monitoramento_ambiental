# 🚗 Sistema de Estacionamento Inteligente com Monitoramento Ambiental

## 👥 Integrantes da Equipe

- **Otavio**
- **Caio**
- **Kaio**

---

## 🎯 Objetivo do Projeto

Este projeto tem como objetivo desenvolver um **sistema de estacionamento inteligente** que auxilia motoristas durante a manobra de estacionamento, utilizando sensores para medir a distância do veículo em relação a obstáculos e fornecendo feedback visual e sonoro em tempo real.

Além disso, o sistema realiza **monitoramento ambiental** através de sensores de temperatura e umidade, oferecendo uma solução completa e integrada para gestão de estacionamentos.

### Funcionalidades Principais:
- ✅ Medição precisa de distância usando sensor ultrassônico
- ✅ Alertas visuais através de LEDs coloridos (Verde, Amarelo, Vermelho)
- ✅ Alertas sonoros progressivos através de buzzer (beeps mais rápidos conforme aproximação)
- ✅ Monitoramento de temperatura e umidade do ambiente
- ✅ Visualização de dados em tempo real via Monitor Serial

---

## 🔧 Componentes Utilizados

### Sensores:
| Componente | Quantidade | Função |
|------------|------------|--------|
| **Sensor Ultrassônico HC-SR04** | 1 | Medição de distância (0-400cm) |
| **Sensor DHT11** | 1 | Medição de temperatura e umidade |

### Atuadores:
| Componente | Quantidade | Função |
|------------|------------|--------|
| **LED Verde** | 1 | Indica distância segura (> 60cm) |
| **LED Amarelo** | 1 | Indica atenção (30-60cm) |
| **LED Vermelho** | 1 | Indica perigo (< 30cm) |
| **Buzzer Ativo** | 1 | Emite alertas sonoros progressivos |

### Microcontrolador e Componentes Auxiliares:
| Componente | Quantidade | Função |
|------------|------------|--------|
| **Arduino Uno R3** | 1 | Microcontrolador principal |
| **Resistor 220Ω** | 3 | Limitação de corrente para LEDs |
| **Protoboard** | 1 | Montagem do circuito |
| **Jumpers** | Diversos | Conexões elétricas |
| **Cabo USB** | 1 | Alimentação e comunicação serial |

---

## 💰 Custo Estimado do Projeto

| Item | Quantidade | Preço Unitário (R$) | Subtotal (R$) |
|------|------------|---------------------|---------------|
| Arduino Uno R3 | 1 | 70,00 | 70,00 |
| Sensor HC-SR04 | 1 | 15,00 | 15,00 |
| Sensor DHT11 | 1 | 12,00 | 12,00 |
| LED Verde | 1 | 0,50 | 0,50 |
| LED Amarelo | 1 | 0,50 | 0,50 |
| LED Vermelho | 1 | 0,50 | 0,50 |
| Buzzer Ativo 5V | 1 | 5,00 | 5,00 |
| Resistor 220Ω | 3 | 0,20 | 0,60 |
| Protoboard 400 pontos | 1 | 15,00 | 15,00 |
| Jumpers (kit) | 1 | 10,00 | 10,00 |
| Cabo USB | 1 | 8,00 | 8,00 |
| **TOTAL** | | | **R$ 137,10** |

> 💡 **Nota:** Os preços são estimados e podem variar conforme fornecedor e região.

---

## 📐 Esquema de Montagem

### Diagrama de Conexões:

```
SENSOR ULTRASSÔNICO HC-SR04:
├─ VCC ──────────────→ 5V (Arduino)
├─ GND ──────────────→ GND (Arduino)
├─ TRIG ─────────────→ Pino Digital 12
└─ ECHO ─────────────→ Pino Digital 11

SENSOR DHT11:
├─ VCC ──────────────→ 5V (Arduino)
├─ GND ──────────────→ GND (Arduino)
└─ DATA ─────────────→ Pino Digital 2

LEDs (com resistor 220Ω em série):
├─ LED Verde ────────→ Pino Digital 13 → Resistor 220Ω → GND
├─ LED Amarelo ──────→ Pino Analógico A1 → Resistor 220Ω → GND
└─ LED Vermelho ─────→ Pino Analógico A2 → Resistor 220Ω → GND

BUZZER:
├─ Positivo (+) ─────→ Pino Digital 10
└─ Negativo (-) ─────→ GND (Arduino)
```

### Tabela de Conexões Detalhada:

| Componente | Pino do Componente | Pino do Arduino | Observações |
|------------|-------------------|-----------------|-------------|
| HC-SR04 | VCC | 5V | Alimentação |
| HC-SR04 | GND | GND | Terra |
| HC-SR04 | TRIG | D12 | Trigger |
| HC-SR04 | ECHO | D11 | Echo |
| DHT11 | VCC | 5V | Alimentação |
| DHT11 | GND | GND | Terra |
| DHT11 | DATA | D2 | Dados |
| LED Verde | Anodo (+) | D13 | Com resistor 220Ω |
| LED Amarelo | Anodo (+) | A1 | Com resistor 220Ω |
| LED Vermelho | Anodo (+) | A2 | Com resistor 220Ω |
| Buzzer | Positivo | D10 | Polarizado |
| Buzzer | Negativo | GND | Terra |

---

## 🖼️ Fotos e Demonstrações do Sistema

### Montagem do Circuito
> 📸 _[Adicione aqui uma foto da montagem completa na protoboard]_

![Montagem do Sistema](https://via.placeholder.com/600x400.png?text=Montagem+do+Sistema)

### Sistema em Funcionamento - LED Verde (Distância Segura)
> 📸 _[Adicione aqui uma foto com LED verde aceso, indicando distância > 60cm]_

![LED Verde Ativo](https://via.placeholder.com/600x400.png?text=LED+Verde+-+Dist%C3%A2ncia+Segura)

### Sistema em Funcionamento - LED Amarelo (Atenção)
> 📸 _[Adicione aqui uma foto com LED amarelo aceso, indicando distância entre 30-60cm]_

![LED Amarelo Ativo](https://via.placeholder.com/600x400.png?text=LED+Amarelo+-+Aten%C3%A7%C3%A3o)

### Sistema em Funcionamento - LED Vermelho (Perigo)
> 📸 _[Adicione aqui uma foto com LED vermelho aceso, indicando distância < 30cm]_

![LED Vermelho Ativo](https://via.placeholder.com/600x400.png?text=LED+Vermelho+-+Perigo)

### Monitor Serial
> 📸 _[Adicione aqui um screenshot do Monitor Serial mostrando os dados]_

![Monitor Serial](https://via.placeholder.com/600x400.png?text=Monitor+Serial)

### Demonstração em Vídeo
> 🎥 _[Adicione aqui um GIF ou link para vídeo demonstrando o sistema completo]_

![Demonstração](https://via.placeholder.com/600x400.png?text=Demonstra%C3%A7%C3%A3o+em+V%C3%ADdeo)

---

## 📊 Lógica de Funcionamento

### Indicadores Visuais (LEDs):
- 🟢 **LED Verde**: Distância > 60cm (Seguro para aproximar)
- 🟡 **LED Amarelo**: Distância entre 30-60cm (Atenção, reduza velocidade)
- 🔴 **LED Vermelho**: Distância < 30cm (Perigo! Pare imediatamente)

### Alertas Sonoros (Buzzer):
O buzzer emite beeps com intervalos que diminuem conforme o veículo se aproxima:

| Distância | Intervalo entre Beeps |
|-----------|-----------------------|
| > 60cm | 1000ms (1 segundo) |
| 50-60cm | 800ms |
| 40-50cm | 600ms |
| 30-40cm | 400ms |
| 20-30cm | 200ms |
| 10-20cm | 100ms |
| < 10cm | 50ms (beep contínuo) |

---

## 🚀 Como Utilizar

### Requisitos:
- Arduino IDE instalado
- Biblioteca DHT Sensor Library (`DHT.h`)

### Instalação da Biblioteca:
1. Abra a Arduino IDE
2. Vá em: **Sketch → Incluir Biblioteca → Gerenciar Bibliotecas**
3. Busque por: **DHT sensor library**
4. Instale a biblioteca by Adafruit

### Upload do Código:
1. Conecte o Arduino ao computador via USB
2. Abra o arquivo `.ino` na Arduino IDE
3. Selecione a placa: **Ferramentas → Placa → Arduino Uno**
4. Selecione a porta COM correta
5. Clique em **Upload** (→)

### Uso:
1. Após o upload, abra o **Monitor Serial** (115200 baud)
2. Posicione objetos em diferentes distâncias do sensor
3. Observe as mudanças nos LEDs, buzzer e dados no monitor

---

## 📝 Licença

Este projeto é de código aberto e está disponível sob a licença MIT.

---

## 🤝 Contribuições

Contribuições são bem-vindas! Sinta-se à vontade para abrir issues ou pull requests.

---

**Desenvolvido com ❤️ por Otavio, Caio e Kaio**