## Homework 7

### C Exercises

Modify the link below so it points to the `ex07` directory in your
student repository.

[Here is a link to the ex07 directory in my repository](https://github.com/SelinaWang/ExercisesInC/tree/master/exercises/ex07)

### Think OS Chapter 7 reading questions

### Caching

1) What happens if a program writes a new value into the program counter?

It proceeds to the address of that instruction in the program.

2) What is the fundamental problem caches are meant to solve?

A solution to speedily read data and complete instructions.

3) If cache access time is 1 ns and memory access time is 10 ns, what is the average
access time of a program with hit rate 50%?  How about 90%?

Average access time with hit rate 50% = 1 ns + 0.5*(10 ns - 1  ns) = 5.5 ns  
Average access time with hit rate 90% = 1 ns + 0.1*(10 ns - 1  ns) = 1.9 ns

4) The book gives several examples of programming language features, like loops, that tend
to improve locality in the access pattern of instructions and/or data.  Can you think of other examples?  
Or counter-examples that might decrease locality?

When the program contains blocks of code with no jumps or branches, instructions run
sequentially within these blocks and so the access pattern increases spatial locality.
When the result of one instruction is not used immediately but rather much later on,
the data access pattern decreases temporal locality.

5)  If you refactor a program to improve locality, would you say the program is "cache aware"?  Why not?

No, because the algorithms does not tailor to the size of the cache and the block size, and other hardware characteristics so that the program can best utilize the cache.

6) See if you can estimate the cost of a memory cache by comparing the prices of two similar CPUs with
different cache sizes.

The more expensive CPUs will have larger cache sizes with more expensive memory caches.

7) Why are cache policies generally more complex at the bottom of the memory hierarchy?

Because there is more time to make decisions, and well-designed policies can make a big difference when the block sizes are large.

8) Can you think of a strategy operating systems could use to avoid thrashing or recover when it occurs?

If the operating system strategically detects an increase in paging and blocking or
killing processes until the system is responsive, then it can avoid thrashing and
recover when it occurs.
