#include <stdio.h>
#include <stdlib.h>
#include "matriks.h"
#include "listVILLAGE.h"
#include "listPLAYER.h"
#include "recruitcommand.h"
#include "changeunit.h"
#include "InitializeNew.h"
#include "move.h"
#include "attack.h"
#include "stackt.h"
#include "mesinkata.h"
#include "mesinkar.h"

addressUNIT SearchUnitPlayer(ListPLAYER L, POINT CurrentLocation) {
//Search a unit in a list of players
//Use CurrentLocation to find a unit with the same coordinate
//Function returns an address of unit
  boolean found = false;
  addressUNIT U1 = FirstUNIT(Units(InfoPLAYER(FirstPLAYER(L)))); //First address unit belonging to Player 1
  addressUNIT U2 = FirstUNIT(Units(InfoPLAYER(NextPLAYER(FirstPLAYER(L))))); //First address unit belonging to Player 2

  if(EQPOINT(UnitLocation(InfoUNIT(U1)),CurrentLocation)) { //If found in list of unit Player 1
    return U1;
  } else if(EQPOINT(UnitLocation(InfoUNIT(U2)),CurrentLocation)) { //If found in list of unit in Player 2
    return U2;
  } else {
    while(NEQPOINT(UnitLocation(InfoUNIT(U1)),CurrentLocation) && NEQPOINT(UnitLocation(InfoUNIT(U2)),CurrentLocation)) { //While location is different
      U1 = NextUNIT(U1);
      U2 = NextUNIT(U2);
    }
    if(EQPOINT(UnitLocation(InfoUNIT(U1)),CurrentLocation)) { //If found in list of unit Player 1
      return U1;
    } else { //found in Player 2
      return U2;
    }
  }
}

void bacamap(int *nb, int *nk, MATRIKS *map)
//Read map and create a new map for a new game
//Nb and Nk have a minimum number of 8x8  tiles

{
    do{
        printf("Please input your desired map size : ");
        scanf("%d ",nb);scanf("%d",nk);
        printf("\n");
        if(*nb < 8 && *nk < 8) {
          printf("You cant create a map that small!\n\n");
        }
    }while(*nb<8 && *nk<8); //Repeat while tile not 8x8

    MakeMATRIKS(*nb,*nk,map); //Make matriks from 0 to *nb-1 and 0 to *nk-1

    for(int i = 0; i < *nb-1; i++) {
      for(int j = 0; j < *nk-1; j++) { //assign all tiles with normal tile and owned by no one (0)
        TypePetak(*map,i,j) = 'N';
        OwnBuildingPetak(*map,i,j) = 0;
      }
    }
    /*king player 1*/
    OccPetak(*map,1,*nk-2) = 'K';
    OwnUnitPetak(*map,1,*nk-2) = 2;
    /*castle player 1*/
    TypePetak(*map,1,*nk-2) = 'T';
    OwnBuildingPetak(*map,1,*nk-2) = 2;
    /*Tower player 1*/
    TypePetak(*map,0,*nk-2) = 'C';
    OwnBuildingPetak(*map,0,*nk-2) = 2;
    TypePetak(*map,1,*nk-3) = 'C';
    OwnBuildingPetak(*map,1,*nk-3) = 2;
    TypePetak(*map,2,*nk-2) = 'C';
    OwnBuildingPetak(*map,2,*nk-2) = 2;
    TypePetak(*map,1,*nk-1) = 'C';
    OwnBuildingPetak(*map,1,*nk-1) = 2;

    /*king player 2*/
    OccPetak(*map,*nb-2,1) = 'K';
    OwnUnitPetak(*map,*nb-2,1) = 1;
    /*castle player 2*/
    TypePetak(*map,*nb-2,1) = 'T';
    OwnBuildingPetak(*map,*nb-2,1) = 1;
    /*tower player 2*/
    TypePetak(*map,*nb-2,0) = 'C';
    OwnBuildingPetak(*map,*nb-2,0) = 1;
    TypePetak(*map,*nb-1,1) = 'C';
    OwnBuildingPetak(*map,*nb-1,1) = 1;
    TypePetak(*map,*nb-2,2) = 'C';
    OwnBuildingPetak(*map,*nb-2,2) = 1;
    TypePetak(*map,*nb-3,1) = 'C';
    OwnBuildingPetak(*map,*nb-3,1) = 1;
    int i,j;
    /*VIllage Location*/
    if (((*nb) * (*nk)) >100){
      /* random int between 0 and *nb *nk */
      for(int k = 0; k < 6; k++) { //6 Villages for tile bigger than 10x10
         i = rand() % *nb - 1;
         j = rand() % *nk - 1;
        while(TypePetak(*map,i,j) != 'N') {
          i = rand() % *nb - 1;
          j = rand() % *nk - 1;
        }
        TypePetak(*map,i,j) = 'V';
      }
    }else{
      /* random int between 0 and nb nk */
      for(int k = 0; k < 4; k++) { //4 Villages for tile equal or smaller than 10x10
        i = rand() % *nb - 1;
        j = rand() % *nk - 1;
        while(TypePetak(*map,i,j) != 'N') { //if
          i = rand() % *nb - 1;
          j = rand() % *nk - 1;
        }
        TypePetak(*map,i,j) = 'V';
      }
    isiCoordinate(map,*nb,*nk);
  }
}

