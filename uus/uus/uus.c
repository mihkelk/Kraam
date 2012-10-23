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

int main() {

	//int h;

	//for (h = 1; h < 900; h++){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); //värv!!

		printf("\333"); //kuuendsüsteemis
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




	getch();


	return 0;
}
