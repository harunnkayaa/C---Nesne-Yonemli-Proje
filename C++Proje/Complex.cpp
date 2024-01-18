/**
* @file Complex.cpp
* @description Complex sınıfını gerçekleştirir
* @assignment KProje2
* @date 24.12.23
* @author Harun Kaya  harun.kaya@stu.fsm.edu.tr
*/



#include "Complex.hpp"
#include <iostream>

using namespace std;

// Kopya constructur fonksiyon: Başka bir Complex nesnesinin değerlerini kopyalar.
Complex::Complex(const Complex& other) : Imaginary(other.getImaginary()), re(other.re) {}

// Parametreli constructur fonksiyon: Reel ve imajiner değerler alarak bir Complex nesnesi oluşturur.
Complex::Complex(double real, double imag) : re(real), Imaginary(imag) {} 

// Çıkarma operatörü: İki Complex nesnesinin reel ve imajiner kısımlarını ayrı ayrı çıkarır.
Complex Complex::operator-(const Complex& diger) const {
    // Lambda ifadesi yerine doğrudan hesaplama
    double reelFark = this->re - diger.re; // Reel kısımların farkını hesapla
    double imajinerFark = this->getImaginary() - diger.getImaginary(); // İmajiner kısımların farkını hesapla

    return Complex(reelFark, imajinerFark); // Yeni kompleks sayıyı döndür
}

// Çıktı akışı operatörü: Complex nesnesinin reel ve imajiner kısımlarını formatlayarak yazdırır.
// Bu şekilde Complex nesnelerimi, reel ve imajiner kısımlarını yazdıracak  şekilde doğrudan çıktı akışlarına göndermeme olanak tanır.
ostream& operator<<(ostream& os, const Complex& c) {
    os << c.getReal() << " + " << c.getImaginary() << "i"; // Nesnemin reel ve imajiner kısımlarını yazdırıyorum
    return os; // Çıktı akışını geri döndürüyorum
}


// Reel kısmı döndüren fonksiyon: Nesnenin reel kısmını döndürür.
double Complex::getReal() const {
    return re;
}

// İmajiner kısmı döndüren fonksiyon: Nesnenin imajiner kısmını döndürür.
double Complex::getImaginary() const {
    return Imaginary::getImaginary();
}

// Nesneyi yazdıran fonksiyon: Complex nesnesinin reel ve imajiner kısımlarını okunaklı bir şekilde yazdırır.
void Complex::print() const {
    if (getImaginary() >= 0)
        cout << getReal() << " + " << getImaginary() << "i" << endl;
    else
        cout << getReal() << " - " << -getImaginary() << "i" << endl;
}

// Toplama operatörü: İki Complex nesnesinin reel ve imajiner kısımlarını ayrı ayrı toplar.
Complex Complex::operator+(const Complex& diger) const {
    // Reel ve imajiner kısımların toplamını hesapla
    double reelKisim = this->re + diger.re;// İki nesnenin reel kısımlarının toplamı.
    double imajinerKisim = this->getImaginary() + diger.getImaginary();
    return Complex(reelKisim, imajinerKisim);
}

// Bölme operatörü: İki Complex nesnesini bölerek yeni bir Complex nesnesi oluşturur.
Complex Complex::operator/(const Complex& diger) const {
    // Payda hesaplaması
    double payda = diger.re * diger.re + diger.getImaginary() * diger.getImaginary();
    // Reel ve imajiner bölüm hesaplamaları
    double reelBolum = (this->re * diger.re + this->getImaginary() * diger.getImaginary()) / payda;
    double imajinerBolum = (this->getImaginary() * diger.re - this->re * diger.getImaginary()) / payda; // İmajiner bölüm hesaplama.
    return Complex(reelBolum, imajinerBolum);// Bölme sonucunu yeni bir Complex nesnesi olarak döndür.
}

