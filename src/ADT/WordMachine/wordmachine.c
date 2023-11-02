#include "wordmachine.h"
#include <stdio.h>


/* State Mesin Word */
boolean EndWord;
Word currentWord;

void IgnoreBlanks(){
    while (CC == BLANK){
        ADV();
    }
}

void STARTWORD(){
    START();
    IgnoreBlanks();
    if (CC == MARK){
        EndWord = true;
    } else {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD(){
    IgnoreBlanks();
    if(CC == MARK){
        EndWord = true;
    } else{
        CopyWord();
        IgnoreBlanks();
    }
}


void CopyWord(){
    currentWord.Length = 0;
    while (CC != BLANK && CC != MARK && CC != '\n'){
        if (currentWord.Length < NMax){
            currentWord.TabWord[currentWord.Length] = CC;
            currentWord.Length++;
        }
        ADV();
    }
}

void printWord(){
    for (int i = 0; i < currentWord.Length; i++)
    {
        printf("%c", currentWord.TabWord[i]);
    }
    printf("\n");
}

// Tambahan Primitif
// int wordToInt(Word x){
//     int result = 0;
//     int sign = 1;
//     int i = 0;
//     if (HURUF(x,0) == '-'){
//         sign = -1;
//         i++;
//     }
//     for (i; i<x.Length; i++){
//         result = result*10 + charToInt(HURUF(x,i));
//     }
//     return result * sign;
// }

void WordToString (Word K, char *S){
    for (int i = 0; i < K.Length; i++)
    {
        S[i] = K.TabWord[i];
    }
    for (int i = K.Length; i < Length(S); i++) 
    {
        if (S[i] != '\0') {
            S[i] = '\0';
        }
    }
}

boolean IsKataEqual(Word S1, char * S2){
    boolean equal = true;
    int i = 0;
    
    if (S1.Length == Length(S2)){
        while (i < Length(S2) && equal){
            if (S1.TabWord[i] != S2[i])
            {
                equal = false;
            }
            else
            {
                i++;
            }
        }
    }
    else{
        equal = false;
    }

    return equal;
}

int Length(char * S2){
    int i = 0;

    while (S2[i] != '\0'){
        i++;
    }

    return i;
}

void resetWord()
{
    currentWord.Length = 0;
}