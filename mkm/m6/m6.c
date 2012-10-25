/*
 * m6.c
 *
 *  Created on: 23.10.2012
 *      Author: mihkelk
 */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h> //värvide jaoks
int x;
int y;
int r;
int koordinaadid[80][80][80];
int suurus = 1000;
int m = 0;
int px = 30;
int py = 30;
int jsuurus = 10; //joonistatava vaatevälja suurus

int toad() {
	//int x;
	//int y;

	FILE *fp = fopen("maailm.txt", "r"); //Faili sisselugemine
	char asukoht = '0';

// Maailma loomine failist
	for (y = 0; asukoht != '-'; y++) {
		for (x = 0; asukoht != '\n'; x++) {
			asukoht = fgetc(fp);
			switch (asukoht) {
			case '0':
				koordinaadid[r][y][x] = 0;
				break;
			case '1':
				koordinaadid[r][y][x] = 1;
				break;
			case '2':
				koordinaadid[r][y][x] = 2;
				break;
			default:
				koordinaadid[r][y][x] = 9;
				break;
			}
		};
		asukoht = fgetc(fp);
	};

	return 1;
}

//-------------------------------joonistamine-----------------------------//
int joonistamine() {
	system("cls");

	for (y = py - jsuurus; y < (py + jsuurus + 1); y++) {
		for (x = px - jsuurus; x < (px + jsuurus + 1); x++) {
			if (x == px && y == py) {
				koordinaadid[r][y][x] = 3;
			}
			switch (koordinaadid[r][y][x]) {
			case 0:
				//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 34);
				printf(" ");
				break;
			case 1:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				printf("\333"); //ASCII koodid kaheksanddsüsteemis
				break;
			case 2:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
				printf("\261");
				break;
			case 3:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				printf("\1");
				break;

			default:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
				printf("%d", koordinaadid[r][y][x]);
				break;

			};

		};
		printf("\n");
	};
	return 0;
}
//------------------------------------------------------------------------//

//-------------------------------peafunktsioon----------------------------//
int main() {

	toad();
	joonistamine();
	int rsalvestatud; // salvestab ruudu kus mängja seisab, et see hiljem taastada

	while ("TRUE") {

//----------Klahvivajutuste-järgi-mängija-koordinaatide-muutmine----------//
		char klahv = getch();

		if (klahv == 'd' && (koordinaadid[r][py][px + 1] != 1)) {

			rsalvestatud = koordinaadid[r][py][px+1];
			px++;
			koordinaadid[r][py][px - 1] = rsalvestatud;
		} else if (klahv == 'a' && (koordinaadid[r][py][px - 1] != 1)) {
			rsalvestatud = koordinaadid[r][py][px+1];
			px--;
			koordinaadid[r][py][px + 3] = rsalvestatud;
		}
		if (klahv == 'w' && (koordinaadid[r][py - 1][px] != 1)) {
			py--;
			koordinaadid[r][py + 1][px] = koordinaadid[r][py - 2][px];
		}
		if (klahv == 's' && (koordinaadid[r][py + 1][px] != 1)) {
			py++;
			koordinaadid[r][py - 1][px] = koordinaadid[r][py + 2][px];
		}
		//toad(r);
		joonistamine();
	};
	return 0;
//------------------------------------------------------------------------//
}
//------------------------------------------------------------------------//


// SetCursorPos(xpos,ypos); kursori paigutamine kuhugi, pole veel kasutusel