void printmap(MATRIKS map,POINT CurrentLocation)
//Print map with tulis matriks procedure
{
    TulisMATRIKS(map,CurrentLocation);
    printf("\n\n");
}

void InfoCommand (MATRIKS map, ListPLAYER L)
/* Print health dan unit lainnya????? */
{
    int x,y;
    printf("\n");
    printf("Enter the coordinate of cell : ");
    scanf("%d %d", &x,&y);
    while ((x<0)||(x>NBrsEff(map)-1)||(y<0)||(y>NKolEff(map)-1))
    {
        printf("\nYou're out of the box!\n");
        printf("\nEnter the coordinate of cell : ");
        scanf("%d %d", &x,&y);
    }

    printf("\n== CELL INFO ==\n");
    if (!IsBuilding(map,x,y)) /* Jika tidak ada building dalam petak tsb */
    {
        printf("There's no building in this cell\n");
    }
    else
    {
        if (TypePetak(map,x,y)=='V')
        {
            printf("Village\n");
            if (OwnBuildingPetak(map,x,y)==1)
            {
                printf("Owned by Player 1\n");
            }
            else if (OwnBuildingPetak(map,x,y)==2)
            {
                printf("Owned by Player 2\n");
            }
        }
        else if (TypePetak(map,x,y)=='C')
        {
            printf("Castle\n");
            if (OwnBuildingPetak(map,x,y)==1)
            {
                printf("Owned by Player 1\n");
            }
            else if (OwnBuildingPetak(map,x,y)==2)
            {
                printf("Owned by Player 2\n");
            }
        }
        else if (TypePetak(map,x,y)=='T')
        {
            printf("Tower\n");
            if (OwnBuildingPetak(map,x,y)==1)
            {
                printf("Owned by Player 1\n");
            }
            else if (OwnBuildingPetak(map,x,y)==2)
            {
                printf("Owned by Player 2\n");
            }
        }
    }
    printf("\n== Unit Info ==\n");
    if (!IsOcc(map,x,y))
    {
        printf("There's no unit in this cell\n\n  ");
    }
    else
    {
        if (OccPetak(map,x,y) == 'K')
        {
            printf("King\n");
            if (OwnUnitPetak(map,x,y)==1)
            {
                printf("Owned by Player 1\n");
            }
            else if (OwnUnitPetak(map,x,y)==2)
            {
                printf("Owned by Player 2\n");
            }
        }
        else if (OccPetak(map,x,y) == 'A')
        {
            printf("Archer\n");
            if (OwnUnitPetak(map,x,y)==1)
            {
                printf("Owned by Player 1\n");
            }
            else if (OwnUnitPetak(map,x,y)==2)
            {
                printf("Owned by Player 2\n");
            }
        }
        else if (OccPetak(map,x,y) == 'S')
        {
            printf("Swordsman\n");
            if (OwnUnitPetak(map,x,y)==1)
            {
                printf("Owned by Player 1\n");
            }
            else if (OwnUnitPetak(map,x,y)==2)
            {
                printf("Owned by Player 2\n");
            }
        }
        POINT TargetLocation = MakePOINT(x,y);
        addressUNIT addrU = SearchUnitPlayer(L,TargetLocation);
        int H = Health(InfoUNIT(addrU));
        int MH = MaxHealth(InfoUNIT(addrU));
        int Att = Attack(InfoUNIT(addrU));

        printf("Health %d/%d | ATK %d\n\n", H,MH,Att);
    }
}

