#include <stdio.h>
#include <stdlib.h>
#include "recruitcommand.h"
#include "mesinkata.h"
#include "mesinkar.h"

boolean IsTypeCastle2 (POINT input, MATRIKS Map)
/* Mengetahui apakah sebuah Castle dimiliki player 1 atau player 2 */
/* Jika milik player 1 maka menghasilkan false, sebaliknya true */
{
    if (EQPOINT(input,Coordinate(Map,0,NKolEff(Map)-2)) || EQPOINT(input,Coordinate(Map,1,NKolEff(Map)-3)) || EQPOINT(input,Coordinate(Map,2,NKolEff(Map)-2)) || EQPOINT(input,Coordinate(Map,1,NKolEff(Map)-1))){
        return true;
    }else{
        return false;
    }
}

boolean IsTypeCastle1 (POINT input,MATRIKS Map)
/* Mengetahui apakah sebuah Castle dimiliki player 1 atau player 2 */
/* Jika milik player 2 maka menghasilkan false, sebaliknya true */
{
    if (EQPOINT(input,Coordinate(Map,NBrsEff(Map)-2,0)) || EQPOINT(input,Coordinate(Map,NBrsEff(Map)-1,1)) || EQPOINT(input,Coordinate(Map,NBrsEff(Map)-2,2)) || EQPOINT(input,Coordinate(Map,NBrsEff(Map)-3,1))){
        return true;
    }else{
        return false;
    }
}

