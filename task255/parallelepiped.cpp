#include <iostream>
#include "parallelepiped.h"

//------------------------------------------------------------------------------
// Ввод параметров параллелепипеда из файла
void In(parallelepiped &p, ifstream &ifst) {
    ifst >> p.a >> p.b >> p.c;
}

// Случайный ввод параметров параллелепипеда
void InRnd(parallelepiped &p) {
    p.a = Random();
    p.b = Random();
    p.c = Random();
}

//------------------------------------------------------------------------------
// Вывод параметров параллелепипеда в форматируемый поток
void Out(parallelepiped &p, ofstream &ofst) {
    ofst << "It is Parallelepiped: a = " << p.a << ", b = " << p.b << ", c = " << p.c
         << ". Volume = " << Volume(p) << "\n";
}

//------------------------------------------------------------------------------
// Вычисление объёма параллелепипеда
double Volume(parallelepiped &p) {
    return (p.a * p.b * p.c);
}
