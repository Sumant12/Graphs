
//  main.cpp
//  Assignment4
//
//  Created by Sumanth Sai on 12/2/16.
//  Copyright © 2016 Sumanth Sai. All rights reserved.
//

#include <iostream>
#include "Graph.hpp"
#include <sstream>
#include <algorithm>
using namespace std;

void Case1()
{
    cout << endl << endl << "*****Testcase1 Start*****" << endl << endl;
    Graph graph1;
    graph1.Buildgraph("fig1.csv");
    cout << "Graph has been constructed from fig1.csv" << endl;
    cout << "List of vertices is " << endl;
    for (std::map<string,int>::iterator itr = graph1.Dict.begin(); itr != graph1.Dict.end(); itr++)
    {
        cout << itr->first << ", " << itr->second << "   ";
    }
    cout << endl << "The Adjacency list built is " << endl;
    for (int i = 1 ; i <= graph1.CountofVerices ; i++)
    {
        cout << i << "-->";
        for (vector<GraphEdge>::size_type eng = 0; eng < graph1.AdjListVector[i].size(); eng++)
        {
            cout << graph1.AdjListVector[i][eng].ReturnVertex() << "(" << graph1.AdjListVector[i][eng].ReturnWeight() << ")";
            (eng == graph1.AdjListVector.size()-1) ? cout << endl : cout << ", ";
        }
        cout << endl;
    }
    graph1.GenerateDotFile("t1.dot");
    cout << "t1.dot is generated" << endl;
    cout << endl << endl << "*****Testcase1 End*****" << endl << endl;
}

void Case2()
{
    cout << endl << endl << "*****Testcase2 Start*****" << endl << endl;
    Graph graph2;
    graph2.Buildgraph("fig2.csv");
    cout << "Graph has been constructed from fig2.csv" << endl;
    cout << "List of vertices is " << endl;
    for (std::map<string,int>::iterator itr = graph2.Dict.begin(); itr != graph2.Dict.end(); itr++)
    {
        cout << itr->first << ", " << itr->second << "   ";
    }
    cout << endl << "The Adjacency list built is " << endl;
    for (int i = 1 ; i <= graph2.CountofVerices ; i++)
    {
        cout << i << "-->";
        for (vector<GraphEdge>::size_type eng = 0; eng < graph2.AdjListVector[i].size(); eng++)
        {
            cout << graph2.AdjListVector[i][eng].ReturnVertex() << "(" << graph2.AdjListVector[i][eng].ReturnWeight() << ")";
            (eng == graph2.AdjListVector.size()-1) ? cout << endl : cout << ", ";
        }
        cout << endl;
    }
    graph2.GenerateDotFile("t2.dot");
    cout << "t2.dot is generated" << endl;
    cout << endl << endl << "*****Testcase2 End*****" << endl << endl;
}

void Case3()
{
    cout << endl << endl << "*****Testcase3 Start*****" << endl << endl;
    Graph graph3;
    graph3.Buildgraph("fig3.csv");
    cout << "Graph has been constructed from fig3.csv" << endl;
    cout << "List of vertices is " << endl;
    for (std::map<string,int>::iterator itr = graph3.Dict.begin(); itr != graph3.Dict.end(); itr++)
    {
        cout << itr->first << ", " << itr->second << "   ";
    }
    cout << endl << "The Adjacency list built is " << endl;
 for (int i = 1 ; i <= graph3.CountofVerices ; i++)
    {
        cout << i << "-->";
       for (vector<GraphEdge>::size_type eng = 0; eng < graph3.AdjListVector[i].size(); eng++)
        {
          cout << graph3.AdjListVector[i][eng].ReturnVertex() << "(" << graph3.AdjListVector[i][eng].ReturnWeight() << ")";
                (eng == graph3.AdjListVector.size()-1) ? cout << endl : cout << ", ";
        }
        cout << endl;
    }
    graph3.InsertWeights("fig3-w.csv");
    cout << "Inserting weights to the graph" << endl;
    cout << endl << "Adjaceny list is " << endl;
for (int i = 1 ; i <= graph3.CountofVerices ; i++)
    {
        cout << i << "-->";
for (vector<GraphEdge>::size_type eng = 0; eng < graph3.AdjListVector[i].size(); eng++)
        {
             cout << graph3.AdjListVector[i][eng].ReturnVertex() << "(" << graph3.AdjListVector[i][eng].ReturnWeight() << ")";
           (eng == graph3.AdjListVector.size()-1) ? cout << endl : cout << ", ";
        }
        cout << endl;
    }
graph3.GenerateDotFile("t3.dot");
    cout << "t3.dot is generated" << endl;
    cout << endl << endl << "*****Testcase3 End*****" << endl << endl;
}