void RecruitCommand (MATRIKS *Map, ListPLAYER *L, int Turn, POINT CurrentLocation)
/* Melakukan aksi rekrut unit oleh suatu player */
/* yang dapat melakukan rekrut hanya KING, dan KING harus berada di tower */
{
    int x,y,choice;
    infotypeUNIT NewUnit;
    boolean End = false; /* Proses input selesai */
    boolean yes = false;
    infotypeUNIT ASTAT, WSTAT, SSTAT;

    /* Mengambil status-status ARCHER dari file 'ARCHERSTAT.txt' */
    /* Isi file berupa string, maka untuk mendapatkan tipe integer harus dikonversi */
    STARTKATAARCHER();
    MaxHealth(ASTAT) = (CKata.TabKata[1] - '0') * 100 + (CKata.TabKata[2] - '0') * 10 + (CKata.TabKata[3] - '0');
    ADVKATAFILE();
    Attack(ASTAT) = (CKata.TabKata[1] - '0') * 10 + (CKata.TabKata[2] - '0');
    ADVKATAFILE();
    MaxMovePoint(ASTAT) = (CKata.TabKata[1] - '0');
    ADVKATAFILE();
    AttackType(ASTAT) = CKata.TabKata[1];
    ADVKATAFILE();
    Price(ASTAT) = (CKata.TabKata[1] - '0') * 10 + (CKata.TabKata[2] - '0');
    ADVKATAFILE();

    /* Mengambil status-status SWORDSMAN dari file 'SWORDSMANSTAT.txt' */
    /* Isi file berupa string, maka untuk mendapatkan tipe integer harus dikonversi */
    STARTKATASWORDSMAN();
    MaxHealth(SSTAT) = (CKata.TabKata[1] - '0') * 100 + (CKata.TabKata[2] - '0') * 10 + (CKata.TabKata[3] - '0');
    ADVKATAFILE();
    Attack(SSTAT) = (CKata.TabKata[1] - '0') * 10 + (CKata.TabKata[2] - '0');
    ADVKATAFILE();
    MaxMovePoint(SSTAT) = (CKata.TabKata[1] - '0');
    ADVKATAFILE();
    AttackType(SSTAT) = CKata.TabKata[1];
    ADVKATAFILE();
    Price(SSTAT) = (CKata.TabKata[1] - '0') * 10 + (CKata.TabKata[2] - '0');

    /* Mengambil status-status WHITE MAGE dari file 'WHITEMAGESTAT.txt' */
    /* Isi file berupa string, maka untuk mendapatkan tipe integer harus dikonversi */
    STARTKATAWHITEMAGE();
    MaxHealth(WSTAT) = (CKata.TabKata[1] - '0') * 100 + (CKata.TabKata[2] - '0') * 10 + (CKata.TabKata[3] - '0');
    ADVKATAFILE();
    Attack(WSTAT) = (CKata.TabKata[1] - '0') * 10 + (CKata.TabKata[2] - '0');
    ADVKATAFILE();
    MaxMovePoint(WSTAT) = (CKata.TabKata[1] - '0');
    ADVKATAFILE();
    AttackType(WSTAT) = CKata.TabKata[1];
    ADVKATAFILE();
    Price(WSTAT) = (CKata.TabKata[1] - '0') * 10 + (CKata.TabKata[2] - '0');

    if(OccPetak(*Map, Idx(CurrentLocation), Clmn(CurrentLocation)) != 'K') {
      /* REKRUT HANYA BOLEH OLEH KING */
      printf("\nYou can only recruit as your King!\n");
    }
    else if(NEQPOINT(CurrentLocation,Coordinate(*Map,1,NKolEff(*Map)-2)) && Turn == 2) {
      /* KING HANYA BOLEH REKRUT DI DALAM TOWER */
      printf("\nYou can only recruit at your tower!\n");
    } else if(NEQPOINT(CurrentLocation,Coordinate(*Map,NBrsEff(*Map)-2,1)) && Turn == 1) {
      printf("\nYou can only recruit at your tower!\n");
    } else {
      while (!End)
      /* Melakukan aksi Rekrut */
      {
          printf("Please enter your empty castle's coordinate : ");
          scanf("%d %d", &x,&y);
          POINT input = MakePOINT(x,y);
          if ((x<0) || (x>NBrsEff(*Map) - 1) || (y<0) || (y>NKolEff(*Map) - 1))
          { // tidak boleh rekrut di luar map
              printf("\nYou're out of the box!\n\n");
              End = true;
          }
          else if (Turn == 1 && !IsTypeCastle1(input,*Map)) {
            // tidak boleh rekrut di Castle player lain
            printf("\nThat is not your castle!\n\n");
            End = true;
          } else if (Turn == 2 && !IsTypeCastle2(input,*Map)) {
            // tidak boleh rekrut di Castle player lain
            printf("\nThat is not your castle!\n\n");
            End = true;
          } else {
            // tidak boleh rekrut di Castle yang sudah ditempati unit
              if(Turn == 1 && IsTypeCastle1(input,*Map)) {
                if (IsOcc(*Map,x,y))
                {
                    printf("\nThat castle is occupied!\n\n");
                    End = true;
                }
                else
                {
                    End=true;
                    yes = true;
                }
              } else if(Turn == 2 && IsTypeCastle2(input,*Map)) {
                if(IsOcc(*Map,x,y)) {
                  printf("\nThat castle is occupied!\n\n");
                  End = true;
                } else {
                  End = true;
                  yes = true;
                }
              }
          }
        }
      if(yes) {
      POINT input = MakePOINT(x,y);
      /* Jika input sudah memenuhi syarat */
      printf("\n=== LIST OF RECRUITS ===\n");
      printf("1. Archer | Health %d | ATK %d | %dG\n", MaxHealth(ASTAT), Attack(ASTAT), Price(ASTAT));
      printf("2. Swordsman | Health %d | ATK %d | %dG\n", MaxHealth(SSTAT), Attack(SSTAT), Price(SSTAT));
      printf("3. White Mage | Health %d | ATK %d | %dG\n", MaxHealth(WSTAT), Attack(WSTAT), Price(WSTAT));
      printf("Enter the number of unit you want to recruit : ");
      do {
        scanf("%d", &choice);
      } while(choice < 1 || choice > 3);
      printf("\n");
      if (Turn == 1) /* Yang merekrut adalah P1 */
      {
          if (choice==1)
          {
            // MEREKRUT ARCHER
            if(Gold(InfoPLAYER(FirstPLAYER(*L))) <= 0) {
              //JIKA TIDAK PUNYA UANG
              printf("You beg the archer to join your fight.\n");
              printf("'Even I have more money than you!', said the archer laughing.\n\n");
            } else if(Gold(InfoPLAYER(FirstPLAYER(*L))) < Price(ASTAT)) {
              //JIKA UANG TIDAK CUKUP
              printf("You offer him %dG.\n", Gold(InfoPLAYER(FirstPLAYER(*L))));
              printf("The archer spit at the ground and walk away.\n\n");
            } else {
              //JIKA UANG CUKUP, MAKA UNIT YANG DIREKRUT DIMASUKKAN KE LISTUNIT MILIK PLAYER TERSEBUT
              OwnUnitPetak(*Map,x,y)=1;
              printf("You have recruited an archer!\n\n");
              NewUnit = ASTAT;
              Health(NewUnit) = MaxHealth(ASTAT);
              MovePoint(NewUnit) = 0;
              AtkOpp(NewUnit)= false;
              Idx(UnitLocation(NewUnit))=x;
              Clmn(UnitLocation(NewUnit))=y;
              Gold(InfoPLAYER(FirstPLAYER(*L)))-=Price(ASTAT);
              InsVLastUNIT(&Units(InfoPLAYER(FirstPLAYER(*L))),NewUnit);
              OccPetak(*Map,x,y)='A';
            }
          }
          else if (choice==2)
          {
            //MEREKRUT SWORDSMAN
            if(Gold(InfoPLAYER(FirstPLAYER(*L))) <= 0) {
              //JIKA TIDAK PUNYA UANG
              printf("You beg the swordsman to join your fight.\n");
              printf("'Even I have more money than you!', said the swordsman laughing.\n\n");
            } else if(Gold(InfoPLAYER(FirstPLAYER(*L))) < Price(SSTAT)) {
              //JIKA UANG TIDAK CUKUP
              printf("You offer him %dG.\n", Gold(InfoPLAYER(FirstPLAYER(*L))));
              printf("The swordsman spit at the ground and walk away.\n\n");
            } else {
              //JIKA UANG CUKUP, MAKA UNIT YANG DIREKRUT DIMASUKKAN KE LIST UNIT MILIK PLAYER
              OwnUnitPetak(*Map,x,y)=1;
              printf("You have recruited a swordsman!\n\n");
              NewUnit = SSTAT;
              Health(NewUnit) = MaxHealth(SSTAT);
              MovePoint(NewUnit) = 0;
              AtkOpp(NewUnit)= false;
              Idx(UnitLocation(NewUnit))=x;
              Clmn(UnitLocation(NewUnit))=y;
              Gold(InfoPLAYER(FirstPLAYER(*L)))-=Price(SSTAT);
              InsVLastUNIT(&Units(InfoPLAYER(FirstPLAYER(*L))),NewUnit);
              OccPetak(*Map,x,y)='S';
            }
          }
          else if (choice == 3)
          {
            //MEREKRUT WHITE MAGE
            if(Gold(InfoPLAYER(FirstPLAYER(*L))) <= 0) {
              //JIKA TIDAK PUNYA UANG
              printf("You beg the white mage to join your fight.\n");
              printf("'Even I have more money than you!', said the white mage laughing.\n\n");
            } else if(Gold(InfoPLAYER(FirstPLAYER(*L))) < Price(WSTAT)) {
              //JIKA UANG TIDAK CUKUP
              printf("You offer him %dG.\n", Gold(InfoPLAYER(FirstPLAYER(*L))));
              printf("The white mage spit at the ground and walk away.\n\n");
            } else {
              //JIKA UANG CUKUP, MAKA UNIT YANG DIREKRUT DIMASUKKAN KE LIST UNIT MILIK PLAYER
              OwnUnitPetak(*Map,x,y)=1;
              printf("You have recruited a white mage!\n\n");
              NewUnit = WSTAT;
              Health(NewUnit) = MaxHealth(WSTAT);
              MovePoint(NewUnit) = 0;
              AtkOpp(NewUnit)= false;
              Idx(UnitLocation(NewUnit))=x;
              Clmn(UnitLocation(NewUnit))=y;
              Gold(InfoPLAYER(FirstPLAYER(*L)))-=Price(WSTAT);
              InsVLastUNIT(&Units(InfoPLAYER(FirstPLAYER(*L))),NewUnit);
              OccPetak(*Map,x,y)='W';
            }
          }
      }
      else if (Turn == 2) /* Yang merekrut adalah P2 */
      {
          if (choice==1)
          {
            //MEREKRUT ARCHER
            if(Gold(InfoPLAYER(NextPLAYER(FirstPLAYER(*L)))) == 0) {
              //JIKA TIDAK PUNYA UANG
              printf("You beg the archer to join your fight.\n", Gold(InfoPLAYER(FirstPLAYER(*L))));
              printf("'Even I have more money than you!', said the archer laughing.\n\n");
            } else if(Gold(InfoPLAYER(NextPLAYER(FirstPLAYER(*L)))) < Price(ASTAT)) {
              //JIKA UANG TIDAK CUKUP
              printf("You offer him %dG.\n", Gold(InfoPLAYER(FirstPLAYER(*L))));
              printf("The archer spit at the ground and walk away.\n\n");
            } else {
              //JIKA UANG CUKUP, MAKA UNIT YANG DIREKRUT DIMASUKKAN KE LIST UNIT MILIK PLAYER
              OwnUnitPetak(*Map,x,y)=2;
              printf("You have recruited an archer!\n\n");
              NewUnit = ASTAT;
              Health(NewUnit) = MaxHealth(ASTAT);
              MovePoint(NewUnit) = 0;
              AtkOpp(NewUnit)= false;
              Idx(UnitLocation(NewUnit))=x;
              Clmn(UnitLocation(NewUnit))=y;
              Gold(InfoPLAYER(NextPLAYER(FirstPLAYER(*L))))-=Price(ASTAT);
              InsVLastUNIT(&Units(InfoPLAYER(NextPLAYER(FirstPLAYER(*L)))),NewUnit);
              OccPetak(*Map,x,y)='A';
            }
          }
          else if (choice==2)
          {
            //MEREKRUT SWORDSMAN
            if(Gold(InfoPLAYER(NextPLAYER(FirstPLAYER(*L)))) == 0) {
              //JIKA TIDAK PUNYA UANG
              printf("You beg the swordsman to join your fight.\n", Gold(InfoPLAYER(FirstPLAYER(*L))));
              printf("'Even I have more money than you!', said the swordsman laughing.\n\n");
            } else if(Gold(InfoPLAYER(NextPLAYER(FirstPLAYER(*L)))) < Price(SSTAT)) {
              //JIKA UANG TIDAK CUKUP
              printf("You offer him %dG.\n", Gold(InfoPLAYER(FirstPLAYER(*L))));
              printf("The swordsman spit at the ground and walk away.\n\n");
            } else {
              //JIKA UANG CUKUP, MAKA UNIT YANG DIREKRUT DIMASUKKAN KE LIST UNIT MILIK PLAYER
              OwnUnitPetak(*Map,x,y)=2;
              printf("You have recruited a swordsman!\n\n");
              NewUnit = SSTAT;
              Health(NewUnit) = MaxHealth(SSTAT);
              MovePoint(NewUnit) = 0;
              AtkOpp(NewUnit)= false;
              Idx(UnitLocation(NewUnit))=x;
              Clmn(UnitLocation(NewUnit))=y;
              Gold(InfoPLAYER(NextPLAYER(FirstPLAYER(*L))))-=Price(SSTAT);
              InsVLastUNIT(&Units(InfoPLAYER(NextPLAYER(FirstPLAYER(*L)))),NewUnit);
              OccPetak(*Map,x,y)='S';
            }
          }
          else if (choice == 3)
          {
            //MEREKRUT WHITE MAGE
            if(Gold(InfoPLAYER(NextPLAYER(FirstPLAYER(*L)))) <= 0) {
              //JIKA TIDAK PUNYA UANG
              printf("You beg the white mage to join your fight.\n");
              printf("'Even I have more money than you!', said the white mage laughing.\n\n");
            } else if(Gold(InfoPLAYER(NextPLAYER(FirstPLAYER(*L)))) < Price(WSTAT)) {
              //JIKA UANG TIDAK CUKUP
              printf("You offer him %dG.\n", Gold(InfoPLAYER(NextPLAYER(FirstPLAYER(*L)))));
              printf("The white mage spit at the ground and walk away.\n\n");
            } else {
              //JIKA UANG CUKUP, MAKA UNIT YANG DIREKRUT DIMASUKKAN KE LIST UNIT MILIK PLAYER
              OwnUnitPetak(*Map,x,y)=2;
              printf("You have recruited a white mage!\n\n");
              NewUnit = WSTAT;
              Health(NewUnit) = MaxHealth(WSTAT);
              MovePoint(NewUnit) = 0;
              AtkOpp(NewUnit)= false;
              Idx(UnitLocation(NewUnit))=x;
              Clmn(UnitLocation(NewUnit))=y;
              Gold(InfoPLAYER(NextPLAYER(FirstPLAYER(*L))))-=Price(WSTAT);
              InsVLastUNIT(&Units(InfoPLAYER(NextPLAYER(FirstPLAYER(*L)))),NewUnit);
              OccPetak(*Map,x,y)='W';
            }
        }
      }
    }
  }
}
