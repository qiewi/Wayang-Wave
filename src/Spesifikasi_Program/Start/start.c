#include <stdio.h>
#include <stdlib.h>
#include "../../ADT/WordMachine/wordmachine.h"
#include "../../ADT/CharMachine/charmachine.h"
#include "../../ADT/LineMachine/linemachine.h"
#include "../Inisialisasi/inisialisasi.h"
#include "../../ADT/MapSetList/mapsetlist.h"
#include "start.h"

void STARTREAD(ListPenyanyi * LP, char filename[]){
  STARTKALIMATFILE(filename);

  Kalimat NamaPenyanyi;
  Kalimat NamaAlbum;
  Kalimat NamaLagu;

  int loop = atoi(CLine.TabLine);
  // printf("\n%sJumlah Penyanyi: %s%d\n", WHITE, MAGENTA, loop);


  for (int i = 0; i < loop; i++){
    ADVSATUKATA();
    // printf("Kalimat %d: %s\n", 1, CLine.TabLine);
    int album = atoi(CLine.TabLine);
    
    // delay(1);
    ADVKALIMAT();
    
    AddPenyanyi(LP, CLine);
    // NamaPenyanyi = NamaPenyanyiNow(LP);

    // printf("\n%sNama Penyanyi ke-%d: %s%s\n", WHITE, i+1, YELLOW, NamaPenyanyi.TabLine);
    // printf("%s--------------------------------------\n", MAGENTA);
    // printf("%sJumlah Album: %s%d\n", WHITE, MAGENTA, album);
    // printf("--------------------------------------\n");

    // delay(1);

    for (int j = 0; j < album; j++){
      ADVSATUKATA();
      int lagu = atoi(CLine.TabLine);

      ADVKALIMAT();

      AddAlbum(LP, CLine);
      // NamaAlbum = NamaAlbumNow(LP);

      // printf("%sNama Album: %s%s\n", WHITE, YELLOW, NamaAlbum.TabLine);
      // printf("%s--------------------------------------\n", MAGENTA);
      // delay(1);
      for (int k = 0; k < lagu; k++)
      {
        ADVKALIMAT();

        AddLagu(LP, CLine);
        // NamaLagu = NamaLaguNow(LP);

        // printf("%sNama Lagu %d: %s%s\n", WHITE, k+1, MAGENTA, NamaLagu.TabLine);
        // delay(0.5);
      }
      // printf("\n");
    }

  }

}

// int main(){
//   STARTREAD();
// }