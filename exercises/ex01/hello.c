#include <stdio.h>

int main() {

	int x = 5;
    int a = 3;
    int b = 4;
    int c = a + b;
    int y = x + 1;

    printf("y is %d\n", y);

    printf("Hello, World!\n");
    return 0;
}
/*
*	###OPTIMIZATION
*	Q.1
*	The assembly code that corresponds to int x = 5 is
*	movl	$5, -16(%rbp)
*	
*	Q.2
*	The line disappears. The assembly code is much more simplified 
*	and it's harder to make out the original program.
*
*	Q.3
*	The line reappears. The assembly code doesn't change much.
*
*	Q.4
*	The assembly code for decarling x and y disappears with optimization.
*	 Optimization seems to minimize variable declaration.
*/

