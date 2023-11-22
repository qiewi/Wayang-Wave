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

// MAIN MENU
void inisialisasi();

void AnimasiLoad();

void AnimasiSave();

void AnimasiQuit();

void AnimasiHelp();

// STATUS & LIST
void AnimasiStatus();

void AnimasiList();

// SONG
void AnimasiSongNext();

void AnimasiSongPrev();

// PLAY
void AnimasiPlaySong();

void AnimasiPlayPlaylist();

// QUEUE
void AnimasiQueueSong();

void AnimasiQueuePlaylist();

// SWAP
void AnimasiSwap();

// PLAYLIST
void AnimasiCreatePlaylist();

void AnimasiDeletePlaylist();

void AnimasiPlaylistAdd();

void AnimasiPlaylistEnhance();

void AnimasiPlaylistRemove();

// MULTI-USER
void AnimasiRegister();

void AnimasiLogin();

void AnimasiLogout();


#endif