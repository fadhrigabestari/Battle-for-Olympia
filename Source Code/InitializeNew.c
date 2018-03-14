#include "InitializeNew.h"
#include "stdio.h"

void CalcGold(Player *P) {
  Gold(*P) = Gold(*P) + Income(*P) - Upkeep(*P);
}

void CalcIncome(Player *P) {
  ListVILLAGE VP = Villages(*P);
  Income(*P) = NbVILLAGE(VP) * 3; //Starting income being 0
}

void CalcUpkeep(Player *P) {
  ListUNIT LP = Units(*P);
  Upkeep(*P) = NbUNIT(LP) - 1; //Starting upkeep being 0
}

void InitNewGame(ListPLAYER *LP, QueuePLAYER *Q, MATRIKS M,StackMOVE *MS) {
  /* Create queue turn */
  CreateEmptyQPLAYER(Q,2);
  AddQPLAYER(Q,1); //Becomes head
  AddQPLAYER(Q,2); //Becomes tail
  /* ** ************************ ** */
  CreateEmptyPLAYER(LP);
  Player P1,P2;

  Unit King, KSTAT;
  STARTKATAKING();
  MaxHealth(KSTAT) = (CKata.TabKata[1] - '0') * 100 + (CKata.TabKata[2] - '0') * 10 + (CKata.TabKata[3] - '0');
  ADVKATAFILE();
  Attack(KSTAT) = (CKata.TabKata[1] - '0') * 10 + (CKata.TabKata[2] - '0');
  ADVKATAFILE();
  MaxMovePoint(KSTAT) = (CKata.TabKata[1] - '0');
  ADVKATAFILE();
  AttackType(KSTAT) = CKata.TabKata[1];
  ADVKATAFILE();
  Price(KSTAT) = (CKata.TabKata[1] - '0') * 10 + (CKata.TabKata[2] - '0');
  ADVKATAFILE();
  //ReadKingStat(King); Read from file external
  King = KSTAT;
  Health(King) = MaxHealth(King);

  /* Initialize P1 */
  Gold(P1) = 50; //Starting gold
  Income(P1) = 0;
  Upkeep(P1) = 0;
  CreateEmptyUNIT(&Units(P1));
  CreateEmptyVILLAGE(&Villages(P1));
  /* Initialize Unit P1 */
  InsVLastUNIT(&(Units(P1)),King); //Starting unit being king only
  UnitLocation(InfoUNIT(FirstUNIT(Units(P1)))) = Coordinate(M,NBrsEff(M) - 2,1);
  //List of village owned is empty

  /* Initialize Move Stack */
  CreateEmptySTACK(MS);

  /* Initialize P2 */
  Gold(P2) = 50; //Starting gold
  Income(P2) = 0;
  Upkeep(P2) = 0;
  CreateEmptyUNIT(&Units(P2));
  CreateEmptyVILLAGE(&Villages(P2));
  /* Initialize Unit P2 */
  InsVLastUNIT(&(Units(P2)),King); //Starting unit being king only
  UnitLocation(InfoUNIT(FirstUNIT(Units(P2)))) = Coordinate(M,1,NKolEff(M) - 2);
  //List of village owned is empy

  InsVLastPLAYER(LP,P1);
  InsVLastPLAYER(LP,P2);
}

