#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "move.h"
#include "stackt.h"
#include "listVILLAGE.h"
#include "InitializeNew.h"
#include "boolean.h"

boolean IsAbleToMove(MATRIKS Map, infotypeUNIT U, POINT CurrentLocation,int i,int j) {
  /* memeriksa apakah coordinat tujuan bisa ditempati atau tidak */
  boolean able = true;
  int loc_baris = Idx(UnitLocation(U));
  int loc_kolom = Clmn(UnitLocation(U));
  POINT Aim;
  Idx(Aim) = i;
  Clmn(Aim) = j;
  int op;

  if (( j < 0) || ( j > NKolEff(Map) - 1) || (i < 0) || (i > NBrsEff(Map) - 1)) {
      /* Jika input koordinat di luar map */
      printf("\nYou can't move outside the map!!\n\n");
      able = false;
  }else if (IsOcc(Map,i,j)) {
      /* Jika input koordinat ditempati unit lain */
      printf("\nThere is another unit there.\n\n");
      able = false;
  }else if (PanjangPOINT(UnitLocation(U),Aim) > MovePoint(U)){
      /* Jika input koordinat melebihi jarak langkah unit */
      printf("\nYou don't have enough movement points to go there\n\n");
      able = false;
  }else if (PanjangPOINT(UnitLocation(U),Aim) == MaxMovePoint(U)){
    if (loc_baris == i+2) {
        if (IsOcc(Map,i+1,j) && (OwnUnitPetak(Map,i+1,j) != OwnUnitPetak(Map,loc_baris,loc_kolom)))
        {
            /* Jika input koordinat dihalangi oleh musuh */
            printf("\nThere is an enemy blocking your way\n\n");
            able = false;
        }
    } else if(loc_baris == i-2) {
        if (IsOcc(Map,i-1,j)&&(OwnUnitPetak(Map,i-1,j)!=OwnUnitPetak(Map,loc_baris,loc_kolom))){
            /* Jika input koordinat dihalangi oleh musuh */
            printf("\nThere is an enemy blocking your way\n\n");
            able=false;
        }
    } else if (loc_kolom == j+2) {
        if (IsOcc(Map,i,j+1)&&(OwnUnitPetak(Map,i,j+1)!=OwnUnitPetak(Map,loc_baris,loc_kolom))){
            /* Jika input koordinat dihalangi oleh musuh */
            printf("\nThere is an enemy blocking your way\n\n");
            able=false;
        }
    } else if(loc_kolom == j-2)
    {
        if (IsOcc(Map,i,j-1) && (OwnUnitPetak(Map,i,j-1)!=OwnUnitPetak(Map,loc_baris,loc_kolom))){
            /* Jika input koordinat dihalangi oleh musuh */
            printf("\nThere is an enemy blocking your way\n\n");
            able = false;
          }
    } else {
      /* Jika input koordinat dihalangi oleh musuh */
      if(IsOcc(Map,loc_baris,j) && OwnUnitPetak(Map,loc_baris,j) != OwnUnitPetak(Map,loc_baris,loc_kolom) &&
      IsOcc(Map,i,loc_kolom) && OwnUnitPetak(Map,i,loc_kolom) != OwnUnitPetak(Map,loc_baris,loc_kolom)) {
        printf("\nThere is an enemy blocking your way\n\n");
        able = false;
      }
    }
  }
  return able;
}

