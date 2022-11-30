#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

struct matrix{
    int n;
    std::vector <int> values;
    std::vector <int> cols;
    std::vector <int> pointer;
};

int getInt();
void getMatrix(matrix & Matrix, int v, int m, int n);
void printMatrix(matrix & Matrix);
std::vector<int> check_row(const std::string & str);
std::vector<int> task(matrix & Matrix);
void sort_row(matrix & Matrix, int row);
bool check_word(const std::string & str);