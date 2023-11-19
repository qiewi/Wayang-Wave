#include "charmachine.h"
#include <stdio.h>
#include <stdlib.h>

char CC;
boolean EOP;

static FILE * pita;
static int retval;

int main() {

    printf("Reading characters from standard input (type a few characters and press enter):\n");
    START();
    while (!feof(stdin)) {
        printf("Character read: %c\n", CC);
        ADV();
    }

    char filename[] = "../../Data/custom.txt";
    printf("\nReading characters from file '%s':\n", filename);
    STARTFILE(filename);
    while (pita != NULL && !feof(pita)) {
        printf("Character read from file: %c\n", CC);
        ADVFILE();
    }

    return 0;
}
