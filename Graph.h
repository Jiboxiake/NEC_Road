//
// Created by Libin Zhou on 8/10/22.
//

#ifndef NEC_ROADN_ALGORITHMS_GRAPH_H
#define NEC_ROADN_ALGORITHMS_GRAPH_H

#endif //NEC_ROADN_ALGORITHMS_GRAPH_H
#ifndef GRAPH
#define GRAPH
#include <vector>
#include<map>
#include <string>
#define BADID -100
extern struct _vertex{
    int id=-1;
    long morton=-1;
    int startIndex=-1;
    int endIndex=-1;
};

extern struct _edge{
    int id;
    int from;
    int to;
    float length; //physical length of the edge
    float weight; //time it takes to travel the edge
    int label=-1;
    _edge* next=NULL; //pointer to the next edge used in the reverse grah. It is a linked list and the first edge is indexed by the to ID.
};

typedef _vertex Vertex;
typedef _edge Edge;

class Graph{

public:
    std::string edgePath = "./ID_edge_final.txt";
    std::string vertexPath = "./ID_ver_final.txt";
    //std::vector <Vertex> vertices;
    std::map <int,Vertex*> vertices;//maybe switch to boost map later, let do it now!
    //boost::unordered_map<int, Vertex>* vertices;
    std::vector <Edge*> edges;
    //std::map<int, Edge> incomingEgdes;
    //boost::unordered_map<int, Edge>* incomingEdges;
    Graph(int vertexCount, int edgeCount);
    void insert_vertex(Vertex v);
    void insert_edge(Edge e);//assume insertion order is based on the from id.
    void insert_edges();
    void insert_vertices();
    void reverse_copy(Graph g);
    void print_outgoing_edges(int id);
    void print_incoming_edges(int id);
};
#endif