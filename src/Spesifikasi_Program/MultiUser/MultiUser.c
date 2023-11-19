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
#include "../../ADT/pcolor/pcolor.h"

#include "../Inisialisasi/inisialisasi.h"
#include "../Play/Play.h"
#include "MultiUser.h"

/* *** ******** ******** ******** ******** ******** ****** ** COMMAND SPEK ** ****** ******** ******** ******** ******** ******** *** */

void CreateDataUser(DataUser * DU)
{
    CreateGraph(&(*DU).G, -99);
    (*DU).TotalUser = 0;
}

void RegisterUser(DataUser * DU)
{
    printf("\n%s=================== %s[ REGISTER ] %s===================\n", GREEN, YELLOW, GREEN);
    printf("\n%sMasukkan nama user: ", WHITE);
    STARTKALIMATINPUT();

    int idUser = CekUser(DU, CInput);

    if (idUser == -1)
    {
        (*DU).NamaUser[(*DU).TotalUser] = CInput;

        CreateQueueLagu(&(*DU).QL[(*DU).TotalUser]);
        CreateCurrentSong(&(*DU).CS[(*DU).TotalUser]);
        CreateRiwayatLagu(&(*DU).RL[(*DU).TotalUser]);
        (*DU).AP[(*DU).TotalUser] = MakeArrayDin();

        (*DU).TotalUser += 1;

        AnimasiRegister();

        printf("\n%s================= ", GREEN); delay(1);
        printf("%s[ %s CREATED! ]", YELLOW, CInput.TabLine);
        printf("%s =================\n\n", GREEN);
    }
    else
    {
        printf("\n%sERROR: %sUsername sudah terdaftar. Silahkan input nama lain.\n", RED, WHITE);
        printf("\n%s===================================================\n\n", GREEN);
    }

}

int CekUser(DataUser * DU, Kalimat NamaUser)
{
    // printf("\nMasukkan username: ");
    // STARTKALIMATINPUT();

    for (int i = 0; i < (*DU).TotalUser; i++)
    {
        if (isKalimatEqual((*DU).NamaUser[i], NamaUser))
        {
            return i;
        }
    }

    return -1;
}

void Login(DataUser * DU, ArrayDin * AP, CurrentSong * CS, CurrentUser * CU, QueueLagu * QL, RiwayatLagu * RL, boolean * sesi)
{
    printf("\n%s=================== %s[ LOGIN ] %s===================\n",GREEN, YELLOW, GREEN);
    printf("\n%sUsername: ", WHITE);

    STARTKALIMATINPUT();

    int idUser = CekUser(DU, CInput);

    if (idUser != -1)
    {
        (*CU).NamaUser = (*DU).NamaUser[idUser];
        (*CU).idUser = idUser;
        (*CU).status = 1;

        (*AP) = (*DU).AP[idUser];
        (*CS) = (*DU).CS[idUser];
        (*QL) = (*DU).QL[idUser];
        (*RL) = (*DU).RL[idUser];

        (*sesi) = true;

        AnimasiLogin();

        printf("\n%s    ================= ", GREEN); delay(1);
        printf("%s[ LOGGED IN TO %s ]", YELLOW, (*CU).NamaUser.TabLine);
        printf("%s =================\n\n", GREEN);

    }
    else
    {
        printf("\n%sERROR: %sUsername tidak terdaftar. Silahkan lakukan register terlebih dahulu\n", RED, WHITE);
        printf("\n%s===================================================\n\n", GREEN);
    }
}

void Logout(DataUser * DU, ArrayDin * AP, CurrentSong * CS, CurrentUser * CU, QueueLagu * QL, RiwayatLagu * RL, int idUser)
{
    
    (*CU).status = 0;
    (*DU).AP[idUser] = (*AP);
    (*DU).CS[idUser] = (*CS);
    (*DU).QL[idUser] = (*QL);
    (*DU).RL[idUser] = (*RL);

    printf("\n%s================= ", GREEN); delay(1);
    printf("%s[ LOGGED OUT ]", YELLOW);
    printf("%s =================\n\n", GREEN);

}