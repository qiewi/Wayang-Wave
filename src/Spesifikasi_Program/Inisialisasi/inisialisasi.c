/* *** ******** ******** ******** ******** ******** ****** ** INCLUDED ADT & SPEK ** ****** ******** ******** ******** ******** ******** *** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "inisialisasi.h"
#include "../../ADT/pcolor/pcolor.h"

/* *** ******** ******** ******** ******** ******** ****** ** COMMAND SPEK ** ****** ******** ******** ******** ******** ******** *** */

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 500 * number_of_seconds;
 
    // Storing start time
    clock_t start_time = clock();
 
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}

void print_image(FILE *fascii)
{
    char read_string[MAX_LEN];
    while(fgets(read_string,sizeof(read_string),fascii) != NULL)
    printf("%s%s",GREEN,read_string);
    printf("\n");

}


// void inisialisasi(){
//     char *filename;
//     FILE *fascii;
//     system("cls || clear");

//     filename = "Spesifikasi_Program/Inisialisasi/wayang.txt";
    
//     fascii = NULL;
//     fascii = fopen(filename,"r");

//     if(fascii  == NULL){
//         printf("error opening %s\n",filename);
//     } else {
//         system("cls || clear");
//         print_image(fascii);
//         fclose(fascii);
//     }
// }

void inisialisasi(){
    char *filename;
    FILE *fascii;
    system("cls || clear");
    for (int i = 0; i < 4; i++){
        if (i == 0) {
            filename = "Spesifikasi_Program/Inisialisasi/wayang/wayang3.txt";
        } else if (i == 1){
            filename = "Spesifikasi_Program/Inisialisasi/wayang/wayang2.txt";
        } else if (i == 2){
            filename = "Spesifikasi_Program/Inisialisasi/wayang/wayang1.txt";
        } else if (i == 3){
            filename = "Spesifikasi_Program/Inisialisasi/wayang/wayang.txt";
        } 
        fascii = NULL;
        fascii = fopen(filename,"r");
        if(fascii  == NULL){
            printf("error opening %s\n",filename);
        } else {
            system("cls || clear");
            print_image(fascii);
            fclose(fascii);
        }
        delay(1);
    }
}

void AnimasiLoad(){
    char *filename;
    FILE *fascii;
    system("cls || clear");
    for (int i = 0; i < 3; i++){
        if (i == 0) {
            filename = "Spesifikasi_Program/Inisialisasi/load/load3.txt";
        } else if (i == 1){
            filename = "Spesifikasi_Program/Inisialisasi/load/load2.txt";
        } else if (i == 2){
            filename = "Spesifikasi_Program/Inisialisasi/load/load1.txt";
        } 
        fascii = NULL;
        fascii = fopen(filename,"r");
        if(fascii  == NULL){
            printf("error opening %s\n",filename);
        } else {
            system("cls || clear");
            print_image(fascii);
            fclose(fascii);
        }
        delay(2);
    }
}

void AnimasiSave(){
    char *filename;
    FILE *fascii;
    system("cls || clear");
    for (int i = 0; i < 3; i++){
        if (i == 0) {
            filename = "Spesifikasi_Program/Inisialisasi/save/save3.txt";
        } else if (i == 1){
            filename = "Spesifikasi_Program/Inisialisasi/save/save2.txt";
        } else if (i == 2){
            filename = "Spesifikasi_Program/Inisialisasi/save/save1.txt";
        } 
        fascii = NULL;
        fascii = fopen(filename,"r");
        if(fascii  == NULL){
            printf("error opening %s\n",filename);
        } else {
            system("cls || clear");
            print_image(fascii);
            fclose(fascii);
        }
        delay(2);
    }
}

void AnimasiQuit(){
    char *filename;
    FILE *fascii;
    system("cls || clear");
    for (int i = 0; i < 3; i++){
        if (i == 0) {
            filename = "Spesifikasi_Program/Inisialisasi/quit/quit1.txt";
        } else if (i == 1){
            filename = "Spesifikasi_Program/Inisialisasi/quit/quit2.txt";
        } else if (i == 2){
            filename = "Spesifikasi_Program/Inisialisasi/quit/quit3.txt";
        } 
        fascii = NULL;
        fascii = fopen(filename,"r");
        if(fascii  == NULL){
            printf("error opening %s\n",filename);
        } else {
            system("cls || clear");
            print_image(fascii);
            fclose(fascii);
        }
        delay(2);
    }
}

