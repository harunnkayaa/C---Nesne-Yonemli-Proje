/**
* @file Matrix.h 
* @description Matrix.h sınıfını gerçekleştirir
* @assignment Proje2
* @date 24.12.23
* @author Harun Kaya  harun.kaya@stu.fsm.edu.tr
*/


#ifndef MATRIX_H
#define MATRIX_H

#include "Complex.hpp"
#include <iostream>
#include "LinearAlgebraObject.hpp"

class Matrix : public LinearAlgebraObject {
private:
    size_t row, col;
    Complex* elements; // Complex türünden bir dizi

public:
    Matrix(size_t numRows, size_t numCols);
    ~Matrix(); // Yıkıcı (Destructor)
    Matrix(const Matrix& other); // Kopya yapıcı (Copy constructor)
    Matrix& operator=(const Matrix& other); // Atama operatörü (Assignment operator)

    Complex& operator()(size_t rowIndex, size_t colIndex);
    const Complex& operator()(size_t rowIndex, size_t colIndex) const;

    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    Matrix& operator+=(const Matrix& other);
    Matrix& operator-=(const Matrix& other);
    Matrix& operator*=(const Matrix& other);
    bool operator==(const Matrix& other) const;
    Matrix transpose() const;
    double determinant() const;

    //void print() const;
    void print() const override;

    size_t getRowCount() const;
    size_t getColumnCount() const;
};

#endif