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

char fnimi[10];

int main(void) {

	//char fnimi;
//-------int chariks funktsioon-----//
	/*	int c[]={1,4,6};
	 char i;
	 i = (c[0]) + 48;
	 //  i = i + 48;
	 printf("%c",i);
	 ////////////////////////////////*/
	//char fnimi[] = "5";
	char heh;
	int nfnimi;
	nfnimi = 5;

	for (nfnimi= 5; nfnimi<7; nfnimi++){
	fnimi[0] = nfnimi + 48; // + ".txt";

	//printf("%c", fnimi);

	FILE *fp = fopen(fnimi, "r");
	heh = fgetc(fp);
	printf("%c", heh);
	}
/*	nfnimi++;

	 fnimi = nfnimi + 48;

		 fp = fopen(fnimi, "r");
		heh = fgetc(fp);
		printf("%c", heh);

*/

	/*	char c[]={'3',':','3'};
	 int i;
	 i = (c[0]);
	 i = i - 48;
	 printf("%d",i);
	 */

	/*int x;
	 int y;
	 int r = 1;
	 int koordinaadid[80][80][80];
	 char heh;
	 char fnimi[] = "5";
	 FILE *fp = fopen(fnimi, "r");
	 heh =  fgetc(fp);
	 printf("%c%", heh);
	 numToChar()
	 FILE *fp = fopen(fnimi, "r");
	 heh =  fgetc(fp);
	 printf("%c%", heh);
	 */
	//heh = );
	//printf(heh);
	/*char asukoht = '0';
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
	 };*/
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

/* katkine
 // itoa = integer to ascii
 int e = 42;
 char b[33];
 char heh[33];
 printf("%c", itoa(e,b,10));
 //printf(heh);
 */
