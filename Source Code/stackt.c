/* File : stackt.c */

#include "stackt.h"
#include "boolean.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptySTACK (StackMOVE *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */
{
    Top(*S) = Nil0;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptySTACK (StackMOVE S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return (Top(S) == Nil0);
}
boolean IsFullSTACK (StackMOVE S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
    return (Top(S) == MaxElSTACK);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (StackMOVE * S, POINT C)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    if (IsEmptySTACK(*S)){
        Top(*S) = 1;
        Idx(InfoTop(*S)) = Idx(C);
        Clmn(InfoTop(*S)) = Clmn(C);
    }else {
        Top(*S) = Top(*S) + 1;
        Idx(InfoTop(*S)) = Idx(C);
        Clmn(InfoTop(*S)) = Clmn(C);
    }
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (StackMOVE * S, POINT* C)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    Idx(*C) = Idx(InfoTop(*S));
    Clmn(*C) = Clmn(InfoTop(*S));
    Top(*S) = Top(*S) - 1;
}
