/* File : listUNIT.h */
/* ADT List Unit Sirkuler dengan elemen terakhir menunjuk pada elemen pertama */
/* Representasi berkait dengan address adalah pointer */
/* infotype adalah Unit */

#ifndef listUNIT_H
#define listUNIT_H

#include "boolean.h"
#include "point.h"

#define Nil NULL

typedef struct{
  int MaxHealth; //FILE E.
  int Health; //FOLLOW MAX HEALTH
  int Attack; //FILE E.
  int MaxMovePoint; //FILE E.
  int MovePoint; //FOLLOW MAX HEALTH
  char AttackType; //FILE E. (M,R)
  boolean AtkOpp; //TRUE IF ABLE TO ATTACK
  POINT UnitLocation; //DEPENDS ON COORDINATE, CHANGE POINT.H -> POINTLOCATION.H
  int Price; //FILE E.
}Unit;

//maxhealth(Infounit(FirstUnit(Units(P))))

typedef Unit infotypeUNIT;
typedef struct tElmtlistUNIT *addressUNIT;
typedef struct tElmtlistUNIT {
	infotypeUNIT infoUNIT;
	addressUNIT nextUNIT;
} ElmtListUNIT;
typedef struct {
	addressUNIT FirstUNIT;
} ListUNIT;

/* Definisi list : */
/* List kosong : FirstUNIT(L) = Nil */
/* Setiap elemen dengan address P dapat diacu InfoUIT(P), NextUNIT(P) */
/* Elemen terakhir list: jika addressnya Last, maka NextUNIT(Last)=FirstUNIT(L) */

/* Notasi Akses List Unit */
#define InfoUNIT(P) (P)->infoUNIT
#define NextUNIT(P) (P)->nextUNIT
#define FirstUNIT(L) ((L).FirstUNIT)

/* Notasi Akses Unit */
#define MaxHealth(U) (U).MaxHealth
#define Health(U) (U).Health
#define Attack(U) (U).Attack
#define MaxMovePoint(U) (U).MaxMovePoint
#define MovePoint(U) (U).MovePoint
#define AttackType(U) (U).AttackType
#define AtkOpp(U) (U).AtkOpp
#define UnitLocation(U) (U).UnitLocation
#define Price(U) (U).Price

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyUNIT (ListUNIT L);
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyUNIT (ListUNIT *L);
/* I.S. L sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

int NbUNIT (ListUNIT L);

/****************** Manajemen Memori ******************/
addressUNIT AlokasiUNIT (infotypeUNIT X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokasiUNIT (addressUNIT P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressUNIT SearchUNIT (ListUNIT L, infotypeUNIT X);
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstUNIT (ListUNIT *L, infotypeUNIT X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLastUNIT (ListUNIT *L, infotypeUNIT X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstUNIT (ListUNIT *L, infotypeUNIT * X);
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLastUNIT (ListUNIT *L, infotypeUNIT * X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstUNIT (ListUNIT *L, addressUNIT P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertLastUNIT (ListUNIT *L, addressUNIT P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfterUNIT (ListUNIT *L, addressUNIT P, addressUNIT Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstUNIT (ListUNIT *L, addressUNIT *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLastUNIT (ListUNIT *L, addressUNIT *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
void DelAfterUNIT (ListUNIT *L, addressUNIT *Pdel, addressUNIT Prec);
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelPUNIT (ListUNIT *L, infotypeUNIT X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */

#endif