void InitNewTurn(Player *P, POINT *CurrentLocation, addressUNIT *CurrentAddress, StackMOVE *MS, MATRIKS Map) {
  addressUNIT A = FirstUNIT(Units(*P));

  *CurrentAddress = A;
  *CurrentLocation = UnitLocation(InfoUNIT(A));
  CalcIncome(P);
  CalcUpkeep(P);
  CalcGold(P);
  CreateEmptySTACK(MS);
  MovePoint(InfoUNIT(A)) = MaxMovePoint(InfoUNIT(A));
  AtkOpp(InfoUNIT(A)) = true;
  if(TypePetak(Map,Idx(UnitLocation(InfoUNIT(A))),Clmn(UnitLocation(InfoUNIT(A)))) == 'V') {
    Health(InfoUNIT(A)) += 10;
    if(Health(InfoUNIT(A)) >= MaxHealth(InfoUNIT(A))) {
      Health(InfoUNIT(A)) = MaxHealth(InfoUNIT(A));
    }
  }
  if(OccPetak(Map,Idx(UnitLocation(InfoUNIT(A))) + 1,Clmn(UnitLocation(InfoUNIT(A)))) == 'W') {
    Health(InfoUNIT(A)) += 10;
    if(Health(InfoUNIT(A)) >= MaxHealth(InfoUNIT(A))) {
      Health(InfoUNIT(A)) = MaxHealth(InfoUNIT(A));
    }
  }
  if(OccPetak(Map,Idx(UnitLocation(InfoUNIT(A))) - 1,Clmn(UnitLocation(InfoUNIT(A)))) == 'W') {
    Health(InfoUNIT(A)) += 10;
    if(Health(InfoUNIT(A)) >= MaxHealth(InfoUNIT(A))) {
      Health(InfoUNIT(A)) = MaxHealth(InfoUNIT(A));
    }
  }
  if(OccPetak(Map,Idx(UnitLocation(InfoUNIT(A))),Clmn(UnitLocation(InfoUNIT(A))) + 1) == 'W') {
    Health(InfoUNIT(A)) += 10;
    if(Health(InfoUNIT(A)) >= MaxHealth(InfoUNIT(A))) {
      Health(InfoUNIT(A)) = MaxHealth(InfoUNIT(A));
    }
  }
  if(OccPetak(Map,Idx(UnitLocation(InfoUNIT(A))),Clmn(UnitLocation(InfoUNIT(A))) - 1) == 'W') {
    Health(InfoUNIT(A)) += 10;
    if(Health(InfoUNIT(A)) >= MaxHealth(InfoUNIT(A))) {
      Health(InfoUNIT(A)) = MaxHealth(InfoUNIT(A));
    }
  }
  A = NextUNIT(A);
  while(A != FirstUNIT(Units(*P))) {
    MovePoint(InfoUNIT(A)) = MaxMovePoint(InfoUNIT(A));
    AtkOpp(InfoUNIT(A)) = true;
    if(TypePetak(Map,Idx(UnitLocation(InfoUNIT(A))),Clmn(UnitLocation(InfoUNIT(A)))) == 'V') {
      Health(InfoUNIT(A)) += 10;
      if(Health(InfoUNIT(A)) >= MaxHealth(InfoUNIT(A))) {
        Health(InfoUNIT(A)) = MaxHealth(InfoUNIT(A));
      }
    }
    if(OccPetak(Map,Idx(UnitLocation(InfoUNIT(A))) + 1,Clmn(UnitLocation(InfoUNIT(A)))) == 'W') {
      Health(InfoUNIT(A)) += 10;
      if(Health(InfoUNIT(A)) >= MaxHealth(InfoUNIT(A))) {
        Health(InfoUNIT(A)) = MaxHealth(InfoUNIT(A));
      }
    }
    if(OccPetak(Map,Idx(UnitLocation(InfoUNIT(A))) - 1,Clmn(UnitLocation(InfoUNIT(A)))) == 'W') {
      Health(InfoUNIT(A)) += 10;
      if(Health(InfoUNIT(A)) >= MaxHealth(InfoUNIT(A))) {
        Health(InfoUNIT(A)) = MaxHealth(InfoUNIT(A));
      }
    }
    if(OccPetak(Map,Idx(UnitLocation(InfoUNIT(A))),Clmn(UnitLocation(InfoUNIT(A))) + 1) == 'W') {
      Health(InfoUNIT(A)) += 10;
      if(Health(InfoUNIT(A)) >= MaxHealth(InfoUNIT(A))) {
        Health(InfoUNIT(A)) = MaxHealth(InfoUNIT(A));
      }
    }
    if(OccPetak(Map,Idx(UnitLocation(InfoUNIT(A))),Clmn(UnitLocation(InfoUNIT(A))) - 1) == 'W') {
      Health(InfoUNIT(A)) += 10;
      if(Health(InfoUNIT(A)) >= MaxHealth(InfoUNIT(A))) {
        Health(InfoUNIT(A)) = MaxHealth(InfoUNIT(A));
      }
    }
    A = NextUNIT(A);
  }
}
