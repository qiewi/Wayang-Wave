/* File: penyanyi.h */
/* Tipe penyanyi */

#ifndef __PENYANYI_H__
#define __PENYANYI_H__

#include "boolean.h"
#include "../Map/map.h"
#include "../Set/set.h"

#define NMax 500

typedef struct
{
   char NamaPenyanyi[NMax]; /* container penyimpan nama Penyanyi */
   Album ListAlbum[];
} Penyanyi;

typedef struct
{
   Lagu ArrayLagu[NMax];
} Album;

typedef struct
{
   char Lagu[NMax];
} Lagu;

#endif