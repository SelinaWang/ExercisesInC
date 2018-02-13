/* Example code for Exercises in C.

Modified version of an example from Chapter 2.5 of Head First C.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define NUM_TRACKS 5

char tracks[][80] = {
    "So What",
    "Freddie Freeloader",
    "Blue in Green",
    "All Blues",
    "Flamenco Sketches"
};


// Finds all tracks that contain the given string.
//
// Prints track number and title.
void find_track(char search_for[])
{
    int i;
    for (i=0; i<NUM_TRACKS; i++) {
        if (strstr(tracks[i], search_for)) {
            printf("Track %i: '%s'\n", i, tracks[i]);
        }
    }
}

// Finds all tracks that match the given pattern.
//
// Prints track number and title.
void find_track_regex(char pattern[])
{
    regex_t regex;
    int reti;
      /* Compile regular expression */
    reti = regcomp(&regex, pattern, 0);
    if (reti) {
      fprintf(stderr, "Could not compile regex\n");
      exit(1);
    }

    /* Execute regular expression */
    int i;
  	regmatch_t r[10];
  	for (i = 0; i < NUM_TRACKS; i++) {
  		reti = regexec (&regex, tracks[i], 10, r, 0);
  		if (!reti) {
              printf("Track %i: '%s'\n", i, tracks[i]);
  		}
	}

    /* Free memory allocated to the pattern buffer by regcomp() */
    regfree(&regex);
    return;
}

// Truncates the string at the first newline, if there is one.
void rstrip(char s[])
{
    char *ptr = strchr(s, '\n');
    if (ptr) {
        *ptr = '\0';
    }
}

int main (int argc, char *argv[])
{
    char search_for[80];

    /* take input from the user and search */
    printf("Search for: ");
    fgets(search_for, 80, stdin);
    rstrip(search_for);

    // find_track(search_for);
    find_track_regex(search_for);

    return 0;
}
