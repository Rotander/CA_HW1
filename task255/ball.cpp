//------------------------------------------------------------------------------
// ball.cpp - содержит функции обработки шара
//------------------------------------------------------------------------------
#define M_PI 3.14159265358979323846

#include "ball.h"
#include <iostream>

//------------------------------------------------------------------------------
// Ввод параметров шара из потока
void In(ball &b, ifstream &ifst) {
    ifst >> b.r;
}

// Случайный ввод параметров шара
void InRnd(ball &b) {
    b.r = Random();
}

//------------------------------------------------------------------------------
// Вывод параметров шара в поток
void Out(ball &b, ofstream &ofst) {
    ofst << "It is Ball: r = "
         << b.r << ". Volume = " << Volume(b) << "\n";
}

//------------------------------------------------------------------------------
// Вычисление объёма шара
double Volume(ball &b) {
    return double(4.0 / 3 * M_PI * b.r * b.r);
}