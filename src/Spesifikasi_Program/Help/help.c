#include <stdio.h>
#include "help.h"

void help(boolean isStart) {
    if (!isStart) {
        printf("======================================================================[ HELP ]======================================================================\n\n");
        printf("1.  START\t\t\t-> Untuk masuk sesi baru.\n");
        printf("2.  LOAD\t\t\t-> Untuk memulai sesi berdasarkan file konfigurasi.\n");
    }
    else {
        printf("======================================================================[ HELP ]======================================================================\n\n");
        printf("1.  LIST DEFAULT\t\t-> Untuk melihat list penyanyi yang ada, album dari penyanyi yang dipilih dan lagu yang ada dari album yang dipilih.\n");
        printf("2.  LIST PLAYLIST\t\t-> Untuk menampilkan playlist yang ada pada pengguna.\n");
        printf("3.  PLAY SONG\t\t\t-> Untuk memainkan lagu berdasarkan masukan nama penyanyi, nama album, dan id lagu.\n");
        printf("4.  PLAY PLAYLIST\t\t-> Untuk memainkan lagu berdasarkan id playlist.\n");
        printf("5.  QUEUE SONG\t\t\t-> Untuk menambahkan lagu ke dalam queue.\n");
        printf("6.  QUEUE PLAYLIST\t\t-> Untuk menambahkan lagu yang ada dalam playlist ke dalam queue.\n");
        printf("7.  QUEUE SWAP <x> <y>\t\t-> Untuk menukar lagu pada urutan ke x dan juga urutan ke y.\n");
        printf("8.  QUEUE REMOVE <id>\t\t-> Untuk menghapus lagu dari queue sesuai id lagu yang diinginkan.\n");
        printf("9.  QUEUE CLEAR\t\t\t-> Untuk mengosongkan queue.\n");
        printf("10. SONG NEXT\t\t\t-> Untuk memutar lagu yang berada di dalam queue.\n");
        printf("11. SONG PREVIOUS\t\t-> Untuk memutar lagu yang terakhir kali diputar.\n");
        printf("12. PLAYLIST CREATE\t\t-> Untuk membuat playlist baru dan ditambahkan pada daftar playlist pengguna.\n");
        printf("13. PLAYLIST ADD SONG\t\t-> Untuk menambahkan lagu pada suatu playlist yang telah ada sebelumnya pada daftar playlist pengguna.\n");
        printf("14. PLAYLIST ADD ALBUM\t\t-> Untuk menambahkan album pada suatu playlist yang telah ada sebelumnya pada daftar playlist pengguna.\n");
        printf("15. PLAYLIST SWAP <id> <x> <y>\t-> Untuk menukar lagu pada urutan ke x dan juga urutan ke y di playlist dengan urutan ke id.\n");
        printf("16. PLAYLIST REMOVE <id> <n>\t-> Untuk menghapus lagu dengan urutan n pada playlist dengan index id.\n");
        printf("17. PLAYLIST DELETE\t\t-> Untuk melakukan penghapusan suatu existing playlist dalam daftar playlist pengguna.\n");
        printf("18. STATUS\t\t\t-> Untuk menampilkan lagu yang sedang dimainkan beserta queue song yang ada dan dari playlist mana lagu itu diputar.\n");
        printf("19. SAVE <filename>\t\t-> Untuk menyimpan state aplikasi terbaru ke dalam suatu file.\n");
        printf("20. QUIT\t\t\t-> Untuk keluar dari sesi aplikasi WayangWave.\n");
    }
}