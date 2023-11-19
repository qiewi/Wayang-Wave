#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

void CreateGraph(Graph* G, int X) 
/* I.S. Sembarang */
/* F.S. Membuat sebuah Graph dengan satu Node */
{
    adrNode P = AlokNode(X);
    FirstG(*G) = P;
}

adrNode AlokNode(int X) 
/* Menghasilkan address dari sebuah Node */
{
    adrNode P;
    P = (adrNode) malloc (sizeof(Node));
    if (P != Null) {
        id(P) = X;
        Trail(P) = Null;
        NextG(P) = Null;
        return P;
    } 
    return Null;
}

adrSuccNode AlokSuccNode(int X) 
/* Menghasilkan address dari sebuah SuccNode */
{
    adrSuccNode P;
    P = (adrSuccNode) malloc (sizeof(SuccNode));
    if (P != Null) {
        NextG(P) = Null;
        id(P) = X;
        return P;
    }
    return Null;
}

void DealokNode(adrNode P) 
/* I.S. Node terdefinisi */
/* F.S. Node di dealokasi */
{
    free(P);
}

void InsertNode(Graph* G, int A) 
/* I.S. Graph terdefinisi */
/* F.S. A menjadi id dari Node pada Graph */
{
    adrNode P = AlokNode(A);
    if (P != Null) {
        if (FirstG(*G) == Null) {
            FirstG(*G) = P;
        } else {
            adrNode temp = FirstG(*G);
            while (NextG(temp) != Null) {
                temp = NextG(temp);
            }
            NextG(temp) = P;
        }
    }
}

void InsertSuccNode(Graph* G, int A, int B) 
/* I.S. Graph terdefinisi */
/* F.S. B menjadi id SuccNode danri Node A */
{
    adrSuccNode P = AlokSuccNode(B);
    if (P != Null) {
        adrNode temp = FirstG(*G);
        while (id(temp) != A) {
            temp = NextG(temp);
        }
        adrSuccNode tempSucc = Trail(temp);
        if (tempSucc == Null) {
            Trail(temp) = P;
        } else {
            while (NextG(tempSucc) != Null) {
                tempSucc = NextG(tempSucc);
            }
            NextG(tempSucc) = P;
        }
    }
}

void PrintGraph(Graph G) 
/* I.S. Graph terdefinisi */
/* F.S. Graph tercetak pada layar */
{
    adrNode P = FirstG(G);
    while (P != Null) {
        printf("%d > ", id(P));
        adrSuccNode temp = Trail(P); 
        while (temp != Null) {
            printf("%d ", id(temp));
            temp = NextG(temp);
        }
        printf("\n");
        P = NextG(P);
    }
}

// int main()
// {
//     Graph G;
//     CreateGraph(&G, 1);

//     InsertNode(&G, 2);
//     InsertSuccNode(&G, 2, 3);
//     InsertSuccNode(&G, 2, 4);

//     PrintGraph(G);
//     printf("%d\n", id(FirstG(G)));

// }