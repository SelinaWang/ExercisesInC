## Homework 10

### C Exercises

Modify the link below so it points to the `ex12` directory in your
student repository.  That's right, Homework 10 is to do Exercise 12.

[Here is a link to the ex12 directory in my repository](https://github.com/SelinaWang/ExercisesInC/tree/master/exercises/ex12)

### Think OS Chapter 10 reading questions

1) What does it mean to say that a data structure is thread safe?

Thread-safe data structures behaves in a manner that ensures that all threads behave properly and fulfill their design specifications and can access the data structure at the same time without unintended interaction.

2) In the circular buffer implementation of a queue, why is the maximum number of elements in the queue `n-1`,
if `n` is the size of the array?

Because we need to stop one element before the "end" of the queue so that we don't accidentally make the queue seem empty the next time we increment next_in.

3) If there is no mutex to protect the queue, give an example of a sequence of steps that could leave
the queue in an inconsistent state.

With a one element queue, thread 1 reads next_in, thread 2 reads next_out, thread 1 changes next_in, thread 2 prints next_out, this print statement will not print the current value of the only element in the queue.

4) When a thread calls `cond_wait`, why does it have to unlock the mutex before blocking?

If the thread did not unlock the mutex before blocking, no other thread would be able to access the queue, no more items could be added or removed, and the queue will always be empty or full.

5) When a thread returns from `cond_wait`, what do we know is definitely true?  What do we think is probably true?

We know for sure that the condition for the while loop is true and we think it is probably true that the queue is safe to access.

6) What happens if you signal a condition variable when there are no waiting threads?

Nothing happens.

7) Do you have to lock the mutex to signal a condition variable?

Yes, before a thread can return from cond_wait it had to lock the mutex first.

8) Does the condition have to be true when you signal a condition variable?

Not necessarily, a intercepted signal might happen.
