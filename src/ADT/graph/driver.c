#include "graph.h"

int main()
{
    Graph G;
    CreateGraph(&G, 1);

    InsertNode(&G, 2);
    InsertSuccNode(&G, 2, 3);
    InsertSuccNode(&G, 2, 4);

    PrintGraph(G);
    printf("%d\n", id(FirstG(G)));

}