#include "../../ADT/graph/graph.h"
#include "../../ADT/pcolor/pcolor.h"

#include "../Play/Play.h"
#include "../MultiUser/MultiUser.h"


int CheckFriend(adrNode P, int idUser)
{
    adrSuccNode temp = Trail(P); 
    while (temp != Null) {
        if (id(temp) == idUser)
        {
            return id(temp);
        }
        temp = temp->Next;
    }
    return -1;
}

adrNode AddressGraph(DataUser * DU, CurrentUser * CU)
{
    adrNode P = First((*DU).G);
    P = P->Next;
    int i = 0;

    while (P != Null)
    {    
        if (id(P) == (*CU).idUser)
        {
            return P;
        }

        P = P->Next;

    }

    return Null;

}

void FollowFriend(DataUser * DU, CurrentUser * CU) // to do list: bikin verif anggota graph
{
    printf("\n%sList Username di WayangWave: \n", GREEN);

    for (int i = 0; i < (*DU).TotalUser; i++)
    {
        printf("  %s%d. %s \n", WHITE, i+1, (*DU).NamaUser[i].TabLine);
    }

    printf("\nInput nama user yang ingin di-follow: %s", YELLOW);
    STARTKALIMATINPUT();

    int idUser = CekUser(DU, CInput);

    if (idUser == -1)
    {
        printf("\n%sERROR: %sUsername %s tidak terdaftar!\n", RED, WHITE, CInput.TabLine);
    }
    else if (idUser != (*CU).idUser)
    {
        adrNode P = AddressGraph(DU, CU);
        if (P != Null)
        {   
            
            int cek = CheckFriend(P, idUser);
            if (cek == -1)
            {
                InsertSuccNode(&(*DU).G, (*CU).idUser, idUser);
                printf("\n%sOutput: %sKamu berhasil memfollow %s.\n", GREEN, WHITE, CInput.TabLine);
            }
            else
            {
                printf("\n%sERROR: %sKamu sudah memfollow %s!\n", RED, WHITE, CInput.TabLine);
            }
            
        }
        else
        {
            printf("Null\n");
        }
        
    }
    else
    {
        printf("\n%sERROR: %sKamu tidak bisa memfollow diri kamu sendiri.\n", RED, WHITE);
    }
}

void ListFollowing(DataUser * DU, CurrentUser * CU)
{
    printf("\n%sList User yang kamu follow di WayangWave: \n", GREEN);

    adrNode P = AddressGraph(DU, CU);
    adrSuccNode temp = Trail(P); 
    int i = 1;
    
    if (temp != Null)
    {
        while (temp != Null) {
            int idTemen = id(temp);
            printf("%s%d. %s\n", WHITE, i, (*DU).NamaUser[idTemen].TabLine);
            temp = temp->Next;
        }

        printf("\nIngin melihat playlist mereka? %s", GREEN);
        STARTKALIMATINPUT();

        if (CInput.TabLine[0] == 'Y')
        {
            printf("%sMasukkan nama user yang ingin kamu lihat: %s",WHITE, GREEN);
            STARTKALIMATINPUT();

            int idUser = CekUser(DU, CInput);

            if (idUser != -1)
            {
                printf("\n%sDaftar Playlist yang dimiliki oleh %s%s:\n", GREEN, YELLOW, CInput.TabLine);
                if ((*DU).AP[idUser].Neff > 0)
                {
                    for (int i = 0; i < (*DU).AP[idUser].Neff; i++)
                    {
                    printf("  %s%d. %s \n", WHITE, i+1, (*DU).AP[idUser].Nama[i].TabLine);
                    }

                    printf("\nIngin cek isi lagu dari sebuah playlist? (Y/N): %s", GREEN);
                    STARTKALIMATINPUT();

                    if (CInput.TabLine[0] == 'Y')
                    {

                        printf("%sInput ID playlist: %s", WHITE, GREEN);
                        STARTKALIMATINPUT();

                        int idPL = atoi(CInput.TabLine) - 1;

                        if (idPL+1 > (*DU).AP[idUser].Neff || idPL+1 <= 0)
                        {
                            printf("\n%sERROR: %sTidak ada playlist dengan ID %d.\n", RED, WHITE, idPL+1);
                        }
                        else
                        {   
                            printf("\n%sDaftar lagu dalam playlist %s\"%s\":%s\n", GREEN, YELLOW, (*DU).AP[idUser].Nama[idPL].TabLine, WHITE);

                            address p = First((*DU).AP[idUser].A[idPL]);
                            int j = 0;

                            if (p == Nil)
                            {
                            printf("%sTidak ada lagu.\n", WHITE);
                            }
                            else
                            {
                            while (p != Nil)
                            {
                                printf("  %s%d. %s - %s \n", WHITE, j+1, NamaPenyanyi(p).TabLine, JudulLagu(p).TabLine);
                                p = Next(p);
                                j++;
                            }
                            }

                            printf("\n");
                        
                        }
                    }


                }
                else
                {
                    printf("%sUser %s tidak memiliki playlist.\n", WHITE, CInput.TabLine);
                }

            }
            else
            {
                printf("\n%sERROR: %sUsername %s tidak terdaftar!\n", RED, WHITE, CInput.TabLine);
            }

        }
    }
    else
    {
        printf("%sKamu belum follow satupun user\n", WHITE);
    }
}