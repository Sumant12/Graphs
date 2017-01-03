//
//  Graph.hpp
//  Assignment4
//
//  Created by Sumanth Sai on 12/2/16.
//  Copyright © 2016 Sumanth Sai. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <sstream>
#include <map>

using namespace std;

class GraphEdge_v{
public:
    string v;
    int key;
    string parent;
    GraphEdge_v(){
        v = "junk";
        key = 99999;
        parent = "junk";
    }
    
};

class GraphEdge{
    
public:
    int vertex;
    int weight;;
    GraphEdge(int v,int w){
        vertex = v;
        weight = w;
    }
    
    void AssignWeight(int weight1){
        weight = weight1;
    }
    
    int ReturnVertex(){
        return vertex;
    }
    int ReturnWeight(){
        return weight;
    }
    
};

class Graph{
public:
    GraphEdge_v GraphEdgeArray[20];
    map<std::string,int> Dict;
    vector<vector<GraphEdge> > AdjListVector = vector<vector<GraphEdge> >(20);
    int Directed;
    int CountofVerices =0;
    void Buildgraph(string GraphName);
    int FindIndex(string vertex, int size);
    void ShowPath(string vertex);
    void InsertWeights(string name);
    string VertexName(int index);
    void GenerateDotFile(string name);
    void AddVertex(string name);
    void AddEdge(string name1, string name2, int weight);
    void DeleteVertex(string name);
    void DeleteEdge(string name1, string name2, int weight);
    void InitializeArray();
    void Swap(int i, int j);
    void Heapify(int i);
    void ChangeDistance(string vertex, int val, int size, string pred);
    void Dijkstra(string vertex);
    void HeapifyDown(int index, int size);
    void ColorDotFile(string name);
};


#endif /* Graph_hpp */
