/**
* @file Complex.cpp
* @description Imaginary.h sınıfını gerçekleştirir
* @assignment Proje2
* @date 24.12.23
* @author Harun Kaya  harun.kaya@stu.fsm.edu.tr
*/

#include "Imaginary.hpp"
#include <iostream>

using namespace std;
Imaginary::Imaginary(double imag) : im(imag) {}
// Imaginary sınıfının yapıcı fonksiyonu, İmajiner bir sayıyı temsil eder.
// Parametre olarak bir imajiner değer imag alır ve bu değeri sınıfın imajiner kısmı olarak ayarlar.

double Imaginary::getImaginary() const {
    return im;
}

void Imaginary::setImaginary(double imag) {
    im = imag;// Sınıfın imajiner kısmını parametre ile gelen değere ayarlar.
}