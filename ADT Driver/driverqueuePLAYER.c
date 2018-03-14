#include "queuePLAYER.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	QueuePLAYER Q;
	int Max;
	int P1,P2,X,N;

	printf("Masukkan nilai max queue: ");
	scanf("%d",&Max);
	CreateEmptyQPLAYER (&Q, Max);
	if (IsEmptyQPLAYER(Q)) 
	{
		printf("List Kosong\n");
	}
	else
	{
		printf("List tidak kosong\n");
	}
	printf("Masukkan identitas player 1: ");
	scanf("%d",&P1);
	printf("Masukkan identitas player 2: ");
	scanf("%d",&P2);
	AddQPLAYER(&Q,P1);
	AddQPLAYER(&Q,P2);

	if (IsFullQPLAYER(Q))
	{
		printf("Q suda penuh!\n");
	}
	else
	{
		printf("Q belum penuh!\n");
	}

	DelQPLAYER(&Q, &X);
	printf("Data yg dihapus: ");
	printf("%d\n", X);

	printf("Info head: %d\n", InfoHeadQPLAYER(Q));
	printf("InfoTailQPLAYER : %d\n", InfoTailQPLAYER(Q));

	printf("Jumlah elemen queue sekarang: ");
	printf("%d\n", NBElmtQPLAYER(Q));

}