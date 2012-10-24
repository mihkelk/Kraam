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
// Programm mis kirjutad välja värvide väärtusi
int main() {

	int v;

	for (v = 0; v < 99; v++) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), v); //värv!!
		printf("%d", v);
		printf("\n");
	};

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

	getch();

	return 0;
}
