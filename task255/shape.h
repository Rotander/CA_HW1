#ifndef __shape__
#define __shape__

//------------------------------------------------------------------------------
// shape.h - содержит описание обобщающей геометрической фигуры,
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся фигуры
struct shape {
    // значения ключей для каждой из фигур
    enum key {BALL, PARALLELEPIPED, TETRAHEDRON};
    key k; // ключ
    double density;
};

// Ввод обобщенной фигуры
shape *In(ifstream &ifdt);

// Случайный ввод обобщенной фигуры
shape *InRnd();

// Вывод обобщенной фигуры
void Out(shape &s, ofstream &ofst);

// Вычисление периметра обобщенной фигуры
double Volume(shape &s);

// Удаление обобщенной фигуры
void DeleteShape(shape *s);

#endif