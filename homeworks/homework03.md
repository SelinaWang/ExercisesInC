## Homework 3

### C Exercises

Modify the link below so it points to the `ex03` directory in your
student repository.

[Here is a link to the ex02.5 directory in my repository](https://github.com/SelinaWang/ExercisesInC/tree/master/exercises/ex02.5)

### Think OS Chapter 4 reading questions

**Files and file systems**

1) The Georgian alphabet has 33 letters.  How many bit are needed to specify a letter?
6 bits because 2^5 < 33 < 2^6.
2) In the UTF-16 character encoding, the binary representation of a character can take up to 32 bits.  
Ignoring the details of the encoding scheme, how many different characters can be represented?
2^32 = 4294967296 characters.
3) What is the difference between "memory" and "storage" as defined in *Think OS*?
Memory is volatile and when the computer shuts down the contents of memory are lost.
Storage is non-volatile so they are used for long-term storage.
4) What is the difference between a GiB and a GB?  What is the percentage difference in their sizes?
A GiB is 2^30 bytes and a GB is 10^9 bytes. The percentage difference is ((2^30)/(10^9)-1)x100%=7.374182%.
5) How does the virtual memory system help isolate processes from each other?
Virtual memory system generates virtual addresses and then the hardware translates to physical addresses before accessing main memory which is done on a pre-process basis, so even if multiple processes generate the same virtual address, they would map to different locations in physical memory.
6) Why do you think the stack and the heap are usually located at opposite ends of the address space?
Due to the fact that stack and heap spaces grow toward each other and that the spaces are both filled up at run time, we want to maximize the space between them.
7) What Python data structure would you use to represent a sparse array?
A Dictionary.
8) What is a context switch?
A context switch is when the operating system interrupts a running process, save its state, and then run another process.
