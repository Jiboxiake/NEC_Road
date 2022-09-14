//
// Created by Libin Zhou on 8/10/22.
//
#include "Dijkstra.h"
#include <queue>
SPResult Dijkstra::simple_Dijkstra(Graph g, int source, int destination) {
    SPResult result;
    result.number_of_hops=0;
    result.result = std::numeric_limits<float>::max();
    if(!g.vertices.count(source)==1||!g.vertices.count(destination)==1){
        return result;
    }
    std::map<int,float> distmap;
    Vertex* currentVertex;
    Edge*   currentEdge;
    Vertex* toVertex;
    currentVertex = (g.vertices.at(source));
    distmap[source]=0;
    std::priority_queue<Entry,std::vector<Entry>,CompareWeight>queue;
    Entry e1;
    e1.id=source;
    e1.weight=0;
    e1.previousID=-1;
    float originalDistance =-1;
    float newDistance = -1;
    queue.push(e1);
    while(!queue.empty()){
        e1 = queue.top();
        queue.pop();
        result.number_of_hops++;
        if(e1.id==destination){
            result.result = e1.weight;
            break;
        }
        //read from the adjacency list
        currentVertex = g.vertices.at(e1.id);
        for(int i=currentVertex->startIndex;i<=currentVertex->endIndex;i++){//purely sequential adjacency list scan, hope we can optimize cache performance and vectorization here
            currentEdge = g.edges.at(i);
            newDistance = e1.weight+currentEdge->length;
            toVertex = g.vertices.at(currentEdge->to);
            if(distmap.count(toVertex->id)==1){
                originalDistance=distmap[toVertex->id];

                if(originalDistance>newDistance){
                    Entry e2;
                    e2.weight = newDistance;
                    e2.id = toVertex->id;
                    e2.previousID=e1.id;
                    queue.push(e2);
                    distmap[toVertex->id]=newDistance;
                }
            }else{
                distmap[toVertex->id]=newDistance;
                Entry e2;
                e2.weight = newDistance;
                e2.id = toVertex->id;
                e2.previousID=e1.id;
                queue.push(e2);
            }
        }
    }
    return result;
}