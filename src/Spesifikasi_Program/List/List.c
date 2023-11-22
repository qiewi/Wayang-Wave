/* *** ******** ******** ******** ******** ******** ****** ** INCLUDED ADT & SPEK ** ****** ******** ******** ******** ******** ******** *** */

#include <stdio.h>
#include <stdlib.h>

#include "../../ADT/pcolor/pcolor.h"
#include "../../ADT/LineMachine/linemachine.h"
#include "../../ADT/LinkedList/linkedlist.h"
#include "../../ADT/LineMachine/linemachine.h"
#include "../../ADT/array/arraydinamis.h"
#include "../../ADT/MapSetList/mapsetlist.h"

#include "../Inisialisasi/inisialisasi.h"

/* *** ******** ******** ******** ******** ******** ****** ** COMMAND SPEK ** ****** ******** ******** ******** ******** ******** *** */

void DisplayListDefault(ListPenyanyi * LP)
{
  char ViewLagu;
  int id = -1; // kalau -1 dia undefined (ga ada penyanyi / album)

  AnimasiList();
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
              printf("\n%sERROR: %sAlbum tidak terdaftar.\n", RED, WHITE);
            }
        }

    }
    else
    {
      printf("\n%sERROR: %sPenyanyi tidak terdaftar.\n", RED, WHITE);
    }
  }

}

void displayPlaylist(ArrayDin * AP)
{ 
  AnimasiList();
  printf("%sDaftar Playlist yang kamu miliki:\n", GREEN);
  if ((*AP).Neff > 0)
  {
    for (int i = 0; i < (*AP).Neff; i++)
    {
      printf("  %s%d. %s \n", WHITE, i+1, (*AP).Nama[i].TabLine);
    }

    printf("\nIngin cek isi lagu dari sebuah playlist? (Y/N): %s", GREEN);
    STARTKALIMATINPUT();

    if (CInput.TabLine[0] == 'Y')
    {

        printf("%sInput ID playlist: %s", WHITE, GREEN);
        STARTKALIMATINPUT();

        int idPL = atoi(CInput.TabLine) - 1;

        if (idPL+1 > (*AP).Neff || idPL+1 <= 0)
        {
            printf("\n%sERROR: %sTidak ada playlist dengan ID %d.\n", RED, WHITE, idPL+1);
        }
        else
        {   
            printf("\n%sDaftar lagu dalam playlist %s\"%s\":%s\n", GREEN, YELLOW, (*AP).Nama[idPL].TabLine, WHITE);
            address p = First((*AP).A[idPL]);
            int i = 0;

            if (p == Nil)
            {
              printf("%sTidak ada lagu.\n", WHITE);
            }
            else
            {
              while (p != Nil)
              {
                  printf("  %s%d. %s - %s \n", WHITE, i+1, NamaPenyanyi(p).TabLine, JudulLagu(p).TabLine);
                  p = Next(p);
                  i++;
              }
            }
        
        }
    }

  }
  else
  {
    printf("%sKamu tidak memiliki playlist.\n", WHITE);
  }
}