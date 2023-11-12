#include <stdio.h>
#include "linemachine.h"

boolean EndKalimat;
Kalimat CLine;
Kalimat CInput;
Kalimat CCommand;

void Ignoreblanks()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while (CC == ' ')
    {
        ADV();
    }
}

void IgnoreNewline()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while (CC == NEWLINE)
    {
        ADV();
    }
}

void IgnoreTitikKoma()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while (CC == ';')
    {
        ADV();
    }
}

void SalinInput() {
    ResetInput();  // Reset array
    int i = 0;
    while ((CC != MARK) && (CC != NEWLINE) && (CC != EOF))
    {
        CInput.TabLine[i] = CC;
        // printf("%c", CC);
        i+= 1;
        ADV();
    }
    CInput.Length = i;
}

void SalinKalimat() {
    ResetKalimat();  // Reset array
    int i = 0;
    while ((CC != MARK) && (CC != NEWLINE) && (CC != EOF))
    {
        CLine.TabLine[i] = CC;
        // printf("%c", CC);
        i+= 1;
        ADV();
    }
    CLine.Length = i;
}

void SalinSatuKata() {
    ResetKalimat();  // Reset array
    int i = 0;
    while ((CC != ' ') && (CC != MARK))
    {
        CLine.TabLine[i] = CC;
        i += 1;
        ADV();
    }
    CLine.Length = i;
}

void SalinRecord() {
    ResetKalimat();  // Reset array
    int i = 0;
    while ((CC != MARK) && (CC != NEWLINE))
    {
        CLine.TabLine[i] = CC;
        i += 1;
        ADV();
    }
    CLine.Length = i;
}

void STARTKALIMATINPUT() {
    START();
    IgnoreNewline();
    if (CC == ';'){
        EndKalimat = true;
    } else {
        EndKalimat = false;
        SalinInput();
    }
}

void STARTCOMMAND() {
    START();
    IgnoreNewline();
    if (CC == ';'){
        EndKalimat = true;
    } else {
        EndKalimat = false;
        SalinCommand();
    }
}

void SalinCommand() {
    ResetCommand();  // Reset array
    int i = 0;
    while ((CC != ' ') && (CC != ';') && (CC != EOF))
    {
        CCommand.TabLine[i] = CC;
        // printf("%c", CC);
        i+= 1;
        ADV();
    }
    CCommand.Length = i;
}

void ADVCOMMAND(){
    Ignoreblanks();
    if (CC == ';'){
        EndKalimat = true;
    } else {
        EndKalimat = false;
        SalinCommand();
    }
}



void STARTKALIMATFILE(char filename[]) {
    STARTFILE(filename);
    IgnoreNewline();
    if (CC == MARK2) {
        EndKalimat = true;
    } else {
        EndKalimat = false;
        SalinKalimat();
    }
}

void ADVKALIMAT(){
    IgnoreNewline();
    Ignoreblanks();
    if (CC == MARK2) {
        EndKalimat = true;
    } else {
        EndKalimat = false;
        SalinKalimat();
    }
}

void ADVSATUKATA() {
    Ignoreblanks();
    IgnoreNewline();
    if (CC == ' ') {
        EndKalimat = true;
    } else {
        EndKalimat = false;
        SalinSatuKata();
    }
}

void ADVRECORD() {
    Ignoreblanks();
    IgnoreNewline();
    IgnoreTitikKoma();
    if (CC == ';' || CC == NEWLINE) {
        EndKalimat = true;
    } else {
        EndKalimat = false;
        SalinRecord();
    }
}

void copyKalimat (Kalimat k1, Kalimat *k2){
    k2->Length=k1.Length;
    for (int i=0;i<=k1.Length;i++){
        k2->TabLine[i] = k1.TabLine[i];
    }
}

void ResetKalimat() {
    for (int i = 0; i < sizeof(CLine.TabLine); i++) {
        CLine.TabLine[i] = '\0';
        CLine.Length = 0;
    }
}

void ResetInput() {
    for (int i = 0; i < sizeof(CInput.TabLine); i++) {
        CInput.TabLine[i] = '\0';
        CInput.Length = 0;
    }
}

void ResetCommand() {
    for (int i = 0; i < sizeof(CCommand.TabLine); i++) {
        CCommand.TabLine[i] = '\0';
        CCommand.Length = 0;
    }
}

boolean isKalimatEqual(Kalimat K1, Kalimat K2) // belum dites
{   
    boolean equal = true;
    if (K1.Length == K2.Length)
    {
        int i = 0;
        while (i < K1.Length && equal)
        {
            if (K1.TabLine[i] != K2.TabLine[i])
            {
                equal = false;
            }
            else
            {
                i++;
            }
        }
        return equal;
    }
    else
    {
        return false;
    }
}

boolean isInputEqual(Kalimat Input, char * kata) // belum dites
{   
    boolean equal = true;
    if (Input.Length == Length(kata))
    {
        int i = 0;
        while (i < Input.Length && equal)
        {
            if (Input.TabLine[i] != kata[i])
            {
                equal = false;
            }
            else
            {
                i++;
            }
        }
        return equal;
    }
    else
    {
        return false;
    }
}

int Length(char * S2){
    int i = 0;

    while (S2[i] != '\0'){
        i++;
    }

    return i;
}


