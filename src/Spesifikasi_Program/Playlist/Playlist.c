#include <stdio.h>
#include <stdlib.h>
#include "../../ADT/boolean.h"
#include "../../ADT/LineMachine/linemachine.h"
#include "../../ADT/LinkedList/linkedlist.h"
#include "../../ADT/MapSetList/mapsetlist.h"
#include "../../ADT/array/arraydinamis.h"
#include "../../ADT/pcolor/pcolor.h"
#include "Playlist.h"

void PlaylistCreate(ArrayDin * AP) // to do list: cek panjang karakter
{
    printf("\nMasukkan nama playlist yang ingin dibuat : ");
    STARTKALIMATINPUT();

    InsertNama(AP, CInput);

    printf("\n%sPlaylist %s%s %sberhasil dibuat!", GREEN, WHITE, CInput.TabLine, GREEN);
    printf("\n%sSilahkan masukkan lagu-lagu artis terkini kesayangan Anda!\n", WHITE);
}

int checkLagu(ArrayDin * AP, int idPlaylist, Kalimat NamaLagu)
{   
    address p = First((*AP).A[idPlaylist]);

    while (p != Nil)
    {
        if (isKalimatEqual(JudulLagu(p), NamaLagu))
        {
            return -1;
        }
        else
        {
            p = Next(p);
        }
    }

    return 0;
}

void PlayListRemoveLagu(ArrayDin * AP, int idPlaylist, int idLagu)
{
    if (idPlaylist > (*AP).Neff || idPlaylist <= 0)
    {
        printf("\n%sERROR: %sTidak ada playlist dengan ID %d.\n", RED, WHITE, idPlaylist);
    }
    else
    {
        Kalimat namaPlaylist = (*AP).Nama[idPlaylist-1];

        DelP(namaPlaylist, &(*AP).A[idPlaylist-1], idLagu);
    }
}

void AddSongToPlaylist(ListPenyanyi * LP, ArrayDin * AP, int idPenyanyi, int idAlbum, int idLagu, int idPlaylist)
{
    infoType Data;
    Data.NamaPenyanyi = (*LP).PenyanyiAlbum[idPenyanyi].NamaPenyanyi;
    Data.NamaAlbum = (*LP).PenyanyiAlbum[idPenyanyi].ListAlbum.AlbumLagu[idAlbum].NamaAlbum;
    Data.JudulLagu = (*LP).PenyanyiAlbum[idPenyanyi].ListAlbum.AlbumLagu[idAlbum].IsiLagu.JudulLagu[idLagu];

    InsVLast(&((*AP).A[idPlaylist]), Data);
    // (*CS).NamaAlbum = 
    // (*CS).JudulLagu = (*LP).PenyanyiAlbum[idPenyanyi].ListAlbum.AlbumLagu[idAlbum].IsiLagu.JudulLagu[idLagu];
}

void AddAlbumToPlaylist(ListPenyanyi * LP, ArrayDin * AP, int idPenyanyi, int idAlbum, int idPlaylist) // to do list: bikin checkLagu
{   
    infoType Data;
    for (int i = 0; i < (*LP).PenyanyiAlbum[idPenyanyi].ListAlbum.AlbumLagu[idAlbum].IsiLagu.Count; i++)
    {
        Data.NamaPenyanyi = (*LP).PenyanyiAlbum[idPenyanyi].NamaPenyanyi;
        Data.NamaAlbum = (*LP).PenyanyiAlbum[idPenyanyi].ListAlbum.AlbumLagu[idAlbum].NamaAlbum;
        Data.JudulLagu = (*LP).PenyanyiAlbum[idPenyanyi].ListAlbum.AlbumLagu[idAlbum].IsiLagu.JudulLagu[i];

        if (checkLagu(AP, idPlaylist, Data.JudulLagu) != -1)
        {    
            InsVLast(&((*AP).A[idPlaylist]), Data);
        }
    }
    // (*CS).NamaAlbum = 
    // (*CS).JudulLagu = (*LP).PenyanyiAlbum[idPenyanyi].ListAlbum.AlbumLagu[idAlbum].IsiLagu.JudulLagu[idLagu];
}

