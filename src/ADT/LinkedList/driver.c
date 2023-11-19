#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main() {
    List L;
    infoType X;

    // Membuat List Kosong
    printf("Membuat List Kosong...\n");
    CreateEmpty(&L);
    PrintInfo(L);

    // Memeriksa apakah List kosong
    printf("Memeriksa apakah List kosong: %s\n", IsEmptyLinked(L) ? "Ya" : "Tidak");

    // Menambahkan elemen ke List
    printf("Menambahkan elemen ke List...\n");
    int X =  10;

    InsVLast(&L, X);
    PrintInfo(L);

    // Menghapus elemen dari List
    printf("Menghapus elemen pertama dari List...\n");
    DelVFirst(&L, &X);
    PrintInfo(L);

    printf("Menghapus elemen terakhir dari List...\n");
    DelVLast(&L, &X);
    PrintInfo(L);

    // Menambahkan kembali elemen ke List untuk pengujian selanjutnya
    InsVFirst(&L, X);
    InsVLast(&L, X);

    // Menghitung jumlah elemen dalam List
    printf("Jumlah elemen dalam List: %d\n", NbElmt(L));

    return 0;
}
