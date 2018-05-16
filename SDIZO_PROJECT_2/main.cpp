//
//  main.cpp
//  SDIZO_PROJECT_2
//
//  Created by Szymon Klimczuk on 08.05.2018.
//  Copyright © 2018 Szymon Klimczuk. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>

#include "Matrix.hpp"
#include "List.hpp"


int main(int argc, const char * argv[]) {
    
    srand(time(NULL));
    
    Matrix *matrix;
    List *list;
    
    int menu;
    bool menu_cond = true;
    string filename;
    
    do
    {
        cout << "---- MENU ----" << endl;
        cout << "1 -> LISTA\n2 -> MACIERZ INCYDENCJI\n0 -> WYJSCIE" << endl;
        cout << "WYBOR : ";
        cin >> menu;
        switch (menu) {
            case 1:
                cout << "---- LISTA ----" << endl;
                cout << "1 -> wczytaj z pliku\n2 -> generuj losowo\n3 -> wyswietl" << endl;
                cout << "WYBOR : ";
                cin >> menu;
                switch (menu) {
                    case 1:
                        //wczytywanie danych z pliku
                        cout << "podaj nazwe pliku : ";
                        cin >> filename;
                        filename += ".txt";
                        list = new List(filename);
                        break;
                    case 2:
                        
                        break;
                    case 3:
                        //wyswietlanie listy sąsiedztwa
                        list->printList();
                        break;
                        
                    default:
                        break;
                }
                break;
            case 2:
                cout << "---- MACIERZ INCYDECJI ----" << endl;
                cout << "1 -> wczytaj z pliku\n2 -> generuj losowo\n3 -> wyswietl" << endl;
                cout << "WYBOR : ";
                cin >> menu;
                switch (menu) {
                    case 1:
                        //wczytywanie z pliku
                        cout << "podaj nazwe pliku : ";
                        cin >> filename;
                        filename += ".txt";
                        matrix = new Matrix(filename);
                        break;
                    case 2:
                        //generowanie losowych danych
                        break;
                    case 3:
                        //wyswietlanie macierzy incydencji
                        matrix->printMatrix();
                        break;
                    default:
                        break;
                }
                break;
            case 0:
                cout << "KONIEC" << endl;
                menu_cond = false;
                break;
            default:
                break;
        }
    }while (menu_cond);
    
    return 0;
}


/*
-------WYMAGANIA------------------------------------------------------------
 1. REPREZENTACJA -> macierz incydencji, lista następników/poprzedników
 2. ALGORYTMY -> prim/kruskal, belman/dijkstry
 ---------------
 
*/
