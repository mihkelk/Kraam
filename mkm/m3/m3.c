/*
 * m3.c
 *
 *  Created on: 10.10.2012
 *      Author: mihkelk
 */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main() {
	int x;
	int y;
	int koordinaadid[64][64];
	int px = 2;
	int py = 2;

	int suurus = 40;

	for (y = 0; y < (suurus + 1); y++) {
		for (x = 0; x < (suurus + 1); x++) {

			if ((y == suurus || y == 0) || (x == suurus || x == 0)) {
				koordinaadid[y][x] = 1;
			} else {
				koordinaadid[y][x] = 0;
			};
		};
	};

	while ("TRUE") {

		char klahv = getch();
		printf("%c", klahv);
		if (klahv == 'd' && (koordinaadid[py][px + 1] != 1)) {
			px++;
		} else if (klahv == 'a' && (koordinaadid[py][px - 1] != 1)) {
			px--;
		}
		if (klahv == 'w' && (koordinaadid[py][py - 1] != 1)) {
			py--;
		}
		if (klahv == 's' && (koordinaadid[py][py + 1] != 1)) {
			py++;
		}
		system("cls");

		for (y = 0; y < (suurus + 1); y++) {
			for (x = 0; x < (suurus + 1); x++) {
				if (x == px && y == py) {
					koordinaadid[y][x] = 3;
				}
				printf("%d", koordinaadid[y][x]);
			};
			printf("\n");
		};
	};
	return 0;
}
