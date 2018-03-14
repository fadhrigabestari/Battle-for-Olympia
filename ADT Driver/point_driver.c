#include <stdio.h>
#include <math.h>
#include "boolean.h"
#include "point.h"

int main()
{
    /* KAMUS LOKAL */
    POINT P1, P2;
    float deltax, deltay;
    float sudut;
    boolean SbX;

    /*ALGORITMA*/
    printf("Masukan point 1 (x y)\n");
    BacaPOINT(&P1);
    TulisPOINT(P1);
    printf("Masukan point 2 (x y)\n");
    BacaPOINT(&P2);
    TulisPOINT(P2);

    if (EQ(P1,P2))
    {
     printf("Sama\n");
    }
    if (NEQ(P1,P2))
    {
        printf("Tidak sama\n");
    }


    if ((!IsOrigin(P1)) && (!IsOnSbX(P1)) && (!IsOnSbY(P1)))
    {
        printf("P1 ada di kuadran %d\n", Kuadran(P1));
    }
    else if (IsOrigin(P1))
    {
        printf("Origin\n");
    }
    else if (IsOnSbX(P1))
    {
        printf("SbX\n");
    }
    else if (IsOnSbY(P1))
    {
        printf("SbY\n");
    }

    if ((!IsOrigin(P2)) && (!IsOnSbX(P2)) && (!IsOnSbY(P2)))
    {
        printf("P2 ada di kuadran %d\n", Kuadran(P2));
    }
    else if (IsOrigin(P2))
    {
        printf("Origin\n");
    }
    else if (IsOnSbX(P2))
    {
        printf("SbX\n");
    }
    else if (IsOnSbY(P2))
    {
        printf("SbY\n");
    }

    TulisPOINT(NextX(P1));
    TulisPOINT(NextY(P2));

    printf("Tulis deltax deltay\n");
    scanf("%f %f", &deltax, &deltay);

    TulisPOINT(PlusDelta(P1,deltax,deltay));

    SbX = true;
    TulisPOINT(MirrorOf(P1,SbX));
    SbX = false;
    TulisPOINT(MirrorOf(P2,SbX));

    printf("Jaraknya %.2f dan panjangnya %.2f\n", Jarak0(P1), Panjang(P1,P2));

    printf("Masukan sudut dalam derajat = \n");
    scanf("%f", &sudut);
    Putar(&P1, sudut);
    TulisPOINT(P1);

    printf("Selesai.!\n");

    return 0;

}
