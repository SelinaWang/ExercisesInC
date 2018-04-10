/* Example code for Exercises in C.

Copyright 2016 Allen B. Downey
License: MIT License https://opensource.org/licenses/MIT

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/types.h>
#include <wait.h>


// errno is an external global variable that contains
// error information
extern int errno;
char* global_str = "global";


// get_seconds returns the number of seconds since the
// beginning of the day, with microsecond precision
double get_seconds() {
    struct timeval tv[1];

    gettimeofday(tv, NULL);
    return tv->tv_sec + tv->tv_usec / 1e6;
}


void child_code(int i)
{
    sleep(i);
    printf("Hello from child %d.\n", i);
    printf("child errno %i.\n", errno); // if the child shares the same global
    // the errno should be the same
    printf("global string value %p.\n", global_str); // if the child shares the
    // static segment with the parent, they should see the same global variable
    int *local_array = (int *)malloc(sizeof(int)*(5)); // allocate space for 5 ints
    local_array[i] = 1; // set the int in local_array at postion i to be 1;
    for (int i = 0; i < 5; i++) {
        printf("%i", local_array[i]); // output is different than parent's local_array
        // result as well as other children's, proving that they do not use the same stack segment
    }
    printf("\n");

}

// main takes two parameters: argc is the number of command-line
// arguments; argv is an array of strings containing the command
// line arguments
int main(int argc, char *argv[])
{
    int status;
    pid_t pid;
    double start, stop;
    int i, num_children;

    // the first command-line argument is the name of the executable.
    // if there is a second, it is the number of children to create.
    if (argc == 2) {
        num_children = atoi(argv[1]);
    } else {
        num_children = 1;
    }

    // get the start time
    start = get_seconds();

    for (i=0; i<num_children; i++) {

        // create a child process
        printf("Creating child %d.\n", i);
        pid = fork();

        /* check for an error */
        if (pid == -1) {
            fprintf(stderr, "fork failed: %s\n", strerror(errno));
            perror(argv[0]);
            exit(1);
        }

        /* see if we're the parent or the child */
        if (pid == 0) {
            child_code(i);
            exit(i);
        }
    }

    /* parent continues */
    printf("Hello from the parent.\n");
    printf("parent errno %i.\n", errno); // if the child shares the same global
    // the errno should be the same
    // Results show that the errnos are the same for parent and child processes
    // so they do share the same global segment since errno is a global variable

    printf("global string value %p.\n", global_str); // if the child shares the
    // static segment with the parent, they should see the same global variable

    int *local_array = (int *)malloc(sizeof(int)*(num_children+1)); //allocate
    // ints again cuz was getting fork.c:108:5: error: ‘local_array’ undeclared
    // (first use in this function). The proves that they do not share the same
    // stack segment since stack stored local variables and that local_array was
    // initialized in child node

    local_array[num_children] = 9; // set the int at number of childen to be 9

    for (int i = 0; i < num_children+1; i++) {
        printf("%i", local_array[i]); // The output is the number of 0s = num_children,
        // followed by a 9 set by the parent,proving that the parent and children
        // uses the same heap segment
    }
    printf("\n");

    for (i=0; i<num_children; i++) {
        pid = wait(&status);

        if (pid == -1) {
            fprintf(stderr, "wait failed: %s\n", strerror(errno));
            perror(argv[0]);
            exit(1);
        }

        // check the exit status of the child
        status = WEXITSTATUS(status);
        printf("Child %d exited with error code %d.\n", pid, status);
    }
    // compute the elapsed time
    stop = get_seconds();
    printf("Elapsed time = %f seconds.\n", stop - start);

    exit(0);
}
