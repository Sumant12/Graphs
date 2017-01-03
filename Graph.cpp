//
//  Graph.cpp
//  Assignment4
//
//  Created by Sumanth Sai on 12/2/16.
//  Copyright © 2016 Sumanth Sai. All rights reserved.
//

#include "Graph.hpp"

#define ParentNode(i) ((i%2==0) ? (i-1)/2 : i/2)
#define LeftNode(i)   2*i+1
#define RightNode(i)  (2*i+2)

void Graph::Buildgraph(string GraphName)
{
    Dict.clear();
    for (int i = 0; i < AdjListVector.size(); i++)
    {
        AdjListVector[i].clear();
    }
    fstream stream1;
    stream1.open(GraphName.c_str());
    string eachline;
    getline(stream1, eachline);
    int ind = 1;
    /* Undirected graph */
    if (eachline[0] == 'U')
        Directed = 0;
    else Directed = 1;
    
    for (int i = 1; i < eachline.length(); i++)
    {
        if (eachline[i] != ',')
        {
            string str;
            str.push_back(eachline[i]);
            Dict[str] = ind;
            ind++;
        }
    }
    CountofVerices = ind-1;
    int row = 1;
    while (getline (stream1, eachline))
    {
        int j = 1;
        for (int i = 1; i < eachline.length(); i++)
        {
            if (eachline[i] == ',')
                continue;
            if (eachline[i] == '0')
            {
                j++;
                continue;
            }
            AdjListVector[row].push_back(GraphEdge(j,eachline[i]-48));
            j++;
        }
        row++;
    }
    stream1.close();
}

int Graph::FindIndex(string vertex, int size)
{
    for (int i = 0; i< size ; i++)
    {
        if (GraphEdgeArray[i].v.compare(vertex) == 0)
            return i;
    }
    return -1;
}


void Graph::ShowPath(string vertex)
{
    int ind = FindIndex(vertex, CountofVerices);
    if (GraphEdgeArray[ind].v.compare("junk") == 0)
        return;
    if (GraphEdgeArray[ind].parent.compare("junk") == 0)
    {
        cout << GraphEdgeArray[ind].v << "--->";
        return;
    }
    ShowPath(GraphEdgeArray[ind].parent);
    cout << GraphEdgeArray[ind].v << "--->";
}

void Graph::InsertWeights(string name)
{
    fstream stream1;
    stream1.open(name.c_str());
    string line;
    getline(stream1, line);
    if (line[0] == 'W')
    {
        //It is a WeightedGraph
        Directed = 2;
    }
    int row = 1, j = 1;
    while (getline (stream1, line))
    {
        int value;
        j = 1;
        stringstream strstream1(line);
        char ch;
        strstream1 >> ch;
        while(strstream1 >> ch)
        {
            strstream1 >> value;
            if (value != -1)
            {
            
              
                for(vector<GraphEdge>::size_type e  = 0; e < AdjListVector[row].size(); e++)
                {
                    if (AdjListVector[row][e].ReturnVertex() == j)
                    {
                        AdjListVector[row][e].AssignWeight(value);
                        break;
                    }
                }
            }
            j++;
        }
        row++;
        strstream1.clear();
    
    }
}

string Graph::VertexName(int index)
{
    for (std::map<string,int>::iterator itr = Dict.begin(); itr != Dict.end(); itr++)
    {
        if (itr->second == index)
            return itr->first;
    }

    return "0";
}

void Graph::GenerateDotFile(string name)
{
    stringstream strstream;
    string typearrow, plot1, plot2;
    /* undirected graph */
    if (Directed == 0)
    {
        typearrow = "--";
        strstream << " strict graph {  \n node [shape= ellipse];\n";
    }
    else
    {
        typearrow = "->";
        strstream << " strict digraph {  \n node [shape= ellipse];\n";
    }
    for (std::map<string,int>::iterator it = Dict.begin(); it != Dict.end(); it++)
    {
        plot1 = it->first;
        strstream << plot1 << "\t";
    }
    
    strstream << endl;
    for (std::map<string,int>::iterator itr = Dict.begin(); itr != Dict.end(); itr++)
    {
        for(vector<GraphEdge>::size_type e  = 0; e < AdjListVector[itr->second].size(); e++)
        {
            plot1 = itr->first;
            plot2 = VertexName(AdjListVector[itr->second][e].ReturnVertex());
            //	cout << ch1 << "--" << ch2 << ";\n";
            strstream << plot1 << typearrow << plot2 ;
            if ((Directed == 2) || (AdjListVector[itr->second][e].ReturnWeight() > 1))
            {
                strstream << "[ label=" << AdjListVector[itr->second][e].ReturnWeight() << "]";
            }
            strstream << ";\n";
        }
    }
    strstream << "}\n";
    fstream fs;
    remove(name.c_str());
    fs.open(name.c_str(), std::fstream::in|std::fstream::out|std::fstream::app);
    fs << strstream.str();
    fs.close();
    strstream.str("");
    
}

