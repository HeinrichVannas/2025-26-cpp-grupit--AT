#ifndef SUDOKUVÄLI_H
#define SUDOKUVÄLI_H
#include <iostream>
#include <math.h>
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

    bool onReas(int rida, int number)
    {
        for (int i = 0; i < N; i++)
        {
            if (väli[rida][i] == number)
            {
                return true;
            }
        }
        return false;
    }

    bool onVeerus(int veerg, int number)
    {
        for (int i = 0; i < N; i++)
        {
            if (väli[i][veerg] == number)
            {
                return true;
            }
        }
        return false;
    }

    bool onKastis(int rida, int veerg, int number)
    {
        int reaJagatav = (sqrt(N) != (int)sqrt(N)) ? sqrt(N) + 1 : sqrt(N);
        int veeruJagatav = sqrt(N);

        int kastirida = (int)(rida / reaJagatav) * reaJagatav;
        int kastiveerg = (int)(veerg / veeruJagatav) * veeruJagatav;
        
        for (int i = kastirida; i < kastirida + reaJagatav && i < N; i++)
        {
            for (int j = kastiveerg; j < kastiveerg + veeruJagatav && j < N; j++)
            {
                if (väli[i][j] == number)
                {
                    return true;
                }
            }
        }
        return false;
    }
};


#endif // SUDOKUVÄLI_H