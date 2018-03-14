#include "listUNIT.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include "point.h"

int main ()
{
    ListUNIT L;
    Unit U1; /* U1 ADALAH ELEMEN PERTAMA DARI LIST UNIT */
    Unit U2,X; /* U2 ADALAH ELEMEN KEDUA DARI LIST UNIT */
    CreateEmptyUNIT(&L);
    /* MEMASUKKAN ISI TUPLE DARI ELEMEN PERTAMA LIST UNIT */
    printf("Masukkan MaxHealth unit pertama : ");
    scanf("%d", &MaxHealth(U1));
    printf("Masukkan health unit pertama : ");
    scanf("%d", &Health(U1));
    printf("Masukkan attack unit pertama : ");
    scanf("%d", &Attack(U1));
    printf("Masukkan MaxMovePoint unit pertama : ");
    scanf("%d", &MaxMovePoint(U1));
    printf("Masukkan Movepoint unit pertama : ");
    scanf("%d", &MovePoint(U1));
    printf("Masukkan attack type unit pertama : ");
    scanf(" %c", &AttackType(U1));
    AtkOpp(U1)=true;
    Idx(UnitLocation(U1)) = 2;
    Clmn(UnitLocation(U1)) = 2;
    Price(U1) = 0;
    /* MENAMBAHKAN UNIT KE DALAM LIST SEBAGAI ELEMEN PERTAMA */
    InsVFirstUNIT(&L,U1);
    printf("\n");
    /* MEMASUKKAN ISI DARI TUPLE ELEMEN KEDUA LIST UNIT */
    printf("Masukkan MaxHealth unit kedua : ");
    scanf("%d", &MaxHealth(U2));
    printf("Masukkan health unit kedua : ");
    scanf("%d", &Health(U2));
    printf("Masukkan attack unit kedua : ");
    scanf("%d", &Attack(U2));
    printf("Masukkan MaxMovePoint unit kedua : ");
    scanf("%d", &MaxMovePoint(U2));
    printf("Masukkan Movepoint unit kedua : ");
    scanf("%d", &MovePoint(U2));
    printf("Masukkan attack type unit kedua : ");
    scanf(" %c", &AttackType(U2));
    AtkOpp(U1)=true;
    Idx(UnitLocation(U1)) = 3;
    Clmn(UnitLocation(U1)) = 3;
    Price(U2) = 19;
    /* MENAMBAHKAN UNIT KE DALAM LIST SEBAGAI ELEMEN TERAKHIR */
    InsVLastUNIT(&L,U2);
    printf("\n");
    /* MENGECEK APAKAH LIST KOSONG SETELAH DIISI */
    if (IsEmptyUNIT(L))
    {
        printf("List kosong! \n");
    }
    else
    {
        printf("List sudah berisi! \n");
    }
    printf("\n");
    /* MENGHAPUS ELEMEN PERTAMA DARI LIST */
    printf("Setelah U1 dihapus menjadi : ");
    DelVFirstUNIT(&L,&X);
    /* MENGECEK APAKAH ELEMEN PERTAMA SUDAH DIHAPUS / BELUM */
    if (SearchUNIT(L,U1))
    {
        printf("Unit pertama masih ada!\n");
    }
    else
    {
        printf("Unit pertama sudah tidak ada! \n");
    }
    DelVLastUNIT(&L,&X);
    InsVFirstUNIT(&L,U1);
    DelPUNIT(&L,U1);
    if (IsEmptyUNIT(L))
    {
        printf("List unit kosong!\n");
    }
    else
    {
        printf("List unit sudah berisi!\n");
    }
}
