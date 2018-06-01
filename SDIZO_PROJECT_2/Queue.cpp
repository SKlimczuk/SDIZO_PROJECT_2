//
//  Queue.cpp
//  SDIZO_PROJECT_2
//
//  Created by Szymon Klimczuk on 01.06.2018.
//  Copyright © 2018 Szymon Klimczuk. All rights reserved.
//

#include "Queue.hpp"

Queue::Queue(int num_of_vertexes)
{
    heap = new Edge[num_of_vertexes];
    hpos = 0;
}

Queue::~Queue()
{
    delete []heap;
}

Edge Queue::front()
{
    return heap[0];
}

void Queue::push(Edge e)
{
    int i,j;
    i = hpos++;
    j = (i - 1) >> 1;
    
    while(i && (heap[j].weight > e.weight))
    {
        heap[i] = heap[j];
        i = j;
        j = (i - 1) >> 1;
    }
    heap[i] = e;
}

void Queue::pop()
{
    int i,j;
    Edge e;
    if(hpos)
    {
        e = heap[--hpos];
        i = 0;
        j = 1;
        while(j < hpos)
        {
            if((j + 1 < hpos) && (heap[j + 1].weight < heap[j].weight)) j++;
            if(e.weight <= heap[j].weight) break;
            heap[i] = heap[j];
            i = j;
            j = (j << 1) + 1;
        }
        heap[i] = e;
    }
}
