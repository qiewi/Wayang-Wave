/* *** ******** ******** ******** ******** ******** ****** *** *** ANGGOTA KELOMPOK *** *** ****** ******** ******** ******** ******** ******** *** */

                                                        /* 18222118 Rizqi Andhika Pratama  */
                                                        /* 18222107 Lina Azizah R.H.       */
                                                        /* 18222113 Angelica Aliwinata     */
                                                        /* 18222117 Ahmad Fawwazi          */
                                                        /* 18222123 Melissa Trenggono      */
                                                        /* 18222124 Fadian Alif Mahardika  */

/* *** ******** ******** ******** ******** ******** ****** *** LIBRARY YANG DIGUNAKAN *** ****** ******** ******** ******** ******** ******** *** */
#include <stdio.h>
#include <stdlib.h>


/* *** ******** ******** ******** ******** ******** ****** *** FILE HEADER *** ****** ******** ******** ******** ******** ******** *** */

#include "ADT/boolean.h"
#include "ADT/queue/queue.h"
#include "ADT/MapSetList/mapsetlist.h"
#include "ADT/WordMachine/wordmachine.h"
#include "Spesifikasi_Program/Inisialisasi/inisialisasi.h"
#include "Spesifikasi_Program/Start/start.h"


/* *** ******** ******** ******** ******** ******** ****** *** PROGRAM UTAMA *** ****** ******** ******** ******** ******** ******** *** */
int main()
{   
    // Kamus
    boolean mulai = true;
    // MapAlbum MapAlbum;

/* *** ******** ******** ******** ******** ******** ****** ** PRINT MAIN MENU ** ****** ******** ******** ******** ******** ******** *** */

    inisialisasi();

    printf("%s>> ", WHITE);
    STARTWORD();

    ListPenyanyi LP;
    CreateListPenyanyi(&LP);

    while (mulai)
    {

/* *** ******** ******** ******** ******** ******** ****** ** COMMAND START ** ****** ******** ******** ******** ******** ******** *** */

        if (IsKataEqual(currentWord, "START")){
            delay(1);
            printf("\n%sLoading WayangWave..\n", CYAN);
            delay(1);
            printf("...\n");
            delay(1);
            printf("..\n");

            STARTREAD(&LP);
            
        }
    
/* *** ******** ******** ******** ******** ******** ****** ** COMMAND LOAD ** ****** ******** ******** ******** ******** ******** *** */

        else if (IsKataEqual(currentWord, "LOAD")){

        }
        else if (IsKataEqual(currentWord, "QUIT")){
            printf("Babai //");
            mulai = false;
        }

        printf("%s>> ", WHITE);
        STARTWORD();

    }

    return 0;
    
    // }
}

