/*
 * m7.c
 *
 *  Created on: 02.11.2012
 *      Author: Mihkel
 */

//#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>
#include <windows.h> //
#include <curses.h>
//#include <cursesw.h>

//char smiley = '\1'

int x;
int y;
int z;
int xpos = 0;
int ypos = 0;
int koordinaadid[100][100][100];
int m = 0;
int px = 30;
int py = 30;
int jsuurus = 10; //joonistatava vaatevälja suurus
int coord = 0;

// Maailma loomine failist
int maailm() {
	char cz[10];

	for (z = 49; z < 51; z++) {

		cz[10] = itoa(z, cz, 10); //itoa(arv mida teisaldan, string millesse teisaldan, arvusüsteem)
		//	printf("%s", cz); //[0], cz[1], cz[2]);

		FILE *korrus = fopen(cz, "r");
		//	printf("%c", cz[1]);
		char casukoht = '0';
		for (y = 0; casukoht != '-'; y++) {
			for (x = 0; casukoht != '\n'; x++) {
				casukoht = fgetc(korrus);

				switch (casukoht) {
				case '0':
					koordinaadid[z][y][x] = 0; //tühjus
					break;
				case '1':
					koordinaadid[z][y][x] = 1; //sein
					break;
				case '2':
					koordinaadid[z][y][x] = 2; //muru
					break;
				case '4':
					koordinaadid[z][y][x] = 4; //põõsas
					break;
				case '5':
					koordinaadid[z][y][x] = 5; //trepp alla
					break;
				case '6':
					koordinaadid[z][y][x] = 6; //trepp yles
					break;
				case '7':
					koordinaadid[z][y][x] = 7; //puitpõrand
					break;
				default:
					koordinaadid[z][y][x] = 9;
					break;
				}
			};
			casukoht = fgetc(korrus);
		};

	}

	return 1;
}


//http://blogs.microsoft.co.il/blogs/pavely/archive/2009/07/23/changing-console-fonts.aspx

//-------------------------------joonistamine-----------------------------//
int joonistamine() {

	move(0, 0);

	for (y = py - jsuurus; y < (py + jsuurus); y++) {

		for (x = px - jsuurus; x < (px + jsuurus); x++) {

			if (x == px && y == py) {
				koordinaadid[z][y][x] = 3;
			}
			switch (koordinaadid[z][y][x]) {
			case 0:
				addch(ACS_BLOCK | COLOR_PAIR(6)); // sümbolid laiendatud ascii tabelist pdcursesiga nimetused ACS_*
				break;
			case 1:
				addch(ACS_BLOCK | COLOR_PAIR(1)); // Värve võetakse paaridena mis on defineeritud peafunktsioonis.
				break;
			case 2:
				addch(ACS_CKBOARD | COLOR_PAIR(2));
				break;
			case 3:
				addch('\1' | COLOR_PAIR(4) | A_ALTCHARSET); // altcharset vajalik naerunäeo näitamiseks
				//refresh();
				break;
			case 4:
				addch(ACS_BOARD | COLOR_PAIR(5));
				break;
			case 5:
				addch('v' | COLOR_PAIR(4));
				break;
			case 6:
				addch('^' | COLOR_PAIR(4));
				break;
			case 7:
				addch(ACS_CKBOARD | COLOR_PAIR(7));
				break;
			default:
				printw("%d", koordinaadid[z][y][x]);
				break;
			};
		};
		addch('\n');
	};

	//printw("Kulda 50");
	//printw("   Elusid 50\n");
	//printw("Kõike 50");

	endwin(); //vajalik et ei tekiks jooni värvide vahetusel, vabastab pdcurses-ile antud mälu

	return 0;
}
//------------------------------------------------------------------------//

//-------------------------------peafunktsioon----------------------------//
int main() {

	maailm();
	initscr();
	//initscr();

//http://pdcurses.sourceforge.net/doc/PDCurses.txt

	resize_term(jsuurus * 3, jsuurus * 3); //konsooli suuruse muutmine

	//PDCurses vervindus
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_WHITE);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_WHITE);
	init_pair(5, COLOR_GREEN, COLOR_YELLOW);
	init_pair(6, COLOR_BLACK, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);

	z = 50;
	joonistamine();

	int Q = 1;
	int rs1 = 0; // salvestab ruudu kus mängja seisab, et see hiljem taastada
	int rs2 = 0; // salvestab teise ruudu kus mängija seisis
	int s1 = 1; // samm 1
	int s2 = 0; // samm 2

	while (Q == 1) {
//----------Klahvivajutuste-järgi-mängija-koordinaatide-muutmine----------//

		char klahv = getch();

		if (klahv == 'd' && (koordinaadid[z][py][px + 1] != 1)) {

			if (s1 == 1) {
				s2 = 0;
				rs1 = koordinaadid[z][py][px + 1];
				px++;
				koordinaadid[z][py][px - 1] = rs2;
				s1 = 0;
			}
			if (s2 == 1) {
				rs2 = koordinaadid[z][py][px + 1];
				px++;
				koordinaadid[z][py][px - 1] = rs1;
				s2 = 0;
				s1 = 1;
			}

		} else if (klahv == 'a' && (koordinaadid[z][py][px - 1] != 1)) {
			//rsalvestatud = koordinaadid[z][py][px + 1];
			if (s1 == 1) {
				s2 = 0;
				rs1 = koordinaadid[z][py][px - 1];
				px--;
				koordinaadid[z][py][px + 1] = rs2;
				s1 = 0;
			}
			if (s2 == 1) {
				rs2 = koordinaadid[z][py][px - 1];
				px--;
				koordinaadid[z][py][px + 1] = rs1;
				s2 = 0;
				s1 = 1;
			}
			//koordinaadid[z][py][px + 3] = rsalvestatud;*/
		}
		if (klahv == 'w' && (koordinaadid[z][py - 1][px] != 1)) {
			if (s1 == 1) {
				s2 = 0;
				rs1 = koordinaadid[z][py - 1][px];
				py--;
				koordinaadid[z][py + 1][px] = rs2;
				s1 = 0;
			}
			if (s2 == 1) {
				rs2 = koordinaadid[z][py - 1][px];
				py--;
				koordinaadid[z][py + 1][px] = rs1;
				s2 = 0;
				s1 = 1;
			}

		}
		if (klahv == 's' && (koordinaadid[z][py + 1][px] != 1)) {

			if (s1 == 1) {
				s2 = 0;
				rs1 = koordinaadid[z][py + 1][px];
				py++;
				koordinaadid[z][py - 1][px] = rs2;
				s1 = 0;
			}
			if (s2 == 1) {
				rs2 = koordinaadid[z][py + 1][px];
				py++;
				koordinaadid[z][py - 1][px] = rs1;
				s2 = 0;
				s1 = 1;
			}

		}
		if (klahv == 'q') {
			Q = 0;
		}
		s2 = 1;

		switch (koordinaadid[z][py][px]) {
		case 5:
			z--;
			rs1 = 2;
			rs2 = 2;
			break;
		case 6:
			z++;
			rs1 = 2;
			rs2 = 2;

			break;
		}


	joonistamine();

};
return 0;
//------------------------------------------------------------------------//
}
//------------------------------------------------------------------------//

