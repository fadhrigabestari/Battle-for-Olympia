/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */
#include "boolean.h"
#include "mesinkar.h"
#include "mesinkata.h"

boolean EndKata;
Kata CKata;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK(SPASI)
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while (CC==BLANK && CC!=MARK) {
        ADV();
    }
}

void STARTKATAKING()
/* Mengambil kata pertama dari file "KINGSTAT.txt" */
{
    STARTKING();
    IgnoreBlank();
    if (CC==MARK) {
        EndKata = true;
    } else {
        EndKata = false;
        SalinKataFILE();
    }
}

void STARTKATASWORDSMAN()
/* Mengambil kata pertama dari file "SWORDSMANSTAT.txt" */
{
    STARTSWORDSMAN();
    IgnoreBlank();
    if (CC==MARK) {
        EndKata = true;
    } else {
        EndKata = false;
        SalinKataFILE();
    }
}
void STARTKATAARCHER()
/* Mengambil kata pertama dari file "ARCHERSTAT.txt" */
{
    STARTARCHER();
    IgnoreBlank();
    if (CC==MARK) {
        EndKata = true;
    } else {
        EndKata = false;
        SalinKataFILE();
    }
}
void STARTKATAWHITEMAGE()
/* Mengambil kata pertama dari file "WHITEMAGESTAT.txt" */
{
    STARTWHITEMAGE();
    IgnoreBlank();
    if (CC==MARK) {
        EndKata = true;
    } else {
        EndKata = false;
        SalinKataFILE();
    }
}

void STARTKATA()
/* Mengambil kata pertama dari string inputan pengguna */
{
    STARTCLI();
    IgnoreBlank();
    if (CC==MARK) {
        EndKata = true;
    } else {
        EndKata = false;
        SalinKata();
    }
}

void ADVKATA()
/* Mengambil kata selanjutnya dari string inputan pengguna */
{
    IgnoreBlank();
    if (CC==MARK) {
        EndKata = true;
    } else {
        SalinKata();
    }
}

void ADVKATAFILE()
/* Mengambil kata selanjutnya dari file eksternal */
{
    IgnoreBlank();
    if (CC==MARK) {
        EndKata = true;
    } else {
        SalinKataFILE();
    }
}

void SalinKataFILE()
/*  Menyimpan kata yang telah dibaca dalam file eksternal
    ke dalam array of string bernama CKata */
{
    int i;
    boolean iskarakter;

    i = 1;
    iskarakter = true;
    while (iskarakter)  {
        CKata.TabKata[i] = CC;
        ADV();
        if (CC==MARK || CC==BLANK || i==NMax) {
            iskarakter = false;
        } else {
            i++;
        }
    }
    CKata.Length = i;
    IgnoreBlank();
}

void SalinKata()
/*  Menyimpan kata yang telah dibaca dari string inputan
    pengguna ke dalam array of string bernama CKata */
{
    int i;
    boolean iskarakter;

    i = 1;
    iskarakter = true;
    while (iskarakter)  {
        CKata.TabKata[i] = CC;
        ADVCLI();
        if (CC==MARK || CC==BLANK || i==NMax) {
            iskarakter = false;
        } else {
            i++;
        }
    }
    CKata.Length = i;
    IgnoreBlank();
}

void CreateKataEmpty()
/*  Menghapus kata yang ada dalam CKata, sehingga
    membentuk array dengan length 0 */
{
  CKata.Length = 0;
}

boolean IsKataSama (Kata K1, Kata K2){
/*  Memeriksa apakah kedua kata merupakan kata yang
    sama dengan awalnya memeriksa Length dari array.
    Jika Length kedua array sama, maka akan diperiksa
    char satu-persatu dari kedua kata.
    Jika kedua kata sama akan menghasilkan True, dan
    jika berbeda maka menghasilkan False */
  boolean issama;
  int i;

  issama = true;
  if (K1.Length==K2.Length) {
    if (K1.Length == 0) {
      issama = true;
    } else {
      for (i=1; i<=K1.Length; i++) {
        if (K1.TabKata[i] != K2.TabKata[i]) {
          issama = false;
        }
      }
    }
  } else {
    issama = false;
  }
  return issama;
}
