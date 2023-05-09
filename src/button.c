#include "button.h"
#include "config.h"
#include <drivers/gpio.h>
#include <zephyr.h>

static struct gpio_callback button_cb_data;
static struct k_timer timer;

void button_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
{
    k_timer_start(&timer, MAX_PRESS_DURATION, K_NO_WAIT);
}

void button_init(void)
{
    const struct device *button_dev = device_get_binding(BUTTON_PORT);

    gpio_pin_configure(button_dev, BUTTON_PIN, BUTTON_FLAGS | GPIO_INT_DEBOUNCE);

    gpio_init_callback(&button_cb_data, button_pressed, BIT(BUTTON_PIN));
    gpio_add_callback(button_dev, &button_cb_data);
    gpio_pin_interrupt_configure(button_dev, BUTTON_PIN, GPIO_INT_EDGE_TO_ACTIVE);

    k_timer_init(&timer, NULL, NULL);
}



void button_released(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
{
    if (k_timer_status_get(&timer) > 0) {
        if (k_timer_remaining_get(&timer) > 0) {
            const struct device *led_dev = device_get_binding(LED_PORT);
            gpio_pin_set(led_dev, LED_PIN, 1);
        }
        k_timer_stop(&timer);
    }
}

