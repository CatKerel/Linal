#pragma once
#include <iostream>

class Matrix {
private:
    int n;  
    int m;  
    double** matrix;
public:
    Matrix(int m, int n);
    Matrix(int m, int n, double** value);
    ~Matrix();

    void setValue(unsigned int i, unsigned int j, double value);
    double getValue(unsigned int i, unsigned int j) const;
    int getN() const;
    int getM() const;

    Matrix operator+ (const Matrix& a) const;
    Matrix operator- (const Matrix& a) const;
    Matrix operator* (double a) const;
    Matrix operator/ (double a) const;

    Matrix* operator* (const Matrix& a) const; //returns a pointer!

    Matrix operator+= (const Matrix& a);
    Matrix operator-= (const Matrix& a);
    Matrix operator*= (const double a);
    Matrix operator/= (const double a);

    Matrix transpose() const;
};
std::ostream& operator<< (std::ostream& os, const Matrix& a);
std::istream& operator>> (std::istream& is, Matrix& a);

