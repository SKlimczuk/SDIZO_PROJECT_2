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

using namespace std;

class Matrix
{
private:
    int vertexes;
    int edges;
    int weight;
    int ** matrix_array;
    int *weight_array;
    
public:
    Matrix(string filename);
    Matrix(int v, int e);
    ~Matrix();
    void printMatrix();
    void dijkstry(int start_vertex);
};

#endif /* Matrix_hpp */
