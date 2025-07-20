//----------------------------------------------------------
// CProg01.cpp 
//----------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //For funkc: _getch(), _getche(), _kbhit
#define SIZE 10
#define FACTOR 5
#define my_exit() printf("Press any key..."); while (!_kbhit())
void plin(int ln); // Function prototype for plin
int main() {
    printf("Hello World!\n");
	printf("Input char = ");
	char c = getchar();
	int ic = c; // Convert char to int
	printf("You pressed: %c val(%c) = %d\n", c, c, ic);
	printf("\n     Tables and pointers\n");
	int *p, tb[SIZE];
	plin(30);
	printf("Tables\t\tPointers\n");
	plin(30);
	p = tb; // Assign address of the first element of the array to pointer p
	for (int i = 0; i < SIZE; i++) {
		tb[i] = i * FACTOR;
		printf("tb[%d] = %d\t*p(%d) = %d\n", i, tb[i], i, *(p + i));
	}
	plin(30);
	my_exit();
	return 0; 
}
void plin(int ln) {
	for (int i = 0; i < ln; i++) {
		printf("-");
	}
	printf("\n");
}	
