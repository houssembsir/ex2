#include "led.h"
#include "config.h"
#include <drivers/gpio.h>

void led_init(void)
{
    const struct device *led_dev = device_get_binding(LED_PORT);

    gpio_pin_configure(led_dev, LED_PIN, GPIO_OUTPUT_ACTIVE | LED_FLAGS);
    gpio_pin_set(led_dev, LED_PIN, 0);
}
