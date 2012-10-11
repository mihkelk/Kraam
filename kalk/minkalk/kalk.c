/*
 * kalk.c
 *
 *  Created on: 26.09.2012
 *      Author: mihkelk
 */
#include <stdio.h>
#include <conio.h> //getch jaoks

int main(void)
{

int esimene; //Esimene arv
char tehe; //Tehtemärk
int teine; //Teine arv

printf("Sisestage esimene arv\n");
scanf( "%d", &esimene); //Esimese arvu sisselugemine

getchar();

printf("Sisestage tehtemärk\n"); //ä asemel kirjutab õ
scanf("%c", &tehe); //Loeb sisse tehtemärgi, ei oota enterit, liigub edasi esimese klahvivajutusega.

printf("Sisestage teine arv\n");
scanf( "%d", &teine);

printf("Sisestasite %d %c %d =" , esimene, tehe, teine ); //Sisestatud tehte väljakirjutamine

if(tehe =='+') //Tehtemärgi ümber pole " vaid on '
{printf(" %d", esimene+teine);} //Vastuse väljakirjutamine vastavalt muutuja "tehe" väärtusele
else if(tehe =='-') //Kontrollib vaid siis kui muutuja "tehe" väärtus polnud +
{printf(" %d", esimene-teine);}
else if(tehe =='*')
{printf(" %d", esimene*teine);}
else if(tehe =='/'||':') //tehtemärgina kasutatav nii / kui :
{printf(" %d", esimene/teine);};

getch(); //Pole sama mis "getchar", on minul siiani lahti hoidnud kõiki programme mida "getchar" pole suutnud.
return 0;
}
