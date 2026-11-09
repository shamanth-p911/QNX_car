#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#include "encoder.h"

int main(void)
{
    pthread_t encoder_tid;
    int ret;

    printf("ECU Starting...\n");

    if (encoder_init() != 0)
    {
        printf("Encoder initialization failed\n");
        return EXIT_FAILURE;
    }

    printf("Encoder initialized\n");

    ret = pthread_create(
        &encoder_tid,
        NULL,
        encoder_thread,
        NULL
    );

    if (ret != 0)
    {
        printf("Thread creation failed: %s\n", strerror(ret));
        encoder_cleanup();
        return EXIT_FAILURE;
    }

    printf("Encoder thread started\n");

    pthread_join(encoder_tid, NULL);

    encoder_cleanup();

    return EXIT_SUCCESS;
}
