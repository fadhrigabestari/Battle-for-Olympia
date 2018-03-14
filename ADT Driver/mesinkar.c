/* File: mesinkar.c */
/* Implementasi Mesin Karakter */

#include "mesinkar.h"
#include <stdio.h>

char CC;
boolean EOP;

static FILE * pita;
static int retval;

/* File: mesinkar.c */
/* Implementasi Mesin Karakter */

#include "mesinkar.h"
#include <stdio.h>

char CC;
boolean EOP;

static FILE * pita;
static int retval;

void STARTKING() {
/* Membuka file 'KINGSTAT.txt' dan membaca kata pertama dalam file tersebut */

  /* Algoritma */
  pita = fopen("KINGSTAT.txt","r");
  ADV();
}

void STARTSWORDSMAN() {
/* Membuka file 'SWORDSMANSTAT.txt' dan membaca kata pertama dalam file tersebut */

  /* Algoritma */
  pita = fopen("SWORDSMANSTAT.txt","r");
  ADV();
}

void STARTARCHER() {
/* Membuka file 'ARCHERSTAT.txt' dan membaca kata pertama dalam file tersebut */

  /* Algoritma */
  pita = fopen("ARCHERSTAT.txt","r");
  ADV();
}

void STARTWHITEMAGE() {
/* Membuka file 'WHITEMAGESTAT.txt' dan membaca kata pertama dalam file tersebut */

  /* Algoritma */
  pita = fopen("WHITEMAGESTAT.txt","r");
  ADV();
}

void STARTCLI() {
/* Melakukan pembacaan kata dalam string inputan pengguna */
  ADVCLI();
}

void ADV() {
/* Membaca kata pertama yang ada dalam file eksternal */

  /* Algoritma */
  retval = fscanf(pita,"%c",&CC);
  EOP = (CC == MARK);
  if (EOP) {
       fclose(pita);
  }
}

void ADVCLI() {
/* Membaca kata pertama yang ada dalam string inputan pengguna */

  /* Algoritma */
  scanf("%c", &CC);
  EOP = (CC == MARK);
}
