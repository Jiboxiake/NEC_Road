#include <iostream>
#include "Dijkstra.h"
int main() {
    Graph* g= new Graph(200000,600000);
    g->insert_vertices();
    g->insert_edges();
    //g->print_incoming_edges(230001);
    Dijkstra dij;
    SPResult result= dij.simple_Dijkstra(*g,1347,25432);
    std::cout<<"dist is "<<result.result<<"\n";
    return 0;
}
