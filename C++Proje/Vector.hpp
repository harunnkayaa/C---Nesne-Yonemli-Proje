/**
* @file Vector.h
* @description Vector.h sınıfını gerçekleştirir
* @assignment Proje2
* @date 24.12.23
* @author Harun Kaya  harun.kaya@stu.fsm.edu.tr
*/


#ifndef VECTOR_H
#define VECTOR_H

#include "Complex.hpp"
#include <cstddef>
#include <iostream>
#include "LinearAlgebraObject.hpp"

class Vector : public LinearAlgebraObject{
private:
    size_t size;
    Complex* elements;

public:
    Vector(size_t size);
    Vector(const Vector& other); // Copy constructor
    ~Vector();

    Vector& operator=(const Vector& other);
    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    Complex operator*(const Vector& other) const;
    Vector& operator+=(const Vector& other);
    Vector& operator-=(const Vector& other);
    Vector& operator*=(const Complex& scalar);

    size_t getSize() const;
    Complex getElement(size_t index) const;
    void setElement(size_t index, const Complex& value);

    bool operator==(const Vector& other) const;
    bool operator!=(const Vector& other) const;
  

    //void print() const;
    void print() const override;
};

#endif


/*#ifndef VECTOR_H
#define VECTOR_H

#include "Complex.h"
#include <iostream>
#include <stdexcept>

class Vector {
private:
    size_t size;
    Complex* elements;

public:
    Vector(size_t n);
    ~Vector();
    Vector(const Vector& other);
    Vector& operator=(const Vector& other);

    Complex& operator[](size_t index);
    const Complex& operator[](size_t index) const;

    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    Complex dot(const Vector& other) const;

    Vector& operator+=(const Vector& other);
    Vector& operator-=(const Vector& other);

    bool operator==(const Vector& other) const;

    void print() const;

    size_t getSize() const;
};

#endif // VECTOR_H*/
