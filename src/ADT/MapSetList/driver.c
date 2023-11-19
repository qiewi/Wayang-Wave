#include <stdio.h>
#include "mapsetlist.h"
#include "../LineMachine/linemachine.h"

int main() 
{
    ListPenyanyi LP;
    Kalimat NamaPenyanyi, NamaAlbum, NamaLagu;

    // Membuat List Penyanyi
    printf("Membuat List Penyanyi...\n");
    CreateListPenyanyi(&LP);

    // Menambahkan Penyanyi
    printf("Menambahkan Penyanyi...\n");
    STARTKALIMATINPUT();
    NamaPenyanyi = CInput; 
    AddPenyanyi(&LP, NamaPenyanyi);
    printf("Penyanyi Terakhir: %s\n", NamaPenyanyiNow(&LP).TabLine);

    // Menambahkan Album
    printf("Menambahkan Album...\n");
    STARTKALIMATINPUT();
    NamaAlbum = CInput;
    AddAlbum(&LP, NamaAlbum);
    printf("Album Terakhir: %s\n", NamaAlbumNow(&LP).TabLine);

    // Menambahkan Lagu
    printf("Menambahkan Lagu...\n");
    STARTKALIMATINPUT();
    NamaLagu = CInput;
    AddLagu(&LP, NamaLagu);
    printf("Lagu Terakhir: %s\n", NamaLaguNow(&LP).TabLine);

    return 0;
}
