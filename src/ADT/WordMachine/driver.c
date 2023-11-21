#include "wordmachine.h"
#include <stdio.h>

int main() {
    // Membuat mesin kata
    printf("Membuat mesin kata...\n");
    STARTWORD();
    
    while (!EndWord) {
        printWord();
        ADVWORD();
    }

    return 0;
}
