/* File: mesinkar.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "boolean.h"

#define MARK '.'
/* State Mesin */
extern char CC;
extern boolean EOP;

void STARTKING();
/* Membuka file 'KINGSTAT.txt' dan membaca kata pertama dalam file tersebut */
void STARTSWORDSMAN();
/* Membuka file 'SWORDSMANSTAT.txt' dan membaca kata pertama dalam file tersebut */
void STARTARCHER();
/* Membuka file 'ARCHERSTAT.txt' dan membaca kata pertama dalam file tersebut */
void STARTWHITEMAGE();
/* Membuka file 'WHITEMAGESTAT.txt' dan membaca kata pertama dalam file tersebut */
void STARTCLI();
/* Melakukan pembacaan kata dalam string inputan pengguna */
void ADV();
/* Membaca kata pertama yang ada dalam file eksternal */
void ADVCLI();
/* Membaca kata pertama yang ada dalam string inputan pengguna */

#endif
