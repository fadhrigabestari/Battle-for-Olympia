/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */

#ifndef MATRIKS_H
#define MATRIKS_H

#include "boolean.h"
#include "point.h"
#include "pcolor.h"
#include "listUNIT.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define BrsMin 0
#define BrsMax 100
#define KolMin 0
#define KolMax 100

typedef struct{
  POINT Coordinate;
  char TypePetak; //BUILDING IN THAT SQUARE
  int OwnUnitPetak; //OWNER, P(1), P(2), 0 FOR NEITHER
  int OwnBuildingPetak; //Owner of building in that square
  char OccPetak; //UNIT IN THAT SQUARE
} Petak;

typedef int indeks; /* indeks baris, kolom */

typedef struct {
	Petak Mem[BrsMax+1][KolMax+1];
    int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
	int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} MATRIKS;
/* NBrsEff <= 1 dan NKolEff <= 1 */
/* Indeks matriks yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M);
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */

#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define Elmt(M,i,j) (M).Mem[(i)][(j)]
#define Coordinate(M,i,j) (M).Mem[(i)][(j)].Coordinate
#define TypePetak(M,i,j) (M).Mem[(i)][(j)].TypePetak
#define OwnUnitPetak(M,i,j) (M).Mem[(i)][(j)].OwnUnitPetak
#define OwnBuildingPetak(M,i,j) (M).Mem[(i)][(j)].OwnBuildingPetak
#define OccPetak(M,i,j) (M).Mem[(i)][(j)].OccPetak


boolean IsOcc(MATRIKS M, int i, int j);
/*Mengirimkan true jika petak ditampati oleh sebuah unit*/

boolean IsBuilding(MATRIKS M, int i, int j);
/*Mengirimkan true jika ada building*/

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j);
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */

void isiCoordinate(MATRIKS *M,int nb, int nk);
/*Mengisi koordinat tiap matriks*/

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M);
/* Mengirimkan indeks baris terkecil M */
indeks GetFirstIdxKol (MATRIKS M);
/* Mengirimkan indeks kolom terkecil M */
indeks GetLastIdxBrs (MATRIKS M);
/* Mengirimkan indeks baris terbesar M */
indeks GetLastIdxKol (MATRIKS M);
/* Mengirimkan indeks kolom terbesar M */
boolean IsIdxEff (MATRIKS M, indeks i, indeks j);
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl);
/* Melakukan assignment MHsl  MIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void TulisMATRIKS (MATRIKS M, POINT CurrentLocation);
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

int NBElmtM (MATRIKS M);
/* Mengirimkan banyaknya elemen M */

#endif
