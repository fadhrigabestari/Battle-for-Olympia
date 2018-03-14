#include "listUNIT.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyUNIT (ListUNIT L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
    return (FirstUNIT(L) == Nil);
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyUNIT (ListUNIT *L)
/* I.S. L sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
    FirstUNIT(*L) = Nil;
}

int NbUNIT (ListUNIT L)
/* Mencari jumlah village dalam list */
{
  int n = 0;
  addressUNIT P;

  if(IsEmptyUNIT(L)) {
    return n;
  } else {
    P = FirstUNIT(L);
    n++;
    while(NextUNIT(P) != FirstUNIT(L)) {
      n++;
      P = NextUNIT(P);
    }
    return n;
  }
}
/****************** Manajemen Memori ******************/
addressUNIT AlokasiUNIT (infotypeUNIT X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    addressUNIT P;

    P = (addressUNIT) malloc (sizeof (ElmtListUNIT));

    if (P != Nil) {
        InfoUNIT(P) = X;
        NextUNIT(P) = Nil;
    }
    return P;
}
void DealokasiUNIT (addressUNIT P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(P);
}
/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressUNIT SearchUNIT (ListUNIT L, infotypeUNIT X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    addressUNIT P;

    if (IsEmptyUNIT(L)){
        return (Nil);
    }else {
        P = FirstUNIT(L);
        while (NextUNIT(P) != FirstUNIT(L) && NEQPOINT(UnitLocation(InfoUNIT(P)),UnitLocation(X))) {
                P = NextUNIT(P);
        }
    }
    if (EQPOINT(UnitLocation(InfoUNIT(P)),UnitLocation(X))) {
        return P;
    }else
        return Nil;
}
/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstUNIT (ListUNIT *L, infotypeUNIT X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    addressUNIT P;

    P = AlokasiUNIT(X);
    if (P!=Nil){
        InsertFirstUNIT(L, P);
    }
}
void InsVLastUNIT (ListUNIT *L, infotypeUNIT X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    addressUNIT P;

    P = AlokasiUNIT(X);
    if (P!= Nil) {
        InsertLastUNIT(L, P);
    }
}
/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstUNIT (ListUNIT *L, infotypeUNIT * X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    addressUNIT P;

    DelFirstUNIT(L,&P);
    *X = InfoUNIT(P);
    DealokasiUNIT(P);
}
void DelVLastUNIT (ListUNIT *L, infotypeUNIT * X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    addressUNIT last;

    DelLastUNIT(L, &last);
    *X = InfoUNIT(last);
    DealokasiUNIT(last);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstUNIT (ListUNIT *L, addressUNIT P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    addressUNIT last;

    if (IsEmptyUNIT(*L)) {
        FirstUNIT(*L) = P;
        NextUNIT(P) = P;
    } else  { /* L tidak kosong */
        last = FirstUNIT(*L);
        while (NextUNIT(last) != FirstUNIT(*L)) {
            last = NextUNIT(last);
        }
        NextUNIT(P) = FirstUNIT(*L);
        NextUNIT(last) = P;
        FirstUNIT(*L) = P;
    }
}
void InsertLastUNIT (ListUNIT *L, addressUNIT P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    addressUNIT Q;

    if (IsEmptyUNIT(*L)){
        InsertFirstUNIT(L,P);
    }else {
         if (P != Nil) {
            Q = FirstUNIT(*L);
            while (NextUNIT(Q) != FirstUNIT(*L)) {
                Q = NextUNIT(Q);
            }
            NextUNIT(Q) = P;
            NextUNIT(P) = FirstUNIT(*L);
        }
    }
}
void InsertAfterUNIT (ListUNIT *L, addressUNIT P, addressUNIT Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    NextUNIT(P) = NextUNIT(Prec);
    NextUNIT(Prec) = P;
}
/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstUNIT (ListUNIT *L, addressUNIT *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    addressUNIT last;
     /* Algoritma */
    *P = FirstUNIT(*L);
    if (NextUNIT(*P) == FirstUNIT(*L)) { /* satu elemen */
        FirstUNIT(*L) = Nil;
    } else {
        last = FirstUNIT(*L);
        while (NextUNIT(last) != FirstUNIT(*L)) {
            last = NextUNIT(last);
        } /* Next(last) = First(L) */

        FirstUNIT(*L) = NextUNIT(FirstUNIT(*L));
        NextUNIT(last) = FirstUNIT(*L);
    }
     NextUNIT(*P) = Nil;

}
void DelLastUNIT (ListUNIT *L, addressUNIT *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
{
     addressUNIT PrecLast;

     *P = FirstUNIT(*L);
     PrecLast = Nil;
     while (NextUNIT(*P) != FirstUNIT(*L)) {
        PrecLast = *P;
        *P = NextUNIT(*P);
     }

     if (*P == FirstUNIT(*L)) {
        FirstUNIT(*L) = Nil;
     } else {
        NextUNIT(PrecLast) = FirstUNIT(*L);
     }
}

void DelAfterUNIT (ListUNIT *L, addressUNIT *Pdel, addressUNIT Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    addressUNIT last;

    *Pdel = NextUNIT(Prec);
    last = FirstUNIT(*L);
    while(NextUNIT(last) != FirstUNIT(*L)){
        last = NextUNIT(last);
    }

    if (NextUNIT(Prec) != last ) {
        NextUNIT(Prec) = NextUNIT(*Pdel);
        NextUNIT(*Pdel) = Nil;
    }else if(NextUNIT(Prec) == FirstUNIT(*L)){ /*Prec == last*/
        DelFirstUNIT(L,Pdel);
    }else if (NextUNIT(Prec) == last) {
        DelLastUNIT(L, Pdel);
    }

}
void DelPUNIT (ListUNIT *L, infotypeUNIT X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    addressUNIT P, Prec;

    P = FirstUNIT(*L);
    Prec = Nil;

    if (EQPOINT(UnitLocation(InfoUNIT(P)),UnitLocation(X))) {
        DelFirstUNIT(L,&P);
        DealokasiUNIT(P);
    }else {
        while (NextUNIT(P) != FirstUNIT(*L) && NEQPOINT(UnitLocation(InfoUNIT(P)),UnitLocation(X))) {
            Prec = P;
            P = NextUNIT(P);
        }

        if (EQPOINT(UnitLocation(InfoUNIT(P)),UnitLocation(X)) && NextUNIT(P)!=FirstUNIT(*L)){
            NextUNIT(Prec) = NextUNIT(P);
            P = Nil;
            DealokasiUNIT(P);
        }else if (EQPOINT(UnitLocation(InfoUNIT(P)),UnitLocation(X)) && NextUNIT(P) == FirstUNIT(*L)){ /*P = last*/
            DelLastUNIT(L,&P);
            DealokasiUNIT(P);
        }
     }
}
