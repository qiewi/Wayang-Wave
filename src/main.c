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
#include "ADT/LineMachine/linemachine.h"
#include "Spesifikasi_Program/Inisialisasi/inisialisasi.h"
#include "Spesifikasi_Program/List/List.h"
#include "Spesifikasi_Program/Start/start.h"
#include "Spesifikasi_Program/Play/Play.h"
#include "Spesifikasi_Program/Load/Load.h"


/* *** ******** ******** ******** ******** ******** ****** *** PROGRAM UTAMA *** ****** ******** ******** ******** ******** ******** *** */
int main()
{   
    // Kondisi
    boolean mulai = true;
    boolean sesi = false;
    // MapAlbum MapAlbum;

/* *** ******** ******** ******** ******** ******** ****** ** PRINT MAIN MENU ** ****** ******** ******** ******** ******** ******** *** */

    // Print Main Menu
    inisialisasi();

    // Kamus
    ListPenyanyi LP;
    CreateListPenyanyi(&LP);

    // Meminta Command
    while (mulai)
    {

/* *** ******** ******** ******** ******** ******** ****** ** COMMAND START ** ****** ******** ******** ******** ******** ******** *** */
        printf("%s>> ", WHITE);
        STARTKALIMATINPUT();
        
        if (isInputEqual(CInput, "START")){
            delay(1);
            printf("\n%s[=========", GREEN);
            delay(1);
            printf("==========");
            delay(1);
            printf("%s Loading WayangWave.. ", CYAN);
            delay(1);
            printf("%s==========", GREEN);
            delay(1);
            printf("=========]\n");
            delay(1);
            

            STARTREAD(&LP, "config.txt");

            printf("\n%sOutput: %sFile konfigurasi aplikasi berhasil dibaca.\n", GREEN, WHITE);
            delay(1);
            printf("\n%s[=========", GREEN);
            printf("==========");
            delay(1);
            printf("%s WayangWave Running.. ", CYAN);
            delay(1);
            printf("%s==========", GREEN);
            printf("=========]\n\n");
            delay(1);
            
            sesi = true;
        }
        
    
/* *** ******** ******** ******** ******** ******** ****** ** COMMAND LOAD ** ****** ******** ******** ******** ******** ******** *** */

        else if (isInputEqual(CInput, "LOAD")){ // to do list: tambahin nama file di setelahnya

            LOADFILE(&LP, "savefile.txt");

        }

/* *** ******** ******** ******** ******** ******** ****** ** COMMAND LIST ** ****** ******** ******** ******** ******** ******** *** */

        else if (isInputEqual(CInput, "LIST DEFAULT")){

            if (!sesi)
            {
                printf("%sERROR: %sCommand tidak dapat dieksekusi!\n", RED, WHITE);
            }
            else
            {
                DisplayListDefault(&LP);
            }
            
    
        }

/* *** ******** ******** ******** ******** ******** ****** ** COMMAND PLAY ** ****** ******** ******** ******** ******** ******** *** */

        else if (isInputEqual(CInput, "PLAY SONG")){


            if (!sesi)
            {
                printf("%sERROR: %sCommand tidak dapat dieksekusi!\n", RED, WHITE);
            }
            else
            {
                PlaySong(&LP);
            }      
       
        }

/* *** ******** ******** ******** ******** ******** ****** ** COMMAND QUIT ** ****** ******** ******** ******** ******** ******** *** */

        else if (isInputEqual(CInput, "QUIT")){

            printf("Kamu keluar dari %sWayangWave.\n", GREEN);
            printf("%sDadah ^_^/\n", WHITE);
            mulai = false;
            
        }
        

        else
        {
            printf("%sERROR: %sCommand tidak diketahui!\n", RED, WHITE);
        }

        printf("%s--------------------------------------------------------------------------------------------------------------\n", GREEN);
    
    }


/* *** ******** ******** ******** ******** ******** ****** ** COMMAND START ** ****** ******** ******** ******** ******** ******** *** */

    return 0;
}

