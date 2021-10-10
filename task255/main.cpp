//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию, 
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

#include "container.h"

void errMessage1() {
    cout << "incorrect command line!\n"
            "  Waited:\n"
            "     command -f infile outfile\n"
            "  Or:\n"
            "     command -n number outfile\n";
}

void errMessage2() {
    cout << "incorrect qualifier value!\n"
            "  Waited:\n"
            "     command -f infile outfile\n"
            "  Or:\n"
            "     command -n number outfile\n";
}

//------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
    if (argc != 5) {
        errMessage1();
        return 1;
    }
    cout << "Start" << '\n';

    container c;
    Init(c);

    if (!strcmp(argv[2], "-f")) {
        ifstream ifst(argv[3]);
        In(c, ifst);
    } else if (!strcmp(argv[2], "-n")) {
        auto size = atoi(argv[3]);
        if ((size < 1) || (size > 10000)) {
            cout << "incorrect number of figures = "
                 << size
                 << ". Set 0 < number <= 10000\n";
            return 3;
        }
        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(0)));
        // Заполнение контейнера генератором случайных чисел
        InRnd(c, size);
    } else {
        errMessage2();
        return 2;
    }
    // Вывод содержимого контейнера в файл
    ofstream ofst(argv[4]);
    ofst << "Filled container:\n";
    Out(c, ofst);
    ofst << "Filtered container:\n";
    VolumeFilter(c);
    Out(c, ofst);

    Clear(c);
    cout << "Stop" << endl;
    return 0;
}
