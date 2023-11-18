#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include "../../ADT/MapSetList/mapsetlist.h"
#include "../../ADT/pcolor/pcolor.h"
#include "../../ADT/Queue/queue.h"
#include "../../ADT/LineMachine/linemachine.h"
#include "../../ADT/Stack/RiwayatLagu.h"
#include "../../ADT/LinkedList/linkedlist.h"
#include "../../ADT/array/arraydinamis.h"
#include "../Play/Play.h"
#include "../Playlist/Playlist.h"

void enqueueLaguFirst(QueueLagu *q, Kalimat JudulLaguQueue, Kalimat NamaAlbumQueue, Kalimat NamaPenyanyiQueue);

void enqueueLagu(QueueLagu * q, Kalimat JudulLaguQueue, Kalimat NamaAlbumQueue, Kalimat NamaPenyanyiQueue);

void dequeueLagu(QueueLagu * QL, RiwayatLagu * RL, IdQueue id);

void dequeueLaguNext(QueueLagu * QL, CurrentSong * CS);

void QueueSwap(QueueLagu * QL, IdQueue id1, IdQueue id2);

void QueueRemoveLagu(QueueLagu * QL, RiwayatLagu * RL, int idQueue);

void QueueAddLagu(ListPenyanyi * LP, QueueLagu * QL, CurrentSong * CS);

void QueueClear(QueueLagu * QL);

void PlayPlaylist(ArrayDin * AP, QueueLagu * QL, RiwayatLagu * RL);

void QueuePlaylist(ArrayDin * AP, QueueLagu * QL, CurrentSong * CS, RiwayatLagu * RL);

#endif