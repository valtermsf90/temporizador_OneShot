Controle de LEDs com Raspberry Pi Pico W

Este projeto implementa um sistema de controle de LEDs utilizando um Raspberry Pi Pico W e um botão (pushbutton). O código utiliza temporizadores para desligar os LEDs em sequência e inclui um mecanismo de debounce para evitar leituras falsas do botão.

📌 Funcionalidades

Acionamento dos LEDs ao pressionar um botão.

Desligamento dos LEDs em sequência com intervalo de 3 segundos entre cada um.

Implementação de debounce de software para evitar acionamentos acidentais do botão.

Utilização da ferramenta educacional BitDogLab.

🛠️ Componentes Utilizados

Raspberry Pi Pico W

LEDs (Vermelho, Verde e Azul)

Pushbutton



Componente

Pino Raspberry Pi Pico W

LED Vermelho

GPIO 13

LED Verde

GPIO 11

LED Azul

GPIO 12

Pushbutton

GPIO 5

Como Executar

Clone o repositório:

git clone https://github.com/valtermsf90/temporizador_OneShot

Compile e envie o código para o Raspberry Pi Pico W.

Pressione o botão para acionar os LEDs.

Simulação no Wokwi

Você pode testar o código diretamente no Wokwi:
🔗 Simulação no Wokwi LINK https://wokwi.com/projects/421474242909584385

✉️ Autor: Valter Machado Silva Filho

