#include <stdio.h>
#include <stdlib.h>
#include "listVILLAGE.h"
#include "boolean.h"
#include "point.h"

int main ()
{
    ListVILLAGE LV;
    Village V1; /* V1 ADALAH ELEMEN PERTAMA DARI LIST VILLAGE */
    Village V2; /* V2 ADALAH ELEMEN KEDUA DARI LIST VILLAGE */
    Village X; /* X ADALAH TEMPAT PEMBUANGAN KETIKA SALAH SATU ELEMEN DALAM LIST VILLAGE DIHAPUS */
    CreateEmptyVILLAGE(&LV);
    /* MENGISI ISI TUPPLE DARI ELEMEN PERTAMA LIST VILLAGE */
    printf("Masukkan X dari village pertama : ");
    scanf("%d", &Idx(VillageLocation(V1)));
    printf("Masukkan Y dari village pertama : ");
    scanf("%d", &Clmn(VillageLocation(V1)));
    /* MEMASUKKAN ISI VILLAGE KE DALAM LIST VILLAGE SEBAGAI ELEMEN PERTAMA */
    InsVFirstVILLAGE(&LV,V1);
    /* InsVFirstPLAYER menggunakan InsertFirstVILLAGE */
    printf("\n");
    printf("Masukkan X dari village kedua : ");
    scanf("%d", &Idx(VillageLocation(V2)));
    printf("Masukkan Y dari village kedua : ");
    scanf("%d", &Clmn(VillageLocation(V2)));
    /* MEMASUKKAN ISI VILLAGE KE DALAM LIST VILLAGE SEBAGAI ELEMEN TERAKHIR */
    InsVLastVILLAGE(&LV,V2);
    /* InsVLastVILLAGE menggunakan InsertLastVILLAGE */
    printf("\n");
    /* MENGECEK APAKAH LIST VILLAGE ADA ISINYA ATAU TIDAK SETELAH DIISI */
    if (IsEmptyVILLAGE(LV))
    {
        printf("List village kosong!\n");
    }
    else
    {
        printf("List village sudah berisi!\n");
    }
    /* MENGHAPUS ELEMEN TERAKHIR DARI LIST VILLAGE */
    DelVLastVILLAGE(&LV,&X);
    /* DelVLastVILLAGE menggunakan DelLastVILLAGE */
    printf("\n");
    printf("Setelah V2 dihapus menjadi : ");
    /* MENGECEK APAKAH VILLAGE YANG SUDAH DIHAPUS MASIH ADA ATAU TIDAK DI DALAM LIST */
    if (SearchVILLAGE(LV,V2))
    {
        printf("V2 masih ada!\n");
    }
    else
    {
        printf("V2 sudah dihapus!\n");
    }
    DelVFirstVILLAGE(&LV,&X);
    /* DelVFirstVILLAGE menggunakan DelFirstVILLAGE */
    printf("\n");
    printf("Setelah V2 dihapus menjadi : ");
    /* MENGECEK APAKAH VILLAGE YANG SUDAH DIHAPUS MASIH ADA ATAU TIDAK DI DALAM LIST */
    if (SearchVILLAGE(LV,V1))
    {
        printf("V1 masih ada!\n");
    }
    else
    {
        printf("V1 sudah dihapus!\n");
    }
    InsVFirstVILLAGE(&LV,V1);
    DelPVILLAGE(&LV,V1);
    if (IsEmptyVILLAGE(LV))
    {
        printf("List village kosong!\n");
    }
    else
    {
        printf("List village sudah berisi!\n");
    }
}
