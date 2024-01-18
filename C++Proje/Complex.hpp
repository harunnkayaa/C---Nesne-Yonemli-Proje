/**
* @file Complex.cpp
* @description Complex.h sınıfını gerçekleştirir
* @assignment Proje2
* @date 24.12.23
* @author Harun Kaya  harun.kaya@stu.fsm.edu.tr
*/

#ifndef COMPLEX_H
#define COMPLEX_H

#include "Imaginary.hpp"
#include <iostream>
#include "LinearAlgebraObject.hpp"

using namespace std;

class Complex : public Imaginary, public LinearAlgebraObject {
private:
    double re; // Gerçel kısım
     

public:
    Complex(double real = 0.0, double imag = 0.0);
    double getReal() const;
    double getImaginary() const;
    // Nesnenin içeriğini yazdıran fonksiyon.
    // LinearAlgebraObject sınıfından override edilen  bir fonksiyondur.
    void print() const override;

    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;
    Complex& operator+=(const Complex& other);
    Complex& operator-=(const Complex& other);
    Complex& operator*=(const Complex& other);
    Complex& operator/=(const Complex& other);
    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;

    Complex(const Complex& other);              // Copy constructor
    Complex& operator=(const Complex& other);   // Assignment operator
    friend ostream& operator<<(std::ostream& os, const Complex& c);



};
//ostream& operator<<(std::ostream& os, const Complex& c);
#endif