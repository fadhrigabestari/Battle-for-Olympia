#include "queuePLAYER.h"
#include "point.h"
#include "listPLAYER.h"
#include "mesinkata.h"
#include "mesinkar.h"
#include "matriks.h"
#include "stackt.h"

void CalcGold(Player *P);
/* Calculate amount of gold a player has each turn */

void CalcIncome(Player *P);
/* Calculate amount of income a player has each turn */

void CalcUpkeep(Player *P);
/* Calculate amount of upkeep a player has each turn */

void InitNewGame(ListPLAYER *LP, QueuePLAYER *Q, MATRIKS M,StackMOVE *MS);
/* Initialize list of player, list of queue, current location for a new game */
/* List of player consist of 2 players total */
/* Queue consist of player 1 as head of the queue, and player 2 as tail */
/* Current location being King of player 1 */

void InitNewTurn(Player *P, POINT *CurrentLocation, addressUNIT *CurrentAddress, StackMOVE *MS, MATRIKS Map);
/* Initialize for new turn */
/* Move point become max move point */
/* Attack opportunity becomes true */
/* Current location become *P's King */
