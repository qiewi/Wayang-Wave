#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "inisialisasi.h"
// #include "../../ADT/WordMachine/wordmachine.h"
#include "../../ADT/pcolor/pcolor.h"


// extern Word currentWord;

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
 
    // Storing start time
    clock_t start_time = clock();
 
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}

void print_image(FILE *fascii)
{
    char read_string[MAX_LEN];
    while(fgets(read_string,sizeof(read_string),fascii) != NULL)
    printf("%s%s",GREEN,read_string);
    printf("\n");

}


void inisialisasi(){
    char *filename;
    FILE *fascii;
    system("cls || clear");

    filename = "Spesifikasi_Program/Inisialisasi/wayang.txt";
    
    fascii = NULL;
    fascii = fopen(filename,"r");

    if(fascii  == NULL){
        printf("error opening %s\n",filename);
    } else {
        system("cls || clear");
        print_image(fascii);
        fclose(fascii);
    }
    // InitialCommand();
    // load(currentWord)
}

// int main(){
//     inisialisasi();
// }