void Case4()
{
    cout << endl << endl << "*****Testcase4 Start*****" << endl << endl;
    Graph graph4;
    graph4.Buildgraph("fig1.csv");
    cout << "List of vertices is " << endl;
    for (std::map<string,int>::iterator itr = graph4.Dict.begin(); itr != graph4.Dict.end(); itr++)
    {
        cout << itr->first << ", " << itr->second << "   ";
    }
    cout << endl << "The Adjacency list built is " << endl;
    for (int i = 1 ; i <= graph4.CountofVerices ; i++)
    {
        cout << i << "-->";
        for (vector<GraphEdge>::size_type eng = 0; eng < graph4.AdjListVector[i].size(); eng++)
        {
            cout << graph4.AdjListVector[i][eng].ReturnVertex() << "(" << graph4.AdjListVector[i][eng].ReturnWeight() << ")";
            (eng == graph4.AdjListVector.size()-1) ? cout << endl : cout << ", ";
        }
        cout << endl;
    }
    graph4.AddVertex("z");
    cout << "Added vertex \"z\" to the graph" << endl;
    graph4.AddEdge("z", "w", 1);
    graph4.AddEdge("w", "z", 1);
    cout << "Added edge between \"z\" and \"w\" " << endl;
    graph4.AddEdge("z", "x", 1);
    graph4.AddEdge("x", "z", 1);
    cout << "Added edge between \"z\" and \"x\" " << endl;
    graph4.AddEdge("z", "y", 1);
    graph4.AddEdge("y", "z", 1);
    cout << "Inserted the edge between \"z\" and \"y\" " << endl;
    graph4.GenerateDotFile("t4a.dot");
    cout << "t4a.dot is generated" << endl;
    graph4.DeleteVertex("s");
    cout << "Removed the vertex \"s\" from the graph " << endl;
    graph4.DeleteVertex("x");
    cout << "Removed the vertex \"x\" from the graph " << endl;
    graph4.DeleteEdge("u","t",1);
    graph4.DeleteEdge("t","u",1);
    cout << "Removed the Edge between \"u\" and \"t\" from the graph" << endl;
    graph4.GenerateDotFile("t4b.dot");
    cout << "t4b.dot has been Generated" << endl;
    cout << endl << endl << "*****Testcase4 End*****" << endl << endl;
    
}

