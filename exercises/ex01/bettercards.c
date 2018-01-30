/*
*	Simple card counting game - refactored version.
*	Written for Software System Spring 2018.
*	(c) 2018, Ziyu Selina Wang.
*/
#include <stdio.h>
#include <stdlib.h>

char card_name[3];
int count = 0;

int main() {
	check_card();
	return 0;
}

void get_card_name() {
	puts("Enter the card_name: ");
	scanf("%2s", card_name);
}

void check_card() {
		while (card_name[0]!='X') {
			int val = 0;
			get_card_name();
			switch(card_name[0]) {
			case 'K':
			case 'Q':
			case 'J':
				val = 10;
				break;
			case 'A':
				val = 11;
				break;
			case 'X':
				continue;
			default:
				val = atoi(card_name);
				if ((val <1)||(val>10)) {
					puts("I don't understand that value!");
					continue;
				}
			}
			if ((val>2)&& (val<7)) {
				count++;
			} else if (val==10) {
				count--;
			}
			printf("Current count: %i\n",count);
	} 
}