void AnimasiHelp(){
    char *filename;
    FILE *fascii;
    system("cls || clear");
    for (int i = 0; i < 1; i++){
        if (i == 0) {
            filename = "Spesifikasi_Program/Inisialisasi/help/help1.txt";
        } 
        fascii = NULL;
        fascii = fopen(filename,"r");
        if(fascii  == NULL){
            printf("error opening %s\n",filename);
        } else {
            system("cls || clear");
            print_image(fascii);
            fclose(fascii);
        }
        delay(1);
    }
}

void AnimasiStatus(){
    char *filename;
    FILE *fascii;
    system("cls || clear");
    for (int i = 0; i < 4; i++){
        if (i == 0) {
            filename = "Spesifikasi_Program/Inisialisasi/status/status1.txt";
        } else if (i == 1){
            filename = "Spesifikasi_Program/Inisialisasi/status/status2.txt";
        } else if (i == 2){
            filename = "Spesifikasi_Program/Inisialisasi/status/status3.txt";
        } else if (i == 3){
            filename = "Spesifikasi_Program/Inisialisasi/status/status4.txt";
        } 
        fascii = NULL;
        fascii = fopen(filename,"r");
        if(fascii  == NULL){
            printf("error opening %s\n",filename);
        } else {
            system("cls || clear");
            print_image(fascii);
            fclose(fascii);
        }
        delay(1);
    }
}

void AnimasiList(){
    char *filename;
    FILE *fascii;
    system("cls || clear");
    for (int i = 0; i < 4; i++){
        if (i == 0) {
            filename = "Spesifikasi_Program/Inisialisasi/list/list1.txt";
        } else if (i == 1){
            filename = "Spesifikasi_Program/Inisialisasi/list/list2.txt";
        } else if (i == 2){
            filename = "Spesifikasi_Program/Inisialisasi/list/list3.txt";
        } else if (i == 3){
            filename = "Spesifikasi_Program/Inisialisasi/list/list4.txt";
        } 
        fascii = NULL;
        fascii = fopen(filename,"r");
        if(fascii  == NULL){
            printf("error opening %s\n",filename);
        } else {
            system("cls || clear");
            print_image(fascii);
            fclose(fascii);
        }
        delay(1);
    }
}

void AnimasiPlaySong(){
    char *filename;
    FILE *fascii;
    system("cls || clear");
    for (int i = 0; i < 5; i++){
        if (i == 0) {
            filename = "Spesifikasi_Program/Inisialisasi/play-song/playing 1.txt";
        } else if (i == 1){
            filename = "Spesifikasi_Program/Inisialisasi/play-song/playing 2.txt";
        } else if (i == 2){
            filename = "Spesifikasi_Program/Inisialisasi/play-song/playing 3.txt";
        } else if (i == 3){
            filename = "Spesifikasi_Program/Inisialisasi/play-song/playing 4.txt";
        } else if (i == 4){
            filename = "Spesifikasi_Program/Inisialisasi/play-song/playing 5.txt";
        }
        fascii = NULL;
        fascii = fopen(filename,"r");
        if(fascii  == NULL){
            printf("error opening %s\n",filename);
        } else {
            system("cls || clear");
            print_image(fascii);
            fclose(fascii);
        }
        delay(1);
    }
}

void AnimasiSongNext(){
    char *filename;
    FILE *fascii;
    system("cls || clear");
    for (int i = 0; i < 4; i++){
        if (i == 0) {
            filename = "Spesifikasi_Program/Inisialisasi/song/song1.txt";
        } else if (i == 1){
            filename = "Spesifikasi_Program/Inisialisasi/song/song2.txt";
        } else if (i == 2){
            filename = "Spesifikasi_Program/Inisialisasi/song/song3.txt";
        } else if (i == 3){
            filename = "Spesifikasi_Program/Inisialisasi/song/song4.txt";
        } 
        fascii = NULL;
        fascii = fopen(filename,"r");
        if(fascii  == NULL){
            printf("error opening %s\n",filename);
        } else {
            system("cls || clear");
            print_image(fascii);
            fclose(fascii);
        }
        delay(1);
    }
}

