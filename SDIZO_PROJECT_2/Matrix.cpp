//
//  Matrix.cpp
//  SDIZO_PROJECT_2
//
//  Created by Szymon Klimczuk on 08.05.2018.
//  Copyright © 2018 Szymon Klimczuk. All rights reserved.
//

#include "Matrix.hpp"

Matrix::Matrix(string filename)
{
    ifstream file;
    file.open(filename.c_str());
    
    if(!file.good())
        cout << "Plik nie zostal otwarty poprawnie !" << endl;
    else
    {
        cout << "Plik zostal otwarty poprawnie !" << endl;
        file >> this->edges >> this->vertexes;
        this->matrix_array = new int *[edges];
        
        for(int i=0;i<vertexes;i++)
            matrix_array[i] = new int[edges];
        
        for(int i=0;i<vertexes;i++)
            for(int k=0;k<edges;k++)
                matrix_array[i][k] = 0;
        
        for(int i=0;i<edges;i++)
        {
            int start_vertex;
            int end_vertex;
            int weight_edge;
            file >> start_vertex >> end_vertex >> weight_edge;
            matrix_array[start_vertex][i] = 1;
            matrix_array[end_vertex][i] = -1;
        }
        file.close();
    }
}

Matrix::Matrix(int v, int e)
{
    this->vertexes = v;
    this->edges = e;
    this->matrix_array = new int *[edges];
    
    for(int i=0;i<vertexes;i++)
        matrix_array[i] = new int[edges];
    
    for(int i=0;i<vertexes;i++)
        for(int k=0;k<edges;k++)
            matrix_array[i][k] = 0;
}

Matrix::~Matrix()
{
    for(int i = 0; i < vertexes; i++)
        delete [] matrix_array[i];
    delete [] matrix_array;
}

void Matrix::printMatrix()
{
    cout << endl;
    
    cout << "    ";
    for(int i=0;i<edges;i++)
        cout << setw(4) << i;
    
    cout << endl;
    
    for(int i=0;i<vertexes;i++)
    {
        cout << setw(4) << i;
        for(int k=0;k<edges;k++)
            cout << setw(4) << matrix_array[i][k];
        cout << endl;
    }
}

void Matrix::dijkstry(int start_vertex)
{
    int *cost_array = new int[vertexes];
    int *prev_array = new int[vertexes];
    int *stack_array = new int[vertexes];
    int sptr = 0;
    bool *QS_array = new bool[vertexes];
    //MatrixElement *temp;
    
    
    
    delete[] prev_array;
    delete[] cost_array;
    delete[] QS_array;
    delete[] stack_array;
}
