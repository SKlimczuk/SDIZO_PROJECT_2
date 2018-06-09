//
//  Queue.hpp
//  SDIZO_PROJECT_2
//
//  Created by Szymon Klimczuk on 01.06.2018.
//  Copyright © 2018 Szymon Klimczuk. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include "Edge.h"

class Queue
{
private:
    Edge *heap;
    int hpos; 
public:
    Queue(int num_of_vertexes);
    ~Queue();
    Edge front();
    void push(Edge e);
    void pop();
};

#endif /* Queue_hpp */
