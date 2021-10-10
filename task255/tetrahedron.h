#ifndef __tetrahedron__
#define __tetrahedron__

//------------------------------------------------------------------------------
// tetrahedron.h - содержит описание тетраэдра
//------------------------------------------------------------------------------

#include <fstream>

using namespace std;

# include "rnd.h"
#include "shape.h"

//------------------------------------------------------------------------------
// тетраэдр
struct tetrahedron : shape {
    int a; // стороны
};

// Ввод параметров тетраэдра из файла
void In(tetrahedron &t, ifstream &ifst);

// Случайный ввод параметров тетраэдра
void InRnd(tetrahedron &t);

// Вывод параметров тетраэдра в форматируемый поток
void Out(tetrahedron &t, ofstream &ofst);

// Вычисление объёма тетраэдра
double Volume(tetrahedron &t);

#endif //__tetrahedron__
