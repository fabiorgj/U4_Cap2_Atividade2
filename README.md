Embarcatech - U4 - Microcontroladores

Atividade 2 - Controle de pinos GPIO da ferramenta educacional BitDogLab.. - Aula sícrona de 14/01/2025

Grupo 1, Subgrupo 8

Integrantes:

Fábio Rocha Gomes Jardim

Igor de Eça Almeida

Kauan Lopes de Jesus

Larissa Batista dos Santos

Luis Guilherme Coelho Saturnino

Paolla Giselle Ribeiro

## Vídeo

https://drive.google.com/file/d/1-gcVrFDdZP4TQO9DpK6t3HOW3hxQjxJq/view?usp=sharing

## Descrição

Este projeto foi desenvolvido para a Bitdoglab e permite controlar o LED RGB nativo e o buzzer através de comandos enviados via monitor serial (USB). Cada comando recebido corresponde a uma função específica para ligar/desligar os LEDs e ativar o buzzer, ou, reiniciar o sistema.


## Funcionalidades

- Controle individual dos LEDs (verde, azul e vermelho).

- Ativação de combinações específicas dos LEDs.

- Acionamento do buzzer por 2 segundos.

- Reinicialização do sistema via comando serial.


## Hardware

Foi utilizado a placa de desenvolvimento Bitdoglab.

O led RGB nativo foi utilizado, ele está conectados aos pino GP11, GP12 e GP13, respectivamente, com resistores adequados.

Buzzer nativo foi utilizado, conectado ao pino GP21.


## Como Usar

Utilize o terminal PuTTY para fazer o intermédio entre a placa e o computador.

- Tecla '1': Liga o LED verde.

- Tecla '2': Liga o LED azul.

- Tecla '3': Liga o LED vermelho.

- Tecla '4': Liga todos os LEDs (cor branca).

- Tecla '5': Desliga todos os LEDs.

- Tecla '6': Aciona o buzzer por 2 segundos.

- Tecla '7': Reinicia o sistema.

## Explicação das Funções

- gpio_setup(): Configura os pinos dos LEDs e do buzzer.

- ligar_LED_verde(): Liga o LED verde e desliga os demais.

- ligar_LED_azul(): Liga o LED azul e desliga os demais.

- ligar_LED_vermelho(): Liga o LED vermelho e desliga os demais.

- ligar_LED_branco(): Liga todos os LEDs simultaneamente.

- desligar_LEDs(): Desliga todos os LEDs.

- acionar_buzzer(): Ativa o buzzer por 2 segundos.

- reboot_system(): Reinicia o sistema.