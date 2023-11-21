#include <stdio.h>
#include "RiwayatLagu.h"

int main() {
    
    RiwayatLagu RL;
    Kalimat JudulLagu, NamaAlbum, NamaPenyanyi;

    // Membuat Riwayat Lagu
    printf("Membuat Riwayat Lagu...\n");
    CreateRiwayatLagu(&RL);

    // Menambahkan lagu ke Riwayat
    printf("Menambahkan lagu ke Riwayat...\n");
    // Misalnya, tentukan nilai JudulLagu, NamaAlbum, NamaPenyanyi
    // JudulLagu = /* Nilai Kalimat Judul Lagu */;
    // NamaAlbum = /* Nilai Kalimat Nama Album */;
    // NamaPenyanyi = /* Nilai Kalimat Nama Penyanyi */;
    PushRiwayatLagu(&RL, JudulLagu, NamaAlbum, NamaPenyanyi);

    // Menghapus lagu terakhir dari Riwayat
    // printf("Menghapus lagu terakhir dari Riwayat...\n");
    // CurrentSong CS;
    // PopRiwayatLagu(&RL, &CS);

    // Menampilkan informasi lagu terakhir
    // printf("Lagu terakhir di Riwayat: %s, Album: %s, Penyanyi: %s\n",
    //        CS.JudulLagu.TabLine, CS.NamaAlbum.TabLine, CS.NamaPenyanyi.TabLine);

    return 0;
}
