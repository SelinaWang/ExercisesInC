## Homework 1

### C Exercises

Modify the link below so it points to the `ex01` directory in your
student repository.

[Here is a link to the ex01 directory in my repository](https://github.com/SelinaWang/ExercisesInC/tree/master/exercises/ex01)

### Think OS Chapter 1 reading questions

For each of the reading questions below, write answers in the form of
a clear, concise, complete sentence or two.

1) Give an example of a feature common in interpreted languages that is rare in compiled languages.

Dynamic types (things that happen at run time).

2) Name two advantages of static typing over dynamic typing.
In a dynamically-typed language, you don’t always know the type of a variable until the program is running. Type checks happen before the program starts executing, so errors can be found more quickly. 

3) Give an example of a static semantic error.

A function is given the wrong type of arguments.

4) What are two reasons you might want to turn off code optimization?

If the program has a subtle bug, optimization might make the bug appear or disappear. It is also a good idea of turn off optimization while developing new code adn turn it back on when the program is working to confirm that the tests still pass.

5) When you run `gcc` with `-S`, why might the results look different on different computers?

Because the "-S" flag tells gcc to compile and generate assembly code for the machine that the program is running on, so if you are running on a different architecture you might get different code.

6) If you spell a variable name wrong, or if you spell a function name wrong, the error messages you get might look very different.  Why?

Because you will get a message from the linker.

7) What is a segmentation fault?

If you try to read or write an incorrect location in memory.
