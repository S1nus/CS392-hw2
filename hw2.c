#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

float generateNum() {
	float a = 200;
	float result = ((float)rand()/(float)(RAND_MAX)) * a;
	result = result - 100;
	return result;
}

void generateNnumbers(int n) {
	FILE* nnumbers = fopen("temp/nnumbers", "w");

	for (int i = 0; i<n; i++) {
		float num = generateNum();
		fwrite(&num, sizeof(num), 1, nnumbers);
	}

	fclose(nnumbers);
}

void readAndPrintFloats() {
	FILE *toRead = fopen("temp/nnumbers", "r");

	while (!feof(toRead)) {
		float f;
		fread(&f, sizeof(f), 1, toRead);
		printf("%.6f\n", f);
	}

	fclose(toRead);
}

/*void merge(int low, int middle, int high) {
	printf("Merging %d low %d middle %d high\n", low, middle, high);
}*/

/*void mergesort(int low, int high) {
	printf("Doing mege sort on %d low and %d high\n", low, high);

	if (low < high) {
		int middle = low + (high - low)/2;

		mergesort(low, middle);

		mergesort(middle + 1, high);

		merge(low, middle, high);
	}
}*/

void merge(FILE* file1, FILE* file2) {

}

void mergesort(FILE* nums) {
	int lowIndex = 0;
	int highIndex = 0;
	float f;
	while (!feof(nums)) {
		fread(&f, sizeof(f), 1, nums);
		//printf("F is: %.3f index is: %d\n", f, highIndex);
		highIndex++;
	}
	highIndex--;

	char* fileName = (char*)calloc(30, sizeof(char));
	int aFilenameSize = sprintf(fileName, "array-%d-%d.dat", lowIndex, highIndex);
}

int main(int argc, char** argv) {

	int N = 100;

	mkdir("temp", 0700);

	generateNnumbers(N);

	FILE* numFile = fopen("temp/nnumbers", "rb");

	mergesort(numFile);

	fclose(numFile);

	return 0;
}