void Graph::AddVertex(string name)
{
    if (Dict.find(name) != Dict.end())
    {
        cout << "The Vertex already exists in the graph" << endl;
        return;
    }
    CountofVerices++;
    Dict.insert(std::pair<string,int>(name,CountofVerices));
}

void Graph::AddEdge(string name1, string name2, int weight)
{
    if (Dict.find(name1) == Dict.end())
    {
        AddVertex(name1);
    }
    if (Dict.find(name2) == Dict.end())
    {
        AddVertex(name2);
    }
    int ind1 = Dict[name1];
    int ind2 = Dict[name2];
    AdjListVector[ind1].push_back(GraphEdge(ind2, weight));
}

void Graph::DeleteVertex(string name)
{
    if (Dict.find(name) == Dict.end())
    {
        cout << "The vertex " << name << "is not in the graph" << endl;
        return;
    }
    int index = Dict[name];
    
    for(vector<GraphEdge>::iterator itr1  = AdjListVector[index].begin(); itr1 !=  AdjListVector[index].end(); )
    {
        /* Remove both the edge from an undirected graph */
        if (Directed == 0)
        {
            int index2 = itr1->vertex;
            for(vector<GraphEdge>::iterator itr2  = AdjListVector[index2].begin(); itr2 !=  AdjListVector[index2].end(); itr2++)
            {
                if (itr2->vertex == index)
                {
                 
                    AdjListVector[index2].erase(itr2);
                    break;
                }
            }
        }
        itr1 = AdjListVector[index].erase(itr1);
    }
   
    if (Directed == 1)
    {
        for (std::map<string,int>::iterator item = Dict.begin(); item != Dict.end(); item++)
        {
            for(vector<GraphEdge>::iterator itr3  = AdjListVector[item->second].begin(); itr3 != AdjListVector[item->second].end(); itr3++)
            {
                if (itr3->vertex == index)
                {
                    AdjListVector[item->second].erase(itr3);
                    break;
                }
            }
        }
    }
  // Remove the vertex now
    Dict.erase(Dict.find(name));
    CountofVerices--;
}

void Graph::DeleteEdge(string name1, string name2, int weight)
{
    int ind1 = Dict[name1];
    int ind2 = Dict[name2];
    for(vector<GraphEdge>::iterator eng  = AdjListVector[ind1].begin(); eng != AdjListVector[ind1].end(); eng++)
    {
        if (eng->vertex == ind2)
        {
            AdjListVector[ind1].erase(eng);
            return;
        }
    }
}


void Graph::InitializeArray()
{
    for (int i = 0; i < CountofVerices; i++)
    {
        GraphEdgeArray[i].v = VertexName(i+1);
        GraphEdgeArray[i].key    = 100000;
    }
}

void Graph::Swap(int index1, int index2)
{
    GraphEdge_v swap;
    swap.v = GraphEdgeArray[index1].v;
    swap.key   = GraphEdgeArray[index1].key;
    swap.parent  = GraphEdgeArray[index1].parent;
    GraphEdgeArray[index1].v = GraphEdgeArray[index2].v;
    GraphEdgeArray[index1].key    = GraphEdgeArray[index2].key;
    GraphEdgeArray[index1].parent   = GraphEdgeArray[index2].parent;
    GraphEdgeArray[index2].v = swap.v;
    GraphEdgeArray[index2].key    = swap.key;
    GraphEdgeArray[index2].parent   = swap.parent;
}


void Graph::Heapify(int index)
{
    if (index < 0)
        return;
    int ParInd = ParentNode(index);
    if ((ParInd >= 0) && (GraphEdgeArray[ParInd].key > GraphEdgeArray[index].key))
    {
        Swap(ParInd, index);
        Heapify(ParInd);
    }
}


