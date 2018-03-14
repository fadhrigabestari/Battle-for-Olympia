#include <stdio.h>
#include <stdlib.h>
#include "changeunit.h"

void WriteListUnit(ListPLAYER L, MATRIKS Map, int Turn) {
  /* Menampilkan unit-unit yang dimiliki seorang player */
  addressUNIT P;

  printf("\n== List of Units ==\n");
  if (Turn == 1) {
    /* Menampilkan unit-unit yang dimiliki player 1 */
    Player P1 = InfoPLAYER(FirstPLAYER(L));
    int i = 1;
    P = FirstUNIT(Units(P1));
    /* Menampilkan lokasi dan health unit */
    printf("%d. King (%d,%d) | Health %d\n", i, Idx(UnitLocation(InfoUNIT(P))), Clmn(UnitLocation(InfoUNIT(P))), Health(InfoUNIT(P)));
    P = NextUNIT(P);
    while (P != FirstUNIT(Units(P1))) {
        /* Terus menampilkan sampai address kembali ke address awal (kembali ke unit pertama) */
        i++;
         if (OccPetak(Map, Idx(UnitLocation(InfoUNIT(P))), Clmn(UnitLocation(InfoUNIT(P)))) == 'A')
         /* jika di peta terdapat unit ARCHER */
        {
            printf("%d. Archer (%d,%d) | Health %d\n", i, Idx(UnitLocation(InfoUNIT(P))), Clmn(UnitLocation(InfoUNIT(P))), Health(InfoUNIT(P)));
        }
        else if (OccPetak(Map, Idx(UnitLocation(InfoUNIT(P))), Clmn(UnitLocation(InfoUNIT(P)))) == 'S')
        /* jika di peta terdapat unit SWORDSMAN */
        {
            printf("%d. Swordsman (%d,%d) | Health %d\n", i, Idx(UnitLocation(InfoUNIT(P))), Clmn(UnitLocation(InfoUNIT(P))), Health(InfoUNIT(P)));
        } else if(OccPetak(Map, Idx(UnitLocation(InfoUNIT(P))), Clmn(UnitLocation(InfoUNIT(P)))) == 'W')
        /* jika di peta terdapat unit WHITE MAGE */
        {
            printf("%d. White Mage (%d,%d) | Health %d\n", i, Idx(UnitLocation(InfoUNIT(P))), Clmn(UnitLocation(InfoUNIT(P))), Health(InfoUNIT(P)));
        }
        P = NextUNIT(P);
    }
  } else {
    /* Menampilkan unit-unit yang dimiliki player 2 */
    Player P2 = InfoPLAYER(NextPLAYER(FirstPLAYER(L)));
    int i = 1;
    P = FirstUNIT(Units(P2));
    /* Menampilkan lokasi dan health unit */
    printf("%d. King (%d,%d) | Health %d\n", i, Idx(UnitLocation(InfoUNIT(P))), Clmn(UnitLocation(InfoUNIT(P))), Health(InfoUNIT(P)));

    P = NextUNIT(P);
    while (P != FirstUNIT(Units(P2))) {
      /* Terus menampilkan sampai address kembali ke address awal (kembali ke unit pertama) */
      i++;
      if (OccPetak(Map, Idx(UnitLocation(InfoUNIT(P))), Clmn(UnitLocation(InfoUNIT(P)))) == 'A')
      /* jika di peta terdapat unit ARCHER */
      {
          printf("%d. Archer (%d,%d) | Health %d\n", i, Idx(UnitLocation(InfoUNIT(P))), Clmn(UnitLocation(InfoUNIT(P))), Health(InfoUNIT(P)));
      }
      else if (OccPetak(Map, Idx(UnitLocation(InfoUNIT(P))), Clmn(UnitLocation(InfoUNIT(P)))) == 'S')
      /* jika di peta terdapat unit SWORDSMAN */
      {
          printf("%d. Swordsman (%d,%d) | Health %d\n", i, Idx(UnitLocation(InfoUNIT(P))), Clmn(UnitLocation(InfoUNIT(P))), Health(InfoUNIT(P)));
      }
      else if(OccPetak(Map, Idx(UnitLocation(InfoUNIT(P))), Clmn(UnitLocation(InfoUNIT(P)))) == 'W')
      /* jika di peta terdapat unit WHITE MAGE */
      {
          printf("%d. White Mage (%d,%d) | Health %d\n", i, Idx(UnitLocation(InfoUNIT(P))), Clmn(UnitLocation(InfoUNIT(P))), Health(InfoUNIT(P)));
      }
      P = NextUNIT(P);
    }
  }
}

