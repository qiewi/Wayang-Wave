#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include "../../ADT/MapSetList/mapsetlist.h"
#include "../../ADT/pcolor/pcolor.h"
#include "../../ADT/Queue/queue.h"
#include "../../ADT/LineMachine/linemachine.h"
#include "../../ADT/Stack/RiwayatLagu.h"
#include "../Play/Play.h"

void enqueueLagu(QueueLagu *q, Kalimat JudulLaguQueue, Kalimat NamaAlbumQueue, Kalimat NamaPenyanyiQueue);

void dequeueLagu(QueueLagu *q, RiwayatLagu * RL, IdQueue id);

void QueueRemoveLagu(QueueLagu * QL, RiwayatLagu * RL);

void QueueAddLagu(ListPenyanyi * LP, QueueLagu * QL);

#endif