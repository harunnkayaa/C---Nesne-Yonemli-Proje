/**
* @file Vector.cpp
* @description Vector.cpp sınıfını gerçekleştirir
* @assignment Proje2
* @date 24.12.23
* @author Harun Kaya  harun.kaya@stu.fsm.edu.tr
*/

#include "Vector.hpp"
#include <iostream>
#include <stdexcept>
#include "Vector.hpp"

/*Vektor sınıfının yapıcı fonksiyonu: Belirli bir boyutta vektör oluşturur.  'size' parametresi vektörün boyutunu belirtir.
Vektör, Complex türünde elemanlar içerir ve başlangıçta tüm elemanlar varsayılan değerlere sahiptir.*/ 

Vector::Vector(size_t size) : size(size) {
    elements = new Complex[size];
}
// Kopya yapıcı fonksiyon: Diğer bir Vector nesnesinin kopyasını oluşturur.
Vector::Vector(const Vector& other) : size(other.size) {
    elements = new Complex[size];
    for (size_t i = 0; i < size; i++) {
        elements[i] = other.elements[i];// Elemanları tek tek kopyalar.
    }
}

Vector::~Vector() {
    // Dinamik olarak ayrılan alanı siler.
    delete[] elements;
}


//  İki vektörü toplayarak sonucu mevcut vektöre atar.
Vector& Vector::operator+=(const Vector& other) {
    if (size != other.size) {
        throw std::invalid_argument("Vector sizes do not match"); // Boyut uyumsuzluğu kontrolü.
    }
    for (size_t i = 0; i < size; i++) {
        elements[i] += other.elements[i]; // Her eleman için toplama işlemi yapılır ve güncellenir.
    }
    return *this; // Güncellenen vektör döndürülür.
}
// Atama operatörü: Bir Vector nesnesinin değerlerini başka bir Vector nesnesine kopyalar.
Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {// aynı nesne atanmaya çalışılmıyorsa 
        if (size != other.size) {// Mevcut elemanları siler.
            delete[] elements;
            size = other.size;
            elements = new Complex[size];// Yeni boyutlarda yer ayırır.
        }
        for (size_t i = 0; i < size; i++) {
            elements[i] = other.elements[i];// Elemanları tek tek kopyalar.
        }
    }
    return *this;
}

// Çıkarma Operatörü
// İki vektör arasındaki farkı hesaplar. Vektörler aynı boyutta olmalıdır.
// Eğer boyutlar uyuşmazsa, std::invalid_argument hatası fırlatılır.
Vector Vector::operator-(const Vector& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Vector sizes do not match"); // Boyut uyumsuzluğu kontrolü.
    }
    Vector result(size); // Sonuç vektörü.
    for (size_t i = 0; i < size; i++) {
        result.elements[i] = elements[i] - other.elements[i]; // Her eleman için çıkarma işlemi yapılır.
    }
    return result; // Hesaplanan fark vektörü döndürülür.
}


//  Vektörü bir skalar değer ile çarpar ve sonucu mevcut vektöre atar.
Vector& Vector::operator*=(const Complex& scalar) {
    for (size_t i = 0; i < size; i++) {
        elements[i] *= scalar; // Her elemanı skalar değer ile çarpar ve günceller.
    }
    return *this; // Güncellenen vektör döndürülür.
}

// Vektörün boyutunu (eleman sayısını) döndürür.
size_t Vector::getSize() const {
    return size;  // Vektörün boyutunu döndürür.
}

// İç Çarpım Operatörü
// İki vektör arasındaki iç çarpımı hesaplar. Vektörler aynı boyutta olmalıdır.
// Eğer boyutlar uyuşmazsa, std::invalid_argument hatası fırlatılır.
Complex Vector::operator*(const Vector& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Vector sizes do not match"); // Boyut uyumsuzluğu kontrolü.
    }
    Complex dotProduct; // İç çarpım sonucunu saklamak için Complex türünde değişken.
    for (size_t i = 0; i < size; i++) {
        dotProduct += elements[i] * other.elements[i]; // Her elemanın çarpımını toplayarak iç çarpımı hesaplar.
    }
    return dotProduct; // İç çarpım sonucu döndürülür.
}




//  İki vektör arasındaki farkı hesaplayarak sonucu mevcut vektöre atar.
Vector& Vector::operator-=(const Vector& other) {
    if (size != other.size) {
        throw std::invalid_argument("Vector sizes do not match"); // Boyut uyumsuzluğu kontrolü.
    }
    for (size_t i = 0; i < size; i++) {
        elements[i] -= other.elements[i]; // Her eleman için çıkarma işlemi yapılır ve güncellenir.
    }
    return *this; // Güncellenen vektör döndürülür.
}
// Toplama operatörü: İki vektörü toplar.
Vector Vector::operator+(const Vector& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Vector boyutu uygun degil");
    }

    Vector result(size);
    for (size_t i = 0; i < size; i++) {
        //iki elaman üzeinde toplama islemini yapr.
        result.elements[i] = elements[i] + other.elements[i];
    }
    return result;
}


// getElement fonksiyonu: Belirtilen indeksteki elemanı döndürür.

Complex Vector::getElement(size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range"); // İndeks hatası kontrolü.
    }
    return elements[index]; // İndeksteki elemanı döndürür.
}

// setElement fonksiyonu: Vektörün belirli bir indeksindeki elemanı belirtilen değerle günceller.
void Vector::setElement(size_t index, const Complex& value) {
    if (index >= size) {
        throw std::out_of_range("Index out of range"); // İndeks hatası kontrolü.
    }
    elements[index] = value; // İndeksteki elemanı günceller.
}

//  Vektörün içeriğini okunabilir bir biçimde konsola yazdırır.
void Vector::print() const {
    std::cout << "[";
    for (size_t i = 0; i < size; ++i) {
        std::cout << elements[i];
        if (i < size - 1) std::cout << ", "; // Elemanlar arasına virgül koyar.
    }
    std::cout << "]" << std::endl; // Vektörün sonunu belirtir.
}

// Eşitlik ve Eşit Olmama Operatörleri

// İki vektörün eşit olup olmadığını kontrol eder.
bool Vector::operator==(const Vector& other) const {
    if (size != other.size) {
        return false; // Boyutlar farklıysa vektörler eşit değildir.
    }
    for (size_t i = 0; i < size; ++i) {
        if (elements[i] != other.elements[i]) {
            return false; // Elemanlar farklıysa vektörler eşit değildir.
        }
    }
    return true; // Tüm elemanlar eşitse vektörler eşittir.
}

//İki vektörün eşit olmadığını kontrol eder.
bool Vector::operator!=(const Vector& other) const {
    return !(*this == other); // '==' operatörünün tersini kullanarak kontrol eder.
}
