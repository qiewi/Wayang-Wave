#include "arraydinamis.h"
#include <stdio.h>
#include "../LineMachine/linemachine.h"
#include "../CharMachine/charmachine.h"
#include "../LinkedList/linkedlist.h"
#include "../boolean.h"

int main()
{
    ArrayDin Test = MakeArrayDin();
    
    if (IsEmptyArray(Test))
    {
        printf("kosong\n");
    }

    STARTKALIMATINPUT();

    InsertNama(&Test, CInput);

    printf("Nama Playlist: %s\n", Test.Nama[0].TabLine);
    
}

// run: 
// gcc driverarraydinamis.c arraydinamis.c ../LineMachine/linemachine.c ../CharMachine/charmachine.c ../LinkedList/linkedlist.c  -o driverarraydinamis