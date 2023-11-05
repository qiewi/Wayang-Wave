/* File: mesinKalimat.h */
/* Definisi Mesin Kalimat: Model Akuisisi Versi I */
// 1 Kalimat pada ADT ini adalah 1 game

#ifndef __LINEMACHINE_H__
#define __LINEMACHINE_H__

#include "../boolean.h"
#include "../CharMachine/charmachine.h"
#include "../WordMachine/wordmachine.h"

#define NMaks 450
#define NEWLINE '\n'
#define MARK2 '\0'

typedef struct {
  char TabLine[NMaks+1];
  int Length;
} Kalimat;

/* State Mesin Kalimat */
extern boolean EndKalimat;
extern Kalimat CLine;

void IgnoreNewline();
void Ignoreblanks();

void SalinKalimat();
void SalinSatuKata();

void STARTKALIMATFILE(char filename[]);

void ADVKALIMAT();
void ADVSATUKATA();

void copyKalimat (Kalimat k1, Kalimat *k2);
void ResetKalimat();

boolean isKalimatEqual(Kalimat K1, Kalimat K2);

#endif