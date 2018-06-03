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
        this->matrix_array_undir = new int *[edges];
        
        for(int i=0;i<vertexes;i++)
        {
            matrix_array[i] = new int[edges];
            matrix_array_undir[i] = new int[edges];
        }
        
        for(int i=0;i<vertexes;i++)
            for(int k=0;k<edges;k++)
            {
                matrix_array[i][k] = 0;
                matrix_array_undir[i][k] = 0;
            }
            
        
        for(int i=0;i<edges;i++)
        {
            int start_vertex;
            int end_vertex;
            int weight_edge;
            file >> start_vertex >> end_vertex >> weight_edge;
            matrix_array[start_vertex][i] = weight_edge;
            matrix_array[end_vertex][i] = -1;
            
            matrix_array_undir[start_vertex][i] = weight_edge;
            matrix_array_undir[end_vertex][i] = weight_edge;
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
    
    for(int i = 0; i < vertexes; i++)
        delete [] matrix_array_undir[i];
    delete [] matrix_array_undir;
}

void Matrix::fillRandom(int num_of_vertexes, float density)
{
    int num_of_edges = density*(num_of_vertexes*(num_of_vertexes-1));
    cout << "ilosc krawedzi: " << num_of_edges << endl;
    fstream file;
    file.open("random.txt", ios::out | ios::trunc);
    if(file.good())
    {
        file << num_of_edges << " " << num_of_vertexes << endl;
        
        for(int i=0; i<num_of_edges/num_of_vertexes; i++)
            for(int k=0; k<num_of_vertexes; k++)
            {
                int v1 = k;
                int v2 = rand()%num_of_vertexes;
                while(v1 == v2)
                    v2 = rand()%num_of_vertexes;
                int w = rand()%20+1;
                file << v1 << " " << v2 << " " << w << endl;
            }
        
        file.close();
    }
    else
        cout << "blad przy obsludze pliku" << endl;
}

void Matrix::printMatrix()
{
    cout << "----- graf skierowany" << endl;
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
   
    cout << "----- graf nieskierowany" << endl;
    cout << endl;
    
    cout << "    ";
    for(int i=0;i<edges;i++)
        cout << setw(4) << i;
    
    cout << endl;
    
    for(int i=0;i<vertexes;i++)
    {
        cout << setw(4) << i;
        for(int k=0;k<edges;k++)
            cout << setw(4) << matrix_array_undir[i][k];
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
        for(int i=0; i<edges; i++)
            if(matrix_array[u][i] > 0)
                for(int k=0; k<vertexes; k++)
                    if(matrix_array[k][i] == (-1))
                        //teraz krawedz wyglada nastepujaco: (u)->(k) waga(i,k)=matrix_array[u][i]
                        if(!QS_array[k] && (cost_array[k] > cost_array[u] + matrix_array[u][i]))
                        {
                            cost_array[k] = cost_array[u] + matrix_array[u][i];
                            prev_array[k] = u;
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

void Matrix::prim()
{
    Edge edge;
    Queue queue(edges);
    MSTree mst(vertexes,edges);
    MSTree graph(vertexes,edges);
    bool *visited = new bool[vertexes];
    
    for(int i=0; i<vertexes; i++)
        visited[i] = false;
    
    
    for(int i=0; i<edges; i++)
        for(int k=0; k<vertexes; k++)
        {
            if(matrix_array[k][i] > 0)
            {
                edge.v1 = k;
                edge.weight = matrix_array[k][i];
            }
            if(matrix_array[k][i] == (-1))
            {
                edge.v2 = k;
                graph.addMatrixEdge(edge);
            }
        }
    
    int v = 0;
    visited[v] = true;
    
    for(int i=1; i<vertexes; i++)
    {
        for(int j=0; j<edges; j++)
            if(matrix_array_undir[v][j] > 0)
                for(int k=0; k<vertexes; k++)
                    if(matrix_array_undir[k][j] > 0)
                        if(!visited[k])
                        {
                            edge.v1 = v;
                            edge.v2 = k;
                            edge.weight = matrix_array_undir[v][j];
                            queue.push(edge);
                        }
    
        do {
            edge = queue.front();
            queue.pop();
        } while(visited[edge.v2]);
        
        mst.addMatrixEdge(edge);
        visited[edge.v2] = true;
        v = edge.v2;
    }
    
    mst.printMatrixMST();
    
    delete []visited;
}

bool Matrix::findVertex(int vertex_to_find)
{
    for(int i=0;i<vertexes;i++)
        if(vertex_to_find == i)
            return true;
    return false;
    
}
