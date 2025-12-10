# Colher Estabilizadora

```cpp
#define ESTUDANTES ["Gabriel de Paula", "Guilherme Francis"]
#define DISCIPLINA "Computação Física com Arduino"
#define PROFESSOR "Milene Carvalho"
#define SEMESTRE "2025.2"
```

&nbsp;

## 🧠 Contextualização

Este projeto foi desenvolvido com o objetivo de explorar técnicas de estabilização mecânica e controle de movimento aplicadas em dispositivos assistivos.
A colher estabilizadora foi escolhida por ser um desafio multidisciplinar, envolvendo mecânica, eletrônica e programação embarcada, além de ter um impacto direto na qualidade de vida de usuários com limitações motoras.

&nbsp;

## 🛠️ Montagem

### 📋 Itens

<!-- markdownlint-disable no-inline-html -->

Os itens usados (mas que podem ser substituídos por equivalentes) são:

#### Arduino Nano

<div>
<img src="./media/arduino.jpg" width="200px" alt="arduino-nano">
<div>

#### Giroscopio MPU6050

<div>
<img src="./media/mpu6050.jpg" width="200px" alt="giroscopio">
<div>

#### 2 servo motores

<div>
<img src="./media/motor.jpg" width="200px" alt="servomotor">
<div>

#### Switch para ligar e desligar

<div>
<img src="./media/switch.png" width="200px" alt="switch">
<div>

#### Alimentação do circuito (Bateria 9V)

<div>
<img src="./media/bateria.jpg" width="200px" alt="bateria">
<div>

#### Estrutura feita em impressora 3D

> [Modelo 3D - Parte de cima](./model/colher-top.stl)\
> [Modelo 3D - Parte de baixo](./model/colher-bottom.stl)

&nbsp;

### 🔌 Circuito

<div>
<img src="./media/projetofinal_bb.png" width="500px" alt="circuito">
<div>

#### Conexões

- VIN Alimentação da bateria
- __GND__ Controlado por switch

##### Servomotores

- __D9__ Servo 1 (eixo X)
- __D10__ Servo 2 (eixo Y)
- __5V__ e __GND__

##### Giroscópio

- __A4__ Conectado no SDA
- __A5__ Conectado no SCL
- __3.3V__ e __GND__

&nbsp;

## 🧠 Programação

### 📚 Bibliotecas

No gerenciador de bibliotecas, pesquise por `Servo` e `Wire`, instale-as.

### 💻 Código

???

&nbsp;

## 🖼️ Registros

[`> MP4 <`](./media/video)

![teste](./media/video.gif)

&nbsp;

## Referências

???
