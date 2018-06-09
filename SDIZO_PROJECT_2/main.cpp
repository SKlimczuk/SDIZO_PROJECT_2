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
#include <stdlib.h>
#include <time.h>

#include "Matrix.hpp"
#include "List.hpp"


int main(int argc, const char * argv[]) {
    
    srand(time(NULL));
    
    Matrix *matrix;
    List *list;
    
    int menu;
    bool menu_cond_1 = true;
    bool menu_cond_2 = true;
    string filename;
    
    string menu_1 = "1 -> wczytaj z pliku\n2 -> generuj losowo\n3 -> wyswietl\n4 -> algorytm Dijkstry\n5 -> algorytm Prima\n0 -> powrot";
    
    do
    {
        menu_cond_2 = true;
        cout << "-------- MENU --------" << endl;
        cout << "1 -> LISTA\n2 -> MACIERZ INCYDENCJI\n0 -> WYJSCIE" << endl;
        cout << "WYBOR : ";
        cin >> menu;
        switch (menu) {
            case 1:
                do
                {
                    cout << "-------- LISTA --------" << endl;
                    cout << menu_1 << endl;
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
                            //generowanie losowych danych
                            int num_of_vertex;
                            float density;
                            cout << "Podaj ilosc wiercholkow: ";
                            cin >> num_of_vertex;
                            cout << "Podaj stopien gestosci grafu (0,1> : ";
                            cin >> density;
                            if(density > 0 && density <= 1)
                            {
                                list->fillRandom(num_of_vertex, density);
                            }
                            else
                                cout << "niepoprawny stopien gestosci grafu" << endl;
                             break;
                        case 3:
                            //wyswietlanie listy sąsiedztwa
                            list->printList();
                            break;
                        case 4:
                            //dijkstry
                            int start_vertex;
                            cout << "podaj wierzcholek startowy ";
                            cin >> start_vertex;
                            if(list->findVertex(start_vertex))
                                list->dijkstry(start_vertex);
                            else
                                cout << "wierzcholek nie nalezy do grafu" << endl;
                            break;
                        case 5:
                            //prim
                            list->prim();
                            break;
                        case 0:
                            //powrot
                            cout << "POWROT" << endl;
                            menu_cond_2 = false;
                            break;
                        default:
                            break;
                    }
                }while (menu_cond_2);
                break;
            case 2:
                do
                {
                    cout << "-------- MACIERZ INCYDECJI --------" << endl;
                    cout << menu_1 << endl;
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
                            int num_of_vertex;
                            float density;
                            cout << "Podaj ilosc wiercholkow: ";
                            cin >> num_of_vertex;
                            cout << "Podaj stopien gestosci grafu (0,1> : ";
                            cin >> density;
                            if(density > 0 && density <= 1)
                            {
                                matrix->fillRandom(num_of_vertex, density);
                            }
                            else
                                cout << "niepoprawny stopien gestosci grafu" << endl;
                            break;
                        case 3:
                            //wyswietlanie macierzy incydencji
                            matrix->printMatrix();
                            break;
                        case 4:
                            //dijkstry
                            int start_vertex;
                            cout << "podaj wierzcholek startowy ";
                            cin >> start_vertex;
                            if(matrix->findVertex(start_vertex))
                                matrix->dijkstry(start_vertex);
                            else
                                cout << "wierzcholek nie nalezy do grafu" << endl;
                            break;
                        case 5:
                            //prim
                            matrix->prim();
                            break;
                        case 0:
                            //powrot
                            cout << "POWROT" << endl;
                            menu_cond_2 = false;
                            break;
                        default:
                            break;
                    }
                }while (menu_cond_2);
                break;
            case 0:
                cout << "KONIEC" << endl;
                menu_cond_1 = false;
                break;
            default:
                break;
        }
    }while (menu_cond_1);
    
    return 0;
}
