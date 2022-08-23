//
// Created by Libin Zhou on 8/10/22.
//

#ifndef NEC_ROADN_ALGORITHMS_DIJKSTRA_H
#define NEC_ROADN_ALGORITHMS_DIJKSTRA_H

#endif //NEC_ROADN_ALGORITHMS_DIJKSTRA_H
#ifndef DIJKSTRA
#define DIJKSTRA
#include"Graph.h"
#include "QueryResult.h"
#define DIJKSTRA_TEST 1
class Dijkstra{
public:
    SPResult simple_Dijkstra(Graph g, int source, int destination);
};
#endif