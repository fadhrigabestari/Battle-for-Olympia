#include "matriks.h"
#include <stdio.h>
#include <stdlib.h>
#include "pcolor.h"
int main()
{
	int i,j, Brs,Kol;
	MATRIKS M;

	printf("Masukkan baris matriks: ");
	scanf("%d",&Brs);
	printf("Masukkan kolom matriks: ");
	scanf("%d",&Kol);

	/*menginisialisasi pembuatan matriks dengan indeks 
	baris dan kolom dari masukan pengguna*/
	MakeMATRIKS(Brs,Kol, &M);

	/* Membuat selektor Idx dan Clmn terhadap isi petak*/
	

	/* mencetak baris pertama dan baris terakhir*/
	printf("Baris pertama : %d\n", GetFirstIdxBrs(M));
	printf("Baris terakhir :%d\n", GetLastIdxBrs(M));
	printf("Kolom pertama : %d\n", GetFirstIdxKol(M));
	printf("Kolom terakhir :%d\n", GetLastIdxKol(M));
	

	/* Memasukan tipe petak secara manual dari masukan keyboard pengguna*/
	for (i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++)
		{ 
			for(j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++)
			{
				printf("Masukkan tipe petak (%d, %d): ", i,j);
				scanf(" %c",&TypePetak(M,i,j));
				OccPetak(M,i,j)=TypePetak(M,i,j);
				isiCoordinate(&M,Brs,Kol);
			}
		}

	/* status kepemilikan petak juga diinput oleh user*/
	for (i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++)
		{
			for(j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++)
			{
				if (IsBuilding(M,i,j))
				{
					printf("Masukkan own status petak (%d, %d): ", i,j);
					scanf("%d",&OwnBuildingPetak(M,i,j));
				}
				
				if (IsOcc(M,i,j))
				{
					printf("Masukkan unit petak (%d, %d): ", i,j);
					scanf("%d", &OwnUnitPetak(M,i,j));
				}
			}	
		}

	/*Mengecek suatu indeks dengan memasukan baris dan kolom*/
	printf("Masukkan indeks baris yang ingin diperiksa: ");
	scanf("%d",&i);
	printf("Masukkan indeks kolom yang ingin diperiksa: ");
	scanf("%d",&j);	


	/*Memeriksa kebenaran masukan pengguna yaitu jika valid masih
	kurang dari batas max dan masih berada di dalam matriks.*/
	if ((IsIdxValid(i,j))&&(IsIdxEff(M,i,j)))
	{
		printf("Masukkan valid\n");
		printf(" tipe petak (%d,%d) : %c\n", i,j, TypePetak(M,i,j));
		
		/*Jika valid maka di cek apakah building atau sudah occupied, algoritma akan 
		mencetak status kepemilikan petak*/
		if (IsBuilding(M,i,j))
			{
				printf("own status petak %d\n ",OwnBuildingPetak(M,i,j));
			}
			
		if (IsOcc(M,i,j))
		{
			printf("unit petak : %d\n", OwnUnitPetak(M,i,j));
		}

		/*memeriksa kerja IsiCoordinate dengan menampilkan idx dan clmn matriks*/
		printf(" Indeks baris dari petak: %d\n", Idx(Coordinate(M,i,j)));
		printf(" Indeks kolom dari petak: %d\n", Clmn(Coordinate(M,i,j)));
	}	
	else
	{
		printf("Masukkan tidak terdapat di matriks \n");
	}

}
