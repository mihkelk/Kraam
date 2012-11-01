/*
 * fail.c
 *
 *  Created on: 23.10.2012
 *      Author: mihkelk
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void) {
	int x;
	int y;
	int r = 1;
	int koordinaadid[80][80][80];
char fnimi = '5';
	FILE *fp = fopen("/fnimi", "r");
	char asukoht = '0';
	//üldise toa loomine

	for (y = 0; (asukoht != '-'); y++) {
		for (x = -3; asukoht !='\n'; x++) {
			asukoht = fgetc(fp);
		//	printf("%c", asukoht);
			if (asukoht == '0') {
				koordinaadid[r][y][x] = 0;
			} else if (asukoht == '1') {
				koordinaadid[r][y][x] = 1;
			} else if (asukoht == '2') {
				koordinaadid[r][y][x] = 2;
			//} else {
				//koordinaadid[r][y][x] = 0;

			};
			printf("%d", koordinaadid[r][y][x]);
		};
		printf("\n");
		asukoht = fgetc(fp);
	};
	getch();
	return 0;
}

/*int main(void){
 char rida[128];
 FILE *sisse=fopen("tervitus.txt", "r");
 while(!feof(sisse)){
 //   fscanf(sisse,  "%s", rida);  //võtab ühe sõna
 fgets(rida, 128, sisse);
 printf("%s", rida);
 }
 fclose(sisse);
 getch();
 return 1;

 }*/
