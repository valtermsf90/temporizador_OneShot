#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"

#define LED_R 13
#define LED_G 11
#define LED_B 12
#define BT_A 5

// variaveis
bool led_state = true;

// funções
int64_t desligaLedAzul(alarm_id_t id, void *user_data);
int64_t desligaLedVermelho(alarm_id_t id, void *user_data);
int64_t desligaLedVerde(alarm_id_t id, void *user_data);

//desligaLedVermelho e chama a funcao desligaLedVerde
int64_t desligaLedVermelho(alarm_id_t id, void *user_data)
{
    gpio_put(LED_R, false);
    add_alarm_in_ms(3000, desligaLedVerde, NULL, false);
    return 0;
}
//desligaLedVerde e alterna led_state 
int64_t desligaLedVerde(alarm_id_t id, void *user_data)
{
    gpio_put(LED_G, false);
    led_state = true;
    return 0;
}
//desligaLedAzul e chama a funcao desligaLedVermelho
int64_t desligaLedAzul(alarm_id_t id, void *user_data)
{
    gpio_put(LED_B, false);
    add_alarm_in_ms(3000, desligaLedVermelho, NULL, false);
    return 0;
}

// função principal
int main()
{
    // iniciando a comunicação serial
    stdio_init_all();

    // configuração do pino LED
    gpio_init(LED_R);
    gpio_init(LED_G);
    gpio_init(LED_B);
    gpio_set_dir(LED_R, GPIO_OUT);
    gpio_set_dir(LED_G, GPIO_OUT);
    gpio_set_dir(LED_B, GPIO_OUT);
    // configuração do pino BT
    gpio_init(BT_A);
    gpio_set_dir(BT_A, GPIO_IN);
    gpio_pull_up(BT_A);

    // loop infinito
    while (true)
    {
        sleep_ms(100);
        if (gpio_get(BT_A) == 0 && led_state == true)
        {
            gpio_put(LED_R, led_state);
            gpio_put(LED_G, led_state);
            gpio_put(LED_B, led_state);
            led_state = !led_state;
            add_alarm_in_ms(3000, desligaLedAzul, NULL, false);
        }
    }
}
