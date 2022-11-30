#include "matrix.h"

int main(){
    int v(0), m(0), n(0);
    while(v<0 || m<=0 || n<=0)
    {
        std::cout << "Enter matrix size: ";
        v = getInt();
        m = getInt();
        n = getInt();
    }
    matrix Matrix;
    getMatrix(Matrix, v, m, n);
    printMatrix(Matrix);
    std::vector <int> b;
    b = task(Matrix);
    for(int i=0; i<m; ++i)
    {
        std::cout << b[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    int row(-1);
    while(row<0)
    {
        std::cout << "Enter number of row: ";
        row = getInt();
    }

    std::cout << std::endl;
    sort_row(Matrix, row);
    printMatrix(Matrix);
    return 0;
}
