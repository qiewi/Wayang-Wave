#include <stdio.h>
#include "../../ADT/boolean.h"
#include "../../ADT/pcolor/pcolor.h"
#include "help.h"

int main() {
    boolean sesi, data;

    // Contoh pengujian fungsi help sebelum masuk sesi
    printf("Menampilkan menu bantuan sebelum masuk sesi...\n");
    sesi = false;
    data = false;
    help(sesi, data);

    // Contoh pengujian fungsi help setelah masuk sesi tapi sebelum login
    printf("\nMenampilkan menu bantuan setelah masuk sesi tapi sebelum login...\n");
    sesi = false;
    data = true;
    help(sesi, data);

    // Contoh pengujian fungsi help setelah masuk sesi dan setelah login
    printf("\nMenampilkan menu bantuan setelah masuk sesi dan setelah login...\n");
    sesi = true;
    data = true;
    help(sesi, data);

    return 0;
}