void Case5()
{
    cout << endl << endl << "*****Begin of Testcase5 Execution*****" << endl << endl;
    Graph graph6;
    graph6.CountofVerices = 0;
    graph6.Directed = 0;
    graph6.AddEdge("6","7",1);
    graph6.AddEdge("7","6",1);
    cout << "A new edge has been inserted between \"6\" and \"7\"" << endl;
    graph6.AddEdge("7","8",1);
    graph6.AddEdge("8","7",1);
    cout << "A new edge has been inserted between \"7\" and \"8\"" << endl;
    graph6.AddEdge("8","9",1);
    graph6.AddEdge("9","8",1);
    cout << "A new edge has been inserted between \"8\" and \"9\"" << endl;
    graph6.AddEdge("9","10",1);
    graph6.AddEdge("10","9",1);
    cout << "A new edge has been inserted between \"9\" and \"10\"" << endl;
    graph6.AddEdge("10","6",1);
    graph6.AddEdge("6","10",1);
    cout << "A new edge has been inserted between \"6\" and \"10\"" << endl;
    graph6.AddVertex("1");
    graph6.AddVertex("2");
    graph6.AddVertex("3");
    graph6.AddVertex("4");
    graph6.AddVertex("5");
    cout << "Inserted vertices 1,2,3,4,5 to the graph" << endl;
    graph6.AddEdge("1","6",1);
    graph6.AddEdge("6","1",1);
    cout << "A new edge has been inserted between \"6\" and \"1\"" << endl;
    graph6.AddEdge("2","7",1);
    graph6.AddEdge("7","2",1);
    cout << "A new edge has been inserted between \"2\" and \"7\"" << endl;
    graph6.AddEdge("3","8",1);
    graph6.AddEdge("8","3",1);
    cout << "A new edge has been inserted between \"3\" and \"8\"" << endl;
    graph6.AddEdge("4","9",1);
    graph6.AddEdge("9","4",1);
    cout << "A new edge has been inserted between \"4\" and \"9\"" << endl;
    graph6.AddEdge("5","10",1);
    graph6.AddEdge("10","5",1);
    cout << "A new edge has been inserted between \"5\" and \"10\"" << endl;
    graph6.GenerateDotFile("t5a.dot");
    cout << "Created dot file t5a.dot" << endl;
    graph6.DeleteVertex("8");
    cout << "Removed the vertex \"8\" from the graph" << endl;
    graph6.DeleteVertex("6");
    cout << "Removed the vertex \"6\" from the graph" << endl;
    graph6.GenerateDotFile("t5b.dot");
    cout << "Created dot file t5b.dot" << endl;
    cout << endl << endl << "*****Testcase5 End*****" << endl << endl;
    
}

void Case6()
{
    cout << endl << endl << "*****Testcase6 Start*****" << endl << endl;
    Graph graph6;
    graph6.CountofVerices = 0;
    /* Make the grph directed */
    graph6.Directed = 1;
    graph6.AddVertex("2");
    graph6.AddVertex("4");
    graph6.AddVertex("6");
    graph6.AddVertex("8");
    graph6.AddVertex("10");
    cout << "Inserted vertices 2,4,6,8,10" << endl;
    graph6.AddEdge("2","4",1);
    cout << "A new edge has been inserted between \"2\" and \"4\"" << endl;
    graph6.AddEdge("2","6",1);
    cout << "A new edge has been inserted between \"2\" and \"6\"" << endl;
    graph6.AddEdge("4","6",1);
    cout << "A new edge has been inserted between \"4\" and \"6\"" << endl;
    graph6.AddEdge("4","8",1);
    cout << "A new edge has been inserted between \"4\" and \"8\"" << endl;
    graph6.AddEdge("6","8",1);
    cout << "A new edge has been inserted between \"6\" and \"8\"" << endl;
    graph6.AddEdge("6","10",1);
    cout << "A new edge has been inserted between \"6\" and \"10\"" << endl;
    graph6.AddEdge("8","10",1);
    cout << "A new edge has been inserted between \"8\" and \"10\"" << endl;
    graph6.AddEdge("8","2",1);
    cout << "A new edge has been inserted between \"8\" and \"2\"" << endl;
    graph6.AddVertex("1");
    graph6.AddVertex("3");
    graph6.AddVertex("5");
    graph6.AddVertex("7");
    graph6.AddVertex("9");
    cout << "Inserted vertices 1,3,5,7,9" << endl;
    graph6.AddEdge("1","2",1);
    cout << "A new edge has been inserted between \"1\" and \"2\"" << endl;
    graph6.AddEdge("3","4",1);
    cout << "A new edge has been inserted between \"3\" and \"4\"" << endl;
    graph6.AddEdge("5","6",1);
    cout << "A new edge has been inserted between \"5\" and \"6\"" << endl;
    graph6.AddEdge("7","8",1);
    cout << "A new edge has been inserted between \"7\" and \"8\"" << endl;
    graph6.AddEdge("9","10",1);
    cout << "A new edge has been inserted between \"9\" and \"10\"" << endl;
    graph6.GenerateDotFile("t6a.dot");
    cout << "t6a.dot is generated" << endl;
    graph6.DeleteVertex("2");
    cout << "Removed vertex \"2\" from the graph" << endl;
    graph6.DeleteVertex("7");
    cout << "Removed vertex \"7\" from the graph" << endl;
    graph6.GenerateDotFile("t6b.dot");
    cout << "t6b.dot is generated " << endl;
    cout << endl << endl << "*****Testcase6 End*****" << endl << endl;
}

