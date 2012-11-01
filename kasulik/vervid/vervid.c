/*
 * uus.c
 *
 *  Created on: 14.10.2012
 *      Author: Miku
 */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
// Programm mis kirjutab välja värvide väärtusi
char tser;
int main() {
	int kuni = 251;
	int v;

	while (TRUE) {
		for (v = 0; v < kuni; v++) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), v); //värv!!
			printf("%d", v);
			printf("\n");
			//getch();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		};
		char tser = getch();
		if (tser == '-') {
			kuni = 251;
			system("cls");
		} else {
			kuni = kuni + 251;
		}
	}
		/*		printf("\333"); //kuuendsüsteemis
		 SetCursorPos(50,20);
		 printf("\333");
		 //};

		 char rida[128];
		 FILE *sisse=fopen("tervitus.txt", "r");
		 while(!feof(sisse)){
		 fscanf(sisse,  "%s", rida);  //võtab ühe sõna
		 fgets(rida, 128, sisse);
		 printf("%s", rida);
		 }
		 fclose(sisse);
		 return 1;


		 */

		return 0;
	}

//http://www.mailsend-online.com/blog/setting-windows-console-text-colors-in-c.html