void PlaylistAddLagu(ArrayDin * AP, ListPenyanyi * LP)
{
    int id = -1; // kalau -1 dia undefined (ga ada penyanyi / album)

    printf("%s\nDaftar Penyanyi :\n", GREEN);
    for (int i = 0; i < (*LP).NEff; i++)
    {
        printf("  %s%d. %s \n", WHITE, i+1, (*LP).PenyanyiAlbum[i].NamaPenyanyi.TabLine);
    }

    printf("\nMasukkan Nama Penyanyi yang dipilih : %s", GREEN);
    STARTKALIMATINPUT();
    // printf("%s\n", CInput.TabLine);
    // cek nama penyanyi yang diinput

    int idPenyanyi = indeksPenyanyi(LP, CInput);

    if (idPenyanyi != -1)
    {
        printf("\nDaftar Album oleh %s%s :\n", YELLOW, CInput.TabLine);
        for (int i = 0; i < (*LP).PenyanyiAlbum[idPenyanyi].ListAlbum.NEff; i++) // print list Album
        {
            printf("  %s%d. %s \n", WHITE, i+1, (*LP).PenyanyiAlbum[idPenyanyi].ListAlbum.AlbumLagu[i].NamaAlbum.TabLine);
        }
        
        printf("\nMasukkan Nama Album yang dipilih: %s", GREEN);
        STARTKALIMATINPUT();

        int idAlbum = indeksAlbum(LP, idPenyanyi, CInput);
        // printf("%s\n", CInput.TabLine);

        if (idAlbum != -1)
        {
            printf("\nDaftar Lagu Album %s%s %soleh %s%s:\n", YELLOW, CInput.TabLine, GREEN, YELLOW, (*LP).PenyanyiAlbum[idPenyanyi].NamaPenyanyi.TabLine); // print list Lagu
            for (int i = 0; i < (*LP).PenyanyiAlbum[idPenyanyi].ListAlbum.AlbumLagu[idAlbum].IsiLagu.Count; i++)
            {
            printf("  %s%d. %s \n",WHITE, i+1, (*LP).PenyanyiAlbum[idPenyanyi].ListAlbum.AlbumLagu[idAlbum].IsiLagu.JudulLagu[i].TabLine);
            }

            printf("\nMasukkan ID Lagu yang dipilih : ");
            STARTKALIMATINPUT();

            int idLagu = CInput.TabLine[0] - 49;
            if (idLagu < (*LP).PenyanyiAlbum[idPenyanyi].ListAlbum.AlbumLagu[idAlbum].IsiLagu.Count)
            {
                printf("Daftar Playlist Pengguna: \n");

                for (int p = 0; p < (*AP).Neff; p++)
                {
                    printf("    %d. %s \n", p+1, (*AP).Nama[p].TabLine);
                }

                printf("\nMasukkan ID Playlist yang dipilih : ");
                STARTKALIMATINPUT();

                int idPlaylist = CInput.TabLine[0] - 49; // to do list: bikin verifikasi id

                if (idPlaylist+1 > (*AP).Neff || idPlaylist+1 <= 0)
                {
                    printf("\n%sERROR: %sTidak ada playlist dengan ID %d.\n", RED, WHITE, idPlaylist);
                }
                else
                {
                    AddSongToPlaylist(LP, AP, idPenyanyi, idAlbum, idLagu, idPlaylist);

                    Kalimat JudulLagu =  (*LP).PenyanyiAlbum[idPenyanyi].ListAlbum.AlbumLagu[idAlbum].IsiLagu.JudulLagu[idLagu];
                    Kalimat NamaAlbum = (*LP).PenyanyiAlbum[idPenyanyi].ListAlbum.AlbumLagu[idAlbum].NamaAlbum;
                    Kalimat NamaPenyanyi = (*LP).PenyanyiAlbum[idPenyanyi].NamaPenyanyi;

                    // address p = First((*AP).A[idPlaylist]);
                    // p = Next(p);
                    // printf("\nIsi Playlist: %s\n", JudulLagu(p).TabLine);
                    printf("%sLagu dengan judul %s\"%s\" %spada album %s%s %soleh penyanyi %s%s %sberhasil ditambahkan ke dalam playlist %s%s.\n",GREEN, WHITE, JudulLagu.TabLine, GREEN, WHITE, NamaAlbum.TabLine, GREEN, WHITE, NamaPenyanyi.TabLine, GREEN, WHITE, (*AP).Nama[idPlaylist].TabLine);    
                }
            }
            else
            {
                printf("\n%sERROR: %sID Lagu tidak ada.\n", RED, WHITE);
            }
        }
        else
        {
            printf("\n%sERROR: %sAlbum tidak terdaftar.\n", RED, WHITE);
        }
    }
    else
    {
        printf("\n%sERROR: %sPenyanyi tidak terdaftar.\n", RED, WHITE);
    }    
}

