//Nama      : Yuly Haruka Berliana Gunawan
//NIM       : 13516031
#include <stdlib.h>
#include "jam.h"
#include <stdio.h>
#include "boolean.h"


/* File : mjam.c */
/* Main Program Jam */

int main()
{
    /* KAMUS */
    JAM J1, J2, JMin , JMax;
    int i, n;
    long selisih, J3, J4;

    /* ALGORITMA */
    scanf("%d", &n);

    for (i=1;i<=n;i++)
    {
		printf("[%d]\n", i);
		BacaJAM(&J1);
		BacaJAM(&J2);

		if (JLT(J1,J2))
		{
			selisih = Durasi(J1,J2);
		}else
		{
			selisih = Durasi(J2,J1);
		}
		printf("%ld\n", selisih);

        if (i == 1) {
			JMin = (JLT(J1, J2)) ? J1 : J2;
			JMax = (JGT(J1, J2)) ? J1 : J2;
		} else /* N_i != 1 */ {
			if (JLT(J1,JMin)) { JMin  = J1; }
			if (JLT(J2,JMin)) { JMin  = J2; }

			if (JGT(J1,JMax)) { JMax  = J1; }
			if (JGT(J2,JMax)) { JMax  = J2; }
		}
	}
    TulisJAM(JMin); printf("\n");
	TulisJAM(JMax); printf("\n");
}
