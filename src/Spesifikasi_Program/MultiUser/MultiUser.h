#ifndef __MULTIUSER_H__
#define __MULTIUSER_H__

#include "../../ADT/boolean.h"
#include "../../ADT/Queue/queue.h"
#include "../../ADT/MapSetList/mapsetlist.h"
#include "../../ADT/Stack/RiwayatLagu.h"
#include "../../ADT/LinkedList/linkedlist.h"
#include "../../ADT/array/arraydinamis.h"
#include "../../ADT/LineMachine/linemachine.h"

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
    printf("\nMasukkan nama user: ");
    STARTKALIMATINPUT();

    (*DU).NamaUser[(*DU).TotalUser] = CInput;
    (*DU).TotalUser += 1;
}

int LoginUser(DataUser * DU)
{
    printf("\nMasukkan username: ");
    STARTKALIMATINPUT();

    for (int i = 0; i < (*DU).TotalUser; i++)
    {
        if (isKalimatEqual((*DU).NamaUser[i], CInput))
        {
            return i;
        }
    }

    return -1;
}

#endif