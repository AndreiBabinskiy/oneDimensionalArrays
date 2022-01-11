#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

void printArr(int* arr, int N) {
	for (int i = 0; i < N; i++) {
		printf("[%d]", *(arr + i));
	}
}

int multiplicationArrayElements(int* arr, int multiplication, int N) {
	int max = *arr;
	int min = *arr;
	int iMax{}, jMin{};

	for (int i = 1; i < N; i++) {
		if (*(arr + i) > max)
		{
			max = *(arr + i);
			iMax = i;
		}
		if (*(arr + i) < min)
		{
			min = *(arr + i);
			jMin = i;
		}
	}

	if (iMax > jMin) {
		for (int i = jMin; i < iMax; i++) {
			multiplication *= *(arr + i);
		}
	}
	else if (jMin > iMax) {
		for (int i = iMax; i < jMin; i++) {
			multiplication *= *(arr + i);
		}
	}
	printf("Min = %d -- Max= %d \n", min, max);
	return multiplication;    
}

void bubbleSort(int* arr, int N) {
	int tmp;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - 1; j++) {

			if (*(arr + j) > *(arr + j + 1)) {

				tmp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = tmp;
			}

		}
	}
}

void hoaraSort(int* arr, int left, int right) {

	int i = left, j = right;
	int tmp;

	int m = arr[(left + right) / 2];
	do {
		while (*(arr + i) < m) i++;
		while (*(arr + j) > m) j--;
		if (i <= j) {
			if (*(arr + i) > *(arr + j)) {
				tmp = *(arr + i);
				*(arr + i) = *(arr + j);
				*(arr + j) = tmp;
			}
			i++;
			j--;
		}

	} while (i <= j);

	if (left < j) hoaraSort(arr, left, j);
	if (i < right) hoaraSort(arr, i, right);
}

void copyArr(int* arr, int N) {
	int* newArr;
	newArr = new int[N];
	for (int i = 0; i < N; i++) {
		*(newArr + i) = *(arr + i);
	}

	for (int i = 0; i < N; i++) {
		printf("[%d]", *(newArr + i));
	}
	
}

int binSearch(int* arr, int key, int N) {
	int l = -1;                      
	int r = N;

	while (l < r - 1) {
		int m = (l + r) / 2;            
		if (*(arr + m) < key) {
			l = m;
		}
		else {
			r = m;
		}
	}
	if (*(arr + r) == key) {
		return r;
	}
	else {
		return -1;
	}
}
void main() {
	int* arr;
	int N;
	int multiplication = 1;
	
	int key;
m1:
	printf("Number of elements for  arr : ");
	scanf("%d", &N);

	while (N == 0 || N < 0) {
		printf("Exception (invalid number) \n");
		goto m1;
	}

	arr = new int[N];
	srand(time(NULL));   

	for (int i = 0; i < N; i++) {
		*(arr + i) = 1 + rand() % 100;
	}

	printArr(arr, N);
	printf("\n======================\n");
	multiplication = multiplicationArrayElements(arr, multiplication, N);

	printf("Multiplication = %d \n", multiplication);

	printf("\n======================\n");
	
	clock_t startBubble = clock();
	bubbleSort(arr, N);
	copyArr(arr, N);
	clock_t endBubble = clock();
	double secondsBubble = (double)(endBubble - startBubble) / CLOCKS_PER_SEC;
	printf("\n The Bubble time: %.8f seconds\n", secondsBubble);

	printf("\n======================\n");
	
	clock_t startHoara = clock();
	hoaraSort(arr, 0, N - 1);
	copyArr(arr, N);
	getchar();
	clock_t endHoara = clock();
	double secondsHoara = (double)(endHoara - startHoara) / CLOCKS_PER_SEC;
	printf("\n The Hoara time: %.8f seconds\n", secondsHoara);

	if (secondsHoara > secondsBubble) {
		printf("\n The Bubble sort working faster then Hoara Sort\n");
	}
	else if (secondsHoara > secondsBubble) {
		printf("\n The Hoara sort working faster then Bubble Sort\n");
	}
	else {
		printf("\n The Hoara sort and Bubble Sort have the same time of compilation\n");
	}

	printf("\n======================");
	printf("\nEnter the element: ");
	scanf("%d", &key);

	int index = binSearch(arr, key, N);

	if (index != -1) {
		printf("\n Position of [%d] in the array is: %d \n", key, index);
	}
	else printf("\n No element [%d] in the array\n", key);
}