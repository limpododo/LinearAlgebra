#ifndef LINEARALGEBRA_MATRIX_HPP
#define LINEARALGEBRA_MATRIX_HPP

#include <vector>
#include <iostream>

template <int N, int M, typename Field = int> // n-число строк, m-число столбцов
class Matrix {
private:
    std::vector<std::vector<Field>> _data { N, std::vector<Field>(M) };
public:
    Matrix() = delete;
    Matrix(std::initializer_list<std::initializer_list<Field>> data);
    Matrix(const Matrix& matrix);

    void print();
};

template <int N, int M, typename Field>
Matrix<N, M, Field>::Matrix(std::initializer_list<std::initializer_list<Field>> data) {

    auto it_v = _data.begin();
    auto it_l = data.begin();

    while(it_l != data.end()) {
        std::copy(it_l->begin(), it_l->end(), it_v->begin());
        ++it_l; ++it_v;
    }
}

template <int N, int M, typename Field>
Matrix<N, M, Field>::Matrix(const Matrix &matrix) {
    this->_data = matrix._data;
}

template <int N, int M, typename Field>
void Matrix<N, M, Field>::print() {
    for(int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cout << _data[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

#endif //LINEARALGEBRA_MATRIX_HPP
