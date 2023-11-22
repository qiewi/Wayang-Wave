/* *** ******** ******** ******** ******** ******** ****** ** INCLUDED ADT & SPEK ** ****** ******** ******** ******** ******** ******** *** */

#include <stdio.h>
#include "../../ADT/boolean.h"
#include "../../ADT/pcolor/pcolor.h"
#include "../Inisialisasi/inisialisasi.h"
#include "help.h"

/* *** ******** ******** ******** ******** ******** ****** ** COMMAND SPEK ** ****** ******** ******** ******** ******** ******** *** */

void help(boolean sesi,boolean data){    
    AnimasiHelp();                                                                                                 
    if (!data) {
        printf("%s-----------------------------------------[ Menu Help WayangWave ]---------------------------------------------\n\n", GREEN);
        printf("%s1.  %sSTART\t\t\t%s-> Untuk masuk sesi baru.\n", WHITE, GREEN, WHITE);
        printf("%s2.  %sLOAD %s<filename>\t\t%s-> Untuk memulai sesi berdasarkan file konfigurasi.\n", WHITE, GREEN, YELLOW, WHITE);
        printf("%s3.  %sQUIT\t\t\t%s-> Untuk keluar dari sesi aplikasi WayangWave.\n\n", WHITE, GREEN, WHITE);
    }
    else if (!sesi) {
        printf("%s-----------------------------------------[ Menu Help WayangWave ]---------------------------------------------\n\n", GREEN);
        printf("%s1.  %sREGISTER\t\t\t%s-> Untuk membuat akun WayangWave.\n", WHITE, GREEN, WHITE);
        printf("%s2.  %sLOGIN\t\t\t%s-> Untuk masuk ke dalam akun WayangWave.\n", WHITE, GREEN, WHITE);
        printf("%s3.  %sLOGOUT\t\t\t%s-> Untuk keluar dari akun WayangWave.\n", WHITE, GREEN, WHITE);
        printf("%s4.  %sQUIT\t\t\t%s-> Untuk keluar dari sesi aplikasi WayangWave.\n\n", WHITE, GREEN, WHITE);
        
    }
    else if (sesi){
        printf("%s-----------------------------------------[ Menu Help WayangWave ]---------------------------------------------\n\n", GREEN);
        printf("%s1.  %sLIST DEFAULT\t\t%s-> Untuk melihat list penyanyi yang ada, album dari penyanyi yang dipilih dan lagu yang ada dari album yang dipilih.\n", WHITE, GREEN, WHITE);
        printf("2.  %sLIST PLAYLIST\t\t%s-> Untuk menampilkan playlist yang ada pada pengguna.\n", GREEN, WHITE);
        printf("3.  %sPLAY SONG\t\t\t%s-> Untuk memainkan lagu berdasarkan masukan nama penyanyi, nama album, dan id lagu.\n", GREEN, WHITE);
        printf("4.  %sPLAY PLAYLIST\t\t%s-> Untuk memainkan lagu berdasarkan id playlist.\n", GREEN, WHITE);
        printf("5.  %sQUEUE SONG\t\t\t%s-> Untuk menambahkan lagu ke dalam queue.\n", GREEN, WHITE);
        printf("6.  %sQUEUE PLAYLIST\t\t%s-> Untuk menambahkan lagu yang ada dalam playlist ke dalam queue.\n", GREEN, WHITE);
        printf("7.  %sQUEUE SWAP %s<x> <y>\t\t%s-> Untuk menukar lagu pada urutan ke x dan juga urutan ke y.\n", GREEN, YELLOW, WHITE);
        printf("8.  %sQUEUE REMOVE %s<id>\t\t%s-> Untuk menghapus lagu dari queue sesuai id lagu yang diinginkan.\n", GREEN, YELLOW, WHITE);
        printf("9.  %sQUEUE CLEAR\t\t\t%s-> Untuk mengosongkan queue.\n", GREEN, WHITE);
        printf("10. %sSONG NEXT\t\t\t%s-> Untuk memutar lagu yang berada di dalam queue.\n", GREEN, WHITE);
        printf("11. %sSONG PREVIOUS\t\t%s-> Untuk memutar lagu yang terakhir kali diputar.\n", GREEN, WHITE);
        printf("12. %sPLAYLIST CREATE\t\t%s-> Untuk membuat playlist baru dan ditambahkan pada daftar playlist pengguna.\n", GREEN, WHITE);
        printf("13. %sPLAYLIST ADD SONG\t\t%s-> Untuk menambahkan lagu pada suatu playlist yang telah ada sebelumnya pada daftar playlist pengguna.\n", GREEN, WHITE);
        printf("14. %sPLAYLIST ADD ALBUM\t\t%s-> Untuk menambahkan album pada suatu playlist yang telah ada sebelumnya pada daftar playlist pengguna.\n", GREEN, WHITE);
        printf("15. %sPLAYLIST SWAP %s<id> <x> <y>\t%s-> Untuk menukar lagu pada urutan ke x dan juga urutan ke y di playlist dengan urutan ke id.\n", GREEN, YELLOW, WHITE);
        printf("16. %sPLAYLIST REMOVE %s<id> <n>\t%s-> Untuk menghapus lagu dengan urutan n pada playlist dengan index id.\n", GREEN, YELLOW, WHITE);
        printf("17. %sPLAYLIST DELETE\t\t%s-> Untuk melakukan penghapusan suatu existing playlist dalam daftar playlist pengguna.\n", GREEN, WHITE);
        printf("18. %sSTATUS\t\t\t%s-> Untuk menampilkan lagu yang sedang dimainkan beserta queue song yang ada dan dari playlist mana lagu itu diputar.\n", GREEN, WHITE);
        printf("19. %sFOLLOW USER\t\t%s-> Untuk mem-follow user lain di dalam WayangWave.\n", GREEN, WHITE);
        printf("20. %sFOLLOW LIST\t\t%s-> Untuk menampilkan user yang sudah difollow beserta playlist yang mereka miliki.\n", GREEN, WHITE);
        printf("21. %sSAVE %s<filename>\t\t%s-> Untuk menyimpan state aplikasi terbaru ke dalam suatu file.\n", GREEN, YELLOW, WHITE);
        printf("22. %sQUIT\t\t\t%s-> Untuk keluar dari sesi aplikasi WayangWave.\n\n", GREEN, WHITE);
    }
}