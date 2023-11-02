#include <stdio.h>
#include "../../ADT/WordMachine/wordmachine.h"
#include "../../ADT/CharMachine/charmachine.h"
#include "../../ADT/LineMachine/linemachine.h"
#include "../Inisialisasi/inisialisasi.h"
#include "start.h"

void STARTREAD(ListPenyanyi * LP){
  STARTKALIMATFILE("config.txt");

  int loop = CLine.TabLine[0] - 48;
  printf("\n%sJumlah Penyanyi: %s%d\n", WHITE, MAGENTA, loop);

  for (int i = 0; i < loop; i++){
    ADVSATUKATA();
    // printf("Kalimat %d: %s\n", 1, CLine.TabLine);
    int album = CLine.TabLine[0] - 48;
    
    delay(1);
    ADVKALIMAT();
    AddPenyanyi(LP, CLine);
    printf("\n%sNama Penyanyi List%d: %s%s\n", WHITE, i+1, YELLOW, (*LP).NamaPenyanyi[i].TabLine);
    printf("%s--------------------------------------\n", MAGENTA);
    printf("%sJumlah Album: %s%d\n", WHITE, MAGENTA, album);
    printf("--------------------------------------\n");

    delay(1);

    for (int j = 0; j < album; j++){
      ADVSATUKATA();
      int lagu = CLine.TabLine[0] - 48;

      ADVKALIMAT();
      printf("%sNama Album: %s%s\n", WHITE, YELLOW, CLine.TabLine);
      printf("%s--------------------------------------\n", MAGENTA);
      delay(1);
      for (int k = 0; k < lagu; k++)
      {
        ADVKALIMAT();
        printf("%sNama Lagu %d: %s%s\n", WHITE, k+1, MAGENTA, CLine.TabLine);
        delay(0.5);
      }
      printf("\n");
    }

  }

}

// int main(){
//   STARTREAD();
// }