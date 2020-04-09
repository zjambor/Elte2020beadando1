#include <iostream>
#include <fstream>
#include <future>
#include <thread>
#include <vector>
#include <sstream>
#include <string>
#include <tuple>
#include <array>

using namespace std;

typedef std::vector<std::tuple<int, int>> vec;
//typedef std::vector<vec> matrix;
typedef std::tuple<int, int>** matrix;

void kiir(std::vector<std::vector<int>> matrix)
{
    for (auto it1 = matrix.begin(); it1 != matrix.end(); ++it1)
    {
        for (auto it2 = (*it1).begin(); it2 != (*it1).end(); ++it2)
        {
            std::cout << *it2 << " ";
        }
        std::cout << endl;
    }
}

void kiir_t(std::vector<std::vector<std::tuple<int, int>>> matrix)
{
    for (auto it1 = matrix.begin(); it1 != matrix.end(); ++it1)
    {
        for (auto it2 = (*it1).begin(); it2 != (*it1).end(); ++it2)
        {
            std::cout << std::get<0>(*it2) << ", " << std::get<1>(*it2) << " ";
        }
        std::cout << endl;
    }
}

void print(int **t, int m, int n)
{
    for (auto i = 0; i < m; ++i) {
        for (auto j = 0; j < n; ++j) {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }
}

void print2(std::tuple<int, int> **t, int m, int n)
{
    for (auto i = 0; i < m; ++i) {
        for (auto j = 0; j < n; ++j) {
            std::cout << "(" << std::get<0>(t[i][j]) << ", " << std::get<1>(t[i][j]) << ") ";
        }
        cout << endl;
    }
}

template<typename T, int, int>
auto genericprint(T t, int m, int n)
{
    for (auto i = 0; i < m; ++i) {
        for (auto j = 0; j < n; ++j) {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }
}

/*
LeghosszabbKözösRészsorozat(X, n, Y, m)
for i=1 to n do
  c[i, 0]=0
for j=0 to m do
  c[0, j]=0

for i=1 to n do
    for j=1 to m do
        if xi=yj
          then
              c[i, j]=c[i-1, j-1]+1
              b[i, j]=(i-1, j-1)
          else
            if c[i-1, j]>=c[i, j-1]
              then
                c[i, j]=c[i-1, j]
                b[i, j]=(i-1, j)
              else
                c[i, j]=c[i, j-1]
                b[i, j]=(i, j-1)

  return c, b
*/

matrix LeghosszabbKozosReszsorozat1(std::string X, std::string Y)
{
    auto m = X.size();
    auto n = Y.size();
    /*std::vector<int> v(n, 0);
    std::vector<std::vector<int>> c(m, v);*/
    
    auto **c = new int *[m];

    for (int i = 0; i < m; ++i) {
        c[i] = new int[n];
    }

    auto **b = new std::tuple<int, int>* [m];

    for (int i = 0; i < m; ++i) {
        b[i] = new std::tuple<int, int> [n];
    }

    /*std::array<int, Y.size()> v;
    std::array<std::array<int, n>, m> c;*/
    //c.resize(m);

    /*vec _vec(m, std::make_tuple(0, 0));
    matrix b(m, _vec);*/
    //matrix b;
    for (auto i = 0; i < m; ++i)
    {
        //c[i].resize(n);
        c[i][0] = 0;
    }
    //cout << "level 1 ok" << endl;
    for (auto j = 0; j < n; ++j)
    {
        c[0][j] = 0;
    }

    for (auto i = 0; i < m; ++i)
    {
        //c[i].resize(n);
        b[i][0] = std::make_tuple(0, 0);
    }
    //cout << "level 1 ok" << endl;
    for (auto j = 0; j < n; ++j)
    {
        b[0][j] = std::make_tuple(0, 0);
    }
    //cout << "level 2 ok" << endl;

    for (auto i = 1; i < m; ++i)
    {
        for (auto j = 1; j < n; ++j)
        {
            //cout << X[i] << " | " << Y[j] << endl;
            if (X[i] == Y[j])
            {
                //cout << "level 3 ok" << endl;
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = std::make_tuple(i - 1, j - 1);
            }
            else
            {
                //cout << "level 3 else" << endl;
                /*kiir(c);
                kiir_t(b);*/
                /*print(c, m, n);
                print2(b, m, n);*/
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

void Nyomtat1(matrix b, std::string X, int i, int j) {
    if (i == 0 || j == 0)
        return;
    else
    {
        if (b[i][j] == std::tuple<int,int> (i - 1, j - 1))
        {
            Nyomtat1(b, X, i - 1, j - 1);
            cout << X[i];
        }
        else
        {
            if (b[i][j] == std::tuple<int, int> (i - 1, j))
            {
                Nyomtat1(b, X, i - 1, j);
            }
            else
            {
                Nyomtat1(b, X, i, j - 1);
            }
        }
    }
}


void main_f()
{
    std::string file = "D:\\input.txt";
    std::ifstream ifile(file.c_str());
    std::vector<std::future<matrix>> future_threads;
    // matrix t_strings;

    std::tuple<int, int>** b;
        /*= new std::tuple<int, int> * [m];

    for (int i = 0; i < m; ++i) {
        b[i] = new std::tuple<int, int>[n];
    }*/

    auto num = 0;
    ifile >> num;
    std::cout << "sorok szama: " << num << std::endl;
    std::string text = "";

    std::getline(ifile, text);
    auto sample = text;
    std::vector<int> textlengths;

    for (auto i = 0; i < num; ++i)
    {
        std::getline(ifile, text);
        std::cout << "beolvasott szoveg: " << text << std::endl;
        textlengths.push_back(static_cast<int>(text.size()));
        future_threads.push_back(std::async(std::launch::async, LeghosszabbKozosReszsorozat1, sample, text));        //std::ref(text)
    }
    auto m = sample.size();
    //auto n = text.size();

    for (auto i = 0; i < num; ++i)
    {        
        b = future_threads[i].get();
        auto n = static_cast<int>(textlengths.at(i) - 1);
        Nyomtat1(b, sample, m-1, n);
        std::cout << endl;
    }

   /* auto iter = t_strings.begin();
    for (auto iter = t_strings.begin(); iter != t_strings.end(); ++iter)
    {
        std::cout << *iter << std::endl;
    }*/

    /*
    auto m = 0, n = 0;
    auto x = 0, y = 0;

    cout << "Oszlopok szama: ";
    cin >> m;
    cout << "Sorok szama: ";
    cin >> n;

    std::vector<std::vector<int>> matrix;
    matrix.resize(m);
    for (auto i = 0; i < m; ++i)
    {
        matrix[i].resize(n);
        for (auto iter = matrix[i].begin(); iter != matrix[i].end(); ++iter)
        {
            (matrix[i])[*iter] = 0;
        }
    }

    kiir(matrix);

    cout << "Koordinatak:\nx=";
    cin >> x;
    cout << "y=";
    cin >> y;

    matrix[x - 1][y - 1] = 1;
    kiir(matrix);
    */
    
    std::cout << endl;
    std::cout << "A program futasa befejezodott." << endl;
    ifile.close();
}
