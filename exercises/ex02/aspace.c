/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;

void print_local()
{
  int local_var = 6;
  printf ("Address of local var is %p\n", &local_var);
}

int main ()
{
    int var2 = 5;
    void *p = malloc(128);
<<<<<<< HEAD
    void *q = malloc(128);
    void *m = malloc(20);
    void *n = malloc(20);
    char *s = "Literal string";
=======
    char *s = "Hello, World";
>>>>>>> f1730219000dea2729d3a9625259830250492bea

    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
<<<<<<< HEAD
    printf ("Address of p is %p\n", p);
    printf ("Address of q is %p\n", q);
    printf ("Address of m is %p\n", m);
    printf ("Address of n is %p\n", n);
    printf ("Address of s is %p\n", s);
=======
    printf ("p points to %p\n", p);
    printf ("s points to %p\n", s);
>>>>>>> f1730219000dea2729d3a9625259830250492bea

    print_local();

    return 0;
}
