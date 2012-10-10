/*
 * klahvid.c
 *
 *  Created on: 10.10.2012
 *      Author: mihkelk
 */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>



int main(){
int klahv = kbhit();
  printf("%d", klahv);
  getchar();
}
