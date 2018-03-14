/* *** DEFINISI PROTOTIPE PRIMITIF *** */

#include <stdio.h>
#include <math.h>
#include "boolean.h"
#include "point.h"

/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (int i, int j)
/* Membentuk sebuah POINT dari komponen-komponennya */
{
    POINT P;
    Idx(P) = i;
    Clmn(P) = j;
    return P;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT (POINT * P)
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
{
    int i,j;
    scanf("%d %d", &i,&j);
    MakePOINT(i,j);
}

void TulisPOINT (POINT P)
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */
{
    printf("(%d,%d)", Idx(P),Clmn(P));
}

boolean EQPOINT (POINT P1, POINT P2)
{
  return(Idx(P1) == Idx(P2) && Clmn(P1) == Clmn(P2));
}

boolean NEQPOINT(POINT P1, POINT P2)
{
  return(!EQPOINT(P1,P2));
}

/* *** Kelompok operasi relasional terhadap POINT *** */
POINT NextIPOINT (POINT P)
/* Mengirim salinan P dengan absis ditambah satu */
{
    POINT P1;
    Idx(P1)=(Idx(P)+1);
    Clmn(P1)=Clmn(P);
    return P1;
}

POINT NextJPOINT (POINT P)
/* Mengirim salinan P dengan ordinat ditambah satu */
{
    POINT P1;
    Clmn(P1)=(Clmn(P)+1);
    Idx(P1)=Idx(P);
    return P1;
}

POINT PlusDeltaPOINT (POINT P, int deltaI, int deltaJ)
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
{
    POINT P1;
    Idx(P1)=(Idx(P)+deltaI);
    Clmn(P1)=(Clmn(P)+deltaJ);
    return P1;
}

int PanjangPOINT (POINT P1, POINT P2)
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
/* Tuliskan spec fungsi yang lebih tepat. */
{
    int length = 0;
    int CekIdx = Idx(P1);
    int CekClmn = Clmn(P1);

    if(Idx(P1) <= Idx(P2)) {
      while(CekIdx < Idx(P2)) {
        length++;
        CekIdx++;
      }
      if(Clmn(P1) <= Clmn(P2)) {
        while(CekClmn < Clmn(P2)) {
          length++;
          CekClmn++;
        }
      } else { //Clmn(P1) > Clmn(P2)
        while(CekClmn > Clmn(P2)) {
          length++;
          CekClmn--;
        }
      }
    } else { //Idx(P1) > Idx(P1)
      while(CekIdx > Idx(P2)) {
        length++;
        CekIdx--;
      }
      if(Clmn(P1) <= Clmn(P2)) {
        while(CekClmn < Clmn(P2)) {
          length++;
          CekClmn++;
        }
      } else { //Clmn(P1) > Clmn(P2)
        while(CekClmn > Clmn(P2)) {
          length++;
          CekClmn--;
        }
      }
    }

    return length;
}

void GeserPOINT (POINT *P, int deltaI, int deltaJ)
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
{
    /*KAMUS LOKAL*/
    /*ALGORITMA*/
    *P = PlusDeltaPOINT(*P, deltaI, deltaJ);
}
