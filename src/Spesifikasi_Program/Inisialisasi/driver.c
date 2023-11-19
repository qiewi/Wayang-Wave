#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "inisialisasi.h"
#include "../../ADT/pcolor/pcolor.h"

int main() {
    // Inisialisasi
    printf("Memulai inisialisasi...\n");
    inisialisasi();

    // Animasi Load
    printf("Memulai animasi load...\n");
    AnimasiLoad();

    // Animasi Save
    printf("Memulai animasi save...\n");
    AnimasiSave();

    // Animasi Quit
    printf("Memulai animasi quit...\n");
    AnimasiQuit();

    // Animasi Play Song
    printf("Memulai animasi play song...\n");
    AnimasiPlaySong();

    // Animasi Play Playlist
    printf("Memulai animasi play playlist...\n");
    AnimasiPlayPlaylist();

    // Animasi Register
    printf("Memulai animasi register...\n");
    AnimasiRegister();

    // Animasi Login
    printf("Memulai animasi login...\n");
    AnimasiLogin();

    return 0;
}