void AnimasiSongPrev(){
    char *filename;
    FILE *fascii;
    system("cls || clear");
    for (int i = 0; i < 5; i++){
        if (i == 0) {
            filename = "Spesifikasi_Program/Inisialisasi/song/song6.txt";
        } else if (i == 1){
            filename = "Spesifikasi_Program/Inisialisasi/song/song3.txt";
        } else if (i == 2){
            filename = "Spesifikasi_Program/Inisialisasi/song/song2.txt";
        } else if (i == 3){
            filename = "Spesifikasi_Program/Inisialisasi/song/song1.txt";
        } else if (i == 4){
            filename = "Spesifikasi_Program/Inisialisasi/song/song5.txt";
        } 
        fascii = NULL;
        fascii = fopen(filename,"r");
        if(fascii  == NULL){
            printf("error opening %s\n",filename);
        } else {
            system("cls || clear");
            print_image(fascii);
            fclose(fascii);
        }
        delay(1);
    }
}

void AnimasiPlayPlaylist(){
    char *filename;
    FILE *fascii;
    system("cls || clear");
    for (int i = 0; i < 5; i++){
        if (i == 0) {
            filename = "Spesifikasi_Program/Inisialisasi/play-playlist/playing 1.txt";
        } else if (i == 1){
            filename = "Spesifikasi_Program/Inisialisasi/play-playlist/playing 2.txt";
        } else if (i == 2){
            filename = "Spesifikasi_Program/Inisialisasi/play-playlist/playing 3.txt";
        } else if (i == 3){
            filename = "Spesifikasi_Program/Inisialisasi/play-playlist/playing 4.txt";
        } else if (i == 4){
            filename = "Spesifikasi_Program/Inisialisasi/play-playlist/playing 5.txt";
        }
        fascii = NULL;
        fascii = fopen(filename,"r");
        if(fascii  == NULL){
            printf("error opening %s\n",filename);
        } else {
            system("cls || clear");
            print_image(fascii);
            fclose(fascii);
        }
        delay(1);
    }
}

void AnimasiQueueSong(){
    char *filename;
    FILE *fascii;
    system("cls || clear");
    for (int i = 0; i < 4; i++){
        if (i == 0) {
            filename = "Spesifikasi_Program/Inisialisasi/queue/queue1.txt";
        } else if (i == 1){
            filename = "Spesifikasi_Program/Inisialisasi/queue/queue2.txt";
        } else if (i == 2){
            filename = "Spesifikasi_Program/Inisialisasi/queue/queue3.txt";
        } else if (i == 3){
            filename = "Spesifikasi_Program/Inisialisasi/queue/queue4.txt";
        } 
        fascii = NULL;
        fascii = fopen(filename,"r");
        if(fascii  == NULL){
            printf("error opening %s\n",filename);
        } else {
            system("cls || clear");
            print_image(fascii);
            fclose(fascii);
        }
        delay(1);
    }
}

void AnimasiQueuePlaylist(){
    char *filename;
    FILE *fascii;
    system("cls || clear");
    for (int i = 0; i < 4; i++){
        if (i == 0) {
            filename = "Spesifikasi_Program/Inisialisasi/queue/queue1.txt";
        } else if (i == 1){
            filename = "Spesifikasi_Program/Inisialisasi/queue/queue2.txt";
        } else if (i == 2){
            filename = "Spesifikasi_Program/Inisialisasi/queue/queue3.txt";
        } else if (i == 3){
            filename = "Spesifikasi_Program/Inisialisasi/queue/queue5.txt";
        } 
        fascii = NULL;
        fascii = fopen(filename,"r");
        if(fascii  == NULL){
            printf("error opening %s\n",filename);
        } else {
            system("cls || clear");
            print_image(fascii);
            fclose(fascii);
        }
        delay(1);
    }
}

