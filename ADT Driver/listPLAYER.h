/* File : listsirkuler.h */
/* ADT List Sirkuler dengan elemen terakhir menunjuk pada elemen pertama */
/* Representasi berkait dengan address adalah pointer */
/* infotype adalah integer */

#ifndef listPLAYER_H
#define listPLAYER_H

#include "boolean.h"
#include "listUNIT.h"
#include "listVILLAGE.h"

#define Nil NULL

typedef struct{
  int Gold; //AMOUNT OF GOLD A PLAYER HAS
  int Income; //INCOME EACH TURN
  int Upkeep; //UPKEEP EACH TURN, 1 FOR EVERY PLAYER IT HAS
  ListUNIT Units; //LIST OF PLAYERS A PLAYER HAS, CHANGE LISTPLAYER.H
  ListVILLAGE Villages; //LIST OF VILAGES A PLAYER HAS, CHANGE LIST.H -> LISTVILAGES.H
}Player;

typedef Player infotypePLAYER;
typedef struct tElmtlistPLAYER *addressPLAYER;
typedef struct tElmtlistPLAYER {
	infotypePLAYER infoPLAYER;
	addressPLAYER nextPLAYER;
} ElmtListPLAYER;
typedef struct {
	addressPLAYER FirstPLAYER;
} ListPLAYER;

/* Definisi list : */
/* List kosong : FirstPLAYER(L) = Nil */
/* Setiap elemen dengan address P dapat diacu InfoUIT(P), NextPLAYER(P) */
/* Elemen terakhir list: jika addressnya Last, maka NextPLAYER(Last)=FirstPLAYER(L) */

/* Notasi Akses List PLAYER */
#define InfoPLAYER(P) (P)->infoPLAYER //INFOTYPE (PLAYER)
#define NextPLAYER(P) (P)->nextPLAYER //ADDRESS
#define FirstPLAYER(L) ((L).FirstPLAYER) //ADDRESS

/* Notasi Akses Player */
#define Gold(P) (P).Gold
#define Income(P) (P).Income
#define Upkeep(P) (P).Upkeep
#define Units(P) (P).Units //CREATE LIST OF PLAYER FROM UNIT TYPE
#define Villages(P) (P).Villages //CREATE LIST OF VILLAGES  FROM PLAYER TYPE

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyPLAYER (ListPLAYER L);
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyPLAYER (ListPLAYER *L);
/* I.S. L sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
addressPLAYER AlokasiPLAYER (infotypePLAYER X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokasiPLAYER (addressPLAYER P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstPLAYER (ListPLAYER *L, infotypePLAYER X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLastPLAYER (ListPLAYER *L, infotypePLAYER X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstPLAYER (ListPLAYER *L, infotypePLAYER * X);
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLastPLAYER (ListPLAYER *L, infotypePLAYER * X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstPLAYER (ListPLAYER *L, addressPLAYER P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertLastPLAYER (ListPLAYER *L, addressPLAYER P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfterPLAYER (ListPLAYER *L, addressPLAYER P, addressPLAYER Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstPLAYER (ListPLAYER *L, addressPLAYER *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLastPLAYER (ListPLAYER *L, addressPLAYER *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
void DelAfterPLAYER (ListPLAYER *L, addressPLAYER *Pdel, addressPLAYER Prec);
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

#endif
