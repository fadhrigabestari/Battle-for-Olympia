#include "listPLAYER.h"
#include "queuePLAYER.h"
#include "matriks.h"
#include "listUNIT.h"

#ifndef CHANGEUNIT_H
#define CHANGEUNIT_H

void WriteListUnit(ListPLAYER L, MATRIKS Map, int Turn);
/* Menampilkan unit-unit yang dimiliki seorang player */

void ChangeUnit(ListPLAYER L, MATRIKS Map, POINT *CurrentLocation, addressUNIT *CurrentAddress, int Turn);
/* X adalah hasil pembuangan queue untuk menentukan giliran P1/P2 */
/* CL adalah current location */
/* Merubah current unit */

void NextofUnit(ListPLAYER L, MATRIKS Map, POINT *CurrentLocation, addressUNIT *CurrentAddress, int Turn);
/* Mengganti giliran unit menjadi unit selanjutnya (urutan berasal dari list) */

#endif
