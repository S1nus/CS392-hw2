#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

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

void readAndPrintFloats(char* filename) {
	FILE *toRead = fopen(filename, "r");

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

	int middle = lowIndex + (highIndex - lowIndex)/2;

	char* fileNameA = (char*)calloc(30, sizeof(char));
	int aFilenameSize = sprintf(fileNameA, "temp/array-%d-%d.dat", lowIndex, middle);
	fileNameA = realloc(fileNameA, aFilenameSize);
	char* fileNameB = (char*)calloc(30, sizeof(char));
	int bFilenameSize = sprintf(fileNameB, "temp/array-%d-%d.dat", middle+1, highIndex);
	fileNameB = realloc(fileNameB, bFilenameSize);

	FILE* fileA = fopen(fileNameA, "wb");
	FILE* fileB = fopen(fileNameB, "wb");

	//readAndPrintFloats("temp/nnumbers");
	rewind(nums);
	for (int i = 0; i < middle; i++) {
		float f;
		fread(&f, sizeof(float), 1, nums); 
		fwrite(&f, sizeof(float), 1, fileA);
	}
	for (int i = middle; i<highIndex; i++) {
		float f;
		fread(&f, sizeof(float), 1, nums);
		fwrite(&f, sizeof(float), 1, fileB);
	}

	fclose(fileA);
	fclose(fileB);
	free(fileNameA);
	free(fileNameB);
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
