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
#include <algorithm>

#include "Edge.h"
#include "Queue.hpp"
#include "MSTree.hpp"

using namespace std;

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
    //int length_of_array;
    //int mst_weight;
    ListElement *element;
    ListElement **list_array_dir;
    ListElement **list_array_undir;
    
public:
    List(string filename);
    List(int v, int e);
    ~List();
    void randomList(int num_of_vertex);
    void printList();
    void dijkstry(int start_vertex);
    void prim();
    bool findVertex(int vertex_to_find);
};

#endif /* List_hpp */
