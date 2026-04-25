#ifndef LAHENDAJA_H
#define LAHENDAJA_H

#include <stdexcept>
#include "sudokuväli.h"
using namespace std;

template <int N>
bool lahendaRekursiivselt(sudokuväli<N>& sudoku) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (sudoku.väli[i][j] != 0) continue;

            set<int> sobivad = sudoku.reaVeeruKastiÜhisosa(i,j);
            if (sobivad.empty()) return false;

            bool oliMuutus = false;
            for (int x : sobivad) {
                sudoku.väli[i][j] = x;
                if (!lahendaRekursiivselt(sudoku)) {
                    sudoku.väli[i][j] = 0;
                } else {
                    oliMuutus = true;
                    break;
                }
            }
            return oliMuutus;
        }
    }
    return true;
}

template <int N>
void lahendaSudoku(sudokuväli<N>& sudoku) {
    if (!lahendaRekursiivselt(sudoku)) {
        throw runtime_error("sudoku has no solution");
    }
}


#endif