/* File : listsirkuler.h */
/* ADT List Sirkuler dengan elemen terakhir menunjuk pada elemen pertama */
/* Representasi berkait dengan address adalah pointer */
/* infotype adalah integer */

#ifndef listVILLAGE_H
#define listVILLAGE_H

#include "boolean.h"
#include "point.h"

#define Nil NULL

typedef struct{
  POINT VillageLocation;
}Village;

typedef Village infotypeVILLAGE;
typedef struct tElmtlistVILLAGE *addressVILLAGE;
typedef struct tElmtlistVILLAGE {
	infotypeVILLAGE infoVILLAGE;
	addressVILLAGE nextVILLAGE;
} ElmtListVILLAGE;
typedef struct {
	addressVILLAGE FirstVILLAGE;
} ListVILLAGE;



/* Definisi list : */
/* List kosong : FirstVILLAGE(L) = Nil */
/* Setiap elemen dengan address P dapat diacu InfoVILLAGE(P), NextVILLAGE(P) */
/* Elemen terakhir list: jika addressnya Last, maka NextVILLAGE(Last)=FirstVILLAGE(L) */

/* Notasi Akses List VILLAGE */
#define InfoVILLAGE(P) (P)->infoVILLAGE
#define NextVILLAGE(P) (P)->nextVILLAGE
#define FirstVILLAGE(L) ((L).FirstVILLAGE)
/* Notasi Akses VILLAGE */
#define VillageLocation(V) (V).VillageLocation


/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyVILLAGE (ListVILLAGE L);
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyVILLAGE (ListVILLAGE *L);
/* I.S. L sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

int NbVILLAGE (ListVILLAGE L);

/****************** Manajemen Memori ******************/
addressVILLAGE AlokasiVILLAGE (infotypeVILLAGE X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokasiVILLAGE (addressVILLAGE P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

int NbVILLAGE (ListVILLAGE L);

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressVILLAGE SearchVILLAGE (ListVILLAGE L, infotypeVILLAGE X);
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstVILLAGE (ListVILLAGE *L, infotypeVILLAGE X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLastVILLAGE (ListVILLAGE *L, infotypeVILLAGE X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstVILLAGE (ListVILLAGE *L, infotypeVILLAGE * X);
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLastVILLAGE (ListVILLAGE *L, infotypeVILLAGE * X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstVILLAGE (ListVILLAGE *L, addressVILLAGE P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertLastVILLAGE (ListVILLAGE *L, addressVILLAGE P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfterVILLAGE (ListVILLAGE *L, addressVILLAGE P, addressVILLAGE Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstVILLAGE (ListVILLAGE *L, addressVILLAGE *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLastVILLAGE (ListVILLAGE *L, addressVILLAGE *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
void DelAfterVILLAGE (ListVILLAGE *L, addressVILLAGE *Pdel, addressVILLAGE Prec);
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelPVILLAGE (ListVILLAGE *L, infotypeVILLAGE X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */

#endif
