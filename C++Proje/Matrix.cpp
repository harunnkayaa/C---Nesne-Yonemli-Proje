/**
* @file Matrix.cpp
* @description Matrix.cpp sınıfını gerçekleştirir
* @assignment Proje2
* @date 24.12.23
* @author Harun Kaya  harun.kaya@stu.fsm.edu.tr
*/

#include "Matrix.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>

// Constructor
// Yapıcı fonksiyon: numRows ve numCols parametreleri ile belirtilen boyutlarda bir matris oluşturur.
// Bu matris Complex türünde elemanlar içerir ve başlangıçta tüm elemanlar sıfırlanır.
Matrix::Matrix(size_t numRows, size_t numCols) 
    : row(numRows), col(numCols), elements(new Complex[numRows * numCols]) {}

// Destructor
// Yıkıcı fonksiyon: Matrisin bellekte kapladığı alanı serbest bırakır.
// Dinamik olarak ayrılan 'elements' dizisini siler.
Matrix::~Matrix() {
    delete[] elements;
}

// Copy Constructor
// Kopya yapıcı fonksiyon: Diğer bir Matrix nesnesinin kopyasını oluşturur.
// Bu işlem için 'other' matrisinin tüm elemanlarını yeni oluşturulan matrise kopyalar.
Matrix::Matrix(const Matrix& other) 
    : row(other.row), col(other.col), elements(new Complex[other.row * other.col]) {
    for (size_t i = 0; i < row * col; ++i) {
        elements[i] = other.elements[i];// Elemanları tek tek kopyalar.
    }
}
// transpose fonksiyonu: Matrisin transpozesini hesaplar ve döndürür.
Matrix Matrix::transpose() const {
    Matrix result(col, row); // Transpoze matrisi
    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < col; ++j) {
            result(j, i) = (*this)(i, j); // Satır ve sütunları yer değiştirir.
        }
    }
    return result; // Transpoze matrisi döndürür.
}

// Assignment Operator
// Atama operatörü: Bir Matrix nesnesinin değerlerini diğer Matrix nesnesine kopyalar.
// Kendi kendine atama durumunu kontrol eder ve bellekteki mevcut 'elements' dizisini uygun şekilde yönetir.
Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        delete[] elements;// Mevcut elemanları siler.
        row = other.row;
        col = other.col;
        elements = new Complex[row * col]; // Yeni boyutlarda yer ayırır.
        for (size_t i = 0; i < row * col; ++i) {
            elements[i] = other.elements[i];// Elemanları tek tek kopyalar.
        }
    }
    // Kendi nesnesini döndürür.
    return *this;
}
//arpma operatörü: İki matrisi çarpar.
// Eğer boyutlar uygun değilse, sonuç matrisinin doğru boyutlarda oluşturulması sağlanır.
Matrix Matrix::operator*(const Matrix& other) const {
    Matrix result(row, other.col);
    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < other.col; ++j) {
            Complex sum(0, 0);
            for (size_t k = 0; k < col; ++k) {
                sum += this->elements[i * col + k] * other.elements[k * other.col + j];
            }
            result.elements[i * other.col + j] = sum;
        }
    }
    return result;
}

// Access Operators
// Erişim operatörleri: rowIndex ve colIndex kullanılarak matrisin belirli bir elemanına erişir.


Complex& Matrix::operator()(size_t rowIndex, size_t colIndex) {
    if (rowIndex >= row || colIndex >= col) {
        throw std::out_of_range("Index out of bounds");
        
    }
    return elements[rowIndex * col + colIndex];
    // İstenen elemanı döndürür.
}

const Complex& Matrix::operator()(size_t rowIndex, size_t colIndex) const {
    if (rowIndex >= row || colIndex >= col) {
        throw std::out_of_range("Index out of bounds");
        
    }
    return elements[rowIndex * col + colIndex];
}



// Çıkarma operatörü: İki matrisin farkını hesaplar.
Matrix Matrix::operator-(const Matrix& other) const {
    Matrix result(row, col);
    for (size_t i = 0; i < row * col; ++i) {
        result.elements[i] = this->elements[i] - other.elements[i];
    }
    return result;
}





// '-=' operatörü: Bu matristen başka bir matrisi çıkarır ve sonucu bu matrise atar.
Matrix& Matrix::operator+=(const Matrix& other) {
    *this = *this + other;
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& other) {
    *this = *this - other;
    return *this;
}
// Toplama operatörü: İki matrisi toplar.

Matrix Matrix::operator+(const Matrix& other) const {
    if (row != other.row || col != other.col) {
        throw std::invalid_argument("Matrix dimensions do not match");
        
    }
    Matrix result(row, col);// Sonuç matrisi
    for (size_t i = 0; i < row * col; ++i) {
        // Elemanları toplar.
        result.elements[i] = this->elements[i] + other.elements[i];
    }
    //toplam matrisi döndürür
    return result;
}
Matrix& Matrix::operator*=(const Matrix& other) {
    *this = *this * other;
    return *this;
}

// Equality Operator
bool Matrix::operator==(const Matrix& other) const {
    if (row != other.row || col != other.col) {
        return false;// Boyutlar farklıysa matrisler eşit değildir.
    }
    for (size_t i = 0; i < row * col; ++i) {
        if (!(elements[i] == other.elements[i])) {
            return false;// Elemanlar farklıysa matrisler eşit değildir.
        }
    }
    return true;// Tüm elemanlar eşitse matrisler eşittir.
}





    // print fonksiyonu: Matrisin içeriğini konsola yazdırır.
void Matrix::print() const {
    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < col; ++j) {
            std::cout << (*this)(i, j) << " "; // Her elemanı yazdırır.
        }
        std::cout << std::endl; // Satır sonunda yeni satıra geçer.
    }
}


double Matrix::determinant() const {
    // Kare matris kontrolü - determinant yalnızca kare matrisler için hesaplanabilir.
    if (row != col) {
        //throw std::logic_error("Determinant can only be calculated for square matrices");
        return false;
    }

    // Tek elemanlı matrisin determinantı, o elemanın kendisidir.
    if (row == 1) {
        return (*this)(0, 0).getReal(); // Complex sayının gerçek kısmını döndürüyoruz
    }

    double det = 0.0; // Determinant değerini saklamak için değişken
    Matrix subMatrix(row - 1, col - 1); // Alt matris için yer ayırma

    // Ana matrisin sütunları üzerinde döngü
    for (size_t i = 0; i < col; ++i) {
        size_t subRow = 0;
        size_t subCol = 0;

        // Alt matrisi oluşturmak için çift döngü
        for (size_t j = 1; j < row; ++j) {
            for (size_t k = 0; k < col; ++k) {
                // Ana matrisin i. sütunu hariç tüm elemanları alt matrise kopyala
                if (k != i) {
                    subMatrix(subRow, subCol) = (*this)(j, k);
                    ++subCol;
                }
            }
            ++subRow;
            subCol = 0; // Sütun indeksini sıfırla
        }

        // İşaret hesaplaması - Laplace genişlemesi için
        double sign = (i % 2 == 0) ? 1.0 : -1.0;

        // Ana matrisin ilk satırındaki eleman ile alt matrisin determinantını çarp ve topla
        det += sign * (*this)(0, i).getReal() * subMatrix.determinant(); // Complex sayının gerçek kısmını kullanıyoruz
    }

    return det; // Hesaplanan determinantı döndür
}


// Getters
size_t Matrix::getRowCount() const {
    return row;
}

size_t Matrix::getColumnCount() const {
    return col;
}


//-------------------------------------------

