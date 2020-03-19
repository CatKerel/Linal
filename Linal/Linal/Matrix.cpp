#include "Matrix.h"

Matrix::Matrix(int m, int n) {
    this->m = m;
    this->n = n;
    matrix = new double* [m];
    for (int i = 0; i < m; i++)
        matrix[i] = new double[n];
}

Matrix::Matrix(int n, int m, double** value) {
    this->m = m;
    this->n = n;

    matrix = new double* [m];
    for (int i = 0; i < m; i++)
        matrix[i] = new double[n];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            this->matrix[i][j] = value[i][j];
}

Matrix::~Matrix() { delete[] matrix; }

void Matrix::setValue(unsigned int i, unsigned int j, double value) { matrix[i][j] = value; }

double Matrix::getValue(unsigned int i, unsigned int j) const { return matrix[i][j]; }

int Matrix::getM() const { return m; }

int Matrix::getN() const { return n; }

Matrix Matrix::operator*(double a) const {
    double** matrix = new double* [m];
    for (int i = 0; i < m; i++)
        matrix[i] = new double[n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = this->matrix[i][j] * a;
    return Matrix(n, m, matrix);
}

Matrix Matrix::operator/(const double a) const {
    double** matrix = new double* [m];
    for (int i = 0; i < m; i++)
        matrix[i] = new double[n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = this->matrix[i][j] / a;
    return Matrix(n, m, matrix);
}

Matrix Matrix::operator+(const Matrix& a) const {
    double** matrix = new double* [m];
    for (int i = 0; i < m; i++)
        matrix[i] = new double[n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = this->matrix[i][j] + a.getValue(i,j);
    return Matrix(n, m, matrix);
}

Matrix Matrix::operator-(const Matrix& a) const {
    double** matrix = new double* [m];
    for (int i = 0; i < m; i++)
        matrix[i] = new double[n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = this->matrix[i][j] - a.getValue(i, j);
    return Matrix(n, m, matrix);
}

Matrix Matrix::operator+=(const Matrix& a) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = matrix[i][j] + a.getValue(i, j);
    return *this;
}

Matrix Matrix::operator-=(const Matrix& a) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = matrix[i][j] - a.getValue(i, j);
    return *this;
}

Matrix Matrix::operator*=(double a) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = matrix[i][j] * a;
    return *this;
}

Matrix Matrix::operator/=(double a) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = matrix[i][j] / a;
    return *this;
}

Matrix Matrix::transpose() const {
    int m = this->n;
    int n = this->m;
    double** matrix = new double* [m];
    for (int i = 0; i < m; i++)
        matrix[i] = new double[n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = this->matrix[j][i];
    return Matrix(n, m, matrix);
}

Matrix* Matrix::operator*(const Matrix& a) const { //TODO
    if (this->n != a.m) {
        std::cout << "Matrices cannot be multiplied!" << std::endl;
        return nullptr;
    }

    int m = this->m;
    int n = a.n;
    double** matrix = new double* [m];
    for (int i = 0; i < m; i++)
        matrix[i] = new double[n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < n; k++)
                matrix[i][j] = this->getValue(i, k) * a.getValue(k, j);
    return &Matrix(m, n, matrix);
}

std::ostream& operator<<(std::ostream& os, const Matrix& a) {
    for (int i = 0; i < a.getN(); i++) {
        for (int j = 0; j < a.getM(); j++)
            os << a.getValue(i, j) << " ";
        os << std::endl;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Matrix& a) {
    for (int i = 0; i < a.getN(); i++)
        for (int j = 0; j < a.getM(); j++) {
            double b;
            is >> b;
            a.setValue(i, j, b);
        }
    return is;
}