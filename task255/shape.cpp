//------------------------------------------------------------------------------
// shape.cpp - содержит процедуры связанные с обработкой обобщенной фигуры
// и создания произвольной фигуры
//------------------------------------------------------------------------------

#include <iostream>
#include "tetrahedron.h"
#include "parallelepiped.h"
#include "ball.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенной фигуры из файла
shape *In(ifstream &ifst) {
    int k;
    ifst >> k;
    ball *bp;
    parallelepiped *pp;
    tetrahedron *tp;
    switch (k) {
        case 1:
            bp = new ball;
            bp->k = shape::BALL;
            ifst >> bp->density;
            In(*bp, ifst);
            return bp;
        case 2:
            pp = new parallelepiped;
            pp->k = shape::PARALLELEPIPED;
            ifst >> pp->density;
            In(*pp, ifst);
            return pp;
        case 3:
            tp = new tetrahedron;
            tp->k = shape::TETRAHEDRON;
            ifst >> tp->density;
            In(*tp, ifst);
            return tp;
        default:
            return nullptr;
    }
}

// Случайный ввод обобщенной фигуры
shape *InRnd() {
    auto k = rand() % 2 + 1;
    ball *bp;
    parallelepiped *pp;
    tetrahedron *tp;
    switch (k) {
        case 1:
            bp = new ball;
            bp->k = shape::BALL;
            bp->density = Random();
            InRnd(*bp);
            return bp;
        case 2:
            pp = new parallelepiped;
            pp->k = shape::PARALLELEPIPED;
            pp->density = Random();
            InRnd(*pp);
            return pp;
        case 3:
            tp = new tetrahedron;tp->k = shape::TETRAHEDRON;
            tp->density = Random();
            InRnd(*tp);
            return tp;
        default:
            return nullptr;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров текущей фигуры в поток
void Out(shape &s, ofstream &ofst) {
    switch (s.k) {
        case shape::BALL:
            Out(*((ball *) &s), ofst);
            break;
        case shape::PARALLELEPIPED:
            Out(*((parallelepiped *) &s), ofst);
            break;
        case shape::TETRAHEDRON:
            Out(*((tetrahedron *) &s), ofst);
            break;
        default:
            ofst << "Incorrect figure!" << endl;
    }
}

//------------------------------------------------------------------------------
// Вычисление объёма фигуры
double Volume(shape &s) {
    switch (s.k) {
        case shape::BALL:
            return Volume(*reinterpret_cast<ball *>(&s));
        case shape::PARALLELEPIPED:
            return Volume(*reinterpret_cast<parallelepiped *>(&s));
        case shape::TETRAHEDRON:
            return Volume(*reinterpret_cast<tetrahedron *>(&s));
        default:
            return 0.0;
    }
}

//------------------------------------------------------------------------------
// Удаление обобщенной фигуры
void DeleteShape(shape *s) {
    switch (s->k) {
        case shape::BALL:
            delete (ball *) s;
            break;
        case shape::PARALLELEPIPED:
            delete (parallelepiped *) s;
            break;
        case shape::TETRAHEDRON:
            delete (tetrahedron *) s;
            break;
        default:
            break;
    }
}
