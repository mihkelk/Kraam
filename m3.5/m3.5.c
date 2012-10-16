/*
 * m4.c
 *
 *  Created on: 16.10.2012
 *      Author: mihkelk
 */

/*
 * m3.c
 *
 *  Created on: 10.10.2012
 *      Author: mihkelk
 */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int toad( x, y, r) {
	// int x;
	//int y;
	int suurus = 20;
int kn(main(koordinaadid));
	//int r = main(r);

	//üldise toa loomine

	for (y = 0; y < (suurus + 1); y++) {
		for (x = 0; x < (suurus + 1); x++) {

			if ((y == suurus || y == 0) || (x == suurus || x == 0)) {
				koordinaadid[r][y][x] = 1;
			} else {
				koordinaadid[r][y][x] = 0;
			};
		};
	};

	//vastava toa loomine
	//if r = 10 then
	koordinaadid[10][20[10] = 4;
	koordinaadid[20][4[6] = 1;

	return 0;

}

int main() {
int x;
int y;
int koordinaadid[64][64][64];

int px = 2;
int py = 2;
int r = 10;

while ("TRUE") {

	if (koordinaadid[py][px] == 4) {
			r = 20;

	};



//----------Klahvivajutuste-järgi-mängija-koordinaatide-muutmine----------//
	char klahv = getch();

	if (klahv == 'd' && (koordinaadid[py][px + 1] != 1)) {
		px++;
		koordinaadid[py][px - 1] = 0;
	} else if (klahv == 'a' && (koordinaadid[py][px - 1] != 1)) {
		px--;
		koordinaadid[py][px + 1] = 0;
	}
	if (klahv == 'w' && (koordinaadid[py][py - 1] != 1)) {
		py--;
		koordinaadid[py + 1][px] = 0;
	}
	if (klahv == 's' && (koordinaadid[py][py + 1] != 1)) {
		py++;
		koordinaadid[py - 1][px] = 0;
	}
//------------------------------------------------------------------------//

//-------------------------------joonistamine-----------------------------//
	system("cls");

	for (y = 0; y < (suurus + 1); y++) {
		for (x = 0; x < (suurus + 1); x++) {
			if (x == px && y == py) {
				koordinaadid[r][y][x] = 3;
			}
			if (koordinaadid[r][y][x] == 0) {
				printf(" ");
			} else if (koordinaadid[r][y][x] == 3) {
				printf("\1");
			} else if (koordinaadid[r][y][x] == 1) {
				printf("\333"); //ASCII koodid seitsmendüsteemis
			} else {
				(printf("%d", koordinaadid[r][y][x]));
			};

		};
		printf("\n");
	};
//------------------------------------------------------------------------//
};
}
