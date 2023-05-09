#ifndef CONFIG_H_
#define CONFIG_H_

#include <devicetree.h>
#include <drivers/gpio.h>

#define LED_NODE DT_ALIAS(led0)
#define BUTTON_NODE DT_ALIAS(sw0)

#if !DT_NODE_HAS_STATUS(LED_NODE, okay)
#error "Unsupported board: led0 devicetree alias is not defined"
#endif

#if !DT_NODE_HAS_STATUS(BUTTON_NODE, okay)
#error "Unsupported board: sw0 devicetree alias is not defined"
#endif

#define LED_PORT DT_GPIO_LABEL(LED_NODE, gpios)
#define LED_PIN DT_GPIO_PIN(LED_NODE, gpios)
#define LED_FLAGS DT_GPIO_FLAGS(LED_NODE, gpios)

#define BUTTON_PORT DT_GPIO_LABEL(BUTTON_NODE, gpios)
#define BUTTON_PIN DT_GPIO_PIN(BUTTON_NODE, gpios)
#define BUTTON_FLAGS (GPIO_INPUT | DT_GPIO_FLAGS(BUTTON_NODE, gpios))

#define MIN_PRESS_DURATION K_SECONDS(3)
#define MAX_PRESS_DURATION K_SECONDS(5)

#endif /* CONFIG_H_ */
