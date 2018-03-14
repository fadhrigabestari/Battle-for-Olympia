#include <stdio.h>
#include "matriks.h"
#include "boolean.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */

/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;
}

boolean IsOcc(MATRIKS M, int i, int j)
/*Mengirimkan true jika petak ditempati oleh sebuah unit*/
{
    return(OccPetak(M,i,j) == 'K' || OccPetak(M,i,j) == 'A' || OccPetak(M,i,j) == 'S' || OccPetak(M,i,j) == 'W');
}

boolean IsBuilding(MATRIKS M, int i, int j)
/*Mengirimkan true jika ada building*/
{
    return(TypePetak(M,i,j) == 'V' || TypePetak(M,i,j)== 'T' || TypePetak(M,i,j) == 'C');
}
/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
    return (i>=0 && i<=100 && j>=0 && j<=100);
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
    return(BrsMin);
}

indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
    return(KolMin);
}

indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
    return(GetFirstIdxBrs(M)+NBrsEff(M)-1);
}

indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
    return(GetFirstIdxKol(M)+NKolEff(M)-1);
}

boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
    return(i>=GetFirstIdxBrs(M) && i<=NBrsEff(M) && j>=GetFirstIdxKol(M) && j<=NKolEff(M));
}

void isiCoordinate(MATRIKS *M,int nb, int nk)
/*Mengisi koordinat tiap matriks*/
{
    int i,j;

    for (i=0;i<nb;i++){
        for (j=0;j<nk;j++){
            Idx(Coordinate(*M,i,j)) = i;
            Clmn(Coordinate(*M,i,j)) = j;
        }

    }
}
/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl ke MIn */
{
    indeks i, j;

    MakeMATRIKS(NBrsEff(MIn),NKolEff(MIn),MHsl);
    for (i=GetFirstIdxBrs(MIn);i<=NBrsEff(MIn);i++)
    {
        for (j=GetFirstIdxKol(MIn);j<=NKolEff(MIn);j++)
        {
            Elmt(*MHsl,i,j) = Elmt(MIn,i,j);
        }
    }
}

void TulisMATRIKS (MATRIKS M, POINT CurrentLocation)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
    indeks i, j;
    int nb, nk, bm, km;
    int y =0;
    int x =0;
    int i1 = Idx(CurrentLocation);
    int j1 = Clmn(CurrentLocation);

    if (NBrsEff(M) <= 9 && NKolEff(M)<=9){
        nb = (NBrsEff(M)*4);
        nk = (NKolEff(M)*4) + 1;

        /*indeks sumbu x pada peta*/
        for (i=0;i<=nk;i++){
            if (i%4 == 3){
                printf("%d",x);
                x++;
            }else{
                printf(" ");
            }
        }
        printf("\n");
        for (i=GetFirstIdxBrs(M);i<=nb;i++)
        {

            for (j=GetFirstIdxKol(M);j<=nk;j++)
            {
                bm = i/4;
                km = j/4;
                    if (i%4 == 0 && j!=0){
                        printf("*");
                    }else if (j%4 == 1 && i !=0){
                        printf("*");
                    }else if (i%4 == 1 && j%4 == 3 && TypePetak(M,bm,km) == 'V' && OwnBuildingPetak(M,bm,km) == 0) {
                        printf("%c",TypePetak(M,bm,km));
                    }else if (i%4 == 1 && j%4 == 3 && TypePetak(M,bm,km) == 'N') {
                        printf(" ");
                    }else if (i%4 == 1 && j%4 == 3 && OwnBuildingPetak(M,bm,km) == 1){
                        print_red(TypePetak(M,bm,km));
                    }else if (i1 * 4 + 2 == i && j1 * 4 + 3 == j) {
                        print_green(OccPetak(M,i1,j1));
                    }else if (i%4 == 2 && j%4 == 3 && OwnUnitPetak(M,bm,km) == 1){
                        print_red(OccPetak(M,bm,km));
                    }else if (i%4 == 1 && j%4 == 3 && OwnBuildingPetak(M,bm,km) == 2){
                        print_blue(TypePetak(M,bm,km));
                    }else if (i%4 == 2 && j%4 == 3 && OwnUnitPetak(M,bm,km) == 2){
                        print_blue(OccPetak(M,bm,km));
                    }else if ((i%4)!=0 && i!=0 && j!=0){
                        printf(" ");
                    }else if (j==0){ /*print indeks y*/
                        if (i%4 == 2){
                            printf("%d",y);
                            y++;
                        }else{
                            printf(" ");
                        }
                    }else{
                        printf(" ");
                    }
            }
            if (i!=nb) {printf("\n");}
        }
    }else{ /*ketika indeksnya 2 digit*/
        nb = (NBrsEff(M)*4);
        nk = (NKolEff(M)*4) + 1;

        /*indeks sumbu x pada peta*/
        for (i=0;i<=nk;i++){
            if (x<=10){
                if (i%4 == 0 && i!=0){
                    printf("%d",x);
                    x++;
                }else{
                    printf(" ");
                }
            }else{
                if (i%3 == 2 && i!=0 && x<NKolEff(M)){
                    printf("%d",x);
                    x++;
                }else{
                    printf(" ");
                }
            }
        }
        printf("\n");
        for (i=GetFirstIdxBrs(M);i<=nb;i++)
        {

            for (j=GetFirstIdxKol(M);j<=nk;j++)
            {
                bm = i/4;
                km = j/4;
                    if (i%4 == 0 && j!=0){
                        printf("*");
                    }else if (j%4 == 1 && i !=0){
                        printf("*");
                      }else if (i%4 == 1 && j%4 == 3 && TypePetak(M,bm,km) == 'V' && OwnBuildingPetak(M,bm,km) == 0) {
                          printf("%c",TypePetak(M,bm,km));
                      }else if (i%4 == 1 && j%4 == 3 && TypePetak(M,bm,km) == 'N') {
                          printf(" ");
                    }else if (i%4 == 1 && j%4 == 3 && OwnBuildingPetak(M,bm,km) == 1){
                        print_red(TypePetak(M,bm,km));
                    }else if (i1 * 4 + 2 == i && j1 * 4 + 3 == j) {
                        print_green(OccPetak(M,i1,j1));
                    }else if (i%4 == 2 && j%4 == 3 && OwnUnitPetak(M,bm,km) == 1){
                        print_red(OccPetak(M,bm,km));
                    }else if (i%4 == 1 && j%4 == 3 && OwnBuildingPetak(M,bm,km) == 2){
                        print_blue(TypePetak(M,bm,km));
                    }else if (i%4 == 2 && j%4 == 3 && OwnUnitPetak(M,bm,km) == 2){
                        print_blue(OccPetak(M,bm,km));
                    }else if ((i%4)!=0 && i!=0 && j!=0){
                        printf(" ");
                    }else if (j==0){ /*print indeks y*/
                        if (i%4 == 2){
                            if (y<=9){
                                printf("%d ",y);
                                y++;
                            }else{
                                printf("%d",y);
                                y++;
                            }
                        }else{
                            printf("  ");
                        }
                    }else{
                        printf(" ");
                    }
            }
            if (i!=nb) {printf("\n");}
        }
    }
}

/* ********** Operasi lain ********** */
int NBElmtM (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{
    return(NBrsEff(M)*NKolEff(M));
}
