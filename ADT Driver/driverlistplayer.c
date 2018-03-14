#include "listPLAYER.h"
#include "listUNIT.h"
#include "listVILLAGE.h"
#include "point.h"
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

int main ()
{
    ListUNIT LU;
    Unit U1; /* U1 ADALAH ELEMEN PERTAMA PADA LIST UNIT */
    Unit U2; /* U2 ADALAH ELEMEN KEDUA PADA LIST UNIT */
    CreateEmptyUNIT(&LU);
    printf("BERLAKU UNTUK SEMUA PLAYER\n");
    printf("\n");
    /* MEMASUKKAN INPUT UNTUK LIST UNIT DARI P1 DAN P2 */
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
    InsVFirstUNIT(&LU,U1);
    printf("\n");
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
    AtkOpp(U2)=true;
    Idx(UnitLocation(U2)) = 3;
    Clmn(UnitLocation(U2)) = 3;
    Price(U2) = 19;
    InsVLastUNIT(&LU,U2);
    printf("\n");
    /* MULAI MENGAKSES LIST VILLAGE DAN MEMASUKKAN INPUT LIST VILLAGE UNTUK P1 DAN P2 */
    ListVILLAGE LV;
    Village V1; /* ELEMEN PERTAMA DARI LIST VILLAGE */
    Village V2; /* ELEMEN KEDUA DARI LIST VILLAGE */
    CreateEmptyVILLAGE(&LV);
    printf("Masukkan X dari village pertama : ");
    scanf("%d", &Idx(VillageLocation(V1)));
    printf("Masukkan Y dari village pertama : ");
    scanf("%d", &Clmn(VillageLocation(V1)));
    InsVFirstVILLAGE(&LV,V1);
    printf("\n");
    printf("Masukkan X dari village kedua : ");
    scanf("%d", &Idx(VillageLocation(V2)));
    printf("Masukkan Y dari village kedua : ");
    scanf("%d", &Clmn(VillageLocation(V2)));
    InsVLastVILLAGE(&LV,V2);
    printf("\n");
    /* MULAI MENGAKSES LIST PLAYER DAN MENGISI INPUT UNTUK P1*/
    ListPLAYER LP;
    Player P;
    Player P1; /* P1 ADALAH ELEMEN PERTAMA DARI LIST PLAYER */
    Player P2; /* P2 ADALAH ELEMEN KEDUA DARI LIST PLAYER */
    /* ANGGAP LIST UNIT UNTUK P1 DAN P2 SAMA (LU) DAN LIST VILLAGE UNTUK P1 DAN 2 SAMA (LV) */
    Units(P1) = LU;
    Units(P2) = LU;
    Villages(P1) = LV;
    Villages(P2) = LV;
    CreateEmptyPLAYER(&LP);
    printf("Masukkan Gold P1 : ");
    scanf("%d", &Gold(P1));
    printf("Masukkan income P1 : ");
    scanf("%d", &Income(P1));
    printf("Masukkan upkeep P1 : ");
    scanf("%d", &Upkeep(P1));
    InsVFirstPLAYER(&LP,P1);
    printf("\n");
    /* MEMASUKKAN INPUT UNTUK P2 */
    printf("Masukkan Gold P2 : ");
    scanf("%d", &Gold(P2));
    printf("Masukkan income P2 : ");
    scanf("%d", &Income(P2));
    printf("Masukkan upkeep P2 : ");
    scanf("%d", &Upkeep(P2));
    InsVLastPLAYER(&LP,P2);
    printf("\n");
    /*  MENGECEK APAKAH LIST PLAYER ADA ISINYA / TIDAK */
    if (IsEmptyPLAYER(LP))
    {
        printf("Tidak ada player siapapun ! \n");
    }
    else
    {
        printf("Ada player di dalam list \n");
    }
    printf("\n");
    /* P2 DIHAPUS DENGAN PROSEDUR DELVLAST DAN DICEK APAKAH MASIH ADA P2 DALAM LIST ATAU TIDAK*/
    printf("Setelah P2 dihapus : ");
    DelVLastPLAYER(&LP,&P);
    /* DelVLastPLAYER menggunakan DelLastPLAYER */
    if (NextPLAYER(FirstPLAYER(LP)) == Nil)
    {
        printf("Ada P2 dalam list\n");
    }
    else
    {
        printf("P2 sudah tidak ada :( \n");
    }
    printf("\nSetelah ditambahkan lagi menjadi : ");
    InsVLastPLAYER(&LP,P2); /* MENAMBAH P2 SEBAGAI ELEMEN TERAKHIR */
    /* InsVLastPLAYER menggunakan InsertLastPLAYER */
    if (NextPLAYER(FirstPLAYER(LP))!=Nil)
    {
        printf("Ada P2 dalam list\n");
    }
    else
    {
        printf("P2 masih tidak ada :( \n");
    }
    DelVFirstPLAYER(&LP,&P);
    /* DelVFirstPLAYER menggunakan DelFirstPLAYER */
    if (NextPLAYER(FirstPLAYER(LP)) == Nil)
    {
        printf("Ada P1 dalam list\n");
    }
    else
    {
        printf("P1 sudah tidak ada :( \n");
    }
    printf("\nSetelah ditambahkan lagi menjadi : ");
    InsVFirstPLAYER(&LP,P1); /* MENAMBAH P2 SEBAGAI ELEMEN TERAKHIR */
    /* InsVFirstPLAYER menggunakan InsertFirstPLAYER */
    if (NextPLAYER(FirstPLAYER(LP))!=Nil)
    {
        printf("Ada P1 dalam list\n");
    }
    else
    {
        printf("P1 masih tidak ada :( \n");
    }
}