boolean IsAbleToMoveTwo(MATRIKS Map, infotypeUNIT U, POINT CurrentLocation,int i,int j) {
  /* memeriksa apakah langkah kedua bisa ditempati atau tidak */
  boolean able = true;
  int loc_baris = Idx(UnitLocation(U));
  int loc_kolom = Clmn(UnitLocation(U));
  POINT Aim;
  Idx(Aim) = i;
  Clmn(Aim) = j;
  int op;
  boolean diag1 = true;
  boolean diag2 = true;

  if (( j < 0) || ( j > NKolEff(Map) - 1) || (i < 0) || (i > NBrsEff(Map) - 1)) {
      /* Jika inputan koordinat di luar map */
      able = false;
  }else if (IsOcc(Map,i,j)) {
      /* Jika inputan koordinat ditempati unit lain */
      able = false;
  }else if (PanjangPOINT(UnitLocation(U),Aim) > MovePoint(U)){
      /* Jika inputan koordinat melebihi langkah unit */
      able = false;
  }else if (PanjangPOINT(UnitLocation(U),Aim) == MaxMovePoint(U)) {
    if (loc_baris == i+2) {
        if (IsOcc(Map,i+1,j) && (OwnUnitPetak(Map,i+1,j) != OwnUnitPetak(Map,loc_baris,loc_kolom)))
        /* Jika inputan koordinat dihalangi unit musuh */
        {
            able= false;
        }
    } else if(loc_baris == i - 2) {
        if (IsOcc(Map,i-1,j)&&(OwnUnitPetak(Map,i-1,j)!=OwnUnitPetak(Map,loc_baris,loc_kolom))){
            /* Jika inputan koordinat dihalangi unit musuh */
            able=false;
        }
    } else if (loc_kolom == j+2) {
        if (IsOcc(Map,i,j+1)&&(OwnUnitPetak(Map,i,j+1)!=OwnUnitPetak(Map,loc_baris,loc_kolom))){
            /* Jika inputan koordinat dihalangi unit musuh */
            able=false;
        }
    } else if(loc_kolom == j-2)
    {
        if (IsOcc(Map,i,j-1) && (OwnUnitPetak(Map,i,j-1)!=OwnUnitPetak(Map,loc_baris,loc_kolom))){
            /* Jika inputan koordinat dihalangi unit musuh */
            able = false;
        }
    } else {
      if(IsOcc(Map,loc_baris,j) && OwnUnitPetak(Map,loc_baris,j) != OwnUnitPetak(Map,loc_baris,loc_kolom) &&
      IsOcc(Map,i,loc_kolom) && OwnUnitPetak(Map,i,loc_kolom) != OwnUnitPetak(Map,loc_baris,loc_kolom)) {
        /* Jika inputan koordinat dihalangi unit musuh */
        able = false;
      }
    }
  }
  return able;
}

