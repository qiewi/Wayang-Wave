/* File: penyanyi.h */
/* Tipe penyanyi */

#ifndef __PENYANYI_H__
#define __PENYANYI_H__

#include "boolean.h"
#include "../Map/map.h"
#include "../Set/set.h"
#include "../WordMachine/wordmachine.h"
#include "../Map/map.h"

#define NMax 500

// typedef struct
// {
//    TabPenyanyi Penyanyi[NMax]; 
//    int TotalPenyanyi;
// } ListPenyanyi;

typedef struct 
{
   int idPenyanyi;
   char NamaPenyanyi[NMax];
} Penyanyi;


typedef struct
{
   Lagu ArrayLagu[NMax];
} AlbumPenyanyi;

typedef struct
{
   int IdLagu;
   Word Title;
} Lagu;

#endif