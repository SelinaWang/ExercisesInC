## Homework 4

### C Exercises

Modify the link below so it points to the `ex03` directory in your
student repository.

[Here is a link to the ex03 directory in my repository](https://github.com/SelinaWang/ExercisesInC/tree/master/exercises/ex03)

### Think OS Chapter 4 reading questions

**Files and file systems**

1) What abstractions do file systems provide?  Give an example of something that is logically
true about files systems but not true of their implementations.
File systems abstract a file system to a mapping from each file's name to its contents and a file to a sequence of bytes. However in their implementations, files are not byte-based but stored in blocks in persistent storage.
2) What information do you imagine is stored in an `OpenFileTableEntry`?
The "file position" as in where in the file are we, the location of the block and the current block being read.
3) What are some of the ways operating systems deal with the relatively slow performance of persistent storage?
block transfers, prefetching, buffering, and caching.
4) Suppose your program writes a file and prints a message indicating that it is done writing.  
Then a power cut crashes your computer.  After you restore power and reboot the computer, you find that the
file you wrote is not there.  What happened?
The data was in a cache and not yet on disk.
5) Can you think of one advantage of a File Allocation Table over a UNIX inode?  Or an advantage of a inode over a FAT?
Searching for a file is faster with a inode.
6) What is overhead?  What is fragmentation?
Overhead is the space taken up by the allocator and fragmentation is when some blocks are left unused or partially used.
7) Why is the "everything is a file" principle a good idea?  Why might it be a bad idea?
It is a good idea because it applies to a lot of other systems than the file abstraction.
If you would like to learn more about file systems, a good next step is to learn about journaling file systems. However, if adapted to the wrong system, the abstraction could make life much harder for programmers and making things more complicated than they have to be.
Start with [this Wikipedia article](https://en.wikipedia.org/wiki/Journaling_file_system), then
[Anatomy of Linux Journaling File Systems](http://www.ibm.com/developerworks/library/l-journaling-filesystems/index.html).  
Also consider reading [this USENIX paper](https://www.usenix.org/legacy/event/usenix05/tech/general/full_papers/prabhakaran/prabhakaran.pdf).
