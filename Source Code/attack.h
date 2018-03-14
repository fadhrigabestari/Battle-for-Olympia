#ifndef attack_H
#define attack_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "boolean.h"
#include "listPLAYER.h"
#include "listUNIT.h"
#include "point.h"
#include "matriks.h"

boolean isBesideEnemy(MATRIKS Map, POINT CurrentLocation);
/* 	Memeriksa apakah unit lawan dapat menyerang balik.
	U1 adalah unit yang menyerang, sedangkan U2 adalah
	unit yang ingin menyerang balik. Jika U2 adalah
	King maka isRetaliates pasti bernilai True */

boolean isRetaliates (addressUNIT U1, addressUNIT U2);
/*	Memeriksa apakah di koordinat atas, kiri, kanan, dan bawah unit
	terdapat unit lain yang dimiliki oleh player lain */

void AttackUnit(MATRIKS *Map, addressUNIT *U, ListPLAYER *L, boolean *KingAlive);
/*	Procedure untuk teknis penyerangan.
	Untuk penjelasan program ada di dalam attack.c */

#endif
