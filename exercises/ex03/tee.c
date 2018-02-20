#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

static int append_mode = 0;

int parse_args(int argc, char *argv[])
{
	char c;
	while ((c = getopt(argc, argv, "a")) != -1) {
		switch (c) {
		case 'a':
			append_mode = 1;
			break;
		case '?':
			if (isprint(optopt))
				fprintf(stderr, "Unkonw option `-%c'.\n", optopt);
			else
				fprintf(stderr,
					"Unknown option character `\\x%x'.\n", optopt);
			return 1;
		default:
			abort();
			break;
		}
	}
	return 0;
}

int main(int argc, char *argv[])
{
	char buf[100];
	size_t len;
	char *file_mode;
    int i;
	FILE *files[20];
	int num_files;

	if (parse_args(argc, argv)) {
		return 1;
	}

	file_mode = (append_mode ? "a" : "w");

	num_files = argc - optind;
	if (num_files > 0) {
		if (files == NULL) {
			fprintf(stderr, "Unable to allocate file buffer space\n");
			return 1;
		}

		/* go through file arguments and either open for writing
		   or append based on the -a flag */
		for (i = optind; i < argc; i++) {
			FILE *pFile = fopen(argv[i], file_mode);
			if (pFile == NULL)
			{
				fprintf(stderr, "Unable to open file %s for mode %s",
					argv[i], file_mode);
				goto main_cleanup;
			}
			files[i - optind] = pFile; /* mind the offset */
		}
	}

	FILE *not_stdin = fopen("tee.c", "r");
	while ((len = fread(&buf[0], 1, sizeof(buf), not_stdin)) > 0) {
		fwrite(&buf[0], 1, len, stdout);
		for (i = 0; i < num_files; i++) {
			fwrite(&buf[0], 1, len, files[i]);
		}
	}

	main_cleanup:
	if (num_files > 0) {
		for (i = 0; i < num_files; i++) {
			fclose(files[i]);
		}
	}

	return 0;
}

/* This implementation was the first one I found on google and I think I just got lucky
* cuz this version is simple and works for the purpose defined. I didn't really change
* much of the code cuz I think it is pretty much optimized here.
* My solution does not work with the -i option and it doesn't deal with a lot of the
* errors that the professional code deals with to try and prevent fatal errors from
* user input.
*/
