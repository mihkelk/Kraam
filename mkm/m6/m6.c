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
int koordinaadid[64][64][64];
int suurus = 100;
int m = 0;
int px = 2;
int py = 2;
int jsuurus = 10;


int toad( r) {
	int x;
	int y;

	FILE *fp = fopen("maailm.txt", "r");
	char asukoht = '0';
	//üldise toa loomine

	for (y = 0; asukoht !='-'; y++) {
		for (x = 0; asukoht !='\n'; x++) {
			asukoht = fgetc(fp);
			if (asukoht == '0') {
				koordinaadid[r][y][x] = 0;
			} else if (asukoht == '1') {
				koordinaadid[r][y][x] = 1;
			} else if (asukoht == '2') {
				koordinaadid[r][y][x] = 2;}
			else {koordinaadid[r][y][x] = 0;};
		};
	 asukoht = fgetc(fp);
	};


return 1;
}
;

//vastava toa loomine
/*	koordinaadid[10][20][10] = 2;
 koordinaadid[10][4][6] = 0;

 koordinaadid[20][4][6] = 1;
 koordinaadid[20][0][11] = 2;*/

int tuba1() {
px = 10;
py = 19;
return 1;
}
;
int tuba2() { //tegelase teise toa otsa liigutamine
px = 11;
py = 1;
return 1;
}
;

int main() {
int x;
int y;
//int koordinaadid[64][64][64];
//int suurus = 20;

int r = 10;
toad(r);
while ("TRUE") {



	if (koordinaadid[10][py][px] == 2) {
		r = 20;
		tuba2();
	};
	if (koordinaadid[20][py][px] == 2) {
		r = 10;
		tuba1();
	};

//----------Klahvivajutuste-järgi-mängija-koordinaatide-muutmine----------//
	char klahv = getch();

	if (klahv == 'd' && (koordinaadid[r][py][px + 1] != 1)) {
		px++;
		koordinaadid[r][py][px - 1] = 0;
	} else if (klahv == 'a' && (koordinaadid[r][py][px - 1] != 1)) {
		px--;
		koordinaadid[r][py][px + 1] = 0;
	}
	if (klahv == 'w' && (koordinaadid[r][py - 1][px] != 1)) {
		py--;
		koordinaadid[r][py + 1][px] = 0;
	}
	if (klahv == 's' && (koordinaadid[r][py + 1][px] != 1)) {
		py++;
		koordinaadid[r][py - 1][px] = 0;
	}
	toad(r);
//------------------------------------------------------------------------//

//-------------------------------joonistamine-----------------------------//
	system("cls");

	for (y = py - jsuurus; y < (py + jsuurus + 1); y++) {
		for (x = px - jsuurus; x < (px + jsuurus + 1); x++) {
			if (x == px && y == py) {
				koordinaadid[r][y][x] = 3;
			}
			switch (koordinaadid[r][y][x]) {
			case 0:
					printf(" ");
				break;
			case 1:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				printf("\333"); //ASCII koodid kaheksanddsüsteemis
				break;
			case 3:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
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
//------------------------------------------------------------------------//
};
return 0;
}

// SetCursorPos(xpos,ypos); kursori paigutamine kuhugi

