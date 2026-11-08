/*
 * encoder.h
 *
 *  Created on: 08-Nov-2026
 *      Author: shama
 */

#ifndef ENCODER_H_
#define ENCODER_H_

int encoder_init();

void *encoder_thread(void *arg);

int encoder_get_count(void);

void encoder_cleanup();


#endif /* ENCODER_H_ */