void AnimasiSwap(){
    char *filename;
    FILE *fascii;
    system("cls || clear");
    for (int i = 0; i < 5; i++){
        if (i == 0) {
            filename = "Spesifikasi_Program/Inisialisasi/swap/swap1.txt";
        } else if (i == 1){
            filename = "Spesifikasi_Program/Inisialisasi/swap/swap2.txt";
        } else if (i == 2){
            filename = "Spesifikasi_Program/Inisialisasi/swap/swap3.txt";
        } else if (i == 3){
            filename = "Spesifikasi_Program/Inisialisasi/swap/swap4.txt";
        } else if (i == 4){
            filename = "Spesifikasi_Program/Inisialisasi/swap/swap5.txt";
        } 
        fascii = NULL;
        fascii = fopen(filename,"r");
        if(fascii  == NULL){
            printf("error opening %s\n",filename);
        } else {
            system("cls || clear");
            print_image(fascii);
            fclose(fascii);
        }
        delay(1);
    }
}

void AnimasiCreatePlaylist(){
    char *filename;
    FILE *fascii;
    system("cls || clear");
    for (int i = 0; i < 3; i++){
        if (i == 0) {
            filename = "Spesifikasi_Program/Inisialisasi/playlist/playlist1.txt";
        } else if (i == 1){
            filename = "Spesifikasi_Program/Inisialisasi/playlist/playlist2.txt";
        } else if (i == 2){
            filename = "Spesifikasi_Program/Inisialisasi/playlist/playlist3.txt";
        } 
        fascii = NULL;
        fascii = fopen(filename,"r");
        if(fascii  == NULL){
            printf("error opening %s\n",filename);
        } else {
            system("cls || clear");
            print_image(fascii);
            fclose(fascii);
        }
        delay(1);
    }
}

void AnimasiDeletePlaylist(){
    char *filename;
    FILE *fascii;
    system("cls || clear");
    for (int i = 0; i < 4; i++){
        if (i == 0) {
            filename = "Spesifikasi_Program/Inisialisasi/playlist/playlist3.txt";
        } else if (i == 1){
            filename = "Spesifikasi_Program/Inisialisasi/playlist/playlist4.txt";
        } else if (i == 2){
            filename = "Spesifikasi_Program/Inisialisasi/playlist/playlist5.txt";
        } else if (i == 3){
            filename = "Spesifikasi_Program/Inisialisasi/playlist/playlist6.txt";
        } 
        fascii = NULL;
        fascii = fopen(filename,"r");
        if(fascii  == NULL){
            printf("error opening %s\n",filename);
        } else {
            system("cls || clear");
            print_image(fascii);
            fclose(fascii);
        }
        delay(1);
    }
}

void AnimasiPlaylistAdd(){
    char *filename;
    FILE *fascii;
    system("cls || clear");
    for (int i = 0; i < 6; i++){
        if (i == 0) {
            filename = "Spesifikasi_Program/Inisialisasi/playlist-add/playlist-add1.txt";
        } else if (i == 1){
            filename = "Spesifikasi_Program/Inisialisasi/playlist-add/playlist-add2.txt";
        } else if (i == 2){
            filename = "Spesifikasi_Program/Inisialisasi/playlist-add/playlist-add3.txt";
        } else if (i == 3){
            filename = "Spesifikasi_Program/Inisialisasi/playlist-add/playlist-add4.txt";
        } else if (i == 4){
            filename = "Spesifikasi_Program/Inisialisasi/playlist-add/playlist-add5.txt";
        } else if (i == 5){
            filename = "Spesifikasi_Program/Inisialisasi/playlist-add/playlist-add6.txt";
        } 
        fascii = NULL;
        fascii = fopen(filename,"r");
        if(fascii  == NULL){
            printf("error opening %s\n",filename);
        } else {
            system("cls || clear");
            print_image(fascii);
            fclose(fascii);
        }
        delay(1);
    }
}

void AnimasiPlaylistRemove(){
    char *filename;
    FILE *fascii;
    system("cls || clear");
    for (int i = 0; i < 7; i++){
        if (i == 0) {
            filename = "Spesifikasi_Program/Inisialisasi/playlist-remove/playlist-remove6.txt";
        } else if (i == 1){
            filename = "Spesifikasi_Program/Inisialisasi/playlist-remove/playlist-remove5.txt";
        } else if (i == 2){
            filename = "Spesifikasi_Program/Inisialisasi/playlist-remove/playlist-remove4.txt";
        } else if (i == 3){
            filename = "Spesifikasi_Program/Inisialisasi/playlist-remove/playlist-remove3.txt";
        } else if (i == 4){
            filename = "Spesifikasi_Program/Inisialisasi/playlist-remove/playlist-remove2.txt";
        } else if (i == 5){
            filename = "Spesifikasi_Program/Inisialisasi/playlist-remove/playlist-remove1.txt";
        } else if (i == 6){
            filename = "Spesifikasi_Program/Inisialisasi/playlist-remove/playlist-remove.txt";
        } 
        fascii = NULL;
        fascii = fopen(filename,"r");
        if(fascii  == NULL){
            printf("error opening %s\n",filename);
        } else {
            system("cls || clear");
            print_image(fascii);
            fclose(fascii);
        }
        delay(1);
    }
}

