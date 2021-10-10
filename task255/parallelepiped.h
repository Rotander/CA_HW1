#ifndef __parallelepiped__
#define __parallelepiped__

//------------------------------------------------------------------------------
// parallelepiped.h - содержит описание параллелепипеда и его интерфейса
//------------------------------------------------------------------------------

#include <fstream>

using namespace std;

# include "rnd.h"
#include "shape.h"

// параллелепипед
struct parallelepiped : shape {
    int a, b, c;
};

// Ввод параметров параллелепипеда из файла
void In(parallelepiped &p, ifstream &ifst);

// Случайный ввод параметров параллелепипеда
void InRnd(parallelepiped &p);

// Вывод параметров параллелепипеда в форматируемый поток
void Out(parallelepiped &p, ofstream &ofst);

// Вычисление объёма параллелепипеда
double Volume(parallelepiped &p);

#endif //__parallelepiped__
