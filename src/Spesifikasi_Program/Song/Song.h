#ifndef __SONG_H__
#define __SONG_H__

/* *** ******** ******** ******** ******** ******** ****** ** INCLUDED ADT & SPEK ** ****** ******** ******** ******** ******** ******** *** */

#include "../../ADT/pcolor/pcolor.h"
#include "../../ADT/Queue/queue.h"
#include "../Inisialisasi/inisialisasi.h"
#include "../Play/Play.h"
#include "../Queue/Queue.h"

/* *** ******** ******** ******** ******** ******** ****** ** COMMAND SPEK ** ****** ******** ******** ******** ******** ******** *** */

void SongNext(QueueLagu * QL, RiwayatLagu * RL, CurrentSong * CS);

void SongPrev(QueueLagu * QL, RiwayatLagu * RL, CurrentSong * CS);

#endif