void Case7()
{
    cout << endl << endl << "*****Testcase7 Start*****" << endl << endl;
    Graph graph7;
    graph7.Buildgraph("fig3.csv");
    cout << "Graph has been constructed from fig3.csv" << endl;
    cout << "List of vertices is " << endl;
    cout << "-----------------------------------" << endl;
    for (std::map<string,int>::iterator itr = graph7.Dict.begin(); itr != graph7.Dict.end(); itr++)
    {
        cout << itr->first << ", " << itr->second << "   ";
    }
    graph7.InsertWeights("fig3-w.csv");
    graph7.InitializeArray();
    for (std::map<string,int>::iterator itr = graph7.Dict.begin(); itr != graph7.Dict.end(); itr++)
    {
        cout << endl << itr->first << " ";
        string Vname = itr->first;
        graph7.Dijkstra(Vname);
       for (std::map<string,int>::iterator itr2 = graph7.Dict.begin(); itr2 != graph7.Dict.end(); itr2++)
        {
            int index = graph7.FindIndex(itr2->first, graph7.CountofVerices);
            cout.width(6); cout << graph7.GraphEdgeArray[index].key;
        }
    
        graph7.InitializeArray();
    }
    cout << endl << "The Corresponding Adjaceny list is " << endl;
    for (int i = 1 ; i <= graph7.CountofVerices ; i++)
    {
        cout << i << "-->";
        for (vector<GraphEdge>::size_type e = 0; e < graph7.AdjListVector[i].size(); e++)
        {
            cout << graph7.AdjListVector[i][e].ReturnVertex() << "(" << graph7.AdjListVector[i][e].ReturnWeight() << ")";
            (e == graph7.AdjListVector[i].size()-1) ? cout << endl : cout << ", ";
        }
        cout << endl;
    }
    
    cout << endl << endl << "*****Testcase7 End*****" << endl << endl;
    
}



void Case8()
{
    cout << endl << endl << "*****Testcase8 Start*****" << endl << endl;
    Graph graph8;
    graph8.CountofVerices =0;
    graph8.Directed = 0;
    graph8.AddVertex("s");
    graph8.AddVertex("t");
    graph8.AddVertex("x");
    graph8.AddVertex("y");
    graph8.AddVertex("z");
    graph8.AddEdge("s", "t",10);
    graph8.AddEdge("t", "s",10);
    graph8.AddEdge("s","y",5);
    graph8.AddEdge("y","s",5);
    graph8.AddEdge("s","z",7);
    graph8.AddEdge("z","s",7);
    graph8.AddEdge("t","x",1);
    graph8.AddEdge("x","t",1);
    graph8.AddEdge("t","y",2);
    graph8.AddEdge("y","t",2);
    graph8.AddEdge("y","x",9);
    graph8.AddEdge("x","y",9);
    graph8.AddEdge("y","z",2);
    graph8.AddEdge("z","y",2);
    graph8.AddEdge("z","x",4);
    graph8.AddEdge("x","z",4);
   // graph8.GenerateDotFile("t8a.dot");
    graph8.InitializeArray();
    cout << "List of  vertices is " << endl;
    cout << "-----------------------------------" << endl;
    for (std::map<string,int>::iterator it = graph8.Dict.begin(); it != graph8.Dict.end(); it++)
    {
        cout.width(6);cout << it->first;
      
    }
    cout << endl << "------------------------------------" << endl;
    for (std::map<string,int>::iterator it = graph8.Dict.begin(); it != graph8.Dict.end(); it++)
    {
        cout << it->first << " ";
        string Vname = it->first;
        graph8.Dijkstra(Vname);
        for (std::map<string,int>::iterator it2 = graph8.Dict.begin(); it2 != graph8.Dict.end(); it2++)
        {
            int findindex = graph8.FindIndex(it2->first, graph8.CountofVerices);
            cout.width(6); cout << graph8.GraphEdgeArray[findindex].key;
        }
        cout << endl;
        graph8.InitializeArray();
    }
    cout << endl << endl << "*****Testcase8 End*****" << endl << endl;
}

