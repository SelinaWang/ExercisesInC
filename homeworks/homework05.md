## Homework 5

### C Exercises

Modify the link below so it points to the `ex05` directory in your
student repository.

[Here is a link to the ex05 directory in my repository](https://github.com/SelinaWang/ExercisesInC/tree/master/exercises/ex05)

### Think OS Chapter 5 reading questions

**Bits and bytes**

1) Suppose you have the value 128 stored as an unsigned 8-bit number.  What happens if you convert
it to a 16-bit number and accidentally apply sign extension?

If the number is still unsigned then you would get 65408 instead of 128 and -128 if
the new number is not signed.

2) Write a C expression that computes the two's complement of 12 using the XOR bitwise operator.
Try it out and confirm that the result is interpreted as -12.

b00001100 ^ b11111111 + b00000001

3) Can you guess why IEEE floating-point uses biased integers to represent the exponent rather than a
sign bit or two's complement?

Biasing is done because exponents have to be signed values in order to be able to represent both tiny and huge values, but two's complement, the usual representation for signed values, would make comparison harder. To solve this problem the exponent is stored as an unsigned value suitable for comparison, and when being interpreted it is converted into an exponent within a signed range by subtracting the bias. By arranging the fields such that the sign bit takes the most significant bit position, the biased exponent takes the middle position, then the mantissa will be the least significant bits and the resulting value will be ordered properly.

4) Following the example in Section 5.3, write the 32-bit binary representation of -13 in single precision
IEEE floating-point.  What would you get if you accidentally interpreted this value as an integer?

b11000001010100000000000000000000. This value as an integer is 3243245568 as an unsigned int or -1051721728 as a signed int.

5) Write a function that takes a string and converts from lower-case to upper-case by flipping the sixth bit.  
As a challenge, you can make a faster version by reading the string 32 or 64 bits at a time, rather than one
character at a time.  This optimization is made easier if the length of the string is a multiple of 4 or 8 bytes.
`
char* lower_to_upper(char* str) {
  int len = strlen(str);
  char* new_str = malloc(len*sizeof(char));
  int i;
  for (i=0;i<len;i++) {
    new_str[i]= str[i] ^ b00100000
  }
  return new_str;  
}

`
