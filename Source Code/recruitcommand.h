#include "listPLAYER.h"
#include "queuePLAYER.h"
#include "matriks.h"
#include "listUNIT.h"

boolean IsTypeCastle1 (POINT input, MATRIKS Map);
/*Mengirimkan true jika koordinat input berisi bangunan Castle milik Player 1*/

boolean IsTypeCastle2 (POINT input, MATRIKS Map);
/*Mengirimkan true jika koordinat input berisi bangunan Castle milik Player 2*/

void RecruitCommand (MATRIKS *Map, ListPLAYER *L, int Turn,POINT CurrentLocation);
/*Melakukan perekrutan unit*/
/* yang dapat melakukan rekrut hanya KING, dan KING harus berada di tower */
