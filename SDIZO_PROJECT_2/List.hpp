//
//  List.hpp
//  SDIZO_PROJECT_2
//
//  Created by Szymon Klimczuk on 08.05.2018.
//  Copyright © 2018 Szymon Klimczuk. All rights reserved.
//

#ifndef List_hpp
#define List_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

#define kruskal_edge pair<int,int>
#define kruskal_pair pair<int, kruskal_edge>

struct Edge
{
    int v1,v2,weight;
};

struct ListElement
{
    ListElement *next;
    int vertex;
    int weight;
};

class List
{
private:
    int vertexes;
    int edges;
    ListElement *element;
    ListElement **list_array_dir;
    ListElement **list_array_undir;
    
public:
    List(string filename);
    List(int v, int e);
    ~List();
    void printList();
    void dijkstry(int start_vertex);
    void kruskal();
    bool findVertex(int vertex_to_find);
};

#endif /* List_hpp */
