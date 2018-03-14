#include "listPLAYER.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyPLAYER (ListPLAYER L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
    return (FirstPLAYER(L) == Nil);
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyPLAYER (ListPLAYER *L)
/* I.S. L sembarang */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
    FirstPLAYER(*L) = Nil;
}
/****************** Manajemen Memori ******************/
addressPLAYER AlokasiPLAYER (infotypePLAYER X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    addressPLAYER P;

    P = (addressPLAYER) malloc (sizeof (ElmtListPLAYER));

    if (P != Nil) {
        InfoPLAYER(P) = X;
        NextPLAYER(P) = Nil;
    }
    return P;
}
void DealokasiPLAYER (addressPLAYER P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(P);
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstPLAYER (ListPLAYER *L, infotypePLAYER X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    addressPLAYER P;

    P = AlokasiPLAYER(X);
    if (P!=Nil){
        InsertFirstPLAYER(L, P);
    }
}
void InsVLastPLAYER (ListPLAYER *L, infotypePLAYER X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    addressPLAYER P;

    P = AlokasiPLAYER(X);
    if (P!= Nil) {
        InsertLastPLAYER(L, P);
    }
}
/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstPLAYER (ListPLAYER *L, infotypePLAYER * X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    addressPLAYER P;

    DelFirstPLAYER(L,&P);
    *X = InfoPLAYER(P);
    DealokasiPLAYER(P);
}
void DelVLastPLAYER (ListPLAYER *L, infotypePLAYER * X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    addressPLAYER last;

    DelLastPLAYER(L, &last);
    *X = InfoPLAYER(last);
    DealokasiPLAYER(last);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstPLAYER (ListPLAYER *L, addressPLAYER P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    addressPLAYER last;

    if (IsEmptyPLAYER(*L)) {
        FirstPLAYER(*L) = P;
        NextPLAYER(P) = P;
    } else  { /* L tidak kosong */
        last = FirstPLAYER(*L);
        while (NextPLAYER(last) != FirstPLAYER(*L)) {
            last = NextPLAYER(last);
        }
        NextPLAYER(P) = FirstPLAYER(*L);
        NextPLAYER(last) = P;
        FirstPLAYER(*L) = P;
    }
}
void InsertLastPLAYER (ListPLAYER *L, addressPLAYER P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    addressPLAYER Q;

    if (IsEmptyPLAYER(*L)){
        InsertFirstPLAYER(L,P);
    }else {
         if (P != Nil) {
            Q = FirstPLAYER(*L);
            while (NextPLAYER(Q) != FirstPLAYER(*L)) {
                Q = NextPLAYER(Q);
            }
            NextPLAYER(Q) = P;
            NextPLAYER(P) = FirstPLAYER(*L);
        }
    }
}
void InsertAfterPLAYER (ListPLAYER *L, addressPLAYER P, addressPLAYER Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    NextPLAYER(P) = NextPLAYER(Prec);
    NextPLAYER(Prec) = P;
}
/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstPLAYER (ListPLAYER *L, addressPLAYER *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    addressPLAYER last;
     /* Algoritma */
    *P = FirstPLAYER(*L);
    if (NextPLAYER(*P) == FirstPLAYER(*L)) { /* satu elemen */
        FirstPLAYER(*L) = Nil;
    } else {
        last = FirstPLAYER(*L);
        while (NextPLAYER(last) != FirstPLAYER(*L)) {
            last = NextPLAYER(last);
        } /* Next(last) = First(L) */

        FirstPLAYER(*L) = NextPLAYER(FirstPLAYER(*L));
        NextPLAYER(last) = FirstPLAYER(*L);
    }
     NextPLAYER(*P) = Nil;

}
void DelLastPLAYER (ListPLAYER *L, addressPLAYER *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
{
     addressPLAYER PrecLast;

     *P = FirstPLAYER(*L);
     PrecLast = Nil;
     while (NextPLAYER(*P) != FirstPLAYER(*L)) {
        PrecLast = *P;
        *P = NextPLAYER(*P);
     }

     if (*P == FirstPLAYER(*L)) {
        FirstPLAYER(*L) = Nil;
     } else {
        NextPLAYER(PrecLast) = FirstPLAYER(*L);
     }
}

void DelAfterPLAYER (ListPLAYER *L, addressPLAYER *Pdel, addressPLAYER Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    addressPLAYER last;

    *Pdel = NextPLAYER(Prec);
    last = FirstPLAYER(*L);
    while(NextPLAYER(last) != FirstPLAYER(*L)){
        last = NextPLAYER(last);
    }

    if (NextPLAYER(Prec) != last ) {
        NextPLAYER(Prec) = NextPLAYER(*Pdel);
        NextPLAYER(*Pdel) = Nil;
    }else if(NextPLAYER(Prec) == FirstPLAYER(*L)){ /*Prec == last*/
        DelFirstPLAYER(L,Pdel);
    }else if (NextPLAYER(Prec) == last) {
        DelLastPLAYER(L, Pdel);
    }

}
