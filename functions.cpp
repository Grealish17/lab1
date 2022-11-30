#include "matrix.h"

int getInt()
{
    int a;
    while(true) {
        if ((std::cin >> a).good())
            return a;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cout << "Wrong number! Enter again!\n";
        }
        std::cin.ignore();
    }
}

bool check_word(const std::string & str)
{
    unsigned long l = str.length();
    for(int i=0; i<l; ++i)
    {
        if (!((i == 0 && str[i] == '-') || (str[i] <= '9' && str[i] >= '0')))
            return false;
    }
    return true;
}

std::vector<int> check_row(const std::string & str)
{
    std::vector<int> res;
    std::string word;
    std::stringstream buf;
    buf << str;
    while(!buf.eof())
    {
        buf >> word;
        if (check_word(word))
        {
            res.push_back(std::stoi(word));
        }
        else
        {
            res.clear();
            break;
        }
    }
    return res;
}

void getMatrix(matrix & Matrix, int v, int m, int n)
{
    int a;
    std::string str;
    std::cout << "Enter matrix!\n";
    std::cout << "Values: \n";

    for(int i=0; i<v; ++i)
    {
        a = getInt();
        Matrix.values.push_back(a);
    }

    std::cout << "Columns: \n";
    for(int i=0; i<v; ++i)
    {
        a = getInt();
        Matrix.cols.push_back(a);
    }

    std::cout << "Pointer: \n";
    for(int i=0; i<m+1; ++i)
    {
        a = getInt();
        Matrix.pointer.push_back(a);
    }
    Matrix.n=n;
    std::cout << std::endl;
    std::cout << std::endl;
}

void printMatrix(matrix & Matrix)
{

    unsigned long m = Matrix.pointer.size() - 1;
    for(int i=0; i<m; ++i)
    {
        int p = Matrix.pointer[i];
        int q = Matrix.pointer[i+1] - 1;
        std::vector <int> val;
        for(int l=q; l>=p; --l)
        {
            val.push_back(l);
        }
        for(int j=0; j<Matrix.n; ++j)
        {
            if (val.empty())
            {
                std::cout << "0 ";
            }
            else if(j == Matrix.cols[val.back()])
            {
                std::cout << Matrix.values[val.back()] << " ";
                val.pop_back();
            }
            else
            {
                std::cout << "0 ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

void sort_row(matrix & Matrix, int row)
{
    int p = Matrix.pointer[row];
    int q = Matrix.pointer[row+1] - 1;
    std::sort(Matrix.values.begin() + p, Matrix.values.begin() + q + 1);
}

std::vector<int> task(matrix & Matrix)
{
    unsigned long m = Matrix.pointer.size() - 1;
    std::vector <int> b;
    b.resize(m);
    for(int i=0; i<m; ++i)
    {
        int first, last;
        int p = Matrix.pointer[i];
        int q = Matrix.pointer[i+1] - 1;
        if(p == q + 1)
        {
            b[i] = 0;
            continue;
        }

        if(Matrix.cols[p] == 0)
            first = Matrix.values[p];
        else
            first = 0;

        if(Matrix.cols[q] == Matrix.n - 1)
            last = Matrix.values[q];
        else
            last = 0;

        if(q - p != Matrix.n - 1)
        {
            b[i] = last;
        }
        else
        {
            for(int j=p; j<=q; ++j)
            {
                if(Matrix.values[j] <= 0)
                {
                    b[i] = last;
                    break;
                }
                else
                {
                    b[i] = first;
                }
            }
        }
    }
    return  b;
}