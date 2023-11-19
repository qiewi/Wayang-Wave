#include <stdio.h>
#include <stdlib.h>
#include "../../ADT/boolean.h"
#include "../../ADT/Queue/queue.h"
#include "../../ADT/MapSetList/mapsetlist.h"
#include "../../ADT/Stack/RiwayatLagu.h"
#include "../../ADT/LinkedList/linkedlist.h"
#include "../../ADT/array/arraydinamis.h"
#include "../../ADT/LineMachine/linemachine.h"
#include "../../ADT/pcolor/pcolor.h"

#include "../Inisialisasi/inisialisasi.h"
#include "../Play/Play.h"
#include "MultiUser.h"

int main() {
    DataUser DU;
    ArrayDin AP;
    CurrentSong CS;
    CurrentUser CU;
    QueueLagu QL;
    RiwayatLagu RL;
    boolean sesi;

    // Membuat Data User
    printf("Membuat Data User...\n");
    CreateDataUser(&DU);

    // Proses Registrasi User
    printf("Registrasi User...\n");
    RegisterUser(&DU);

    // Proses Login
    printf("Login User...\n");
    Login(&DU, &AP, &CS, &CU, &QL, &RL, &sesi);

    // Proses Logout
    printf("Logout User...\n");
    Logout(&DU, &AP, &CS, &CU, &QL, &RL, CU.idUser);

    return 0;
}
