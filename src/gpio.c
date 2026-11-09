/*
 * gpio.c
 *
 *  Created on: 08-Nov-2026
 *      Author: shama
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "public/rpi_gpio.h"
#include "gpio.h"

int gpio_configure(int gpio_pin, unsigned configuration)
{
    return rpi_gpio_setup(gpio_pin, configuration);
}

int gpio_read(int gpio_pin, unsigned *level){
	return rpi_gpio_input(gpio_pin,level);
}

int gpio_init(void)
{
    int status;

    status = gpio_configure(GPIO17, GPIO_IN);
    if (status != GPIO_SUCCESS)
        return status;

    status = gpio_configure(GPIO18, GPIO_IN);
    if (status != GPIO_SUCCESS)
        return status;

    return GPIO_SUCCESS;
}
int gpio_register_interrupt(int gpio_pin, int coid, unsigned event, unsigned event_id){
	return rpi_gpio_add_event_detect(gpio_pin, coid,event,event_id);
}