void TulisAbleMATRIKS (MATRIKS M, infotypeUNIT U, POINT CurrentLocation)
/* menampilkan map dengan tambahan pagar sebagai koordinat-koordiat yang dapat dijalani oleh unit */
{
    indeks i, j;
    int nb, nk, bm, km;
    int y =0;
    int x =0;
    int i1 = Idx(CurrentLocation);
    int j1 = Clmn(CurrentLocation);
    int i2 = i1 + 1; int i3 = i1 + 2;
    int i4 = i1 - 1; int i5 = i1 - 2;

    int j2 = j1 + 1; int j3 = j1 + 2;
    int j4 = j1 - 1; int j5 = j1 - 2;

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
                    /* proses menampilkan map ke layar */
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
                    }else if (i2 * 4 + 2 == i && j1 * 4 + 3 == j && IsAbleToMoveTwo(M,U,CurrentLocation,i2,j1)) {
                          printf("#");
                    }else if (i3 * 4 + 2 == i && j1 * 4 + 3 == j && IsAbleToMoveTwo(M,U,CurrentLocation,i3,j1)) {
                          printf("#");
                    }else if (i4 * 4 + 2 == i && j1 * 4 + 3 == j && IsAbleToMoveTwo(M,U,CurrentLocation,i4,j1)) {
                          printf("#");
                    }else if (i5 * 4 + 2 == i && j1 * 4 + 3 == j && IsAbleToMoveTwo(M,U,CurrentLocation,i5,j1)) {
                          printf("#");
                    }else if (i1 * 4 + 2 == i && j2 * 4 + 3 == j && IsAbleToMoveTwo(M,U,CurrentLocation,i1,j2)) {
                          printf("#");
                    }else if (i1 * 4 + 2 == i && j3 * 4 + 3 == j && IsAbleToMoveTwo(M,U,CurrentLocation,i1,j3)) {
                          printf("#");
                    }else if (i1 * 4 + 2 == i && j4 * 4 + 3 == j && IsAbleToMoveTwo(M,U,CurrentLocation,i1,j4)) {
                          printf("#");
                    }else if (i1 * 4 + 2 == i && j5 * 4 + 3 == j && IsAbleToMoveTwo(M,U,CurrentLocation,i1,j5)) {
                          printf("#");
                    }else if (i2 * 4 + 2 == i && j2 * 4 + 3 == j && IsAbleToMoveTwo(M,U,CurrentLocation,i2,j2)) {
                          printf("#");
                    }else if (i4 * 4 + 2 == i && j4 * 4 + 3 == j && IsAbleToMoveTwo(M,U,CurrentLocation,i4,j4)) {
                          printf("#");
                    }else if (i2 * 4 + 2 == i && j4 * 4 + 3 == j && IsAbleToMoveTwo(M,U,CurrentLocation,i2,j4)) {
                          printf("#");
                    }else if (i4 * 4 + 2 == i && j2 * 4 + 3 == j && IsAbleToMoveTwo(M,U,CurrentLocation,i4,j2)) {
                          printf("#");
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
                    }else if (i2 * 4 + 2 == i && j1 * 4 + 3 == j && IsAbleToMoveTwo(M,U,CurrentLocation,i2,j1)) {
                          printf("#");
                    }else if (i3 * 4 + 2 == i && j1 * 4 + 3 == j && IsAbleToMoveTwo(M,U,CurrentLocation,i3,j1)) {
                          printf("#");
                    }else if (i4 * 4 + 2 == i && j1 * 4 + 3 == j && IsAbleToMoveTwo(M,U,CurrentLocation,i4,j1)) {
                          printf("#");
                    }else if (i5 * 4 + 2 == i && j1 * 4 + 3 == j && IsAbleToMoveTwo(M,U,CurrentLocation,i5,j1)) {
                          printf("#");
                    }else if (i1 * 4 + 2 == i && j2 * 4 + 3 == j && IsAbleToMoveTwo(M,U,CurrentLocation,i1,j2)) {
                          printf("#");
                    }else if (i1 * 4 + 2 == i && j3 * 4 + 3 == j && IsAbleToMoveTwo(M,U,CurrentLocation,i1,j3)) {
                          printf("#");
                    }else if (i1 * 4 + 2 == i && j4 * 4 + 3 == j && IsAbleToMoveTwo(M,U,CurrentLocation,i1,j4)) {
                          printf("#");
                    }else if (i1 * 4 + 2 == i && j5 * 4 + 3 == j && IsAbleToMoveTwo(M,U,CurrentLocation,i1,j5)) {
                          printf("#");
                    }else if (i2 * 4 + 2 == i && j2 * 4 + 3 == j && IsAbleToMoveTwo(M,U,CurrentLocation,i2,j2)) {
                          printf("#");
                    }else if (i4 * 4 + 2 == i && j4 * 4 + 3 == j && IsAbleToMoveTwo(M,U,CurrentLocation,i4,j4)) {
                          printf("#");
                    }else if (i2 * 4 + 2 == i && j4 * 4 + 3 == j && IsAbleToMoveTwo(M,U,CurrentLocation,i2,j4)) {
                          printf("#");
                    }else if (i4 * 4 + 2 == i && j2 * 4 + 3 == j && IsAbleToMoveTwo(M,U,CurrentLocation,i4,j2)) {
                          printf("#");
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

void MoveUnit(MATRIKS *Map, ListPLAYER *L, infotypeUNIT *U,POINT *CurrentLocation)
/* memindahkan suatu unit ke koordinat inputan */
{
    // Tampilin current map
    TulisAbleMATRIKS(*Map,*U,*CurrentLocation);
    printf("\n");

    int i,j, op;
    int loc_baris, loc_kolom;
    boolean input;
    boolean able;
    POINT Aim;      /*koordinat tujuan unit yang akan digerakkan*/

    // Tulis menunya
    input = false;
    loc_baris = Idx(UnitLocation(*U));
    loc_kolom = Clmn(UnitLocation(*U));

    printf("\nPlease enter your unit's destination  : ");
    scanf("%d %d",&i,&j);

    Idx(Aim) = i;
    Clmn(Aim) = j;
    able = IsAbleToMove(*Map,*U,*CurrentLocation,i,j);
    if (able)
    {
        MovePoint(*U)=MovePoint(*U)-PanjangPOINT(UnitLocation(*U),Aim); //move point dikurang panjang point
        if (TypePetak(*Map,i,j)=='V') {
            MovePoint(*U) = 0;
            Village V;
            VillageLocation(V) = MakePOINT(i,j); //Village location == point i,j
            if(OwnBuildingPetak(*Map,i,j) == 1 && OwnUnitPetak(*Map,loc_baris,loc_kolom) == 2) {
              DelPVILLAGE(&Villages(InfoPLAYER(FirstPLAYER(*L))),V);
              OwnBuildingPetak(*Map,i,j) = OwnUnitPetak(*Map,loc_baris,loc_kolom);
              InsVLastVILLAGE(&Villages(InfoPLAYER(NextPLAYER(FirstPLAYER(*L)))),V);
            } else if (OwnBuildingPetak(*Map,i,j) == 2 && OwnUnitPetak(*Map,loc_baris,loc_kolom) == 1) {
              DelPVILLAGE(&Villages(InfoPLAYER(NextPLAYER(FirstPLAYER(*L)))),V);
              OwnBuildingPetak(*Map,i,j) = OwnUnitPetak(*Map,loc_baris,loc_kolom);
              InsVLastVILLAGE(&Villages(InfoPLAYER(FirstPLAYER(*L))),V);
            } else if(OwnBuildingPetak(*Map,i,j) == 0) {
              OwnBuildingPetak(*Map,i,j) = OwnUnitPetak(*Map,loc_baris,loc_kolom);
              if(OwnUnitPetak(*Map,loc_baris,loc_kolom) == 1) {
                InsVLastVILLAGE(&Villages(InfoPLAYER(FirstPLAYER(*L))),V);
              } else {
                InsVLastVILLAGE(&Villages(InfoPLAYER(NextPLAYER(FirstPLAYER(*L)))),V);
              }
            }
        }
        OwnUnitPetak(*Map,i,j) = OwnUnitPetak(*Map,loc_baris,loc_kolom); //Own unit petak tujuan == own unit asal
        OwnUnitPetak(*Map,loc_baris,loc_kolom) = 0;
        OccPetak(*Map,i,j) = OccPetak(*Map,loc_baris,loc_kolom);
        OccPetak(*Map,loc_baris,loc_kolom) = ' ';
        loc_baris=i;
        loc_kolom=j;
        *CurrentLocation = MakePOINT(loc_baris,loc_kolom);
        UnitLocation(*U) = *CurrentLocation;
        printf("\nYou have successfully moved to (%d,%d)\n\n",loc_baris,loc_kolom);
        input=true;
    }
}

void MoveUNDO(MATRIKS *Map, ListPLAYER *L, infotypeUNIT *U,POINT *CurrentLocation,StackMOVE *SM,boolean isMOVE)
/* melakukan antara MOVE atau UNDO sesuai dengan inputan boolean isMOVE */
{
  if (isMOVE)
  /* Jika isMOVE bernilai True, maka aksi yang dilakukan adalah aksi MOVE */
  {
    POINT P1;
    Idx(P1) = Idx(*CurrentLocation);
    Clmn(P1) = Clmn(*CurrentLocation);

    MoveUnit(Map,L,U,CurrentLocation);
    if(TypePetak(*Map,Idx(*CurrentLocation),Clmn(*CurrentLocation)) == 'V') {
      CreateEmptySTACK(SM);
    }

    if (Idx(P1) != Idx(*CurrentLocation) || Clmn(P1) != Clmn(*CurrentLocation))
    /* Setiap pergerakan yang dilakukan unit akan dimasukkan ke dalam StackMOVE */
    {
      Push(SM,P1);
    }
  }
  else
  /* Jika isMOVE bernilai false, maka aksi yang dilakukan adalah aksi UNDO */
  {
    if (IsEmptySTACK(*SM))
    /* Jika StackMOVE kosong (belum melakukan pergerakan) */
    {
      printf("\nYou can't undo! \n\n");
    }
    else
    /* Jika StackMOVE tidak kosong */
    {
      POINT CLBefore;
      Pop(SM,&CLBefore); // Mengambil koordinat sebelumnya dari dalam StackMOVE

      MovePoint(*U)=MovePoint(*U)+PanjangPOINT(CLBefore,*CurrentLocation); //move point dikurang panjang point

      /* Mengembalikan kepemilikan petak koordinat sebelumnya, dan menghapus kepemilikan petak koordinat posisi */
      OwnUnitPetak(*Map,Idx(CLBefore),Clmn(CLBefore)) = OwnUnitPetak(*Map,Idx(*CurrentLocation),Clmn(*CurrentLocation)); //Own unit petak tujuan == own unit asal
      OwnUnitPetak(*Map,Idx(*CurrentLocation),Clmn(*CurrentLocation)) = 0;
      OccPetak(*Map,Idx(CLBefore),Clmn(CLBefore)) = OccPetak(*Map,Idx(*CurrentLocation),Clmn(*CurrentLocation));
      OccPetak(*Map,Idx(*CurrentLocation),Clmn(*CurrentLocation)) = ' ';
      *CurrentLocation = CLBefore;
      UnitLocation(*U) = *CurrentLocation;

      printf("\nYou have move back to your location before.\n\n");
    }
  }
}
