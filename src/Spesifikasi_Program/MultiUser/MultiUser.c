#include "MultiUser.h"
#include <stdio.h>
#include <stdlib.h>

void CreateDataUser(DataUser * DU)
{
    (*DU).TotalUser = 0;
}

void RegisterUser(DataUser * DU)
{
    printf("\nMasukkan nama user: ");
    STARTKALIMATINPUT();

    (*DU).NamaUser[(*DU).TotalUser] = CInput;
    (*DU).TotalUser += 1;
}

int LoginUser(DataUser * DU)
{
    printf("\nMasukkan username: ");
    STARTKALIMATINPUT();

    for (int i = 0; i < (*DU).TotalUser; i++)
    {
        if (isKalimatEqual((*DU).NamaUser[i], CInput))
        {
            return i;
        }
    }

    return -1;
}