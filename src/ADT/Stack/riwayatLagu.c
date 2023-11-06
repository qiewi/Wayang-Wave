#include <stdio.h>
#include "riwayatLagu.h"

void PushRiwayatLagu (RiwayatLagu *S, infotypeRiwayat NamaLagu){
    if (IsEmpty(*S)) {
        Top(*S) = 0;
        CopyWord(&InfoTop(*S), NamaLagu);
    }
    else{
        if (!IsFull(*S)) {
            S.Top++;
            CopyWord(&InfoTop(*S), NamaLagu);
        }
    }
}

void PopRiwayatLagu (RiwayatLagu *S, infotypeRiwayat NamaLagu){
    CopyWord(NamaLagu, InfoTop(*S));
	Top(*S)--;
}
