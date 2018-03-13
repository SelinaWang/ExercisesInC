## Homework 6

### C Exercises

Modify the link below so it points to the `ex06` directory in your
student repository.

[Here is a link to the ex06 directory in my repository](https://github.com/SelinaWang/ExercisesInC/tree/master/exercises/ex06)

### Think OS Chapter 6 reading questions

**Memory management**

1) Which memory management functions would you expect to take constant time?
Which ones take time proportional to the size of the allocated chunk?

I would expect `calloc` and `realloc` to take time propotional to the size
of the allocated chunk and `malloc` and `free` to take constant time.

2) For each of the following memory errors, give an example of something that might go wrong:

a) Reading from unallocated memory.

The program doesn't detect the "segmentation fault" and the reads the unallocated memory, and the value it gets is whatever happened to be stored at a particular location. If the value is not interpreted as the right type, the results might be hard to interpret.

b) Writing to unallocated memory.

The bad value might not be read until a long time has passed after it's written and
causes problems. At that point it will be very difficult to find the source of the
problem.

c) Reading from a freed chunk.

This is similar to reading from unallocated memory and therefore should run into similar problems.

d) Writing to a freed chunk.

This is similar to writing to unallocated memory and therefore should run into similar problems.

e) Failing to free a chunk that is no longer needed.

You are causing a "memory leak". If continued, the system will run out of physical memory at some point and on systems without virtual memory, the next to `malloc` will fail and return NULL.

3) Run

```
    ps aux --sort rss
```

to see a list of processes sorted by RSS, which is "resident set size", the amount of physical
memory a process has.  Which processes are using the most memory?

Google Chrome, Atom editor, and Spotify.

4) What's wrong with allocating a large number of small chunks?  What can you do to mitigate the problem?

Boundary tags and free list pointers take up space. So for very small chunks, malloc is
not space efficient. In this case, we can allocate them in arrays.

If you want to know more about how malloc works, read
[Doug Lea's paper about dlmalloc](http://gee.cs.oswego.edu/dl/html/malloc.html)