void AnimasiPlaylistEnhance(){
    char *filename;
    FILE *fascii;
    system("cls || clear");
    for (int i = 0; i < 6; i++){
        if (i == 0) {
            filename = "Spesifikasi_Program/Inisialisasi/playlist-add/playlist-add1.txt";
        } else if (i == 1){
            filename = "Spesifikasi_Program/Inisialisasi/playlist-add/playlist-add2.txt";
        } else if (i == 2){
            filename = "Spesifikasi_Program/Inisialisasi/playlist-add/playlist-add3.txt";
        } else if (i == 3){
            filename = "Spesifikasi_Program/Inisialisasi/playlist-add/playlist-add4.txt";
        } else if (i == 4){
            filename = "Spesifikasi_Program/Inisialisasi/playlist-add/playlist-add5.txt";
        } else if (i == 5){
            filename = "Spesifikasi_Program/Inisialisasi/playlist-add/playlist-add6.txt";
        } 
        fascii = NULL;
        fascii = fopen(filename,"r");
        if(fascii  == NULL){
            printf("error opening %s\n",filename);
        } else {
            system("cls || clear");
            print_image(fascii);
            fclose(fascii);
        }
        delay(1);
    }
}



void AnimasiRegister(){
    char *filename;
    FILE *fascii;
    system("cls || clear");
    for (int i = 0; i < 3; i++){
        if (i == 0) {
            filename = "Spesifikasi_Program/Inisialisasi/register/register3.txt";
        } else if (i == 1){
            filename = "Spesifikasi_Program/Inisialisasi/register/register2.txt";
        } else if (i == 2){
            filename = "Spesifikasi_Program/Inisialisasi/register/register1.txt";
        } 
        fascii = NULL;
        fascii = fopen(filename,"r");
        if(fascii  == NULL){
            printf("error opening %s\n",filename);
        } else {
            system("cls || clear");
            print_image(fascii);
            fclose(fascii);
        }
        delay(2);
    }
}

void AnimasiLogin(){
    char *filename;
    FILE *fascii;
    system("cls || clear");
    for (int i = 0; i < 3; i++){
        if (i == 0) {
            filename = "Spesifikasi_Program/Inisialisasi/login/login3.txt";
        } else if (i == 1){
            filename = "Spesifikasi_Program/Inisialisasi/login/login2.txt";
        } else if (i == 2){
            filename = "Spesifikasi_Program/Inisialisasi/login/login1.txt";
        } 
        fascii = NULL;
        fascii = fopen(filename,"r");
        if(fascii  == NULL){
            printf("error opening %s\n",filename);
        } else {
            system("cls || clear");
            print_image(fascii);
            fclose(fascii);
        }
        delay(1);
    }
}

void AnimasiLogout(){
    char *filename;
    FILE *fascii;
    system("cls || clear");
    for (int i = 0; i < 4; i++){
        if (i == 0) {
            filename = "Spesifikasi_Program/Inisialisasi/logout/logout.txt";
        } else if (i == 1){
            filename = "Spesifikasi_Program/Inisialisasi/logout/logout1.txt";
        } else if (i == 2){
            filename = "Spesifikasi_Program/Inisialisasi/logout/logout2.txt";
        } else if (i == 3){
            filename = "Spesifikasi_Program/Inisialisasi/logout/logout3.txt";
        } 
        fascii = NULL;
        fascii = fopen(filename,"r");
        if(fascii  == NULL){
            printf("error opening %s\n",filename);
        } else {
            system("cls || clear");
            print_image(fascii);
            fclose(fascii);
        }
        delay(1);
    }
}


// int main(){
//     inisialisasi();
// }