void ChangeUnit(ListPLAYER L, MATRIKS Map, POINT *CurrentLocation, addressUNIT *CurrentAddress, int Turn) {
  /* Mengubah giliran unit menjadi unit pilihan */
  int choice;
  addressUNIT P;

  WriteListUnit(L,Map,Turn);
  /* menampilkan unit-unit milik player */
  printf("Please enter the no. of unit you want to select : ");
  scanf("%d", &choice);
  printf("\n");
  if(Turn == 1) {
    P = FirstUNIT(Units(InfoPLAYER(FirstPLAYER(L))));
    for(int i = 0; i < choice - 1; i++) {
      P = NextUNIT(P);
    }
  } else {
    P = FirstUNIT(Units(InfoPLAYER(NextPLAYER(FirstPLAYER(L)))));
    for(int i = 0; i < choice - 1; i++) {
      P = NextUNIT(P);
    }
  }
  *CurrentLocation = UnitLocation(InfoUNIT(P));
  *CurrentAddress = P;
}

void NextofUnit(ListPLAYER L, MATRIKS Map, POINT *CurrentLocation, addressUNIT *CurrentAddress, int Turn) {
  /* Mengganti giliran unit menjadi unit selanjutnya (urutan berasal dari list) */
  addressUNIT P = *CurrentAddress;
  int n;

  P = NextUNIT(P);
  if(Turn == 1) { // PLAYER 1
    n = 0;
    while(MovePoint(InfoUNIT(P)) == 0 && !AtkOpp(InfoUNIT(P)) && n <= NbUNIT(Units(InfoPLAYER(FirstPLAYER(L))))) {
      P = NextUNIT(P);
      n++;
    }
  } else { // PLAYER 2
    n = 0;
    while(MovePoint(InfoUNIT(P)) == 0 && !AtkOpp(InfoUNIT(P)) && n <= NbUNIT(Units(InfoPLAYER(NextPLAYER(FirstPLAYER(L)))))) {
      P = NextUNIT(P);
      n++;
    }
  }

  if(MovePoint(InfoUNIT(P)) != 0 || AtkOpp(InfoUNIT(P))) {
    /* Jika next unit tidak bisa berlajan maupun menyerang, maka unit tersebut tidak mendapat giliran lagi */
    *CurrentLocation = UnitLocation(InfoUNIT(P));
    *CurrentAddress = P;
    printf("\nYour next available unit is your ");
    if(OccPetak(Map,Idx(*CurrentLocation),Clmn(*CurrentLocation)) == 'K') {
      printf("King.\n\n");
    } else if(OccPetak(Map,Idx(*CurrentLocation),Clmn(*CurrentLocation)) == 'A') {
      printf("Archer.\n\n");
    } else if(OccPetak(Map,Idx(*CurrentLocation),Clmn(*CurrentLocation)) == 'S') {
      printf("Swordsman.\n\n");
    } else if(OccPetak(Map,Idx(*CurrentLocation),Clmn(*CurrentLocation)) == 'W') {
      printf("White Mage.\n\n");
    }
  } else {
    /* jika tidak ada unit yang bisa dimainkan lagi */
    printf("\nNone of your units can attack nor move.\n\n");
  }
}
