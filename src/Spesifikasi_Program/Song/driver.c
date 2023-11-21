#include <stdio.h>
#include <stdlib.h>
#include "../../ADT/MapSetList/mapsetlist.h"
#include "../../ADT/pcolor/pcolor.h"
#include "../../ADT/Queue/queue.h"
#include "../../ADT/Stack/RiwayatLagu.h"
#include "../../ADT/LineMachine/linemachine.h"
#include "../../ADT/LinkedList/linkedlist.h"
#include "../../ADT/array/arraydinamis.h"

#include "../Play/Play.h"
#include "../Playlist/Playlist.h"
#include "../Inisialisasi/inisialisasi.h"

int main() {
    QueueLagu QL;
    CurrentSong CS;
    RiwayatLagu RL;
    ListPenyanyi LP;
    ArrayDin AP;
    CurrentUser CU;

    // Inisialisasi QueueLagu, CurrentSong, dan RiwayatLagu
    // Asumsikan inisialisasi QueueLagu, CurrentSong, dan RiwayatLagu telah diimplementasikan
    
    // Menambahkan lagu ke antrian
    printf("Menambahkan lagu ke antrian...\n");
    // enqueueLagu(&QL, JudulLagu, NamaAlbum, NamaPenyanyi);

    // Menghapus lagu dari antrian
    printf("Menghapus lagu dari antrian...\n");
    // dequeueLagu(&QL, &RL, idLagu);

    // Menukar lagu di antrian
    printf("Menukar lagu di antrian...\n");
    // QueueSwap(&QL, idLagu1, idLagu2);

    // Menghapus semua lagu dari antrian
    printf("Mengosongkan antrian...\n");
    // QueueClear(&QL);

    // Menambahkan lagu dari playlist ke antrian
    printf("Menambahkan lagu dari playlist ke antrian...\n");
    // QueuePlaylist(&AP, &QL, &CS, &RL);

    return 0;
}
