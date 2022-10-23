//
// Created by Libin Zhou on 8/10/22.
//

#include <fstream>
#include "Graph.h"
#include "iostream"
#include <limits>
Graph::Graph(int vertexCount, int edgeCount) {

    //std::cout<<vertexCount<<"\n";
    edges.reserve(edgeCount);
    //std::cout <<edges.capacity()<<"\n";
}
void Graph::insert_vertices() {
    std::ifstream  vertexFile;
    vertexFile.open(vertexPath);
    std::string line;
    std::string delimiter = ",";
    while(std::getline(vertexFile,line)){
        int del0 = line.find(delimiter,0);
        int start1 = del0+1;
        int del1 = line.find(delimiter,start1);
        int start2 = del1+1;
        int id = std::stoi(line.substr(0,del0));
        int latitude = std::stoi(line.substr(start1,del1));
        int longitude = std::stoi(line.substr(start2));
        Vertex* v = new Vertex();
        v->morton=0;//todo: set Morton code correctly
        v->id = id;
        v->startIndex = -1;
        v->endIndex = -1;
        vertices[v->id] = v;
    }
}

void Graph::insert_edges() {
    if(vertices.size()<=0){
        return;
    }
    int i=0;
    std::ifstream edgeFile;
    edgeFile.open(edgePath);
    //edgeFile.open("./Graph_Source/ID_edge_final.txt");
    std::string line;
    std::string delimiter = ",";
    Vertex* current;
    Vertex* previous;
    int previousID=BADID;
    while(std::getline(edgeFile,line)){
        int del0 = line.find(delimiter,0);
        int start1 = del0+1;
        int del1 = line.find(delimiter,start1);
        int start2 = del1+1;
        int del2 = line.find(delimiter,start2);
        int fromID = std::stoi(line.substr(0,del0));
        int toID = std::stoi(line.substr(start1,del1));
        int label = std::stoi(line.substr(start2,del2));
        float length = std::stof(line.substr(del2+1));
        //std::cout<<"from id is "<<fromID<<" toID is "<<toID<<" label is "<<label<<" length is "<<length<<"\n";
        Edge* e = new Edge();
        e->from = fromID;
        e->id=i;
        e->to = toID;
        e->length = length;
        e->label=label;
        e->next= NULL;
        if(!vertices.count(fromID)==1){
            assert(false);
        }
        current = vertices.at(fromID);
        if(fromID!=previousID){
            if(previousID!=BADID){
                previous = vertices.at(previousID);
                if(previous->startIndex<0){
                    assert(false);
                }
                previous->endIndex = edges.size()-1;
            }
            previousID = fromID;
        }
        if(current->startIndex<0){
            current->startIndex = edges.size();
        }
        edges.push_back(e);
        //handles the incoming edge adjacency list

    }
    //std::cout<<edges.size()<<"\n";
    edgeFile.close();
}
