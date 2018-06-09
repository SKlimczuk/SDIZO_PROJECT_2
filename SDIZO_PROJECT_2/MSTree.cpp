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
    graph_list = new Node*[num_of_vertexes];
    for(int i = 0; i < num_of_vertexes; i++)
        graph_list[i] = NULL;
    this->length = num_of_vertexes - 1;
    this->weight = 0;
}

MSTree::MSTree(int num_of_vertexes,int num_of_edges)
{
    this->graph_matrix = new int *[num_of_vertexes];
    
    for(int i=0; i<num_of_vertexes; i++)
        graph_matrix[i] = new int[num_of_edges];
    
    for(int i=0; i<num_of_vertexes; i++)
        for(int k=0; k<num_of_edges; k++)
            graph_matrix[i][k] = 0;
    this->length = num_of_vertexes - 1;
    this->weight = 0;
    this->counter = 0;
}

MSTree::~MSTree()
{
    /*if(getListGraph(0) != nullptr)
    {
        Node *p,*r;
        for(int i = 0; i <= length; i++)
        {
            p = graph_list[i];
            while(p)
            {
                r = p;
                p = p->next;
                delete r;
            }
        }
        delete [] graph_list;
    }
    *//*
    {
        for(int i = 0; i <= length; i++)
            delete [] graph_matrix[i];
        delete [] graph_matrix;
    }*/
}

void MSTree::addListEdge(Edge e)
{
    Node *p;
    
    weight += e.weight;
    p = new Node;
    p->vertex = e.v2;
    p->weight = e.weight;
    p->next = graph_list[e.v1];
    graph_list[e.v1] = p;
    
    p = new Node;
    p->vertex = e.v1;
    p->weight = e.weight;
    p->next = graph_list[e.v2];
    graph_list[e.v2] = p;
}

void MSTree::addMatrixEdge(Edge e)
{
    weight += e.weight;
    
    graph_matrix[e.v1][counter] = e.weight;
    graph_matrix[e.v2][counter] = e.weight;
    
    this->counter++;
}

Node *MSTree::getListGraph(int position)
{
    return graph_list[position];
}

int *MSTree::getMatrixGraph(int position)
{
    return graph_matrix[position];
}

void MSTree::printListMST()
{
    Node *p;
    for(int i = 0; i <= length; i++)
    {
        cout << i << " -> ";
        for(p = graph_list[i]; p; p = p->next)
            cout << setw(4) << p->vertex << "(" << p->weight << ")";
        cout << endl;
    }
    cout << "minimalne drzewo rozpinające $(" << weight << ")" << endl;
}

void MSTree::printMatrixMST()
{
    cout << endl;
    cout << "    ";
    for(int i=0; i<length; i++)
        cout << setw(4) << i;
    
    cout << endl;
    
    for(int i=0; i<=length; i++)
    {
        cout << setw(4) << i;
        for(int k=0; k<length; k++)
            cout << setw(4) << graph_matrix[i][k];
        cout << endl;
    }
    cout << "minimalne drzewo rozpinające $(" << weight << ")" << endl;
}
