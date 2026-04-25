#include "sudokuväli.h"


int main(){

    int sisend[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0 ,0 ,8 ,0 ,0 ,7 ,9}
    };

    sudokuväli<9> väli;
    väli.täida(sisend);
    väli.väljasta();

    cout << väli.onReas(0, 7) << '\n';
    cout << väli.onVeerus(0, 8) << '\n';
    cout << väli.onKastis(4, 6, 8) << '\n';

    int sisend2[6][6] = {
        {1, 0, 0, 0, 0, 0},
        {0, 2, 0, 0, 0, 0},
        {0, 0, 3, 0, 0, 0},
        {0, 0, 0, 4, 0, 0},
        {0, 0, 0, 0, 5, 0},
        {0, 0, 0, 0, 0, 6}
    };

    sudokuväli<6> väli2;
    väli2.täida(sisend2);
    väli2.väljasta();

    cout << väli2.onReas(0, 1) << '\n';
    cout << väli2.onVeerus(0, 2) << '\n';
    cout << väli2.onKastis(4, 3, 4) << '\n';

    return 0;
}