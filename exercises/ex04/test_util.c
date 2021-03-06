/* Solution code for Software Systems at Olin College.

Copyright 2017 Selina Wang

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "util.h"
#include "minunit.h"

int tests_run = 0;

static char *test1() {
    char *res = icmpcode_v4(9);
    char *message = "test1 failed: endswith(\"icmpcode_v4\", \"9\") should return \"destination network administratively prohibited\"";
    mu_assert(message, res == "destination network administratively prohibited");
    return NULL;
}

static char *test2() {
  char *res = icmpcode_v4(14);
  char *message = "test1 failed: endswith(\"icmpcode_v4\", \"14\") should return \"host recedence violation\"";
  mu_assert(message, res == "host recedence violation");
  return NULL;
}

static char *test3() {
  char *res = icmpcode_v4(3);
  char *message = "test1 failed: endswith(\"icmpcode_v4\", \"3\") should return \"port unreachable\"";
  mu_assert(message, res == "port unreachable");
  return NULL;
}

static char * all_tests() {
    mu_run_test(test1);
    mu_run_test(test2);
    mu_run_test(test3);
    return NULL;
}

int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != NULL) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
