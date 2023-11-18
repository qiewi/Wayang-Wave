#ifndef __MULTIUSER_H__
#define __MULTIUSER_H__

/* *** ******** ******** ******** ******** ******** ****** ** INCLUDED ADT & SPEK ** ****** ******** ******** ******** ******** ******** *** */

#include <stdio.h>
#include <stdlib.h>

#include "../../ADT/boolean.h"
#include "../../ADT/Queue/queue.h"
#include "../../ADT/MapSetList/mapsetlist.h"
#include "../../ADT/Stack/RiwayatLagu.h"
#include "../../ADT/LinkedList/linkedlist.h"
#include "../../ADT/array/arraydinamis.h"
#include "../../ADT/LineMachine/linemachine.h"
#include "../Play/Play.h"

#define UserMaks 10

typedef struct {
	Kalimat NamaUser[UserMaks];
	ArrayDin AP[UserMaks];
    CurrentSong CS[UserMaks];
    QueueLagu QL[UserMaks];
    RiwayatLagu RL[UserMaks];
    int TotalUser;
} DataUser;

/* *** ******** ******** ******** ******** ******** ****** ** COMMAND SPEK ** ****** ******** ******** ******** ******** ******** *** */

void CreateDataUser(DataUser * DU);

void RegisterUser(DataUser * DU);

int CekUser(DataUser * DU, Kalimat NamaUser);

void Login(DataUser * DU, ArrayDin * AP, CurrentSong * CS, CurrentUser * CU, QueueLagu * QL, RiwayatLagu * RL, boolean * sesi);

void Logout(DataUser * DU, ArrayDin * AP, CurrentSong * CS, CurrentUser * CU, QueueLagu * QL, RiwayatLagu * RL, int idUser);

#endif