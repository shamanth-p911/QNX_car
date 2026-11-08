#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "encoder.h"
#include "motor.h"

int main(void) {

    if (encoder_init() != 0) {
        printf("Encoder initialization failed\n");
        return EXIT_FAILURE;
    }
    if (motor_init() != 0) {
        printf("Motor initialization failed\n");
        encoder_cleanup();
        return EXIT_FAILURE;
    }
	 pthread_t motor_tid;
	 pthread_t encoder_tid;

	 pthread_create(&motor_tid,NULL,motor_tid,NULL);
	 pthread_create(&encoder_tid,NULL,encoder_tid,NULL);

	 pthread_join(motor_tid,NULL);
	 pthread_join(encoder_tid,NULL);

	 motor_stop();
	 motor_cleanup();
	 encoder_cleanup();

	 printf("ECU Shutdown\n");

	 return EXIT_SUCCESS;


}
