//------------------------------------------------------------------------------
// CProg01.cpp 
// Introduction to pointers
//------------------------------------------------------------------------------
#include <stdio.h>				//printf
#include <stdlib.h>				//getrchar
#include <conio.h>				//_kbhit
//------------------------------------------------------------------------------
#define DIM 10
#define my_exit() printf("\n\n\nPress any key to exit..."); while (!_kbhit())
#define loop() printf("\nPress any key"); while (!_kbhit())
//  Global DATA ----------------------------------------------------------------
int FACTOR = 5;
int point = 1;
bool end = false;
// Function prototype ----------------------------------------------------------
void plin(int ln); 
int  pmenu();
//------------------------------------------------------------------------------
int main() {
//------------------------------------------------------------------------------
top:
	point = pmenu();
	switch (point) {
		case 1: {
			printf("\nInput factor(0 - 9) = ");
			char c = getchar();
			FACTOR = (int)c - 48;
			if (FACTOR >= 0 && FACTOR <= 9) {
				printf("You pressed: %c val(%c) = %d\n", c, c, FACTOR);
			}
			else {
				printf("Wrong number %d. Program terminated!\n\n", FACTOR);
				my_exit();
				return 1;
			}
			loop();
			break;
		}
		case 2: {
			printf("\n     Tables and pointers\n\nFACTOR = %d\n\n", FACTOR);
			int* p, tb[DIM];
			plin(30);
			printf("Tables\t\tPointers\n");
			plin(30);
			p = tb; 
			for (int i = 0; i < DIM; i++) {
				tb[i] = i * FACTOR;
				printf("tb[%d] = %d\t*p(%d) = %d\n", i, tb[i], i, *(p + i));
			}
			plin(30);
			loop();
			break;
		}
		case 3: {
			printf("\n     Variables and pointers\n\n");
			int *px, x = 15;
			px = &x;
			printf("Variable x = %d\tPointer *px = %d\n", x, *px);
			loop();
			break;
		}
		case 4: {
			end = true;
			break;
		}

	}
	if (end == false) goto top;
	return 0; 
}
//------------------------------------------------------------------------------
//	Auxiliary functions
//------------------------------------------------------------------------------
//	Display lines
void plin(int ln) {
	for (int i = 0; i < ln; i++) {
		printf("-");
	}
	printf("\n");
}	
//	Display menu
int pmenu() {
	int p = 0;
	system("CLS");
	printf("\n\n\n\n\t\t*** MENU ***\n\n");
	printf("\t(1) Input value for FACTOR\n\n");
	printf("\t(2) Show pointers for tables\n\n");
	printf("\t(3) Show pointers for variables\n\n");
	printf("\t(4) Exit");
lop:
	p = (int)_getch() - 48;
	if (p != 1 && p != 2 && p != 3 && p != 4) goto lop;
	system("CLS");
	return p;
}
