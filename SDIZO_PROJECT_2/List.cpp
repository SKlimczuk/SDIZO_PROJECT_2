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
        this->list_array = new ListElement*[vertexes];
        
        for(int i=0; i<vertexes; i++)
            list_array[i] = NULL;
        
        for(int i=0; i<edges; i++)
        {
            int start_vertex, end_vertex, weight_edge;
            file >> start_vertex >> end_vertex >> weight_edge;
            element = new ListElement;
            element->weight = weight_edge;
            element->vertex = end_vertex;
            element->next = list_array[start_vertex];
            list_array[start_vertex] = element;
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
        temp1 = list_array[i];
        while(temp1)
        {
            temp2 = temp1;
            temp1 = temp1->next;
            delete temp2;
        }
    }
    delete[] list_array;
}

void List::printList()
{
    for(int i=0; i<vertexes; i++)
    {
        cout << i << " -> ";
        element = list_array[i];
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
        
        for(temp = list_array[u]; temp; temp=temp->next)
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

bool List::findVertex(int vertex_to_find)
{
    for(int i=0; i<vertexes; i++)
    {
        auto temp_element = list_array[i];
        while(temp_element)
        {
            if(temp_element->vertex == vertex_to_find)
                return true;
            temp_element = temp_element->next;
        }
    }
    return false;
}
