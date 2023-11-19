#include <stdio.h>
#include <stdlib.h>
#include "../../ADT/pcolor/pcolor.h"
#include "../../ADT/LineMachine/linemachine.h"
#include "../../ADT/LinkedList/linkedlist.h"
#include "../../ADT/array/arraydinamis.h"
#include "../../ADT/MapSetList/mapsetlist.h"

int main() {
    ListPenyanyi LP;
    ArrayDin AP;

    // Inisialisasi ListPenyanyi dan ArrayDin
    printf("Inisialisasi ListPenyanyi dan ArrayDin...\n");
    // Asumsikan fungsi inisialisasi telah diimplementasikan
    // inisialisasiListPenyanyi(&LP);
    // inisialisasiArrayDin(&AP);

    // Menampilkan daftar penyanyi, album, dan lagu
    printf("Menampilkan daftar penyanyi, album, dan lagu...\n");
    DisplayListDefault(&LP);

    // Menampilkan daftar playlist
    printf("Menampilkan daftar playlist...\n");
    displayPlaylist(&AP);

    return 0;
}
