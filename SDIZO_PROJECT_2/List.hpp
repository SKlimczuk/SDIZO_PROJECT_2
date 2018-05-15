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

struct ListElement
{
    int *next;
    int data;
};

class List
{
private:
    int vertexes;
    int edges;
public:
    List(int v, int e);
};

#endif /* List_hpp */
