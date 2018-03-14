#include "attack.h"
#include <stdio.h>
#include <stdlib.h>

boolean isRetaliates (addressUNIT U1, addressUNIT U2)
/* 	Memeriksa apakah unit lawan dapat menyerang balik.
	U1 adalah unit yang menyerang, sedangkan U2 adalah
	unit yang ingin menyerang balik. Jika U2 adalah
	King maka isRetaliates pasti bernilai True */
{
	if (Price(InfoUNIT(U2)) == 0)
	{
		return true;
	}
	else
	{
		return (AttackType(InfoUNIT(U1)) == AttackType(InfoUNIT(U2)));
	}
}

boolean isBesideEnemy(MATRIKS Map, POINT CurrentLocation) 
/*	Memeriksa apakah di koordinat atas, kiri, kanan, dan bawah unit
	terdapat unit lain yang dimiliki oleh player lain */
{
	int i = Idx(CurrentLocation);
	int j = Clmn(CurrentLocation);
	boolean Up,Down,Left,Right;

	if(IsOcc(Map,i-1,j) && OwnUnitPetak(Map,i-1,j) != OwnUnitPetak(Map,i,j)) {
		Up = true;
	} else {
		Up = false;
	}
	if(IsOcc(Map,i+1,j) && OwnUnitPetak(Map,i+1,j) != OwnUnitPetak(Map,i,j)) {
		Down = true;
	} else {
		Down = false;
	}
	if(IsOcc(Map,i,j+1) && OwnUnitPetak(Map,i,j+1) != OwnUnitPetak(Map,i,j)) {
		Right = true;
	} else {
		Right = false;
	}
	if(IsOcc(Map,i,j-1) && OwnUnitPetak(Map,i,j-1) != OwnUnitPetak(Map,i,j)) {
		Left = true;
	} else {
		Left = false;
	}
	if (Up || Down || Right || Left) {
		return true;
	} else {
		return false;
	}
}
void AttackUnit(MATRIKS *Map, addressUNIT *U, ListPLAYER *L, boolean *KingAlive)
/*	Procedure untuk teknis penyerangan. */
{
	int i,j,N,select;
	int AttackChance, DefenseChance;
	addressUNIT target[4];
	POINT targetPOINT[4];
	int max;
	addressPLAYER P1,P2;
	boolean found = false;
	addressUNIT enemy;
	POINT enemyLOC;

	i = Idx(UnitLocation(InfoUNIT(*U)));
	j = Clmn(UnitLocation(InfoUNIT(*U)));

	if(!isBesideEnemy(*Map,UnitLocation(InfoUNIT(*U))))
	/* Jika tidak ada musuh di sekitar unit */
	{
		printf("\nThere are no enemies around you!\n\n");
	}
	else /* Jika ada */
	{
		N = 0;
		/* 	Mencari dimana saja terdapat musuh disekitar unit. Musuh-musuh di sekitar unit
		akan dimasukkan kedalam array AddressUnit */
		
		/* memeriksa bagian atas unit */
		if (IsOcc(*Map,i-1,j) && (OwnUnitPetak(*Map,i-1,j) != OwnUnitPetak(*Map,i,j)))
		{
			N++;
			POINT enemyPOINT = MakePOINT(i-1,j);
			if (OwnUnitPetak(*Map,i-1,j) == 1)
			{
				enemy = FirstUNIT(Units(InfoPLAYER(FirstPLAYER(*L))));

				while (NEQPOINT(UnitLocation(InfoUNIT(enemy)),enemyPOINT))
				{
					enemy = NextUNIT(enemy);
				}
			}
			else
			{
				enemy = FirstUNIT(Units(InfoPLAYER(NextPLAYER(FirstPLAYER(*L)))));

				while (NEQPOINT(UnitLocation(InfoUNIT(enemy)),enemyPOINT))
				{
					enemy = NextUNIT(enemy);
				}
			}

			target[N] = enemy;
			targetPOINT[N] = MakePOINT(i-1,j);
		}

		/* memeriksa bagian bawah unit */
		if (IsOcc(*Map,i+1,j) && (OwnUnitPetak(*Map,i+1,j) != OwnUnitPetak(*Map,i,j)))
		{
			N++;
			POINT enemyPOINT = MakePOINT(i+1,j);
			if (OwnUnitPetak(*Map,i+1,j) == 1)
			{
				enemy = FirstUNIT(Units(InfoPLAYER(FirstPLAYER(*L))));

				while (NEQPOINT(UnitLocation(InfoUNIT(enemy)),enemyPOINT))
				{
					enemy = NextUNIT(enemy);
				}
			}
			else
			{
				enemy = FirstUNIT(Units(InfoPLAYER(NextPLAYER(FirstPLAYER(*L)))));

				while (NEQPOINT(UnitLocation(InfoUNIT(enemy)),enemyPOINT))
				{
					enemy = NextUNIT(enemy);
				}
			}

			target[N] = enemy;
			targetPOINT[N] = MakePOINT(i+1,j);
		}

		/* memeriksa bagian kanan unit */
		if (IsOcc(*Map,i,j+1) && (OwnUnitPetak(*Map,i,j+1) != OwnUnitPetak(*Map,i,j)))
		{
			N++;
			POINT enemyPOINT = MakePOINT(i,j+1);
			if (OwnUnitPetak(*Map,i,j+1) == 1)
			{
				enemy = FirstUNIT(Units(InfoPLAYER(FirstPLAYER(*L))));

				while (NEQPOINT(UnitLocation(InfoUNIT(enemy)),enemyPOINT))
				{
					enemy = NextUNIT(enemy);
				}
			}
			else
			{
				enemy = FirstUNIT(Units(InfoPLAYER(NextPLAYER(FirstPLAYER(*L)))));

				while (NEQPOINT(UnitLocation(InfoUNIT(enemy)),enemyPOINT))
				{
					enemy = NextUNIT(enemy);
				}
			}

			target[N] = enemy;
			targetPOINT[N] = MakePOINT(i,j+1);
		}

		/* memeriksa bagian kiri unit */
		if (IsOcc(*Map,i,j-1) && (OwnUnitPetak(*Map,i,j-1) != OwnUnitPetak(*Map,i,j)))
		{
			N++;
			POINT enemyPOINT = MakePOINT(i,j-1);
			if (OwnUnitPetak(*Map,i,j-1) == 1)
			{
				enemy = FirstUNIT(Units(InfoPLAYER(FirstPLAYER(*L))));

				while (NEQPOINT(UnitLocation(InfoUNIT(enemy)),enemyPOINT))
				{
					enemy = NextUNIT(enemy);
				}
			}
			else
			{
				enemy = FirstUNIT(Units(InfoPLAYER(NextPLAYER(FirstPLAYER(*L)))));

				while (NEQPOINT(UnitLocation(InfoUNIT(enemy)),enemyPOINT))
				{
					enemy = NextUNIT(enemy);
				}
			}

			target[N] = enemy;
			targetPOINT[N] = MakePOINT(i,j-1);
		}


		/* Menampilkan musuh-musuh yang dapat diserang di sekitar unit */
		printf("\nList of enemy you can attack : \n");
		for (int k = 1; k <= N; k++)
		{
			printf("%d. ",k);
			if (OccPetak(*Map,Idx(UnitLocation(InfoUNIT(target[k]))),Clmn(UnitLocation(InfoUNIT(target[k])))) == 'K')
			{
				printf("King ");
			}
			else if (OccPetak(*Map,Idx(UnitLocation(InfoUNIT(target[k]))),Clmn(UnitLocation(InfoUNIT(target[k])))) == 'A')
			{
				printf("Archer ");
			}
			else if (OccPetak(*Map,Idx(UnitLocation(InfoUNIT(target[k]))),Clmn(UnitLocation(InfoUNIT(target[k])))) == 'S')
			{
				printf("Swordsman ");
			} else if (OccPetak(*Map,Idx(UnitLocation(InfoUNIT(target[k]))),Clmn(UnitLocation(InfoUNIT(target[k])))) == 'W') {
				printf("White Mage ");
			}

			printf("(%d,%d) | ", Idx(UnitLocation(InfoUNIT(target[k]))), Clmn(UnitLocation(InfoUNIT(target[k]))));
			printf("Health %d/%d ", Health(InfoUNIT(target[k])), MaxHealth(InfoUNIT(target[k])));

			if (isRetaliates(*U,target[k]))
			{
				printf("(Retaliates)");
			}

			printf("\n");
		}

		/* Pengguna memilih ingin menyerang unit yang mana */
		printf("\nSelect enemy you want to attack : ");
		do
		{
			scanf("%d", &select);

			if ((select < 0) || (select > N))
			{
				printf("Your input is invalid. Please try again.");
			}
		} while ((select < 0) || (select > N));


		MovePoint(InfoUNIT(*U)) = 0; /* Jika menyerang, maka unit tidak bisa melakukan command MOVE. lagi */
		AtkOpp(InfoUNIT(*U)) = false; /* Jika menyerang, maka unit tidak bisa melakukan command ATTACK. lagi */

		/* 	UNTUK MENYERANG, UNIT YANG MENYERANG MENDAPAT ANGKA RANDOM DARI 1-20, DAN UNIT DISERANG MENDAPAT ANGKA RANDOM 1-10.
			JIKA ANGKA YANG DIDAPAT UNIT MENYERANG LEBIH BESAR SAMA DENGAN ANGKA YANG DIDAPAT UNIT DISERANG, MAKA AKSI
			PENYERANGAN BERHASIL */
		if ((AttackChance = rand() % 21) >= (DefenseChance = rand() % 11))
		{
			printf("Enemy's ");
			if (OccPetak(*Map,Idx(UnitLocation(InfoUNIT(target[select]))),Clmn(UnitLocation(InfoUNIT(target[select])))) == 'K')
			{
				printf("King ");
			}
			else if (OccPetak(*Map,Idx(UnitLocation(InfoUNIT(target[select]))),Clmn(UnitLocation(InfoUNIT(target[select])))) == 'A')
			{
				printf("Archer ");
			}
			else if (OccPetak(*Map,Idx(UnitLocation(InfoUNIT(target[select]))),Clmn(UnitLocation(InfoUNIT(target[select])))) == 'S')
			{
				printf("Swordsman ");
			} else if (OccPetak(*Map,Idx(UnitLocation(InfoUNIT(target[select]))),Clmn(UnitLocation(InfoUNIT(target[select])))) == 'W') {
				printf("White Mage ");
			}
			printf("is damaged by %d.\n", Attack(InfoUNIT(*U)));

			/* JIKA DARAH UNIT YANG DISERANG LEBIH SEDIKIT DARI KEKUATAN UNIT YANG MENYERANG, MAKA UNIT DISERANG AKAN MATI */
			if (Health(InfoUNIT(target[select])) <= Attack(InfoUNIT(*U)))
			{
				printf("Enemy's ");
				if (OccPetak(*Map,Idx(UnitLocation(InfoUNIT(target[select]))),Clmn(UnitLocation(InfoUNIT(target[select])))) == 'K')
				{
					printf("King ");
				}
				else if (OccPetak(*Map,Idx(UnitLocation(InfoUNIT(target[select]))),Clmn(UnitLocation(InfoUNIT(target[select])))) == 'A')
				{
					printf("Archer ");
				}
				else if (OccPetak(*Map,Idx(UnitLocation(InfoUNIT(target[select]))),Clmn(UnitLocation(InfoUNIT(target[select])))) == 'S')
				{
					printf("Swordsman ");
				} else if (OccPetak(*Map,Idx(UnitLocation(InfoUNIT(target[select]))),Clmn(UnitLocation(InfoUNIT(target[select])))) == 'W') {
					printf("White Mage ");
				}
				printf(" is dead!\n");

				if (OccPetak(*Map,Idx(UnitLocation(InfoUNIT(target[select]))),Clmn(UnitLocation(InfoUNIT(target[select])))) == 'K')
				{
					*KingAlive = false;
				}
				if (OwnUnitPetak(*Map,Idx(targetPOINT[select]), Clmn(targetPOINT[select])) == 1)
				{
					OwnUnitPetak(*Map,Idx(targetPOINT[select]), Clmn(targetPOINT[select])) = 0;
					OccPetak(*Map,Idx(targetPOINT[select]), Clmn(targetPOINT[select])) = ' ';
					DelPUNIT(&Units(InfoPLAYER(FirstPLAYER(*L))),InfoUNIT(target[select]));
				}
				else
				{
					OwnUnitPetak(*Map,Idx(targetPOINT[select]), Clmn(targetPOINT[select])) = 0;
					OccPetak(*Map,Idx(targetPOINT[select]), Clmn(targetPOINT[select])) = ' ';
					DelPUNIT(&Units(InfoPLAYER(NextPLAYER(FirstPLAYER(*L)))),InfoUNIT(target[select]));
				}
			}
			else
			{
				Health(InfoUNIT(target[select])) -= Attack(InfoUNIT(*U));
			}
		}
		/* 	JIKA ANGKA YANG DIDAPAT UNIT MENYERANG LEBIH KECIL DENGAN ANGKA YANG DIDAPAT UNIT DISERANG, MAKA AKSI
			PENYERANGAN GAGAL */
		else
		{
			printf("\nYou missed!\n");
		}

		/* AKSI MELAKUKAN SERANGAN BALIK */
		if (isRetaliates(*U, target[select]))
		{
			/* 	DALAM PENYERANGAN BALIK, UNIT MENYERANG DAN UNIT DISERANG JUGA MENDAPAT ANGKA RANDOM, TAPI INTERVAL ANGKA RANDOM UNIT
				MENYERANG DAN UNIT DISERANG SAMA BESAR, YAITU DARI 1-20. JIKA ANGKA YANG DIDAPAT UNIT MENYERANG LEBIH KECIL SAMA DENGAN,
				MAKA UNIT DISERANG DAPAT MELAKUKAN SERANGAN BALIK */
			if ((AttackChance = rand() % 21) <= (DefenseChance = rand() % 21))
			{
				printf("Enemy's ");
				if (OccPetak(*Map,Idx(UnitLocation(InfoUNIT(target[select]))),Clmn(UnitLocation(InfoUNIT(target[select])))) == 'K')
				{
					printf("King ");
				}
				else if (OccPetak(*Map,Idx(UnitLocation(InfoUNIT(target[select]))),Clmn(UnitLocation(InfoUNIT(target[select])))) == 'A')
				{
					printf("Archer ");
				}
				else if (OccPetak(*Map,Idx(UnitLocation(InfoUNIT(target[select]))),Clmn(UnitLocation(InfoUNIT(target[select])))) == 'S')
				{
					printf("Swordsman ");
				} else if (OccPetak(*Map,Idx(UnitLocation(InfoUNIT(target[select]))),Clmn(UnitLocation(InfoUNIT(target[select])))) == 'W') {
					printf("White Mage ");
				}
				printf("retaliates.\n");

				printf("Your ");
				if (OccPetak(*Map,Idx(UnitLocation(InfoUNIT(*U))),Clmn(UnitLocation(InfoUNIT(*U)))) == 'K')
				{
					printf("King ");
				}
				else if (OccPetak(*Map,Idx(UnitLocation(InfoUNIT(*U))),Clmn(UnitLocation(InfoUNIT(*U)))) == 'A')
				{
					printf("Archer ");
				}
				else if (OccPetak(*Map,Idx(UnitLocation(InfoUNIT(*U))),Clmn(UnitLocation(InfoUNIT(*U)))) == 'S')
				{
					printf("Swordsman ");
				} else if (OccPetak(*Map,Idx(UnitLocation(InfoUNIT(*U))),Clmn(UnitLocation(InfoUNIT(*U)))) == 'W') {
					printf("White Mage ");
				}
				printf("is damaged by %d.\n", (Attack(InfoUNIT(target[select]))));

				/* 	JIKA DARAH UNIT MENYERANG YANG AKAN DISERANG BALIK LEBIH SEDIKIT DARI KEKUATAN UNIT YANG MENYERANG BALIK, MAKA UNIT TERSEBUT
				 	AKAN MATI */
				if (Health(InfoUNIT(*U)) <= (Attack(InfoUNIT(target[select]))))
				{
					printf("Your ");
					if (OccPetak(*Map,Idx(UnitLocation(InfoUNIT(*U))),Clmn(UnitLocation(InfoUNIT(*U)))) == 'K')
					{
						printf("King ");
					}
					else if (OccPetak(*Map,Idx(UnitLocation(InfoUNIT(*U))),Clmn(UnitLocation(InfoUNIT(*U)))) == 'A')
					{
						printf("Archer ");
					}
					else if (OccPetak(*Map,Idx(UnitLocation(InfoUNIT(*U))),Clmn(UnitLocation(InfoUNIT(*U)))) == 'S')
					{
						printf("Swordsman ");
					} else if (OccPetak(*Map,Idx(UnitLocation(InfoUNIT(*U))),Clmn(UnitLocation(InfoUNIT(*U)))) == 'W') {
						printf("White Mage ");
					}
					printf(" is dead!\n");

					if(OccPetak(*Map,Idx(UnitLocation(InfoUNIT(*U))),Clmn(UnitLocation(InfoUNIT(*U)))) == 'K') {
						*KingAlive = false;
					}
					if (OwnUnitPetak(*Map,i,j) == 1)
					{
						OwnUnitPetak(*Map,Idx(UnitLocation(InfoUNIT(*U))), Clmn(UnitLocation(InfoUNIT(*U)))) = 0;
						OccPetak(*Map,Idx(UnitLocation(InfoUNIT(*U))), Clmn(UnitLocation(InfoUNIT(*U)))) = ' ';
						DelPUNIT(&Units(InfoPLAYER(FirstPLAYER(*L))),InfoUNIT(*U));
					}
					else
					{
						OwnUnitPetak(*Map,Idx(UnitLocation(InfoUNIT(*U))), Clmn(UnitLocation(InfoUNIT(*U)))) = 0;
						OccPetak(*Map,Idx(UnitLocation(InfoUNIT(*U))), Clmn(UnitLocation(InfoUNIT(*U)))) = ' ';
						DelPUNIT(&Units(InfoPLAYER(NextPLAYER(FirstPLAYER(*L)))),InfoUNIT(*U));
					}
				}
				else
				{
					Health(InfoUNIT(*U)) -= (Attack(InfoUNIT(target[select])));
				}
			}
			/* 	JIKA ANGKA YANG DIDAPAT UNIT MENYERANG LEBIH BESAR,
				MAKA UNIT DISERANG DAPAT MELAKUKAN SERANGAN BALIK */
			else
			{
				printf("Enemy's ");
				if (OccPetak(*Map,Idx(UnitLocation(InfoUNIT(target[select]))),Clmn(UnitLocation(InfoUNIT(target[select])))) == 'K')
				{
					printf("King ");
				}
				else if (OccPetak(*Map,Idx(UnitLocation(InfoUNIT(target[select]))),Clmn(UnitLocation(InfoUNIT(target[select])))) == 'A')
				{
					printf("Archer ");
				}
				else if (OccPetak(*Map,Idx(UnitLocation(InfoUNIT(target[select]))),Clmn(UnitLocation(InfoUNIT(target[select])))) == 'S')
				{
					printf("Swordsman ");
				} else if (OccPetak(*Map,Idx(UnitLocation(InfoUNIT(target[select]))),Clmn(UnitLocation(InfoUNIT(target[select])))) == 'W') {
					printf("White Mage ");
				}
				printf("tried to retaliate but he failed!\n");
			}
		}
	}
	printf("\n");
}
