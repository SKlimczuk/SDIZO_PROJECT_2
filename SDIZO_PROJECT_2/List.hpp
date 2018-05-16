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

using namespace std;

struct ListElement
{
    ListElement *next;
    int vertex;
};

class List
{
private:
    int vertexes;
    int edges;
    ListElement *element;
    ListElement **list_array;
    
public:
    List(string filename);
    List(int v, int e);
    ~List();
    void printList();
};

#endif /* List_hpp */
