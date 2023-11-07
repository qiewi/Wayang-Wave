#ifndef __PLAY_H__
#define __PLAY_H__

#include "../../ADT/MapSetList/mapsetlist.h"
#include <stdio.h>
#include "../../ADT/LineMachine/linemachine.h"
#include "../../ADT/pcolor/pcolor.h"

typedef struct {
	Kalimat JudulLagu; 
    Kalimat NamaAlbum;
    Kalimat NamaPenyanyi;
    int status;
} CurrentSong;

void CreateCurrentSong(CurrentSong * CS);

void AddSong(ListPenyanyi * LP, CurrentSong * CS, int idPenyanyi, int idAlbum, int idLagu);

void PlaySong(ListPenyanyi * LP, CurrentSong * CS);

#endif