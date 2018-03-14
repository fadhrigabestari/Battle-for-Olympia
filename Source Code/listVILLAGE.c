#include "listVILLAGE.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyVILLAGE (ListVILLAGE L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
    return (FirstVILLAGE(L) == Nil);
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyVILLAGE (ListVILLAGE *L)
/* I.S. L sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
    FirstVILLAGE(*L) = Nil;
}
/****************** Manajemen Memori ******************/
addressVILLAGE AlokasiVILLAGE (infotypeVILLAGE X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    addressVILLAGE P;

    P = (addressVILLAGE) malloc (sizeof (ElmtListVILLAGE));

    if (P != Nil) {
        InfoVILLAGE(P) = X;
        NextVILLAGE(P) = Nil;
    }
    return P;
}
void DealokasiVILLAGE (addressVILLAGE P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(P);
}

int NbVILLAGE (ListVILLAGE L)
/* Mencari jumlah village dalam list */
{
  int n = 0;
  addressVILLAGE P;

  if(IsEmptyVILLAGE(L)) {
    return n;
  } else {
    P = FirstVILLAGE(L);
    n++;
    while(NextVILLAGE(P) != FirstVILLAGE(L)) {
      n++;
      P = NextVILLAGE(P);
    }
    return n;
  }
}
/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressVILLAGE SearchVILLAGE (ListVILLAGE L, infotypeVILLAGE X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    addressVILLAGE P;

    if (IsEmptyVILLAGE(L)){
        return (Nil);
    }else {
        P = FirstVILLAGE(L);
        while (NextVILLAGE(P) != FirstVILLAGE(L) && NEQPOINT(VillageLocation(InfoVILLAGE(P)),VillageLocation(X))) {
                P = NextVILLAGE(P);
        }
    }
    if (EQPOINT(VillageLocation(InfoVILLAGE(P)),VillageLocation(X))) {
        return P;
    }else
        return Nil;
}
/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstVILLAGE (ListVILLAGE *L, infotypeVILLAGE X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    addressVILLAGE P;

    P = AlokasiVILLAGE(X);
    if (P!=Nil){
        InsertFirstVILLAGE(L, P);
    }
}
void InsVLastVILLAGE (ListVILLAGE *L, infotypeVILLAGE X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    addressVILLAGE P;

    P = AlokasiVILLAGE(X);
    if (P!= Nil) {
        InsertLastVILLAGE(L, P);
    }
}
/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstVILLAGE (ListVILLAGE *L, infotypeVILLAGE * X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    addressVILLAGE P;

    DelFirstVILLAGE(L,&P);
    *X = InfoVILLAGE(P);
    DealokasiVILLAGE(P);
}
void DelVLastVILLAGE (ListVILLAGE *L, infotypeVILLAGE * X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    addressVILLAGE last;

    DelLastVILLAGE(L, &last);
    *X = InfoVILLAGE(last);
    DealokasiVILLAGE(last);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstVILLAGE (ListVILLAGE *L, addressVILLAGE P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    addressVILLAGE last;

    if (IsEmptyVILLAGE(*L)) {
        FirstVILLAGE(*L) = P;
        NextVILLAGE(P) = P;
    } else  { /* L tidak kosong */
        last = FirstVILLAGE(*L);
        while (NextVILLAGE(last) != FirstVILLAGE(*L)) {
            last = NextVILLAGE(last);
        }
        NextVILLAGE(P) = FirstVILLAGE(*L);
        NextVILLAGE(last) = P;
        FirstVILLAGE(*L) = P;
    }
}
void InsertLastVILLAGE (ListVILLAGE *L, addressVILLAGE P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    addressVILLAGE Q;

    if (IsEmptyVILLAGE(*L)){
        InsertFirstVILLAGE(L,P);
    }else {
         if (P != Nil) {
            Q = FirstVILLAGE(*L);
            while (NextVILLAGE(Q) != FirstVILLAGE(*L)) {
                Q = NextVILLAGE(Q);
            }
            NextVILLAGE(Q) = P;
            NextVILLAGE(P) = FirstVILLAGE(*L);
        }
    }
}
void InsertAfterVILLAGE (ListVILLAGE *L, addressVILLAGE P, addressVILLAGE Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    NextVILLAGE(P) = NextVILLAGE(Prec);
    NextVILLAGE(Prec) = P;
}
/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstVILLAGE (ListVILLAGE *L, addressVILLAGE *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    addressVILLAGE last;
     /* Algoritma */
    *P = FirstVILLAGE(*L);
    if (NextVILLAGE(*P) == FirstVILLAGE(*L)) { /* satu elemen */
        FirstVILLAGE(*L) = Nil;
    } else {
        last = FirstVILLAGE(*L);
        while (NextVILLAGE(last) != FirstVILLAGE(*L)) {
            last = NextVILLAGE(last);
        } /* Next(last) = First(L) */

        FirstVILLAGE(*L) = NextVILLAGE(FirstVILLAGE(*L));
        NextVILLAGE(last) = FirstVILLAGE(*L);
    }
     NextVILLAGE(*P) = Nil;

}
void DelLastVILLAGE (ListVILLAGE *L, addressVILLAGE *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
{
     addressVILLAGE PrecLast;

     *P = FirstVILLAGE(*L);
     PrecLast = Nil;
     while (NextVILLAGE(*P) != FirstVILLAGE(*L)) {
        PrecLast = *P;
        *P = NextVILLAGE(*P);
     }

     if (*P == FirstVILLAGE(*L)) {
        FirstVILLAGE(*L) = Nil;
     } else {
        NextVILLAGE(PrecLast) = FirstVILLAGE(*L);
     }
}

void DelAfterVILLAGE (ListVILLAGE *L, addressVILLAGE *Pdel, addressVILLAGE Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    addressVILLAGE last;

    *Pdel = NextVILLAGE(Prec);
    last = FirstVILLAGE(*L);
    while(NextVILLAGE(last) != FirstVILLAGE(*L)){
        last = NextVILLAGE(last);
    }

    if (NextVILLAGE(Prec) != last ) {
        NextVILLAGE(Prec) = NextVILLAGE(*Pdel);
        NextVILLAGE(*Pdel) = Nil;
    }else if(NextVILLAGE(Prec) == FirstVILLAGE(*L)){ /*Prec == last*/
        DelFirstVILLAGE(L,Pdel);
    }else if (NextVILLAGE(Prec) == last) {
        DelLastVILLAGE(L, Pdel);
    }

}
void DelPVILLAGE (ListVILLAGE *L, infotypeVILLAGE X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    addressVILLAGE P, Prec;

    P = FirstVILLAGE(*L);
    Prec = Nil;

    if (EQPOINT(VillageLocation(InfoVILLAGE(P)),VillageLocation(X))) {
        DelFirstVILLAGE(L,&P);
        DealokasiVILLAGE(P);
    }else {
        while (NextVILLAGE(P) != FirstVILLAGE(*L) && NEQPOINT(VillageLocation(InfoVILLAGE(P)),VillageLocation(X))) {
            Prec = P;
            P = NextVILLAGE(P);
        }

        if (EQPOINT(VillageLocation(InfoVILLAGE(P)),VillageLocation(X)) && NextVILLAGE(P)!=FirstVILLAGE(*L)){
            NextVILLAGE(Prec) = NextVILLAGE(P);
            P = Nil;
            DealokasiVILLAGE(P);
        }else if (EQPOINT(VillageLocation(InfoVILLAGE(P)),VillageLocation(X)) && NextVILLAGE(P) == FirstVILLAGE(*L)){ /*P = last*/
            DelLastVILLAGE(L,&P);
            DealokasiVILLAGE(P);
        }
     }
}
