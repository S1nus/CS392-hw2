#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main() {
	FILE *toRead = fopen("temp/array-0-50.dat", "r");

	while (!feof(toRead)) {
		float f;
		fread(&f, sizeof(f), 1, toRead);
		printf("%.6f\n", f);
	}

	fclose(toRead);
}
