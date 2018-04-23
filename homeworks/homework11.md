## Homework 11

### C Exercises

Modify the link below so it points to the `ex11` directory in your
student repository.

[Here is a link to the ex11 directory in my repository](https://github.com/SelinaWang/ExercisesInC/tree/master/exercises/ex11)

### Think OS Chapter 11 reading questions

1) Why is is a bad idea to pass a `sem_t` as a parameter?

`sem_t` is a type that behaves like a structure, so if you assign it to a variable you are making a copy of the contents. Copying a semaphore is a bad idea.

2) When you use a Semaphore as a mutex, what should its initial value be?

1 to indicate that the mutex is unlocked, that is one thread can pass the semaphore without blocking.

3) Can you think of another use for a Semaphore where you might use a different initial value?

If you need to limit the number of simultaneously open file descriptors
among multiple threads, you could initialize a general semaphore to the maximum
number of open file descriptors and each thread that wants to open a file needs to wait
on the semaphore first. If the max hasn't yet been reached, the semaphore will have a
positive value and the thread will be able to breeze right through the wait, decrement
the semaphore and thus open a file. If the max has been reached, the semaphore value
will be zero and thread will block until another thread closes a file, releasing a resource, and incrementing the semaphore that allows others to proceed.

4) In my solution to the producers-consumers problem using Semaphores,
what does it mean if the value of `queue->spaces` is `3` at some point in time?

The number of empty spaces in the queue is 3 which is the number of producer threads that can execute queue_pop without blocking.

5) What does it mean if `queue->space` is `-3`?

It means there are three producer threads blocked waiting to execute queue_pop.

6) Why doesn't `queue_pop` have to use `queue_empty` to check whether the queue is empty?

Because the semaphore is keeping track of how many spaces are being used and blocks the consumers if the queue is empty.

7) Any problem that can be solved with Semaphores can also be solved with mutexes and condition variables.
How can you prove that that's true?

Because semaphores can be implemented using mutexes and conditional variables.

8) What is Property 3?  Hint: see *The Little Book of Semaphores*,
[Section 4.3](http://greenteapress.com/semaphores/LittleBookOfSemaphores.pdf).

If there are threads waiting on a semaphore when a
thread executes signal, then one of the waiting threads has to be
woken.
