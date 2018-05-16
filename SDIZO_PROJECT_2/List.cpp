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
    
}

void List::printList()
{
    for(int i=0; i<vertexes; i++)
    {
        cout << i << " -> ";
        element = list_array[i];
        while (element)
        {
            cout << setw(4) << element->vertex;
            element = element->next;
        }
        cout << endl;
    }
}
