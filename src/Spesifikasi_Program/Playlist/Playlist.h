#ifndef __PLAYLIST_H__
#define __PLAYLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include "../../ADT/LinkedList/LinkedList.h"
#include "../../ADT/Stack/RiwayatLagu.h"
#include "../../ADT/array/arraydinamis.h"
#include "../../ADT/LineMachine/linemachine.h"
#include "../../ADT/pcolor/pcolor.h"

void PlaylistCreate(ArrayDin * AP);

void PlayListRemoveLagu(ArrayDin * AP, int idPlaylist, int idLagu);

int checkLagu(ArrayDin * AP, int idPlaylist, Kalimat NamaLagu);

void AddSongToPlaylist(ListPenyanyi * LP, ArrayDin * AP, int idPenyanyi, int idAlbum, int idLagu, int idPlaylist);

void AddAlbumToPlaylist(ListPenyanyi * LP, ArrayDin * AP, int idPenyanyi, int idAlbum, int idPlaylist);

void PlaylistAddLagu(ArrayDin * AP, ListPenyanyi * LP);

void PlaylistAddAlbum(ArrayDin * AP, ListPenyanyi * LP);





void PlaylistSwap();



void PlaylistRemove();



void PlaylistDelete();
#endif
