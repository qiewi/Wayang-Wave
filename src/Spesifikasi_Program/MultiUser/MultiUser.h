#ifndef __ENHANCE_H__
#define __ENHANCE_H__

#include "ADT/boolean.h"
#include "ADT/Queue/queue.h"
#include "ADT/MapSetList/mapsetlist.h"
#include "ADT/Stack/RiwayatLagu.h"
#include "ADT/LinkedList/linkedlist.h"
#include "ADT/array/arraydinamis.h"
#include "ADT/LineMachine/linemachine.h"

#define UserMaks 10

typedef struct {
	Kalimat NamaUser[UserMaks];
	ArrayDin AP[UserMaks];
    QueueLagu QL[UserMaks];
    RiwayatLagu RL[UserMaks];
    int TotalUser;
} DataUser;


void CreateDataUser(DataUser * DU)
{
    (*DU).TotalUser = 0;
}

void RegisterUser(DataUser * DU)
{
    
}

#endif