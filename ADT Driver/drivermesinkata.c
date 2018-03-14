#include "boolean.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{
  Kata strswordsman, strarcher, strwhitemage;
  int count,i;

  //input dari file eksternal king
  STARTKATAKING();
  if (EndKata)
  {
    printf("FILE KING KOSONG\n" );
  } else
  {
    while (!EndKata)
    {
      for (i=1;i<=CKata.Length;i++) {
          printf("%c",CKata.TabKata[i]);
      }
      printf("\n" );
      ADVKATAFILE();
    }
  }

  //input dari file eksternal Swordsman
  strswordsman.TabKata[1] = 'S';
  strswordsman.TabKata[2] = 'W';
  strswordsman.TabKata[3] = 'O';
  strswordsman.TabKata[4] = 'R';
  strswordsman.TabKata[5] = 'D';
  strswordsman.TabKata[6] = 'S';
  strswordsman.TabKata[7] = 'M';
  strswordsman.TabKata[8] = 'A';
  strswordsman.TabKata[9] = 'N';
  strswordsman.Length = 9;

  count = 0;
  STARTKATASWORDSMAN();

  if (EndKata)
  {
    printf("FILE SWORDSMAN KOSONG\n" );
  } else
  {
    printf("terdapat ");
    while (!EndKata)
    {
      if (IsKataSama(CKata,strswordsman))
      {
        count++;
      }
      ADVKATAFILE();
    }
    printf("%d kali kemunculan kata Swordsman\n", count);
  }

  //input dari file eksternal Archer
  strarcher.TabKata[1] = 'A';
  strarcher.TabKata[2] = 'R';
  strarcher.TabKata[3] = 'C';
  strarcher.TabKata[4] = 'H';
  strarcher.TabKata[5] = 'E';
  strarcher.TabKata[6] = 'R';
  strarcher.Length = 6;

  STARTKATAARCHER();
  if (EndKata)
  {
    printf("FILE ARCHER KOSONG\n" );
  } else
  {
    while (!EndKata)
    {
      if (!(IsKataSama(CKata,strarcher)))
      {
        for (i=1;i<=CKata.Length;i++) {
            printf("%c",CKata.TabKata[i]);
        }
      }
      printf("\n" );
      ADVKATAFILE();
    }
  }

  //input dari file eksternal WHITEMAGE
  STARTKATAWHITEMAGE();
  if (EndKata)
  {
    printf("FILE WHITEMAGE KOSONG\n" );
  } else
  {
    while (!EndKata)
    {
      for (i=1;i<=CKata.Length;i++) {
          printf("%c",CKata.TabKata[i]);
      }
      printf("\n");
      ADVKATAFILE();
    }
  }

  //INPUT DARI INPUT PENGGUNA
  STARTKATA();
  if (EndKata)
  {
    printf("ANDA TIDAK MEMASUKKAN KATA APAPUN\n" );
  } else
  {
    while (!EndKata)
    {
      for (i=1;i<=CKata.Length;i++) {
          printf("%c",CKata.TabKata[i]);
      }
      printf("\n" );
      ADVKATA();
    }
  }




  return 0;
}
