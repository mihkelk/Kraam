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
char tehe; //Tehtem�rk
int teine; //Teine arv

printf("Sisestage esimene arv\n");
scanf( "%d", &esimene); //Esimese arvu sisselugemine

getchar();

printf("Sisestage tehtem�rk\n"); //� asemel kirjutab �
scanf("%c", &tehe); //Loeb sisse tehtem�rgi, ei oota enterit, liigub edasi esimese klahvivajutusega.

printf("Sisestage teine arv\n");
scanf( "%d", &teine);

printf("Sisestasite %d %c %d =" , esimene, tehe, teine ); //Sisestatud tehte v�ljakirjutamine

if(tehe =='+') //Tehtem�rgi �mber pole " vaid on '
{printf(" %d", esimene+teine);} //Vastuse v�ljakirjutamine vastavalt muutuja "tehe" v��rtusele
else if(tehe =='-') //Kontrollib vaid siis kui muutuja "tehe" v��rtus polnud +
{printf(" %d", esimene-teine);}
else if(tehe =='*')
{printf(" %d", esimene*teine);}
else if(tehe =='/'||':') //tehtem�rgina kasutatav nii / kui :
{printf(" %d", esimene/teine);};

getch(); //Pole sama mis "getchar", on minul siiani lahti hoidnud k�iki programme mida "getchar" pole suutnud.
return 0;
}
