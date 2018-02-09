/*
Adder program allows the user to enter integers, one per line, until the user
hits Control-D, which is the end-of-file (EOF) character.

SoftSys 2018
Ziyu Selina Wang
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10
#define ARRAY_SIZE 7

char buffer[BUFFER_SIZE];
int num_array[ARRAY_SIZE];
int counter = 0;
char* num;
int number;
int inp;
int sum =0;
int done = 0;
int invalid = 0;

int get_input() {
  num = fgets(buffer, sizeof(buffer), stdin);
  // Checl if the user is done entering numbers
  if (num == NULL) {
    done = 1;
    return 0;
  }
  // check if the string is too long
  if (strlen(buffer) == BUFFER_SIZE) {
    invalid = 1;
    return 0;
  }
  number = atoi(num);
  // check if the entered string is not able to be converted to an int
  if (number == 0) {
    invalid = 1;
    return 0;
  }
  // If passes all tests then return the number
  return number;
}

int calculate_sum(int array[], int len) {
  int i;
  for (i=0; i<len; i++) {
      sum+=num_array[i];
  }
  printf("The sum of all the entered number(s) is %d\n", "sum");
}

int main() {
  printf("%s\n", "Enter the numbers you would like to add up (max num of inputs = 9):");
  int i;
  for (i=0; i<ARRAY_SIZE; i++) {
      inp = get_input();
      if (done == 1) {
        calculate_sum(num_array, i);
        return 0;
      }
      if (invalid == 1) {
        printf("%s\n", "Error: invalid input");
        return -1;
      }
      num_array[i] = inp;
  }

  // If we are out of the for loop, it means the user had entered too many nums
  printf("%s\n", "Entered too many inputs");
  return -1;
}
