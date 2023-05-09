#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include "button.h"
#include "led.h"

void main(void)
{
    button_init();
    led_init();

    while (1) {
        k_sleep(K_FOREVER);
    }
}
