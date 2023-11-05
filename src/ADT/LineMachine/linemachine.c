#include <stdio.h>
#include "linemachine.h"

boolean EndKalimat;
Kalimat CLine;

void Ignoreblanks()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while (CC == BLANK)
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
    while ((CC != BLANK) && (CC != MARK))
    {
        CLine.TabLine[i] = CC;
        i += 1;
        ADV();
    }
    CLine.Length = i;
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
    if (CC == BLANK) {
        EndKalimat = true;
    } else {
        EndKalimat = false;
        SalinSatuKata();
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


