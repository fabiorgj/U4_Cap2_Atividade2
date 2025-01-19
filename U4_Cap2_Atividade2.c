#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "hardware/reset.h"

// UART defines
#define UART_ID uart1
#define BAUD_RATE 115200
#define UART_TX_PIN 4
#define UART_RX_PIN 5

// GPIOs para LEDs e buzzer
#define LED_GREEN_PIN 11
#define LED_BLUE_PIN 12
#define LED_RED_PIN 13

// Função para configurar os pinos
void gpio_setup() {
    gpio_init(LED_GREEN_PIN);
    gpio_set_dir(LED_GREEN_PIN, GPIO_OUT);

    gpio_init(LED_BLUE_PIN);
    gpio_set_dir(LED_BLUE_PIN, GPIO_OUT);

    gpio_init(LED_RED_PIN);
    gpio_set_dir(LED_RED_PIN, GPIO_OUT);

}

// Função 1: Ligar LED verde (GPIO 11) e desligar as demais GPIOs
void ligar_LED_verde() {
    gpio_put(LED_GREEN_PIN, 1); // Acender o LED verde
    gpio_put(LED_BLUE_PIN, 0);  // Desligar o LED azul
    gpio_put(LED_RED_PIN, 0);   // Desligar o LED vermelho
}
// Função 4: Ligar todos os LEDs (GPIO 11 - verde, GPIO 12 - azul e GPIO 13 - vermelho) resultando na cor branca
void ligar_LED_branco() {
    gpio_put(LED_GREEN_PIN, 1); // Acender o LED verde
    gpio_put(LED_BLUE_PIN, 1);  // Acender o LED azul
    gpio_put(LED_RED_PIN, 1);   // Acender o LED vermelho
    
}

// Função 3: Ligar LED vermelho (GPIO 13) e desligar as demais GPIOs
void ligar_LED_vermelho() {
    gpio_put(LED_RED_PIN, 1);   
    gpio_put(LED_GREEN_PIN, 0); 
    gpio_put(LED_BLUE_PIN, 0);  
}

// Função 7: função que habilita o modo de gravação via USB e reiniciar o sistema
void reboot_system() {
    printf("Habilitando modo de gravação via USB...\n");
    sleep_ms(1000); // pequeno intervalo para exibir a mensagem antes de reiniciar
    reset_usb_boot(0, 0);  // Reiniciando o sistema em modo de bootloader USB
}

// Função que liga LED azul (GPIO 12) e desliga os demais
void ligar_LED_azul() {
    gpio_put(LED_BLUE_PIN, 1); 
    gpio_put(LED_GREEN_PIN, 0);  
    gpio_put(LED_RED_PIN, 0);   
}

int main() {
    // Set up our UART
    uart_init(UART_ID, BAUD_RATE);
    // Set the TX and RX pins by using the function select on the GPIO
    // Set datasheet for more information on function select
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
    // Send out a string, with CR/LF conversions
    uart_puts(UART_ID, " Hello, UART!\n");
    // Configuração dos pinos
    gpio_setup();

    while (true) {
        char caractere_comando = uart_getc(UART_ID); // Recebe um caractere via UART

        // Ação baseada no caractere recebido
        if (caractere_comando == '1') {
            ligar_LED_verde();  // Chamando a funçã para ligar o LED verde
            printf("LED verde ligado!\n");
        } 

        else if (caractere_comando == '4') {
            ligar_LED_branco();  
            printf("Todos os LEDs ligados!\n");

        } 
        else if (caractere_comando == '7') {
            reboot_system();  // Chamando a função para reiniciar o sistema
        }

        sleep_ms(100);  // pequena pausa de 100ms para o loop
    }
}