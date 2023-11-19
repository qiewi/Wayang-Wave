#include <stdio.h>
#include <stdlib.h>
#include "../../ADT/pcolor/pcolor.h"
#include "../../ADT/Stack/RiwayatLagu.h"
#include "../../ADT/Queue/queue.h"
#include "../../ADT/LineMachine/linemachine.h"
#include "../../ADT/MapSetList/mapsetlist.h"

#include "../Inisialisasi/inisialisasi.h"
#include "Play.h"

int main() {
    ListPenyanyi LP;
    CurrentSong CS;
    CurrentUser CU;
    QueueLagu QL;
    RiwayatLagu RL;

    // Inisialisasi CurrentSong dan CurrentUser
    printf("Inisialisasi CurrentSong dan CurrentUser...\n");
    CreateCurrentSong(&CS);
    CreateCurrentUser(&CU);

    // Proses menambahkan lagu
    printf("Menambahkan lagu...\n");
    // Disini asumsikan nilai idPenyanyi, idAlbum, idLagu telah ditentukan
    // AddSong(&LP, &CS, idPenyanyi, idAlbum, idLagu);

    // Proses memutar lagu
    printf("Memutar lagu...\n");
    PlaySong(&LP, &CS, &QL, &RL);

    // Proses mengambil lagu dari riwayat
    printf("Mengambil lagu dari riwayat...\n");
    PopRiwayatLagu(&RL, &CS);

    return 0;
}
