#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"
#include "hardware/timer.h"

// GPIOs para LEDs e buzzer
#define LED_GREEN_PIN 11
#define LED_BLUE_PIN 12
#define LED_RED_PIN 13
#define BUZZER_PIN 21
#define BUZZER_FREQUENCY 2000

// Função para configurar os pinos
void gpio_setup() {
    gpio_init(LED_GREEN_PIN);
    gpio_set_dir(LED_GREEN_PIN, GPIO_OUT);

    gpio_init(LED_BLUE_PIN);
    gpio_set_dir(LED_BLUE_PIN, GPIO_OUT);

    gpio_init(LED_RED_PIN);
    gpio_set_dir(LED_RED_PIN, GPIO_OUT);

    gpio_set_function(BUZZER_PIN, GPIO_FUNC_PWM);

    // Obter o slice do PWM associado ao pino
    uint slice_num = pwm_gpio_to_slice_num(BUZZER_PIN);

    // Configurar o PWM com frequência desejada
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, clock_get_hz(clk_sys) / (BUZZER_FREQUENCY * 4096)); // Divisor de clock
    pwm_init(slice_num, &config, true);

    // Iniciar o PWM no nível baixo
    pwm_set_gpio_level(BUZZER_PIN, 0);

}

// Função 1: Ligar LED verde (GPIO 11) e desligar as demais GPIOs
void ligar_LED_verde(void) {
    printf("Ligando LED verde\n");
    gpio_put(LED_GREEN_PIN, 1); // Acender o LED verde
    gpio_put(LED_BLUE_PIN, 0);  // Desligar o LED azul
    gpio_put(LED_RED_PIN, 0);   // Desligar o LED vermelho
}

// Função que liga LED azul (GPIO 12) e desliga os demais
void ligar_LED_azul(void) {
    printf("Ligando LED azul\n");
    gpio_put(LED_BLUE_PIN, 1); 
    gpio_put(LED_GREEN_PIN, 0);  
    gpio_put(LED_RED_PIN, 0);   
}

// Função 3: Ligar LED vermelho (GPIO 13) e desligar as demais GPIOs
void ligar_LED_vermelho(void) {
    printf("Ligando LED vermelho\n");
    gpio_put(LED_RED_PIN, 1);   
    gpio_put(LED_GREEN_PIN, 0); 
    gpio_put(LED_BLUE_PIN, 0);  
}

// Função 4: Ligar todos os LEDs (GPIO 11 - verde, GPIO 12 - azul e GPIO 13 - vermelho) resultando na cor branca
void ligar_LED_branco(void) {
    printf("Ligando LED branco\n");
    gpio_put(LED_GREEN_PIN, 1); // Acender o LED verde
    gpio_put(LED_BLUE_PIN, 1);  // Acender o LED azul
    gpio_put(LED_RED_PIN, 1);   // Acender o LED vermelho
    
}

// Função 5: Desligar todos os LEDs
void desligar_LEDs(void) {
    printf("Desligando LEDs\n");
    gpio_put(LED_GREEN_PIN, 0); // Desligar o LED verde
    gpio_put(LED_BLUE_PIN, 0);  // Desligar o LED azul
    gpio_put(LED_RED_PIN, 0);   // Desligar o LED vermelho
}

// Função 6: Acionar o buzzer por 2 segundos
void acionar_buzzer(void) {
     // Obter o slice do PWM associado ao pino
    uint slice_num = pwm_gpio_to_slice_num(BUZZER_PIN);

    // Ativar o PWM com duty cycle de 50%
    pwm_set_gpio_level(BUZZER_PIN, 2048); // 50% de 4096

    printf("Buzz\n");

    // Temporização para duração do som
    sleep_ms(2000);

    // Desativar o PWM (duty cycle 0)
    pwm_set_gpio_level(BUZZER_PIN, 0);
}

// Função 7: função que reinicia o sistema
void reboot_system() {
    printf("Reiniciando o sistema...\n");
    sleep_ms(1000); // pequena pausa para exibir mensagem antes de reiniciar
    watchdog_reboot(0, 0, 0);  // Reiniciando o sistema
}

int main() {

    stdio_usb_init(); // Inicializa a comunicação serial via USB
    gpio_setup();  // Configura os pinos
    printf("Raspberry Pi Pico W pronta para receber comandos.\n");

    while (true) {
        char c = getchar();  // Aguarda entrada de um caractere via serial

        // Remove caractere de nova linha (caso enviado pelo terminal)
        if (c == '\n' || c == '\r') {
            continue;
        }

        printf("Recebido: %c\n", c);

        // Verifica o caractere recebido e chama a função correspondente
        switch (c) {
            case '1': ligar_LED_verde(); break;
            case '2': ligar_LED_azul(); break;
            case '3': ligar_LED_vermelho(); break;
            case '4': ligar_LED_branco(); break;
            case '5': desligar_LEDs(); break;
            case '6': acionar_buzzer(); break;
            case '7': reboot_system(); break;
            default: 
                printf("Comando invalido! Digite 1 a 6.\n");
                break;
        }
    }

    return 0;
}
