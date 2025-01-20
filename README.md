README
# Função 1: Ligar o LED Verde
- Comando UART: '1'
- Descrição: 
  Quando o caractere '1' é enviado via UART, o LED verde conectado ao pino GPIO 11 será ligado, enquanto os LEDs azul (GPIO 12) e vermelho (GPIO 13) serão desligados.

# Função 7: Reiniciar o Sistema no Modo Bootloader
- Comando UART: '7'
- Descrição:
  Quando o caractere '7' é enviado via UART, o sistema reinicia permitindo uma reconfiguração do microcontrolador no modo de bootloader USB.
