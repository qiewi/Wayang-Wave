#ifndef __INISIALISASI_H__
#define __INISIALISASI_H__

/* *** ******** ******** ******** ******** ******** ****** ** INCLUDED ADT & SPEK ** ****** ******** ******** ******** ******** ******** *** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../ADT/pcolor/pcolor.h"

#define MAX_LEN 5000

/* *** ******** ******** ******** ******** ******** ****** ** COMMAND SPEK ** ****** ******** ******** ******** ******** ******** *** */

void delay(int number_of_seconds);

void print_image(FILE *fascii);

void inisialisasi();

void AnimasiLoad();

void AnimasiSave();

void AnimasiQuit();

void AnimasiPlaySong();

void AnimasiPlayPlaylist();

void AnimasiQueueSong();

void AnimasiQueuePlaylist();

void AnimasiCreatePlaylist();

void AnimasiPlaylistAdd();

void AnimasiPlaylistEnhance();

void AnimasiRegister();

void AnimasiLogin();

void AnimasiLogout();

// int main(){
//     inisialisasi();
// }

#endif