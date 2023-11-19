#include <stdio.h>
#include "linemachine.h"

int main() {
    // Uji STARTKALIMATINPUT
    printf("Menguji STARTKALIMATINPUT...\n");
    STARTKALIMATINPUT();
    printf("Input: %s\n\n", CInput.TabLine);

    // Uji STARTCOMMAND
    printf("Menguji STARTCOMMAND...\n");
    STARTCOMMAND();
    printf("Command: %s\n\n", CCommand.TabLine);

    // Uji STARTKALIMATFILE dengan file contoh
    char filename[] = "../../Data/custom.txt"; 
    printf("Menguji STARTKALIMATFILE dengan file '%s'...\n", filename);
    STARTKALIMATFILE(filename);
    printf("Kalimat dari file: %s\n\n", CLine.TabLine);

    // Uji ADVKALIMAT
    printf("Menguji ADVKALIMAT...\n");
    ADVKALIMAT();
    printf("Kalimat selanjutnya: %s\n\n", CLine.TabLine);

    // Uji tambahan untuk fungsi lain seperti ADVSATUKATA, ADVRECORD, dll.

    return 0;
}
