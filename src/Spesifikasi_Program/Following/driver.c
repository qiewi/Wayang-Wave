#include <stdio.h>
#include <stdlib.h>
#include "../../ADT/graph/graph.h"
#include "../../ADT/pcolor/pcolor.h"

#include "../Play/Play.h"
#include "../MultiUser/MultiUser.h"

int main() {
    DataUser DU;
    CurrentUser CU;

    // Inisialisasi DataUser dan CurrentUser
    printf("Inisialisasi DataUser dan CurrentUser...\n");
    // Asumsikan fungsi inisialisasi telah diimplementasikan
    // inisialisasiDataUser(&DU);
    // inisialisasiCurrentUser(&CU);

    // Follow Friend
    printf("Mencoba Follow Friend...\n");
    FollowFriend(&DU, &CU);

    // List Following
    printf("Menampilkan List Following...\n");
    ListFollowing(&DU, &CU);

    return 0;
}
