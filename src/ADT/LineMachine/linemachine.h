/* File: mesinKalimat.h */
/* Definisi Mesin Kalimat: Model Akuisisi Versi I */
// 1 Kalimat pada ADT ini adalah 1 game

#ifndef __LINEMACHINE_H__
#define __LINEMACHINE_H__

#include "../boolean.h"
#include "../CharMachine/charmachine.h"

#define NMaks 100
#define NEWLINE '\n'
#define MARK2 '\0'

typedef struct {
  char TabLine[NMaks+1];
  int Length;
} Kalimat;

/* State Mesin Kalimat */
extern boolean EndKalimat;
extern Kalimat CLine;
extern Kalimat CInput;
extern Kalimat CCommand;


void IgnoreNewline();
void Ignoreblanks();
void IgnoreTitikKoma();

void SalinKalimat();
void SalinSatuKata();
void SalinRecord();
void SalinCommand();

void STARTKALIMATINPUT();
void SalinInput();
void ResetInput();
void ResetCommand();
Kalimat DirectoryCommand(Kalimat file);

void STARTKALIMATFILE(char filename[]);
void STARTCOMMAND();

void ADVKALIMAT();
void ADVSATUKATA();
void ADVRECORD();
void ADVCOMMAND();

void copyKalimat (Kalimat k1, Kalimat *k2);
void ResetKalimat();

boolean isKalimatEqual(Kalimat K1, Kalimat K2);
boolean isInputEqual(Kalimat Input, char * kata);
int Length(char * S2);

#endif