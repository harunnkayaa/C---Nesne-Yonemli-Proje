/**
* @file TriangleMatrix.cpp
* @description TriangleMatrix.cpp sınıfını gerçekleştirir
* @assignment Proje2
* @date 24.12.23
* @author Harun Kaya  harun.kaya@stu.fsm.edu.tr
*/

#include "TriangleMatrix.hpp"


TriangleMatrix::TriangleMatrix(size_t size, bool isUpper) : SquareMatrix(size) {
    // Matrisin tüm elemanlarını sıfırla
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            (*this)(i, j) = Complex(0, 0);
        }
    }
    // Üst veya alt üçgen matris oluşturma işlemi
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = isUpper ? i : 0; j < (isUpper ? size : i + 1); ++j) {
            (*this)(i, j) = Complex(1, 0); // Varsayılan olarak 1 değerini atarız
        }
    }
}

