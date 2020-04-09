//*** Solution with arrays and pointers

#ifndef FUNC_H
#define FUNC_H

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

typedef std::tuple<int, int> tuple_int;
typedef tuple_int** matrix;

matrix LeghosszabbKozosReszsorozat(std::string X, std::string Y);

#endif /* FUNC_H */