void Case9()
{
    cout << endl << endl << "*****Testcase9 Start*****" << endl << endl;
    Graph graph9;
    graph9.Buildgraph("fig3.csv");
    graph9.InsertWeights("fig3-w.csv");
    graph9.InitializeArray();
    graph9.Dijkstra("s");
    cout << endl << "------------------------------------------" << endl;
    cout << "Vertex   The path from source vertex s    " << endl;
    cout << "         to this vertex in G3             " << endl;
    cout << "------------------------------------------" << endl;
    for (std::map<string,int>::iterator itr = graph9.Dict.begin(); itr != graph9.Dict.end(); itr++)
    {
        cout << itr->first << "     ";
        stringstream ss;
        int findIndex = graph9.FindIndex(itr->first, graph9.CountofVerices);
        ss.str("");
        while(graph9.GraphEdgeArray[findIndex].parent.compare("junk") != 0)
        {
            ss << graph9.GraphEdgeArray[findIndex].parent << "---";
            findIndex = graph9.FindIndex(graph9.GraphEdgeArray[findIndex].parent, graph9.CountofVerices);
            if (findIndex == -1)
                break;
        }
        string str3(ss.str());
        reverse(str3.begin(), str3.end());
        str3.erase(0,3);
        str3.append("---");
        str3.append(itr->first);
        if (itr->first.compare("s") == 0)
        {
            str3 = "nil";
        }
        cout << str3 << endl;
    }
    graph9.InitializeArray();
    graph9.Dijkstra("z");
    cout << endl << "------------------------------------------" << endl;
    cout << "Vertex   The path from source vertex z    " << endl;
    cout << "         to this vertex in G3             " << endl;
    cout << "------------------------------------------" << endl;
    for (std::map<string,int>::iterator it2 = graph9.Dict.begin(); it2 != graph9.Dict.end(); it2++)
    {
        cout << it2->first << "     ";
        stringstream ss2;
        int findIndex = graph9.FindIndex(it2->first, graph9.CountofVerices);
        ss2.str("");
        while(graph9.GraphEdgeArray[findIndex].parent.compare("junk") != 0)
        {
            ss2 << graph9.GraphEdgeArray[findIndex].parent << "---";
            findIndex = graph9.FindIndex(graph9.GraphEdgeArray[findIndex].parent, graph9.CountofVerices);
            if (findIndex == -1)
                break;
        }
        string mystr2(ss2.str());
        reverse(mystr2.begin(), mystr2.end());
        mystr2.erase(0,3);
        mystr2.append("---");
        mystr2.append(it2->first);
        if (it2->first.compare("z") == 0)
        {
            mystr2 = "nil";
        }
        cout << mystr2 << endl;
    }
    
    
    cout << endl << endl << "*****Testcase9 End*****" << endl << endl;
}

