#include "queuePLAYER.h"
#include <stdlib.h>
#include <stdio.h>

/* ********* Prototype ********* */
boolean IsEmptyQPLAYER (QueuePLAYER Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return (HeadQPLAYER(Q) == Nil0 && TailQPLAYER(Q) == Nil0);
}
boolean IsFullQPLAYER (QueuePLAYER Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    return (NBElmtQPLAYER(Q) == MaxElQPLAYER(Q));
}
int NBElmtQPLAYER (QueuePLAYER Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
    if (IsEmptyQPLAYER(Q)){
        return (0);
    }else{
        if (HeadQPLAYER(Q) < TailQPLAYER(Q)){
            return(TailQPLAYER(Q) - HeadQPLAYER(Q) + 1);
        }else{
            return(TailQPLAYER(Q) + MaxElQPLAYER(Q) - HeadQPLAYER(Q) + 1);
        }
    }
}

/* *** Kreator *** */
void CreateEmptyQPLAYER (QueuePLAYER * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
    (*Q).TQPLAYER = (infotypeQPLAYER *) malloc ((Max + 1) * sizeof(infotypeQPLAYER));
    if ((*Q).TQPLAYER == NULL){
        MaxElQPLAYER(*Q) = 0;
    }else{
        HeadQPLAYER(*Q) = Nil0;
        TailQPLAYER(*Q) = Nil0;
        MaxElQPLAYER(*Q) = Max;
    }
}
/* *** Destruktor *** */
void DeAlokasiQPLAYER (QueuePLAYER * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
    free((*Q).TQPLAYER);
    MaxElQPLAYER(*Q) = 0;
}

/* *** Primitif Add/Delete *** */
void AddQPLAYER (QueuePLAYER * Q, infotypeQPLAYER X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
{
    if (IsEmptyQPLAYER(*Q)) {
        HeadQPLAYER(*Q) = 1;
        TailQPLAYER(*Q) = HeadQPLAYER(*Q);
    } else {
        if(TailQPLAYER(*Q) == MaxElQPLAYER(*Q)) TailQPLAYER(*Q) = 1;
        else TailQPLAYER(*Q)++;
    }
    InfoTailQPLAYER(*Q) = X;
}
void DelQPLAYER (QueuePLAYER * Q, infotypeQPLAYER * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
    *X = InfoHeadQPLAYER(*Q);
    if (NBElmtQPLAYER(*Q) == 1) {
           HeadQPLAYER(*Q) = Nil0;
           TailQPLAYER(*Q) = Nil0;
    } else {
        if(HeadQPLAYER(*Q) == MaxElQPLAYER(*Q)) {
                HeadQPLAYER(*Q) = 1;
        } else {
            HeadQPLAYER(*Q)++;
        }
    }
}
