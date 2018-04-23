/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "mutex.h"

#define NUM_CHILDREN 2

void perror_exit(char *s)
{
    perror(s);
    exit(-1);
}

void *check_malloc(int size)
{
    void *p = malloc(size);
    if (p == NULL) {
        perror_exit("malloc failed");
    }
    return p;
}

typedef struct {
    int counter;
    int end;
    int *array;
    Mutex *mutex;
} Shared;

Shared *make_shared(int end)
{
    int i;
    Shared *shared = check_malloc(sizeof(Shared));

    shared->counter = 0;
    shared->end = end;

    shared->array = check_malloc(shared->end * sizeof(int));
    for (i=0; i<shared->end; i++) {
        shared->array[i] = 0;
    }
<<<<<<< HEAD
    shared->mutex = make_mutex();

=======

    shared->mutex = make_mutex();
>>>>>>> 9e69a065b2fb4dc1a74f1b39309557f6c3b33c8f
    return shared;
}

pthread_t make_thread(void *(*entry)(void *), Shared *shared)
{
    int ret;
    pthread_t thread;

    ret = pthread_create(&thread, NULL, entry, (void *) shared);
    if (ret != 0) {
        perror_exit("pthread_create failed");
    }
    return thread;
}

void join_thread(pthread_t thread)
{
    int ret = pthread_join(thread, NULL);
    if (ret == -1) {
        perror_exit("pthread_join failed");
    }
}

void child_code(Shared *shared)
{
<<<<<<< HEAD
    // printf("Starting child at counter %d\n", shared->counter);

    while (1) {
        if (shared->counter >= shared->end) {
            return;
        }
        mutex_lock(shared->mutex);
        shared->array[shared->counter]++;
        shared->counter++;
        mutex_unlock(shared->mutex);
=======
    printf("Starting child at counter %d\n", shared->counter);

    while (1) {
        mutex_lock(shared->mutex);
        if (shared->counter >= shared->end) {
            mutex_unlock(shared->mutex);
            return;
        }

        shared->array[shared->counter]++;
        shared->counter++;
>>>>>>> 9e69a065b2fb4dc1a74f1b39309557f6c3b33c8f

        if (shared->counter % 10000 == 0) {
            printf("%d\n", shared->counter);
        }
<<<<<<< HEAD
=======
        mutex_unlock(shared->mutex);
>>>>>>> 9e69a065b2fb4dc1a74f1b39309557f6c3b33c8f
    }
}

void *entry(void *arg)
{
    Shared *shared = (Shared *) arg;
    child_code(shared);
<<<<<<< HEAD
    // printf("Child done.\n");
=======
    printf("Child done.\n");
>>>>>>> 9e69a065b2fb4dc1a74f1b39309557f6c3b33c8f
    pthread_exit(NULL);
}

void check_array(Shared *shared)
{
    int i, errors=0;

<<<<<<< HEAD
    // printf("Checking...\n");
=======
    printf("Checking...\n");
>>>>>>> 9e69a065b2fb4dc1a74f1b39309557f6c3b33c8f

    for (i=0; i<shared->end; i++) {
        if (shared->array[i] != 1) errors++;
    }
<<<<<<< HEAD
    // printf("%d errors.\n", errors);
=======
    printf("%d errors.\n", errors);
>>>>>>> 9e69a065b2fb4dc1a74f1b39309557f6c3b33c8f
}

int main()
{
    int i;
    pthread_t child[NUM_CHILDREN];

    Shared *shared = make_shared(1000000);

    for (i=0; i<NUM_CHILDREN; i++) {
        child[i] = make_thread(entry, shared);
    }

    for (i=0; i<NUM_CHILDREN; i++) {
        join_thread(child[i]);
    }

    check_array(shared);
    return 0;
}