void PrintState (ListPLAYER L, MATRIKS Map, int X, POINT CL)
/* CL adalah current location */
/* untuk print status awal sebelum pemain memasukkan input command */
{
    addressUNIT P;

    if (X==1)
    {
        Player P1 = InfoPLAYER(FirstPLAYER(L));
        P=FirstUNIT(Units(P1));
        while (NEQPOINT(UnitLocation(InfoUNIT(P)),CL))
        {
            P=NextUNIT(P);
        }
        printf("Player 1's Turn\n");
        printf("Cash: %dG | ", Gold(P1));
        printf("Income: %dG | ", Income(P1));
        printf("Upkeep: %dG |\n", Upkeep(P1));
        if (OccPetak(Map, Idx(UnitLocation(InfoUNIT(P))), Clmn(UnitLocation(InfoUNIT(P)))) == 'K')
        {
            printf("Unit: King (%d,%d) | ", Idx(UnitLocation(InfoUNIT(P))), Clmn(UnitLocation(InfoUNIT(P))));
        }
        else if (OccPetak(Map, Idx(UnitLocation(InfoUNIT(P))), Clmn(UnitLocation(InfoUNIT(P)))) == 'A')
        {
            printf("Unit: Archer (%d,%d) | ", Idx(UnitLocation(InfoUNIT(P))), Clmn(UnitLocation(InfoUNIT(P))));
        }
        else if (OccPetak(Map, Idx(UnitLocation(InfoUNIT(P))), Clmn(UnitLocation(InfoUNIT(P)))) == 'S')
        {
            printf("Unit: Swordsman (%d,%d) | ", Idx(UnitLocation(InfoUNIT(P))), Clmn(UnitLocation(InfoUNIT(P))));
        } else if (OccPetak(Map, Idx(UnitLocation(InfoUNIT(P))), Clmn(UnitLocation(InfoUNIT(P)))) == 'W') {
          printf("Unit : White Mage (%d,%d) | ", Idx(UnitLocation(InfoUNIT(P))), Clmn(UnitLocation(InfoUNIT(P))));
        }
        printf("Health %d/%d | ", Health(InfoUNIT(P)), MaxHealth(InfoUNIT(P)));
        printf("Movement Point: %d | ", MovePoint(InfoUNIT(P)));
        if (AtkOpp(InfoUNIT(P)))
        {
            printf("Can Attack: Yes\n");
        }
        else
        {
            printf("Can Attack: No\n");
        }
    }
    else if (X==2)
    {
        Player P2 = InfoPLAYER(NextPLAYER(FirstPLAYER(L)));
        P=FirstUNIT(Units(P2));
        while (!(EQPOINT(UnitLocation(InfoUNIT(P)),CL)))
        {
            P=NextUNIT(P);
        }
        printf("Player 2's Turn\n");
        printf("Cash: %dG | ", Gold(P2));
        printf("Income: %dG | ", Income(P2));
        printf("Upkeep: %dG |\n", Upkeep(P2));
        if (OccPetak(Map, Idx(UnitLocation(InfoUNIT(P))), Clmn(UnitLocation(InfoUNIT(P)))) == 'K')
        {
            printf("Unit: King (%d,%d) | ", Idx(UnitLocation(InfoUNIT(P))), Clmn(UnitLocation(InfoUNIT(P))));
        }
        else if (OccPetak(Map, Idx(UnitLocation(InfoUNIT(P))), Clmn(UnitLocation(InfoUNIT(P)))) == 'A')
        {
            printf("Unit: Archer (%d,%d) | ", Idx(UnitLocation(InfoUNIT(P))), Clmn(UnitLocation(InfoUNIT(P))));
        }
        else if (OccPetak(Map, Idx(UnitLocation(InfoUNIT(P))), Clmn(UnitLocation(InfoUNIT(P)))) == 'S')
        {
            printf("Unit: Swordsman (%d,%d) | ", Idx(UnitLocation(InfoUNIT(P))), Clmn(UnitLocation(InfoUNIT(P))));
        } else if (OccPetak(Map, Idx(UnitLocation(InfoUNIT(P))), Clmn(UnitLocation(InfoUNIT(P)))) == 'W') {
          printf("Unit : White Mage (%d,%d) | ", Idx(UnitLocation(InfoUNIT(P))), Clmn(UnitLocation(InfoUNIT(P))));
        }
        printf("Health %d/%d | ", Health(InfoUNIT(P)), MaxHealth(InfoUNIT(P)));
        printf("Movement Point: %d | ", MovePoint(InfoUNIT(P)));
        if (AtkOpp(InfoUNIT(P)))
        {
            printf("Can Attack: Yes\n");
        }
        else
        {
            printf("Can Attack: No\n");
        }
    }
}

