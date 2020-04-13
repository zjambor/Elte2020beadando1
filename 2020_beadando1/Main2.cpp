//*** Solution with std::vector
#include "Func2.h"

stringstream s2;

void Nyomtat2(v_matrix b, std::string X, int i, int j) {
    if (i == 0 || j == 0)
        return;
    else
    {
        if (b[i][j] == tuple_int(i - 1, j - 1))
        {
            Nyomtat2(b, X, i - 1, j - 1);
            s2 << X[i];
        }
        else
        {
            if (b[i][j] == tuple_int(i - 1, j))
            {
                Nyomtat2(b, X, i - 1, j);
            }
            else
            {
                Nyomtat2(b, X, i, j - 1);
            }
        }
    }
}

void main2()
{
    std::string inputfile = "input.txt";
    std::ifstream ifile(inputfile.c_str());

    std::string outputfile = "output-vect.txt";
    std::ofstream ofile(outputfile.c_str(), std::ios::out);

    std::vector<std::future<v_matrix>> future_threads;
    v_matrix b;

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
        future_threads.push_back(std::async(std::launch::async, LeghosszabbKozosReszsorozat2, sample, text));        //std::ref(text)
    }
    auto m = static_cast<int>(sample.size()) - 1;
    auto n = static_cast<int>(textlengths.at(0) - 1);
    std::string str;

    for (auto i = 0; i < num; ++i)
    {
        b = future_threads[i].get();
        auto n = static_cast<int>(textlengths.at(i) - 1);
        s2.clear();
        str.clear();
        if (n > 0)
        {
            Nyomtat2(b, sample, m, n);
        }
        s2 >> str;
        ofile << str << endl;
    }

    genericprint(b, m, n);

    ifile.close();
    ofile.close();
}
