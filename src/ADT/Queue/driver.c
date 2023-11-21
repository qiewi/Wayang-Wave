#include <stdio.h>
#include "queue.h"

int main() {
    
    QueueLagu q;
    Kalimat JudulLagu, NamaAlbum, NamaPenyanyi;
    int id = 0;

    // Membuat Queue Lagu
    printf("Membuat Queue Lagu...\n");
    CreateQueueLagu(&q);

    // Memeriksa apakah Queue kosong
    printf("Apakah Queue kosong? %s\n", isEmpty(q) ? "Ya" : "Tidak");

    // Memeriksa apakah Queue penuh
    printf("Apakah Queue penuh? %s\n", isFull(q) ? "Ya" : "Tidak");

    // Menampilkan isi Queue
    printf("Isi Queue saat ini:\n");
    displayQueueLagu(q);

    return 0;
}
