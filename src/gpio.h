/*
 * gpio.h
 *
 *  Created on: 08-Nov-2026
 *      Author: shama
 */

#ifndef SRC_GPIO_H_
#define SRC_GPIO_H_
int gpio_configure(int gpio_pin, unsigned configuration);
int gpio_read(int gpio_pin, unsigned *level);
int gpio_register_interrupt(int gpio_pin, int coid, unsigned event, unsigned event_id);
#endif /* SRC_GPIO_H_ */
