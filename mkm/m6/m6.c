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
int koordinaadid[4][100][100];
int suurus = 1000;
int m = 0;
int px = 30;
int py = 30;
int jsuurus = 10; //joonistatava vaatevälja suurus

int maailm() {
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
				koordinaadid[r][y][x] = 0; //tühjus
				break;
			case '1':
				koordinaadid[r][y][x] = 1; //sein
				break;
			case '2':
				koordinaadid[r][y][x] = 2; //muru
				break;
			case '4':
				koordinaadid[r][y][x] = 4; //
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
			case 4:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				printf("\260");
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

	maailm();
	joonistamine();
	int Q = 1;
	int rs1 = 0; // salvestab ruudu kus mängja seisab, et see hiljem taastada
	int rs2 = 0; // salvestab teise ruudu kus mängija seisis
	int s1 = 1; // samm 1
	int s2 = 0; // samm 2
	while (Q == 1) {
//----------Klahvivajutuste-järgi-mängija-koordinaatide-muutmine----------//
		char klahv = getch();

		if (klahv == 'd' && (koordinaadid[r][py][px + 1] != 1)) {

			if (s1 == 1) {
				s2 = 0;
				rs1 = koordinaadid[r][py][px + 1];
				px++;
				koordinaadid[r][py][px - 1] = rs2;
				s1 = 0;
			}
			if (s2 == 1) {
				rs2 = koordinaadid[r][py][px + 1];
				px++;
				koordinaadid[r][py][px - 1] = rs1;
				s2 = 0;
				s1 = 1;
			}

		} else if (klahv == 'a' && (koordinaadid[r][py][px - 1] != 1)) {
			//rsalvestatud = koordinaadid[r][py][px + 1];
			if (s1 == 1) {
				s2 = 0;
				rs1 = koordinaadid[r][py][px - 1];
				px--;
				koordinaadid[r][py][px + 1] = rs2;
				s1 = 0;
			}
			if (s2 == 1) {
				rs2 = koordinaadid[r][py][px - 1];
				px--;
				koordinaadid[r][py][px + 1] = rs1;
				s2 = 0;
				s1 = 1;
			}
			//koordinaadid[r][py][px + 3] = rsalvestatud;*/
		}
		if (klahv == 'w' && (koordinaadid[r][py - 1][px] != 1)) {
			if (s1 == 1) {
				s2 = 0;
				rs1 = koordinaadid[r][py - 1][px];
				py--;
				koordinaadid[r][py + 1][px] = rs2;
				s1 = 0;
			}
			if (s2 == 1) {
				rs2 = koordinaadid[r][py - 1][px];
				py--;
				koordinaadid[r][py + 1][px] = rs1;
				s2 = 0;
				s1 = 1;
			}

		}
		if (klahv == 's' && (koordinaadid[r][py + 1][px] != 1)) {

			if (s1 == 1) {
				s2 = 0;
				rs1 = koordinaadid[r][py + 1][px];
				py++;
				koordinaadid[r][py - 1][px] = rs2;
				s1 = 0;
			}
			if (s2 == 1) {
				rs2 = koordinaadid[r][py + 1][px];
				py++;
				koordinaadid[r][py - 1][px] = rs1;
				s2 = 0;
				s1 = 1;
			}

		}
		if (klahv == 'q') {
			Q = 0;
		}
		s2 = 1;
		//toad(r);
		joonistamine();
		//sleep(1000);
		Sleep(200);

	};
	return 0;
//------------------------------------------------------------------------//
}
//------------------------------------------------------------------------//

// SetCursorPos(xpos,ypos); kursori paigutamine kuhugi, pole veel kasutusel

