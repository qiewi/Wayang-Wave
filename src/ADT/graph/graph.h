#ifndef GRAPH
#define GRAPH

#include "../boolean.h"

#define Null 0

/* Definisi tipe yang digunakan */

typedef struct tNode *adrNode;
typedef struct sNode *adrSuccNode;
typedef struct tNode {
    int id;
    adrSuccNode Trail;
    adrNode Next;
} Node;

typedef struct sNode {
    int id;
    adrSuccNode Next;
} SuccNode;

typedef struct {
    adrNode First;
} Graph;

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */ 

/* *** SELEKTOR *** */
#define FirstG(G) (G).First
#define id(G) (G)->id
#define Trail(G) (G)->Trail
#define NextG(G) (G)->Next

/* *** Konstruktor membentuk Graph *** */

void CreateGraph(Graph* G, int X);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Graph dengan satu Node */

adrNode AlokNode(int X);
/* Menghasilkan address dari sebuah Node */

adrSuccNode AlokSuccNode(int X);
/* Menghasilkan address dari sebuah SuccNode */

void DealokNode(adrNode P);
/* I.S. Node terdefinisi */
/* F.S. Node di dealokasi */

void InsertNode(Graph* G, int A);
/* I.S. Graph terdefinisi */
/* F.S. A menjadi id dari Node pada Graph */

void InsertSuccNode(Graph* G, int A, int B);
/* I.S. Graph terdefinisi */
/* F.S. B menjadi id SuccNode danri Node A */

void PrintGraph(Graph G);
/* I.S. Graph terdefinisi */
/* F.S. Graph tercetak pada layar */

#endif
