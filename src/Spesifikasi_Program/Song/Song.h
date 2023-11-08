#ifndef __SONG_H__
#define __SONG_H__

#include "../../ADT/pcolor/pcolor.h"
#include "../../ADT/Queue/queue.h"
#include "../Play/Play.h"
#include "../Queue/Queue.h"

void SongNext(QueueLagu * QL, RiwayatLagu * RL, CurrentSong * CS);

void SongPrev(QueueLagu * QL, RiwayatLagu * RL, CurrentSong * CS);

#endif