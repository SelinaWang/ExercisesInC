## Homework 8

### C Exercises

Modify the link below so it points to the `ex07` directory in your
student repository.

[Here is a link to the ex08 directory in my repository](https://github.com/SelinaWang/ExercisesInC/tree/master/exercises/ex08)

### Think OS Chapter 8 reading questions

**Multitasking**

1) What is the kernel's most basic task?

The kernel's most basic task is to handle interrupts.

2) When an interrupt occurs, what part of the hardware state is saved by hardware?

The hardware saves the program counter in a special register and jumps to the appropriate interrupt handler. The interrupt handler stores the program counter and the flag register in memory, along with the contents of any data registers it plans to use.

3) What is the difference between an interrupt and a context switch?

The kernel doesn't have to save the entire hardware state for an interrupt while it does for a context switch. The kernel also has to clear data stored in the memory management unit which it doesn't for an interrupt. And after a context switch, it might take some time for the new process to load data into the cache. For these reasons, context switches are much slower than interrupts, on the order of thousands of cycles, or a few microseconds.

4) Give an example of an event that might cause a process to move from the blocked to the ready state.

When an operation like a disk request completes, it causes an interrupt. The interrupt handler figures out which process was waiting for the request and switches its state from blocked to ready.

5) Why might a scheduler want to give higher priority to an I/O bound process?

Because these processes are likely to make a request and blocks before its time slice is complete because it has to wait and read data from a network or disk.

6) When I make French toast, I usually make a batch of 12 slices.  But my griddle only has room for 8 slices.
Each piece of toast has to cook for 5 minutes on each side.  How can I schedule 12 slices onto 8 "cores"
to minimize the elapsed time to cook all 12 slices?  (Note: this question is not hypothetical;
this is really how I make French toast.)

Toast one side of 8 slices (5 minutes) and then toast the other side of 4 of these 8 slices while toasting one side of the remaining 4 raw slices (5 minutes), and then toast the other side of the 4 slices from the first batch while toasting the other side of the last 4 slices (5 minutes) for a total of 5+5+5=15 minutes.
