//*** Solution with arrays and pointers
#include "Func.h"
#include "Func2.h"

stringstream s;

void Nyomtat(matrix b, std::string X, int i, int j) {        
    if (i == 0 || j == 0)
        return;
    else
    {
        if (b[i][j] == tuple_int(i - 1, j - 1))
        {
            Nyomtat(b, X, i - 1, j - 1);
            s << X[i];
        }
        else
        {
            if (b[i][j] == tuple_int(i - 1, j))
            {
                Nyomtat(b, X, i - 1, j);
            }
            else
            {
                Nyomtat(b, X, i, j - 1);
            }
        }
    }
}

int main()
{
    std::string inputfile = "D:\\input.txt";
    std::ifstream ifile(inputfile.c_str());

    std::string outputfile = "D:\\output.txt";
    std::ofstream ofile(outputfile.c_str(), std::ios::out);
    
    std::vector<std::future<matrix>> future_threads;
    tuple_int** b;

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
        future_threads.push_back(std::async(std::launch::async, LeghosszabbKozosReszsorozat, sample, text));        //std::ref(text)
    }
    auto m = static_cast<int>(sample.size()) - 1;
    std::string str;

    for (auto i = 0; i < num; ++i)
    {
        b = future_threads[i].get();
        auto n = static_cast<int>(textlengths.at(i) - 1);
        s.clear();
        Nyomtat(b, sample, m, n);
        s >> str;
        ofile << str << endl;
    }

    std::cout << endl;
    std::cout << "1. szakasz befejezodott." << endl;
    ifile.close();
    ofile.close();

    main2();
    std::cout << endl;
    std::cout << "2. szakasz befejezodott." << endl;
    std::cout << "A program futasa befejezodott." << endl;
}
