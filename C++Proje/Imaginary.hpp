
/**
* @file Imaginary.h
* @description Imaginary.h sınıfını gerçekleştirir
* @assignment Proje2
* @date 24.12.23
* @author Harun Kaya  harun.kaya@stu.fsm.edu.tr
*/
#ifndef IMAGINARY_H
#define IMAGINARY_H

#include <iostream>

using namespace std;

class Imaginary {
private:
    double im;  // Sanal kısım

public:
    // Yapıcı fonksiyon: Bir imajiner sayının sanal kısmını başlatır.
    // imag parametresi, imajiner sayının sanal kısmını belirtir.
    Imaginary(double imag);
    double getImaginary() const;
    void setImaginary(double imag); // setImaginary metodunu ekle
};

#endif
