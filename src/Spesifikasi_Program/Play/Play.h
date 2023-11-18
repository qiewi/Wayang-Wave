#ifndef __PLAY_H__
#define __PLAY_H__

/* *** ******** ******** ******** ******** ******** ****** ** INCLUDED ADT & SPEK ** ****** ******** ******** ******** ******** ******** *** */

#include <stdio.h>

#include "../../ADT/MapSetList/mapsetlist.h"
#include "../../ADT/Stack/RiwayatLagu.h"
#include "../../ADT/Queue/queue.h"
#include "../../ADT/LineMachine/linemachine.h"
#include "../../ADT/pcolor/pcolor.h"

typedef struct {
	Kalimat JudulLagu; 
    Kalimat NamaAlbum;
    Kalimat NamaPenyanyi;
    Kalimat NamaPlaylist;
    int status;
    int statusPL;
} CurrentSong;

typedef struct {
	Kalimat NamaUser;
    int idUser;
    int status;
} CurrentUser;

/* *** ******** ******** ******** ******** ******** ****** ** COMMAND SPEK ** ****** ******** ******** ******** ******** ******** *** */

void CreateCurrentSong(CurrentSong * CS);

void CreateCurrentUser(CurrentUser * CU);

void AddSong(ListPenyanyi * LP, CurrentSong * CS, int idPenyanyi, int idAlbum, int idLagu);

void PlaySong(ListPenyanyi * LP, CurrentSong * CS, QueueLagu * QL, RiwayatLagu * RL) ;

void PopRiwayatLagu(RiwayatLagu *S, CurrentSong * CS);

#endif