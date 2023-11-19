#include <stdio.h>
#include <stdlib.h>
#include "../../ADT/pcolor/pcolor.h"
#include "../../ADT/Stack/RiwayatLagu.h"
#include "../Queue/Queue.h"
#include "../Play/Play.h"
#include "Status.h"

int main() {
    CurrentSong CS;
    CurrentUser CU;
    QueueLagu QL;
    RiwayatLagu RL;

    // Inisialisasi CurrentSong, CurrentUser, QueueLagu, dan RiwayatLagu
    // Asumsikan inisialisasi CurrentSong, CurrentUser, QueueLagu, dan RiwayatLagu telah diimplementasikan

    // Menetapkan status lagu saat ini, user, antrian lagu, dan riwayat lagu
    // Misalnya, set nilai untuk CS, CU, QL, dan RL

    // Memanggil fungsi Status untuk menampilkan status lagu saat ini, antrian lagu, dan riwayat lagu
    printf("Menampilkan Status...\n");
    Status(&CS, &CU, &QL, &RL);

    return 0;
}
