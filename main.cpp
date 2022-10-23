#include <iostream>
#include "Dijkstra.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
int main() {
    Graph* g= new Graph(200000,600000);
    g->insert_vertices();
    g->insert_edges();
    //g->print_incoming_edges(230001);
    Dijkstra dij;
    long total =0 ;
    for(int i=0; i<100;i++){
        auto start = std::chrono::high_resolution_clock::now();
        SPResult result= dij.simple_Dijkstra(*g,i,270000-i);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        total+= duration.count();
    }
    printf("total time is %ld\n",total);
    //std::cout<<"dist is "<<result.result<<"\n";
    return 0;
}