void Case10()
{
    cout << endl << endl << "*****Testcase10 Start*****" << endl << endl;
    Graph graph10;
    graph10.Directed = 0;
    graph10.AddVertex("s");
    graph10.AddVertex("t");
    graph10.AddVertex("x");
    graph10.AddVertex("y");
    graph10.AddVertex("z");
    graph10.AddEdge("s", "t",10);
    graph10.AddEdge("t", "s",10);
    graph10.AddEdge("s","y",5);
    graph10.AddEdge("y","s",5);
    graph10.AddEdge("s","z",7);
    graph10.AddEdge("z","s",7);
    graph10.AddEdge("t","x",1);
    graph10.AddEdge("x","t",1);
    graph10.AddEdge("t","y",2);
    graph10.AddEdge("y","t",2);
    graph10.AddEdge("y","x",9);
    graph10.AddEdge("x","y",9);
    graph10.AddEdge("y","z",2);
    graph10.AddEdge("z","y",2);
    graph10.AddEdge("z","x",4);
    graph10.AddEdge("x","z",4);
    graph10.InitializeArray();
    graph10.Dijkstra("s");
    cout << endl << "------------------------------------------" << endl;
    cout << "Vertex   The path from source vertex s    " << endl;
    cout << "         to this vertex in G4             " << endl;
    cout << "------------------------------------------" << endl;
    for (std::map<string,int>::iterator it = graph10.Dict.begin(); it != graph10.Dict.end(); it++)
    {
        cout << it->first << "     ";
        stringstream ss;
        int findIndex = graph10.FindIndex(it->first, graph10.CountofVerices);
        ss.str("");
        while(graph10.GraphEdgeArray[findIndex].parent.compare("junk") != 0)
        {
            ss << graph10.GraphEdgeArray[findIndex].parent << "---";
            findIndex = graph10.FindIndex(graph10.GraphEdgeArray[findIndex].parent, graph10.CountofVerices);
            if (findIndex == -1)
                break;
        }
        string mystr(ss.str());
        reverse(mystr.begin(), mystr.end());
        mystr.erase(0,3);
        mystr.append("---");
        mystr.append(it->first);
        if (it->first.compare("s") == 0)
        {
            mystr = "nil";
        }
        cout << mystr << endl;
    }
    graph10.InitializeArray();
    graph10.Dijkstra("z");
    cout << endl << "------------------------------------------" << endl;
    cout << "Vertex   The path from source vertex z    " << endl;
    cout << "         to this vertex in G4             " << endl;
    cout << "------------------------------------------" << endl;
    for (std::map<string,int>::iterator it2 = graph10.Dict.begin(); it2 != graph10.Dict.end(); it2++)
    {
        cout << it2->first << "     ";
        stringstream ss2;
        int findIndex = graph10.FindIndex(it2->first, graph10.CountofVerices);
        ss2.str("");
        while(graph10.GraphEdgeArray[findIndex].parent.compare("junk") != 0)
        {
            ss2 << graph10.GraphEdgeArray[findIndex].parent << "---";
            findIndex = graph10.FindIndex(graph10.GraphEdgeArray[findIndex].parent, graph10.CountofVerices);
            if (findIndex == -1)
                break;
        }
        string mystr2(ss2.str());
        reverse(mystr2.begin(), mystr2.end());
        mystr2.erase(0,3);
        mystr2.append("---");
        mystr2.append(it2->first);
        if (it2->first.compare("z") == 0)
        {
            mystr2 = "nil";
        }
        cout << mystr2 << endl;
    }
    cout << endl << endl << "*****Testcase10 End*****" << endl << endl;
    
}

