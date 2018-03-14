#include "stackt.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	StackMOVE S;
	int i;
	infotypeSTACK X;

	CreateEmptySTACK(&S);
	if (IsEmptySTACK(S))
	{
		printf("STACK KOSONG!!!\n");
	}
	else
	{
		printf("STACK terisi\n");
	}

	Push(&S, MakePOINT(1,1));
	Push(&S, MakePOINT(2,2));
	Push(&S, MakePOINT(3,3));
	Push(&S, MakePOINT(4,4));
	Push(&S, MakePOINT(5,5));
	Push(&S, MakePOINT(6,6));
	Push(&S, MakePOINT(7,7));
	Push(&S, MakePOINT(8,8));
	Push(&S, MakePOINT(9,9));
	Push(&S, MakePOINT(10,10));

	if (IsFullSTACK(S))
	{
		printf("STACK PENUH\n");
	}
	else
	{
		printf("STACK TIDAK PENUH\n");
	}

	for (i=1;i<=10;i++)
	{
		Pop(&S,&X);
		TulisPOINT(X);
		printf("\n");
	}

}
