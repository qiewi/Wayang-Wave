#include <stdio.h>
#include "../../Spesifikasi_Program/Play/Play.h"
#include "RiwayatLagu.h"

void PushRiwayatLagu(RiwayatLagu *RL, Kalimat JudulLagu, Kalimat NamaAlbum, Kalimat NamaPenyanyi)
{
    if ((*RL).IDXTOP == -1)
    {
        Top(*RL) = 0;
        InfoLagu(*RL) = JudulLagu;
        InfoAlbum(*RL) = NamaAlbum;
        InfoPenyanyi(*RL) = NamaPenyanyi;
        
    }
    else
    {
        if ((*RL).IDXTOP < 50-1) {
            Top(*RL)++;
            InfoLagu(*RL) = JudulLagu;
            InfoAlbum(*RL) = NamaAlbum;
            InfoPenyanyi(*RL) = NamaPenyanyi;
        }
    }
}

void PopRiwayatLagu(RiwayatLagu *RL, CurrentSong * CS) // untuk song prev
{ 
    (*CS).JudulLagu = InfoLagu(*RL);
    (*CS).NamaAlbum = InfoAlbum(*RL);
    (*CS).NamaPenyanyi = InfoPenyanyi(*RL);
    
	Top(*RL)--;
}