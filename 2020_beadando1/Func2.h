//*** Solution with std::vector
#ifndef FUNC2_H
#define FUNC2_H

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
typedef std::vector<tuple_int> vec;
typedef std::vector<vec> v_matrix;

v_matrix LeghosszabbKozosReszsorozat2(std::string X, std::string Y);

void main2();

#endif /* FUNC2_H */