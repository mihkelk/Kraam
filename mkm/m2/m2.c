/*
 * m2.c
 *
 *  Created on: 02.10.2012
 *      Author: mihkelk
 */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


int main(){
int x;
int y;
int koordinaadid[64][64];
int px = 2;
int py = 2;

int suurus = 20;

while("TRUE"){

for(y=0; y<(suurus+1); y++)
{
for(x=0; x<(suurus+1); x++)
{
	if(x==px&y==py)
	{
		  koordinaadid[y][x] = 3;
		  printf("%d", koordinaadid[y][x]);
	}
else if((y==suurus||y==0)||(x==suurus||x==0)){
	koordinaadid[y][x] = 1;
	printf("%d", koordinaadid[y][x]);
	}else{
	koordinaadid[y][x] = 0;
	printf("%d", koordinaadid[y][x]);
	};

};

printf("\n");


};

  char klahv = getch();
  printf("%c", klahv);
  if(klahv=='d'){
	  px++;
  }
  else if(klahv=='a'){
	  px--;
  }
  if(klahv=='w'){
	  py--;
  }
  if(klahv=='s'){
	  py++;
  }
  system ("cls");
}
}