void Graph::ChangeDistance(string vertex, int value, int size, string par)
{
    int i = FindIndex(vertex,  size);
    if ( i == -1)
    {
        //    cout << vertex << " Vertex not found: " << endl;
        return;
    }
    if (GraphEdgeArray[i].key > value)
    {
        GraphEdgeArray[i].key = value;
        GraphEdgeArray[i].parent = par;
        Heapify(i);
    }
}

void Graph::HeapifyDown(int ind, int size)
{
    if (ind >= size)
        return;
    int leftInd = LeftNode(ind);
    int rightInd = RightNode(ind);
    int small = ind;
    if ((leftInd < size) && (GraphEdgeArray[ind].key > GraphEdgeArray[leftInd].key))
    {
        small = leftInd;
    }
    if ((rightInd < size) && (GraphEdgeArray[small].key > GraphEdgeArray[rightInd].key))
    {
        small = rightInd;
    }
    Swap(ind, small);
    if (ind != small)
    {
        HeapifyDown(small, size);
    }
}

void Graph::Dijkstra(string vertex)
{
    int ind;
    if (Dict.find(vertex) != Dict.end())
        ind = Dict.find(vertex)->second;
    else
    {
        return;
    }
    
    // cout << endl << "Dijkstra for vertex " << vertex << " " << ind << endl;
    /* start vertex weight as zero */
    int size = CountofVerices;
    ChangeDistance(vertex, 0, size, "junk");
    while (size > 0)
    {
        int ind = Dict.find(GraphEdgeArray[0].v)->second;
        int w1   = GraphEdgeArray[0].key;
        Swap(0,size-1);
        size--;
        HeapifyDown(0, size);
        for (vector<GraphEdge>::iterator it1  = AdjListVector[ind].begin(); it1 !=  AdjListVector[ind].end(); it1++)
        {
            int ind2 = it1->vertex;
            int weight = it1->weight + w1;
            ChangeDistance(VertexName(ind2), weight, size, VertexName(ind));
        }
    }
   
}

void Graph::ColorDotFile(string name)
{
    stringstream stream1;
    string sign, nam1, nam2;
    if (Directed == 0)
    {
        sign = "--";
        stream1 << " strict graph {  \n node [shape= ellipse];\n";
    }
    else
    {
        sign = "->";
        stream1 << " strict digraph {  \n node [shape= ellipse];\n";
    }
    for (std::map<string,int>::iterator it = Dict.begin(); it != Dict.end(); it++)
    {
        nam1 = it->first;
        stream1 << nam1 << "\t";
    }
    for (int i = 0; i < CountofVerices; i++)
    {
        if ((GraphEdgeArray[i].parent.compare("junk") == 0) || (GraphEdgeArray[i].v.compare("junk") == 0))
        {
            continue;
        }
        stream1 << GraphEdgeArray[i].parent << sign << GraphEdgeArray[i].v;
        stream1 << "[color=red, label=" << (GraphEdgeArray[i].key - GraphEdgeArray[FindIndex(GraphEdgeArray[i].parent, CountofVerices)].key) << "];\n";
    }
    
    stream1 << endl;
    for (std::map<string,int>::iterator itr = Dict.begin(); itr != Dict.end(); itr++)
    {
        for(vector<GraphEdge>::size_type e  = 0; e < AdjListVector[itr->second].size(); e++)
        {
            nam1 = itr->first;
            nam2 = VertexName(AdjListVector[itr->second][e].ReturnVertex());
            int index2 = FindIndex(nam2, CountofVerices);
            if ((index2 != -1) && (GraphEdgeArray[index2].parent.compare(nam1) == 0))
            {
                continue;
            }
            
            stream1 << nam1 << sign << nam2 ;
            if ((Directed == 2) || (AdjListVector[itr->second][e].ReturnWeight() > 1))
            {
                stream1 << "[ label=" << AdjListVector[itr->second][e].ReturnWeight() << "]";
            }
            stream1 << ";\n";
        }
    }
    stream1 << "}\n";
    fstream fs;
    remove(name.c_str());
    fs.open(name.c_str(), std::fstream::in|std::fstream::out|std::fstream::app);
    fs << stream1.str();
    fs.close();
    stream1.str("");
    
    
}

