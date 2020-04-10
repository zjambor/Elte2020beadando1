//*** Solution with std::vector
#include "Func2.h"

v_matrix LeghosszabbKozosReszsorozat2(std::string X, std::string Y)
{
    auto m = X.size();
    auto n = Y.size();
    
    std::vector<int> v(n);
    std::vector<std::vector<int>> c(m, v);

    vec _vec(n);
    v_matrix b(m, _vec);

    try
    {
        for (auto i = 0; i < m; ++i)
        {
            c.at(0).at(i) = 0;
        }
    }
    catch (const std::exception& e)
    {
        return b;
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

    return b;
}
