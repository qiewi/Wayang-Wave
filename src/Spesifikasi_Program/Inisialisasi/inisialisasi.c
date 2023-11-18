/* *** ******** ******** ******** ******** ******** ****** ** INCLUDED ADT & SPEK ** ****** ******** ******** ******** ******** ******** *** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "inisialisasi.h"
#include "../../ADT/pcolor/pcolor.h"

/* *** ******** ******** ******** ******** ******** ****** ** COMMAND SPEK ** ****** ******** ******** ******** ******** ******** *** */

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 500 * number_of_seconds;
 
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


// void inisialisasi(){
//     char *filename;
//     FILE *fascii;
//     system("cls || clear");

//     filename = "Spesifikasi_Program/Inisialisasi/wayang.txt";
    
//     fascii = NULL;
//     fascii = fopen(filename,"r");

//     if(fascii  == NULL){
//         printf("error opening %s\n",filename);
//     } else {
//         system("cls || clear");
//         print_image(fascii);
//         fclose(fascii);
//     }
// }

void inisialisasi(){
    char *filename;
    FILE *fascii;
    system("cls || clear");
    for (int i = 0; i < 4; i++){
        if (i == 0) {
            filename = "Spesifikasi_Program/Inisialisasi/wayang3.txt";
        } else if (i == 1){
            filename = "Spesifikasi_Program/Inisialisasi/wayang2.txt";
        } else if (i == 2){
            filename = "Spesifikasi_Program/Inisialisasi/wayang1.txt";
        } else if (i == 3){
            filename = "Spesifikasi_Program/Inisialisasi/wayang.txt";
        } 
        fascii = NULL;
        fascii = fopen(filename,"r");
        if(fascii  == NULL){
            printf("error opening %s\n",filename);
        } else {
            system("cls || clear");
            print_image(fascii);
            fclose(fascii);
        }
        delay(1);
    }
}

// int main(){
//     inisialisasi();
// }

