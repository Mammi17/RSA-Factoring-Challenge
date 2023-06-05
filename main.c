#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE *str;
	char *ligne = NULL;
	size_t l = 0;
	long long fl = 1, d, result, numb, count;
	ssize_t read;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	str = fopen(argv[1], "r");
	if (str == NULL) {
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&ligne, &l, str)) != -1) {
		fl = 1, d = 2;
		num = atoll(ligne);
		while (fl) {
			result = num % d;
			if (!result) {
				count = num / d;
				printf("%lld=%lld*%lld\n", numb, count, d);
				fl = 0;
			}
			d++;
		}
	}

	free(ligne);
	fclose(str);
	exit(EXIT_SUCCESS);
}
