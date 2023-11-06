#include "../../ADT/MapSetList/mapsetlist.h"
#include <stdio.h>
#include "../../ADT/pcolor/pcolor.h"
#include "../../ADT/LineMachine/linemachine.h"

void DisplayListDefault(ListPenyanyi * LP)
{
  char ViewLagu;
  int id = -1; // kalau -1 dia undefined (ga ada penyanyi / album)

  printf("%sDaftar Penyanyi :\n", GREEN);
  for (int i = 0; i < (*LP).NEff; i++)
  {
    printf("  %s%d. %s \n", WHITE, i+1, (*LP).PenyanyiAlbum[i].NamaPenyanyi.TabLine);
  }

  printf("\n%sIngin melihat album yang ada? (Y/N): %s", WHITE, GREEN);
  STARTKALIMATINPUT();

  if (isInputEqual(CInput, "Y"))
  {
    printf("%sPilih penyanyi untuk melihat album mereka: %s", WHITE, GREEN);
    STARTKALIMATINPUT();
    // cek nama penyanyi yang diinput
    
    int idPenyanyi = indeksPenyanyi(LP, CInput);

    if (idPenyanyi != -1)
    {
        printf("\n%sDaftar Album oleh %s%s :\n", GREEN, YELLOW, CInput.TabLine);
        for (int i = 0; i < (*LP).PenyanyiAlbum[idPenyanyi].ListAlbum.NEff; i++) // print list Album
        {
          printf("  %s%d. %s \n", WHITE, i+1, (*LP).PenyanyiAlbum[idPenyanyi].ListAlbum.AlbumLagu[i].NamaAlbum.TabLine);
        }

        printf("\n%sIngin melihat lagu yang ada? (Y/N): %s", WHITE, GREEN);
        STARTKALIMATINPUT();

        if (isInputEqual(CInput, "Y"))
        {
            printf("%sMasukkan Nama Album yang dipilih: %s", WHITE, GREEN);
            STARTKALIMATINPUT();

            int idAlbum = indeksAlbum(LP, idPenyanyi, CInput);
            // printf("%s\n", CInput.TabLine);

            if (idAlbum != -1)
            {
              printf("\n%sDaftar Lagu di %s%s:\n", GREEN, YELLOW, CInput.TabLine); // print list Lagu
              for (int i = 0; i < (*LP).PenyanyiAlbum[idPenyanyi].ListAlbum.AlbumLagu[idAlbum].IsiLagu.Count; i++)
              {
                printf("  %s%d. %s \n", WHITE, i+1, (*LP).PenyanyiAlbum[idPenyanyi].ListAlbum.AlbumLagu[idAlbum].IsiLagu.JudulLagu[i].TabLine);
              }

            }
            else
            {
              printf("Album tidak terdaftar\n");
            }
        }

    }
    else
    {
      printf("Penyanyi tidak terdaftar\n");
    }
  }



}