// Çarpma operatörü: İki Complex nesnesini çarparak yeni bir Complex nesnesi oluşturur.
Complex Complex::operator*(const Complex& diger) const {
    // Kompleks çarpma işlemini gerçekleştir
    double buReel = this->re; // Bu nesnenin reel kısmını al
    double buImajiner = this->getImaginary(); // Bu nesnenin imajiner kısmını al

    double digerReel = diger.re; // Diğer nesnenin reel kısmını al
    double digerImajiner = diger.getImaginary(); // Diğer nesnenin imajiner kısmını al

  
    double sonucReel = buReel * digerReel - buImajiner * digerImajiner; // Reel kısımların çarpımı ve imajiner kısımların çarpımının farkı
    double sonucImajiner = buReel * digerImajiner + buImajiner * digerReel; // İmajiner kısımların çarpımı ve reel kısımların çarpımının toplamı

    return Complex(sonucReel, sonucImajiner); // Yeni kompleks sayıyı döndür
}


// '-=' operatörü: Bu nesnenin değerlerinden başka bir Complex nesnesinin değerlerini çıkarır.
Complex& Complex::operator-=(const Complex& other) {
    re -= other.re; // Bu nesnenin reel kısmından parametre nesnesinin reel kısmını çıkarır.
    Imaginary::setImaginary(Imaginary::getImaginary() - other.getImaginary());// Bu nesnenin imajiner kısmından parametre nesnesinin imajiner kısnı çıkarır.
    return *this;// Güncellenen nesneyi döndürür.
}

// '!=' operatörü: İki Complex nesnesinin eşit olup olmadığını kontrol eder.
bool Complex::operator!=(const Complex& diger) const {
    return !(*this == diger);// '==' operatörünün tersini kullanarak eşitlik kontrolü yapar.
}

// Atama operatörü: Bir Complex nesnesinin değerlerini başka bir Complex nesnesine kopyalar.
Complex& Complex::operator=(const Complex& other) {
    if (this != &other) {// Kendi kendine atama durumunu kontrol eder.
        re = other.re;
        Imaginary::setImaginary(other.getImaginary());// Parametre nesnesinin imajiner kısmını kopyalar.
    }
    return *this;// Güncellenen nesneyi döndürür.
}

// '+=' operatörü: Bu nesnenin değerlerine başka bir Complex nesnesinin değerlerini ekler.
Complex& Complex::operator+=(const Complex& other) {
    re += other.re;// Bu nesnenin reel kısmına parametre nesnesinin reel kısmını ekler.
    Imaginary::setImaginary(Imaginary::getImaginary() + other.getImaginary());// Bu nesnenin imajiner kısmından parametre nesnesinin imajiner kısnı toplar.
    return *this;
}




// '*=' operatörü: Bu nesnenin değerlerini başka bir Complex nesnesi ile çarpar.
Complex& Complex::operator*=(const Complex& other) {
    double temp_re = re * other.re - this->getImaginary() * other.getImaginary();// Reel kısımların çarpımı ve imajiner kısımların çarpımının farkı.
    double temp_im = re * other.getImaginary() + this->getImaginary() * other.re;// Reel ve imajiner kısımların çapraz çarpımlarının toplamı.
    re = temp_re;// Çarpım sonucunun reel kısmını günceller.
    // Çarpım sonucunun imajiner kısmını günceller.
    this->setImaginary(temp_im); // Imaginary sınıfında setImaginary metodunu tanımlamanız gerekiyor.
    return *this;
}


// '/=' operatörü: Bu nesnenin değerlerini başka bir Complex nesnesine böler.
Complex& Complex::operator/=(const Complex& other) {
    double denominator = other.re * other.re + other.getImaginary() * other.getImaginary();
    double temp_re = (re * other.re + Imaginary::getImaginary() * other.getImaginary()) / denominator;// Reel bölümün hesaplanması.
    double temp_im = (Imaginary::getImaginary() * other.re - re * other.getImaginary()) / denominator;// Imajiner bölümün hesaplanması.
    // Bölüm sonucunun reel kısmını günceller.
    re = temp_re;
    // Bölüm sonucunun imajiner kısmını günceller.
    Imaginary::setImaginary(temp_im);
    return *this;
}


// '==' operatörü: İki Complex nesnesinin eşit olup olmadığını kontrol eder.
bool Complex::operator==(const Complex& diger) const {
    return re == diger.re && getImaginary() == diger.getImaginary();
}







