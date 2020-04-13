//*** Solution with arrays and pointers
#include "Func.h"

matrix LeghosszabbKozosReszsorozat(std::string X, std::string Y)
{
    auto m = X.size();
    auto n = Y.size();

    auto** c = new int* [m];
    for (int i = 0; i < m; ++i) {
        c[i] = new int[n];
    }

    auto** b = new tuple_int * [m];
    for (int i = 0; i < m; ++i) {
        b[i] = new tuple_int[n];
    }

    for (auto i = 0; i < m; ++i)
    {
        c[i][0] = 0;
    }
    for (auto j = 0; j < n; ++j)
    {
        c[0][j] = 0;
    }

    for (auto i = 1; i < m; ++i)
    {
        for (auto j = 1; j < n; ++j)
        {
            if (X[i] == Y[j])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = std::make_tuple(i - 1, j - 1);
            }
            else
            {
                if (c[i - 1][j] >= c[i][j - 1])
                {
                    c[i][j] = c[i - 1][j];
                    b[i][j] = std::make_tuple(i - 1, j);
                }
                else
                {
                    c[i][j] = c[i][j - 1];
                    b[i][j] = std::make_tuple(i, j - 1);
                }
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        delete[] c[i];
    }

    delete[] c;

    return b;
}
