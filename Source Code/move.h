#include "matriks.h"
#include "stackt.h"
#include "listPLAYER.h"


#ifndef MOVE_H
#define MOVE_H

boolean IsAbleToMove(MATRIKS Map, infotypeUNIT U,POINT CurrentLocation, int i, int j);
/* memeriksa apakah coordinat tujuan bisa ditempati atau tidak */
boolean IsAbleToMoveTwo(MATRIKS Map, infotypeUNIT U, POINT CurrentLocation,int i,int j);
/* memeriksa apakah langkah kedua bisa ditempati atau tidak */

void TulisAbleMATRIKS (MATRIKS M, infotypeUNIT U, POINT CurrentLocation);
/* menampilkan map dengan tambahan pagar sebagai koordinat-koordiat yang dapat dijalani oleh unit */
void MoveUnit(MATRIKS *Map, ListPLAYER *L, infotypeUNIT *U,POINT *CurrentLocation);
/* memindahkan suatu unit ke koordinat inputan */

void MoveUNDO(MATRIKS *Map, ListPLAYER *L, infotypeUNIT *U,POINT *CurrentLocation,StackMOVE *SM,boolean isMOVE);
/* melakukan antara MOVE atau UNDO sesuai dengan inputan boolean isMOVE */

#endif
