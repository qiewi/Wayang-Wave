#ifndef __STATUS_H__
#define __STATUS_H__

/* *** ******** ******** ******** ******** ******** ****** ** INCLUDED ADT & SPEK ** ****** ******** ******** ******** ******** ******** *** */

#include "../../ADT/pcolor/pcolor.h"
#include "../../ADT/Stack/RiwayatLagu.h"
#include "../Play/Play.h"
#include "../Queue/Queue.h"
#include "../Inisialisasi/inisialisasi.h"

/* *** ******** ******** ******** ******** ******** ****** ** COMMAND SPEK ** ****** ******** ******** ******** ******** ******** *** */

void Status(CurrentSong * CS, CurrentUser *CU, QueueLagu * QL, RiwayatLagu * RL);

#endif