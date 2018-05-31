//
//  List.cpp
//  SDIZO_PROJECT_2
//
//  Created by Szymon Klimczuk on 08.05.2018.
//  Copyright © 2018 Szymon Klimczuk. All rights reserved.
//

#include "List.hpp"

List::List(string filename)
{
    ifstream file;
    file.open(filename.c_str());
    
    if(!file.good())
        cout << "Plik nie zostal otwarty poprawnie !" << endl;
    else
    {
        cout << "Plik zostal poprawnie otwarty" << endl;
        file >> this->edges >> this->vertexes;
        this->list_array_dir = new ListElement*[vertexes];
        this->list_array_undir = new ListElement*[vertexes];
        
        for(int i=0; i<vertexes; i++)
            list_array_dir[i] = NULL;
        
        for(int i=0; i<edges; i++)
        {
            int start_vertex, end_vertex, weight_edge;
            file >> start_vertex >> end_vertex >> weight_edge;
            element = new ListElement;
            element->weight = weight_edge;
            element->vertex = end_vertex;
            element->next = list_array_dir[start_vertex];
            list_array_dir[start_vertex] = element;
        }
        
        file.close();
    }
}


List::List(int v, int e){}

List::~List()
{
    ListElement *temp1, *temp2;
    for(int i = 0; i < vertexes; i++)
    {
        temp1 = list_array_dir[i];
        while(temp1)
        {
            temp2 = temp1;
            temp1 = temp1->next;
            delete temp2;
        }
    }
    delete[] list_array_dir;
}

void List::printList()
{
    for(int i=0; i<vertexes; i++)
    {
        cout << i << " -> ";
        element = list_array_dir[i];
        while (element)
        {
            cout << setw(4) << element->vertex << "(" << element -> weight << ")";
            element = element->next;
        }
        cout << endl;
    }
}

void List::dijkstry(int start_vertex)
{
    int *cost_array = new int[vertexes];
    int *prev_array = new int[vertexes];
    int *stack_array = new int[vertexes];
    int sptr = 0;
    bool *QS_array = new bool[vertexes];
    ListElement *temp;
    
    int u, j;
    
    for(int i=0; i<vertexes; i++)
    {
        cost_array[i] = 1000000;
        prev_array[i] = -1;
        QS_array[i] = false;
    }
   
    cost_array[start_vertex] = 0;
    
    for(int i=0; i<vertexes; i++)
    {
        for(u=0; QS_array[u]; u++);
        for(j=u++; j<vertexes; j++)
            if(!QS_array[j] && (cost_array[j] < cost_array[u]))
                u = j;
        
        QS_array[u] = true;
        
        for(temp = list_array_dir[u]; temp; temp=temp->next)
            if(!QS_array[temp->vertex] && (cost_array[temp->vertex] > cost_array[u] + temp->weight))
            {
                cost_array[temp->vertex] = cost_array[u] + temp->weight;
                prev_array[temp->vertex] = u;
            }
    }
    
    //wyswietlanie wynikow
    for(int i=0; i<vertexes;i++)
    {
        cout << i << " : ";
        
        for(int j = i; j > -1; j=prev_array[j])
            stack_array[sptr++] = j;
        
        while(sptr)
            cout << stack_array[--sptr] << " ";
        
        cout << "$(" << cost_array[i] << ")" << endl;
    }
    
    delete[] prev_array;
    delete[] cost_array;
    delete[] QS_array;
    delete[] stack_array;
}

void List::kruskal()
{
    vector<Edge> edges_vec;
    for(int i=0; i<vertexes; i++)
    {
        auto temp_element = list_array_dir[i];
        while(temp_element)
        {
            Edge e;
            e.v1= i;
            e.v2 = temp_element->vertex;
            e.weight = temp_element-> weight;
            edges_vec.push_back(e);
            temp_element = temp_element->next;
        }
    }
    
    //sort(edges_vec.begin(), edges_vec.end());
    
    for(int i=0;i<edges_vec.size();i++)
        cout << edges_vec[i].v1 << " " << edges_vec[i].v2 << " " << edges_vec[i].weight << endl;
    
}

bool List::findVertex(int vertex_to_find)
{
    for(int i=0; i<vertexes; i++)
    {
        auto temp_element = list_array_dir[i];
        while(temp_element)
        {
            if(temp_element->vertex == vertex_to_find)
                return true;
            temp_element = temp_element->next;
        }
    }
    return false;
}