int main(){
  printf("\n");
  printf(" 888888ba             dP     dP   dP             .8888b                    \n");
  printf(" 88    `8b            88     88   88             88                        \n");
  printf(" 88aaaa8P  .d8888b. d8888P d8888P 88 .d8888b.    88aaa  .d8888b. 88d888b.  \n");
  printf(" 88   `8b. 88'  `88   88     88   88 88ooood8    88     88'  `88 88'  `88  \n");
  printf(" 88    .88 88.  .88   88     88   88 88.  ...    88     88.  .88 88        \n");
  printf(" 88888888P `88888P8   dP     dP   dP `88888P'    dP     `88888P' dP        \n");
  printf("ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n");
  printf("                                                                           \n");
  printf("         .88888.  dP                               oo                      \n");
  printf("        d8'   `8b 88                                                       \n");
  printf("        88     88 88 dP    dP 88d8b.d8b.  88d888b. dP .d8888b.             \n");
  printf("        88     88 88 88    88 88'`88'`88  88'  `88 88 88'  `88             \n");
  printf("        Y8.   .8P 88 88.  .88 88  88  88  88.  .88 88 88.  .88             \n");
  printf("         `8888P   dP `8888P88 dP  dP  dP  88Y888P  dP `88888P8             \n");
  printf("oooooooooooooooooooooo~~~~~88ooooooooooooo88ooooooooooooooooooooooooooooooo\n");
  printf("                      d8888P              dP                               \n");

    int nb, nk, pil;
    char input[100];
    MATRIKS Map;
    POINT CurrentLocation;
    addressUNIT CurrentAddress;
    ListPLAYER ListP;
    QueuePLAYER QueueP;
    int Turn;
    boolean KingAlive = true;
    StackMOVE MS;
    Kata mv, ud, cu, rc, at, mp, in, et, sv, ex, nu;

    /* INISIASI-INISIASI KATA-KATA COMMAND */
    mv.Length = 4;
    mv.TabKata[1] = 'M';
    mv.TabKata[2] = 'O';
    mv.TabKata[3] = 'V';
    mv.TabKata[4] = 'E';

    ud.Length = 4;
    ud.TabKata[1] = 'U';
    ud.TabKata[2] = 'N';
    ud.TabKata[3] = 'D';
    ud.TabKata[4] = 'O';

    cu.Length = 11;
    cu.TabKata[1] = 'C';
    cu.TabKata[2] = 'H';
    cu.TabKata[3] = 'A';
    cu.TabKata[4] = 'N';
    cu.TabKata[5] = 'G';
    cu.TabKata[6] = 'E';
    cu.TabKata[7] = '_';
    cu.TabKata[8] = 'U';
    cu.TabKata[9] = 'N';
    cu.TabKata[10] = 'I';
    cu.TabKata[11] = 'T';

    nu.Length = 9;
    nu.TabKata[1] = 'N';
    nu.TabKata[2] = 'E';
    nu.TabKata[3] = 'X';
    nu.TabKata[4] = 'T';
    nu.TabKata[5] = '_';
    nu.TabKata[6] = 'U';
    nu.TabKata[7] = 'N';
    nu.TabKata[8] = 'I';
    nu.TabKata[9] = 'T';

    rc.Length = 7;
    rc.TabKata[1] = 'R';
    rc.TabKata[2] = 'E';
    rc.TabKata[3] = 'C';
    rc.TabKata[4] = 'R';
    rc.TabKata[5] = 'U';
    rc.TabKata[6] = 'I';
    rc.TabKata[7] = 'T';

    at.Length = 6;
    at.TabKata[1] = 'A';
    at.TabKata[2] = 'T';
    at.TabKata[3] = 'T';
    at.TabKata[4] = 'A';
    at.TabKata[5] = 'C';
    at.TabKata[6] = 'K';

    mp.Length = 3;
    mp.TabKata[1] = 'M';
    mp.TabKata[2] = 'A';
    mp.TabKata[3] = 'P';

    in.Length = 4;
    in.TabKata[1] = 'I';
    in.TabKata[2] = 'N';
    in.TabKata[3] = 'F';
    in.TabKata[4] = 'O';

    et.Length = 8;
    et.TabKata[1] = 'E';
    et.TabKata[2] = 'N';
    et.TabKata[3] = 'D';
    et.TabKata[4] = '_';
    et.TabKata[5] = 'T';
    et.TabKata[6] = 'U';
    et.TabKata[7] = 'R';
    et.TabKata[8] = 'N';

    sv.Length = 4;
    sv.TabKata[1] = 'S';
    sv.TabKata[2] = 'A';
    sv.TabKata[3] = 'V';
    sv.TabKata[4] = 'E';

    ex.Length = 4;
    ex.TabKata[1] = 'E';
    ex.TabKata[2] = 'X';
    ex.TabKata[3] = 'I';
    ex.TabKata[4] = 'T';

    printf("Please pick :\n");
    printf("1. Start Battle for Olympia\n");
    printf("2. Load previous save file\n");
    printf("3. How to play Battle for Olympia\n");
    printf("Your Input : ");
    scanf("%d", &pil);

    while (pil != 1)
    {
        if (pil == 2) // Jika pilihan yang dipilih adalah load game
        {
            printf("\nSorry, this service hasn't been ready to be used yet!\n\n");
        }
        else if (pil == 3) { // Jika pilihan yang dipilih adalah cara bermain
          printf("How to play Battle for Olympia\n\n");
          printf("The goal is simple, kill the enemy King!\n");
          printf("Each game, both player will be assigned a tower and some castles that will spawn at the edge of the map.\n");
          printf("There will also be a bunch of villages randomly scattered around the map.\n");
          printf("Map size will be determined before each match, with the minimum size of 8x8 tiles.\n");
          printf("Player 1 is displayed at the buttom left of the map, with RED as their color.\n");
          printf("Player 2 is displayed at the top right of the map, with BLUE as their color.\n");
          printf("Any unit that is currently selected will be highlighted GREEN for your convenience.\n");
          printf("Each turn, a player can decide to do the following commands : \n");
          printf("MAP.         -- Display the current state of the map.\n");
          printf("MOVE.        -- Move a selected unit to a desired location.\n");
          printf("UNDO.        -- Go back to a previous location before MOVE. command.\n");
          printf("RECRUIT.     -- Summon a unit in your castle from your tower.\n");
          printf("CHANGE_UNIT. -- Change to a specific unit.\n");
          printf("NEXT_UNIT.   -- Change to the next available unit.\n");
          printf("INFO.        -- Display information about a specific tile.\n");
          printf("ATTACK.      -- Attack an enemy next to your current unit.\n");
          printf("SAVE.        -- Save the current state of the game to an external file.\n");
          printf("END_TURN     -- End your turn.\n");
          printf("EXIT.        -- End your game and exit the program.\n");
          printf("Mind you, you have to input these EXACT inputs to play our game.\n");
          printf("Be especially careful to put a '.' at the end of every command, or face the consequences!\n");
          printf("Those consequences mainly being crashing the game completely and losing your whole progress.\n");
          printf("Trust us, we know more than anybody that putting a '.'' after every command is easily missed!\n");
          printf("Anyhow, there are still a LOT of hidden mechanics that we wont tell you!\n");
          printf("We hope that you will discover them as you play through the game.\n");
          printf("\nEnjoy the game!\n\n");
        }

        printf("Please pick :\n");
        printf("1. Start Battle for Olympia\n");
        printf("2. Load previous save file\n");
        printf("3. How to play Battle for Olympia\n");
        printf("Your Input : ");
        scanf("%d", &pil);
    }

    if (pil == 1) // inputan pilihan memulai game
    {
        printf("\n\nGAME START!\n\n");
        bacamap(&nb,&nk,&Map); // Membaca besar peta, dan membentuk peta tersebut sesuai dengan baris dan kolom inputan
        InitNewGame(&ListP, &QueueP, Map, &MS); // Menginisiasi info-info yang akan digunakan dalam permainan


        while(KingAlive) { // Permainan akan terus berjalan selama King dari kedua player masi hidup
            DelQPLAYER(&QueueP, &Turn); // Mengambil player yang sedang dalam gilirannya
            if(Turn == 1) { // Jika giliran player 1, maka akan diambil info-info permainan dari list player satu
              InitNewTurn(&(InfoPLAYER(FirstPLAYER(ListP))), &CurrentLocation, &CurrentAddress, &MS, Map);
            } else { // Jika giliran player 2, maka akan diambil info-info permainan dari list player dua
              InitNewTurn(&(InfoPLAYER(NextPLAYER(FirstPLAYER(ListP)))), &CurrentLocation, &CurrentAddress, &MS, Map);
            }
            printmap(Map,CurrentLocation); // Menampilkan peta beserta isi-isinya ke layar
            PrintState(ListP, Map,Turn, CurrentLocation); // menampilkan status-status dan info-info player

            printf("Your command : ");
            STARTKATA(); // MENGINPUT COMMAND YANG DIINGINKAN

            while (!IsKataSama(CKata, et) && !IsKataSama(CKata,ex) && KingAlive)
            /*  Input command tidak akan berhenti sampai pemain memasukkan END_TURN. , EXIT., dan selama King
                masi hidup */
            {
                if (IsKataSama(CKata, mv))
                /* Jika Command yang diinput adalah MOVE. */
                {
                  printf("\n");
                    MoveUNDO(&Map, &ListP, &InfoUNIT(CurrentAddress), &CurrentLocation,&MS,true);
                    /* Melakukan void move dan memasukkan pergerakan ke dalam StackMOVE */
                    if(TypePetak(Map,Idx(CurrentLocation),Clmn(CurrentLocation)) == 'V') {
                      /*  Jika Unit berjalan ke salah satu VILLAGE, maka unit tidak bisa melakukan
                          UNDO, sehingga StackMOVE harus dikosongkan */
                      CreateEmptySTACK(&MS);
                    }
                    if(Turn == 1) {
                      /* Jika player 1 maka akan mengalkulasi Income player 1 */
                      CalcIncome(&InfoPLAYER(FirstPLAYER(ListP)));
                    } else {
                      /* Jika player 2 maka akan mengalkulasi Income player 2 */
                      CalcIncome(&InfoPLAYER(NextPLAYER(FirstPLAYER(ListP))));
                    }
                }
                else if (IsKataSama(CKata,ud))
                /* Jika Command yang diinput adalah UNDO. */
                {
                    MoveUNDO(&Map, &ListP, &InfoUNIT(CurrentAddress), &CurrentLocation,&MS,false);
                    /* Melakukan void UNDO */
                }
                else if (IsKataSama(CKata,cu))
                /* Jika Command yang diinput adalah CHANGE_UNIT. */
                {
                    ChangeUnit(ListP,Map, &CurrentLocation,&CurrentAddress,Turn);
                    CreateEmptySTACK(&MS);
                    /*  Melakukan void ChangeUnit dan akan menghapus isi StackMOVE karena jika
                        unit melakukan change unit maka unit tersebut tidak bisa melakukan UNDO */
                }
                else if (IsKataSama(CKata,nu))
                /* Jika Command yang diinput adalah NEXT_UNIT. */
                {
                    NextofUnit(ListP, Map, &CurrentLocation, &CurrentAddress, Turn);
                    CreateEmptySTACK(&MS);
                    /*  Melakukan void NextofUnit dan akan menghapus isi StackMOVE karena Jika
                        unit melakukan next unit maka unit tersebut tidak bisa melakukan UNDO */
                }
                else if (IsKataSama(CKata, rc))
                /* Jika Command yang diinput adalah RECRUIT. */
                {
                  printf("\n");
                  CreateEmptySTACK(&MS); // Mengosongkan StackMOVE karena tidak boleh UNDO
                  printmap(Map,CurrentLocation); // Menampilkan map agar tahu dimana koordinat Castle
                  RecruitCommand(&Map,&ListP,Turn,CurrentLocation); //Melakukan void RecruitCommand
                  if(Turn == 1) {
                    /* Jika player 1, maka akan mengalkulasi UpKeep player 1 */
                    CalcUpkeep(&InfoPLAYER(FirstPLAYER(ListP)));
                  } else {
                    /* Jika player 2, maka akan mengalkulasi UpKeep player 2 */
                    CalcUpkeep(&InfoPLAYER(NextPLAYER(FirstPLAYER(ListP))));
                  }
                }
                else if (IsKataSama(CKata, at))
                /* Jika Command yang diinput adalah ATTACK. */
                {
                  CreateEmptySTACK(&MS); // Mengosongkan StackMOVE karena tidak boleh UNDO
                  if(AtkOpp(InfoUNIT(CurrentAddress))) {
                    /* Jika unit memiliki Attack Opportunity, maka unit bisa menyerang */
                    AttackUnit(&Map,&CurrentAddress,&ListP,&KingAlive);
                  } else {
                    /* Jika unit tidak memiliki Attack Opportunity */
                    printf("Your ");
                    if(TypePetak(Map,Idx(CurrentLocation),Clmn(CurrentLocation)) == 'K') {
                      printf("King cannot attack this turn!\n");
                    } else if(TypePetak(Map,Idx(CurrentLocation),Clmn(CurrentLocation)) == 'A') {
                      printf("Archer cannot attack this turn!\n");
                    } else {
                      printf("Swordsman cannot attack this turn!\n");
                    }
                  }
                }
                else if (IsKataSama(CKata, mp))
                /* Jika Command yang diinput adalah MAP. */
                {
                    printmap(Map,CurrentLocation);
                }
                else if (IsKataSama(CKata, in))
                /* Jika Command yang diinput adalah INFO. */
                {
                    InfoCommand(Map,ListP);
                }
                else if (IsKataSama(CKata, sv))
                /* Jika Command yang diinput adalah SAVE. */
                {
                  CreateEmptySTACK(&MS);
                  printf("\nSorry, this service hasn't been ready to be used yet!\n\n");
                }
                else // Jika inputan COMMAND tidak terdaftar
                {
                    printf("\nYour input is invalid, please try again.\n\n");
                }

                if(KingAlive) {
                  /*  Menampilkan state setelah melakukan aksi, dan meminta inputan
                      command lagi */
                  PrintState(ListP, Map, Turn, CurrentLocation);

                  printf("Your command : ");
                  CreateKataEmpty();
                  STARTKATA();
                }
            }

            if (IsKataSama(CKata,ex))
            /* Jika Command yang diinput adalah EXIT. */
            /* akan mendealokasikan semua data dalam permainan */
            {
              addressPLAYER EndP;
              printf("\nExit command detected!\n\nGame Over!\n\n");
              DelLastPLAYER(&ListP, &EndP);
              DealokasiPLAYER(EndP);
              DelLastPLAYER(&ListP, &EndP);
              DealokasiPLAYER(EndP);
              exit(0);
            }

            if (!KingAlive)
            /*  Jika salah satu KING mati maka player tersebut kalah depan
                permainan akan berhenti */
            {
              addressPLAYER EndP;
              printf("\nA king has fallen!\n\nGame Over!\n\n");
              DelLastPLAYER(&ListP, &EndP);
              DealokasiPLAYER(EndP);
              DelLastPLAYER(&ListP, &EndP);
              DealokasiPLAYER(EndP);
              exit(0);
            }

            if (IsKataSama(CKata,et)) {
              /* Jika Command yang diinput adalah END_TURN. */
              printf("\nYour turn is over!\n\n");
              AddQPLAYER(&QueueP, Turn);
              CreateKataEmpty();
            }
        }
    }

    return 0;
}
