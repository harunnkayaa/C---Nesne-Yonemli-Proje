/**
* @file Complex.cpp
* @description IdentityMatrix.cpp sınıfını gerçekleştirir
* @assignment Proje2
* @date 24.12.23
* @author Harun Kaya  harun.kaya@stu.fsm.edu.tr
*/


#include "IdentityMatrix.hpp"
// IdentityMatrix yapıcı fonksiyonu: Bir birim matris oluşturur.
// Parametre olarak matrisin boyutunu (size) alır ve SquareMatrix sınıfından türetilmiştir.
IdentityMatrix::IdentityMatrix(size_t size) : SquareMatrix(size) {
    // Matrisin köşegenindeki her elemanı 1'e reel olarak ve 0'a imajiner olarak ayarlar.
    for (size_t i = 0; i < size; i++) {
        (*this)(i, i) = Complex(1, 0);
    }
}