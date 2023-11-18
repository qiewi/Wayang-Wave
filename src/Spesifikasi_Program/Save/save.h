#ifndef __SAVE_H__
#define __SAVE_H__

#include <stdio.h>
#include <stdlib.h>
#include "../../ADT/MapSetList/mapsetlist.h"
#include "../../ADT/pcolor/pcolor.h"
#include "../../ADT/Queue/queue.h"
#include "../../ADT/Stack/RiwayatLagu.h"
#include "../../ADT/LineMachine/linemachine.h"
#include "../../ADT/LinkedList/linkedlist.h"
#include "../../ADT/array/arraydinamis.h"
#include "../MultiUser/MultiUser.h"
#include "../Play/Play.h"

static FILE * File;

void SaveFile(ListPenyanyi * LP, char filename[], DataUser * DU);

#endif