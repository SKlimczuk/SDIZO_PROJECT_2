//
//  Matrix.hpp
//  SDIZO_PROJECT_2
//
//  Created by Szymon Klimczuk on 08.05.2018.
//  Copyright © 2018 Szymon Klimczuk. All rights reserved.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <chrono>

#include "Edge.h"
#include "Queue.hpp"
#include "MSTree.hpp"

using namespace std;

class Matrix
{
private:
    int vertexes;
    int edges;
    int weight;
    int ** matrix_array;
    int ** matrix_array_undir;
    
public:
    Matrix(string filename);
    Matrix(int v, int e);
    ~Matrix();
    void fillRandom(int num_of_vertexes, float density);
    void printMatrix();
    void dijkstry(int start_vertex);
    void prim();
    bool findVertex(int vertex_to_find);
};

#endif /* Matrix_hpp */
