#ifndef SUDOKUVÄLI_H
#define SUDOKUVÄLI_H
#include <algorithm>
#include <iostream>
#include <cmath>
#include <set>
using namespace std;

template <int N>
struct sudokuväli
{
    int väli[N][N];


    void täida(int sisend[N][N])
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                väli[i][j] = sisend[i][j];
            }
        }
    }
    
    void väljasta()
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << väli[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    bool onReas(int rida, int veerg, int number)
    {
        for (int i = 0; i < N; i++)
        {
            if (i == veerg) continue;
            if (väli[rida][i] == number)
            {
                return true;
            }
        }
        return false;
    }

    bool onVeerus(int rida, int veerg, int number)
    {
        for (int i = 0; i < N; i++)
        {
            if (i == rida) continue;
            if (väli[i][veerg] == number)
            {
                return true;
            }
        }
        return false;
    }

    bool onKastis(int rida, int veerg, int number)
    {
        int reaJagatav = sqrt(N) != static_cast<int>(sqrt(N)) ? sqrt(N) + 1 : sqrt(N);
        int veeruJagatav = sqrt(N);

        int kastirida = rida / reaJagatav * reaJagatav;
        int kastiveerg = veerg / veeruJagatav * veeruJagatav;
        
        for (int i = kastirida; i < kastirida + reaJagatav && i < N; i++)
        {
            for (int j = kastiveerg; j < kastiveerg + veeruJagatav && j < N; j++)
            {
                if (i == rida && j == veerg) continue;
                if (väli[i][j] == number)
                {
                    return true;
                }
            }
        }
        return false;
    }

    set<int> reaVeeruKastiÜhisosa(int rida, int veerg)
    {
        set<int> set1, set2, set3, set4, setfinal;
        for (int i = 1; i <= N; i++) {
            if (!onReas(rida, veerg, i)) {
                set1.insert(i);
            }
        }
        for (int i = 1; i <= N; i++) {
            if (!onVeerus(rida, veerg, i)) {
                set2.insert(i);
            }
        }
        set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(set3, set3.begin()));
        for (int i = 1; i <= N; i++) {
            if (!onKastis(rida, veerg, i)) {
                set4.insert(i);
            }
        }
        set_intersection(set3.begin(), set3.end(), set4.begin(), set4.end(), inserter(setfinal, setfinal.begin()));
        return setfinal;
    }

    bool kontrolli()
    {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (onReas(i, j, väli[i][j])) return false;
                if (onVeerus(i, j, väli[i][j])) return false;
                if (onKastis(i, j, väli[i][j])) return false;
            }
        }
        return true;
    }
};

#endif // SUDOKUVÄLI_H