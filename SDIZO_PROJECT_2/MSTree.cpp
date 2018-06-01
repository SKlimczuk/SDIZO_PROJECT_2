//
//  MSTree.cpp
//  SDIZO_PROJECT_2
//
//  Created by Szymon Klimczuk on 01.06.2018.
//  Copyright © 2018 Szymon Klimczuk. All rights reserved.
//

#include "MSTree.hpp"

MSTree::MSTree(int num_of_vertexes)
{
    graph = new Node*[num_of_vertexes];
    for(int i = 0; i < num_of_vertexes; i++)
        graph[i] = NULL;
    this->length = num_of_vertexes - 1;
    this->weight = 0;
}

MSTree::~MSTree()
{
    Node *p,*r;
    for(int i = 0; i <= length; i++)
    {
        p = graph[i];
        while(p)
        {
            r = p;
            p = p->next;
            delete r;
        }
    }
    
    delete [] graph;
}

void MSTree::addEdge(Edge e)
{
    Node *p;
    
    weight += e.weight;
    p = new Node;
    p->vertex = e.v2;
    p->weight = e.weight;
    p->next = graph[e.v1];
    graph[e.v1] = p;
    
    p = new Node;
    p->vertex = e.v1;
    p->weight = e.weight;
    p->next = graph[e.v2];
    graph[e.v2] = p;
}

Node *MSTree::getGraph(int num_of_vertexes)
{
    return graph[num_of_vertexes];
}

void MSTree::printMST()
{
    Node *p;
    for(int i = 0; i <= length; i++)
    {
        cout << i << " -> ";
        for(p = graph[i]; p; p = p->next)
            cout << setw(4) << p->vertex << "(" << p->weight << ")";
        cout << endl;
    }
    cout << "minimalne drzewo rozpinające $(" << weight << ")" << endl;
}