void Case11()
{
    cout << endl << endl << "*****Testcase11 Start*****" << endl << endl;
    Graph graph11;
    graph11.Buildgraph("fig3.csv");
    graph11.InsertWeights("fig3-w.csv");
    graph11.InitializeArray();
    GraphEdge_v ge;
    ge.key = 0;
    ge.v = "junk";
    string source="junk";
    for (std::map<string,int>::iterator itr1 = graph11.Dict.begin(); itr1 != graph11.Dict.end(); itr1++)
    {
        string vname = itr1->first;
        graph11.Dijkstra(vname);
        for (int i = 0; i < graph11.CountofVerices; i++)
        {
            if ((graph11.GraphEdgeArray[i].key != 100000) &&(graph11.GraphEdgeArray[i].key > ge.key))
            {
                source = itr1->first;
                ge.key = graph11.GraphEdgeArray[i].key;
                ge.v = graph11.GraphEdgeArray[i].v;
            }
        }
        graph11.InitializeArray();
    }
    graph11.InitializeArray();
    graph11.Dijkstra(source);
    cout << "Longest path between any two distinct vertices is " << endl;
    int findIndex = graph11.FindIndex(ge.v, graph11.CountofVerices);
    stringstream s;
    s.str("");
    while(graph11.GraphEdgeArray[findIndex].v.compare("junk") != 0)
    {
        s << graph11.GraphEdgeArray[findIndex].v << "---";
        findIndex = graph11.FindIndex(graph11.GraphEdgeArray[findIndex].parent, graph11.CountofVerices);
        if (findIndex == -1)
            break;
    }
    string mystr(s.str());
    reverse(mystr.begin(), mystr.end());
    mystr.erase(0,3);
    cout << endl << mystr << endl;
    graph11.ColorDotFile("t11.dot");
      cout<<"Check dot file for the path"<<endl;
    cout << endl << endl << "*****Testcase11 End*****" << endl << endl;
}


void Case12()
{
    cout << endl << endl << "*****Testcase12 Start*****" << endl << endl;
    Graph graph12;
    graph12.Directed = 0;
    graph12.AddVertex("s");
    graph12.AddVertex("t");
    graph12.AddVertex("x");
    graph12.AddVertex("y");
    graph12.AddVertex("z");
    graph12.AddEdge("s", "t",10);
    graph12.AddEdge("t", "s",10);
    graph12.AddEdge("s","y",5);
    graph12.AddEdge("y","s",5);
    graph12.AddEdge("s","z",7);
    graph12.AddEdge("z","s",7);
    graph12.AddEdge("t","x",1);
    graph12.AddEdge("x","t",1);
    graph12.AddEdge("t","y",2);
    graph12.AddEdge("y","t",2);
    graph12.AddEdge("y","x",9);
    graph12.AddEdge("x","y",9);
    graph12.AddEdge("y","z",2);
    graph12.AddEdge("z","y",2);
    graph12.AddEdge("z","x",4);
    graph12.AddEdge("x","z",4);
    graph12.InitializeArray();
    GraphEdge_v ge;
    ge.key = 0;
    ge.v = "junk";
    string src = "junk";
    for (std::map<string,int>::iterator it = graph12.Dict.begin(); it != graph12.Dict.end(); it++)
    {
        string vname = it->first;
        graph12.Dijkstra(vname);
        for (int i = 0; i < graph12.CountofVerices; i++)
        {
            if ((graph12.GraphEdgeArray[i].key != 100000) && (graph12.GraphEdgeArray[i].key > ge.key))
            {
                src = it->first;
                ge.key = graph12.GraphEdgeArray[i].key;
                ge.v = graph12.GraphEdgeArray[i].v;
            }
        }
        graph12.InitializeArray();
    }
    graph12.InitializeArray();
    graph12.Dijkstra(src);
    cout << "Longest  path between two Distinct vertices is " << endl;
    int fIndex = graph12.FindIndex(ge.v, graph12.CountofVerices);
    stringstream s;
    s.str("");
    while(graph12.GraphEdgeArray[fIndex].v.compare("junk") != 0)
    {
        s << graph12.GraphEdgeArray[fIndex].v << "---";
        fIndex = graph12.FindIndex(graph12.GraphEdgeArray[fIndex].parent, graph12.CountofVerices);
        if (fIndex == -1)
            break;
    }
    string str3(s.str());
    reverse(str3.begin(), str3.end());
    str3.erase(0,3);
    cout << endl << str3 << endl;
    graph12.ColorDotFile("t12.dot");
    cout<<"Check dot file for the path"<<endl;
    
    cout << endl << endl << "*****End of Testcase12 Execution*****" << endl << endl;
}

int main(int argc, const char * argv[]) {
    
    Case1();
    Case2();
    Case3();
    Case4();
    Case5();
    Case6();
    Case7();
    Case8();
    Case9();
    Case10();
    Case11();
   Case12();
    
    
    
    return 0;
}