void PlaylistAddAlbum(ArrayDin * AP, ListPenyanyi * LP)
{
    int id = -1; // kalau -1 dia undefined (ga ada penyanyi / album)

    printf("%s\nDaftar Penyanyi :\n", GREEN);
    for (int i = 0; i < (*LP).NEff; i++)
    {
        printf("  %s%d. %s \n", WHITE, i+1, (*LP).PenyanyiAlbum[i].NamaPenyanyi.TabLine);
    }

    printf("\nMasukkan Nama Penyanyi yang dipilih : %s", GREEN);
    STARTKALIMATINPUT();
    // printf("%s\n", CInput.TabLine);
    // cek nama penyanyi yang diinput

    int idPenyanyi = indeksPenyanyi(LP, CInput);

    if (idPenyanyi != -1)
    {
        printf("\nDaftar Album oleh %s%s :\n", YELLOW, CInput.TabLine);
        for (int i = 0; i < (*LP).PenyanyiAlbum[idPenyanyi].ListAlbum.NEff; i++) // print list Album
        {
            printf("  %s%d. %s \n", WHITE, i+1, (*LP).PenyanyiAlbum[idPenyanyi].ListAlbum.AlbumLagu[i].NamaAlbum.TabLine);
        }
        
        printf("\nMasukkan Nama Album yang dipilih: %s", GREEN);
        STARTKALIMATINPUT();

        int idAlbum = indeksAlbum(LP, idPenyanyi, CInput);
        // printf("%s\n", CInput.TabLine);

        if (idAlbum != -1)
        {
                printf("\nDaftar Playlist Pengguna: %s\n", WHITE);

                for (int p = 0; p < (*AP).Neff; p++)
                {
                    printf("    %d. %s \n", p+1, (*AP).Nama[p].TabLine);
                }

                printf("\nMasukkan ID Playlist yang dipilih : ");
                STARTKALIMATINPUT();

                int idPlaylist = CInput.TabLine[0] - 49; 

                if (idPlaylist+1 > (*AP).Neff || idPlaylist+1 <= 0)
                {
                    printf("\n%sERROR: %sTidak ada playlist dengan ID %d.\n", RED, WHITE, idPlaylist);
                }
                else
                {
                    AddAlbumToPlaylist(LP, AP, idPenyanyi, idAlbum, idPlaylist);

                    Kalimat NamaAlbum = (*LP).PenyanyiAlbum[idPenyanyi].ListAlbum.AlbumLagu[idAlbum].NamaAlbum;
                    Kalimat NamaPenyanyi = (*LP).PenyanyiAlbum[idPenyanyi].NamaPenyanyi;

                    // PrintInfo((*AP).A[idPlaylist]);

                    // address p = First((*AP).A[idPlaylist]);
                    // for(int tes = 0; tes < 3; tes++)
                    // {   
                    //     p = Next(p);
                    //     printf("\n%d - %s\n", tes, JudulLagu(p).TabLine);
                    // }
                    printf("%sAlbum dengan judul %s\"%s\" %sberhasil ditambahkan ke dalam playlist %s\"%s\".\n",GREEN, WHITE, NamaAlbum.TabLine, GREEN, WHITE, (*AP).Nama[idPlaylist].TabLine);    
                }
        }
        else
        {
            printf("\n%sERROR: %sAlbum tidak terdaftar.\n", RED, WHITE);
        }
    }
    else
    {
        printf("\n%sERROR: %sPenyanyi tidak terdaftar.\n", RED, WHITE);
    }    

}



// int main()
// {
//     ArrayDin AP = MakeArrayDin();

//     PlaylistCreate(&AP);
// }