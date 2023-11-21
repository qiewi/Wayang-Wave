/* *** ******** ******** ******** ******** ******** ****** ** INCLUDED ADT & SPEK ** ****** ******** ******** ******** ******** ******** *** */

#include <stdio.h>
#include <stdlib.h>

#include "../../ADT/WordMachine/wordmachine.h"
#include "../../ADT/CharMachine/charmachine.h"
#include "../../ADT/LineMachine/linemachine.h"
#include "../../ADT/MapSetList/mapsetlist.h"

#include "../Inisialisasi/inisialisasi.h"
#include "../MultiUser/MultiUser.h"
#include "start.h"

/* *** ******** ******** ******** ******** ******** ****** ** COMMAND SPEK ** ****** ******** ******** ******** ******** ******** *** */

void STARTREAD(ListPenyanyi * LP, char filename[], DataUser * DU){
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

  ADVKALIMAT();

  int jumlahUser = atoi(CLine.TabLine);

  for (int u = 0; u < jumlahUser; u++)
  {
      ADVKALIMAT();
      (*DU).NamaUser[(*DU).TotalUser] = CLine;

      CreateQueueLagu(&(*DU).QL[(*DU).TotalUser]);
      CreateCurrentSong(&(*DU).CS[(*DU).TotalUser]);
      CreateRiwayatLagu(&(*DU).RL[(*DU).TotalUser]);
      (*DU).AP[(*DU).TotalUser] = MakeArrayDin();

      (*DU).TotalUser += 1;
  }

}

// int main(){
//   STARTREAD();
// }