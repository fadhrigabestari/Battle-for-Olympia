/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "boolean.h"
#include "mesinkar.h"

#define NMax 100
#define BLANK ' '

typedef struct {
	char TabKata[NMax+1]; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
    int Length;
} Kata;

/* State Mesin Kata */
extern boolean EndKata;
extern Kata CKata;


void IgnoreBlank();
/* 	Mengabaikan satu atau beberapa BLANK(SPASI)
   	I.S. : CC sembarang
   	F.S. : CC ≠ BLANK atau CC = MARK */
void STARTKATAKING();
/* 	Mengambil kata pertama dari file "KINGSTAT.txt" */
void STARTKATASWORDSMAN();
/* 	Mengambil kata pertama dari file "SWORDSMANSTAT.txt" */
void STARTKATAARCHER();
/* 	Mengambil kata pertama dari file "ARCHERSTAT.txt" */
void STARTKATAWHITEMAGE();
/* 	Mengambil kata pertama dari file "WHITEMAGESTAT.txt" */
void STARTKATA();
/* 	Mengambil kata pertama dari string inputan pengguna */
void ADVKATA();
/* 	Mengambil kata selanjutnya dari string inputan pengguna */
void ADVKATAFILE();
/* 	Mengambil kata selanjutnya dari file eksternal */
void SalinKataFILE();
/*  Menyimpan kata yang telah dibaca dalam file eksternal
    ke dalam array of string bernama CKata */
void SalinKata();
/*  Menyimpan kata yang telah dibaca dari string inputan 
    pengguna ke dalam array of string bernama CKata */
void CreateKataEmpty();
/*  Menghapus kata yang ada dalam CKata, sehingga
    membentuk array dengan length 0 */
boolean IsKataSama (Kata K1, Kata K2);
/*  Memeriksa apakah kedua kata merupakan kata yang
    sama dengan awalnya memeriksa Length dari array.
    Jika Length kedua array sama, maka akan diperiksa
    char satu-persatu dari kedua kata.
    Jika kedua kata sama akan menghasilkan True, dan
    jika berbeda maka menghasilkan False */

#endif
