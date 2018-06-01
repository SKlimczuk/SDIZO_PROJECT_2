//
//  MSTree.hpp
//  SDIZO_PROJECT_2
//
//  Created by Szymon Klimczuk on 01.06.2018.
//  Copyright © 2018 Szymon Klimczuk. All rights reserved.
//

#ifndef MSTree_hpp
#define MSTree_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>

#include "Edge.h"

using namespace std;

struct Node
{
    Node *next;
    int vertex;
    int weight;
};

class MSTree
{
private:
    Node **graph;
    int length;
    int weight;
public:
    MSTree(int num_of_vertexes);
    ~MSTree();
    void addEdge(Edge e);
    Node *getGraph(int position);
    void printMST();
};

#endif /* MSTree_hpp */
