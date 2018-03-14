/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */

#ifndef queuePLAYER_H
#define queuePLAYER_H

#include "boolean.h"

#define Nil0 0
/* Konstanta untuk mendefinisikan address tak terdefinisi */

/* Definisi elemen dan address */
typedef int infotypeQPLAYER;
typedef int addressQPLAYER;   /* indeks tabel */
/* Contoh deklarasi variabel bertype Queue : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct { infotypeQPLAYER * TQPLAYER;   /* tabel penyimpan elemen */
                 addressQPLAYER HEADQPLAYER;  /* alamat penghapusan */
                 addressQPLAYER TAILQPLAYER;  /* alamat penambahan */
                 int MaxElQPLAYER;     /* Max elemen queue */
               } QueuePLAYER;
/* Definisi Queue kosong: HEAD=Nil; TAIL=Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* ********* AKSES (Selektor) ********* */
/* Jika Q adalah Queue, maka akses elemen : */
#define HeadQPLAYER(Q) (Q).HEADQPLAYER
#define TailQPLAYER(Q) (Q).TAILQPLAYER
#define InfoHeadQPLAYER(Q) (Q).TQPLAYER[(Q).HEADQPLAYER]
#define InfoTailQPLAYER(Q) (Q).TQPLAYER[(Q).TAILQPLAYER]
#define MaxElQPLAYER(Q) (Q).MaxElQPLAYER

/* ********* Prototype ********* */
boolean IsEmptyQPLAYER (QueuePLAYER Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFullQPLAYER (QueuePLAYER Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmtQPLAYER (QueuePLAYER Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void CreateEmptyQPLAYER (QueuePLAYER * Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
void DeAlokasiQPLAYER (QueuePLAYER * Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */


/* *** Primitif Add/Delete *** */
void AddQPLAYER (QueuePLAYER * Q, infotypeQPLAYER X);
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
void DelQPLAYER (QueuePLAYER * Q, infotypeQPLAYER * X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

#endif
