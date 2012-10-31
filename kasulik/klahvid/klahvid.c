/*
 * klahvid.c
 *
 *  Created on: 10.10.2012
 *      Author: mihkelk
 */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(void) {
	int klahv = kbhit();
	printf("%d", klahv);
	printf("\219");
	getchar();
	return 0;
}
