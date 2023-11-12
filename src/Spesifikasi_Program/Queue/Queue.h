#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include "../../ADT/MapSetList/mapsetlist.h"
#include "../../ADT/pcolor/pcolor.h"
#include "../../ADT/Queue/queue.h"
#include "../../ADT/LineMachine/linemachine.h"
#include "../../ADT/Stack/RiwayatLagu.h"
#include "../Play/Play.h"

void enqueueLaguFirst(QueueLagu *q, Kalimat JudulLaguQueue, Kalimat NamaAlbumQueue, Kalimat NamaPenyanyiQueue);

void enqueueLagu(QueueLagu * q, Kalimat JudulLaguQueue, Kalimat NamaAlbumQueue, Kalimat NamaPenyanyiQueue);

void dequeueLagu(QueueLagu * QL, RiwayatLagu * RL, IdQueue id);

void dequeueLaguNext(QueueLagu * QL, CurrentSong * CS);

void QueueSwap(QueueLagu * QL, IdQueue id1, IdQueue id2);

void QueueRemoveLagu(QueueLagu * QL, RiwayatLagu * RL, int idQueue);

void QueueAddLagu(ListPenyanyi * LP, QueueLagu * QL);

void QueueClear(QueueLagu * QL);

#endif