#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <malloc.h>
#include <stdlib.h>

void printArrA(int* arrA, int N) {
	for (int i = 0; i < N; i++) {
		printf("[%d]", *(arrA + i));
	}
}

void printArrB(int* arrB, int M) {
	for (int j = 0; j < M; j++) {
		printf("[%d]", *(arrB + j));
	}
}

void main() {
	int* arrA;
	int* arrB;
	int N, M;
	int sum1 = 0;
	int sum2 = 0;

	m1:
	printf("Number of elements for  arrA : ");
	scanf("%d", &N);
	m0:
	printf("Number of elements for arrB : ");
	scanf("%d", &M);

	while (N == 0 || N < 0) {
		printf("Exception (invalid number) \n");
		goto m1;
	}
	while (M == 0 || M < 0) {
		printf("Exception (invalid number)\n");
		goto m0;
	}
	
	arrA = (int*)(malloc(N * sizeof(int)));

	for (int i = 0; i < N; i++) {
		*(arrA + i) = 1 + rand() % 100;
		sum1 += *(arrA + i);
	}

	arrB = (int*)(malloc(M * sizeof(int)));

	for (int j = 0; j < M; j++) {
		*(arrB + j) = 1 + rand() % 100;
		sum2 += (*arrB + j);
	}

	printf("Array A\n");
	printArrA(arrA, N);
	printf("\nArray B\n");
	printArrB(arrB, M);


	if (sum1 > sum2) {
		printf("\nSum Array with the smallest values\n");
		printArrB(arrB, M);
	}
	else {
		printf("\nSum array with the smallest values\n");
		printArrA(arrA, N);
	}
}

