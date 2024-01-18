

/**
* @file SquareMatrix.cpp
* @description SquareMatrix.cpp sınıfını gerçekleştirir
* @assignment Proje2
* @date 24.12.23
* @author Harun Kaya  harun.kaya@stu.fsm.edu.tr
*/
#include "Matrix.hpp"

#include "SquareMatrix.hpp"

SquareMatrix::SquareMatrix(size_t size) : Matrix(size, size) {
/*SquareMatrix Yapıcı Fonksiyonu: Bir kare matris oluşturur.
 'size' parametresi hem satır hem de sütun sayısını belirtir, böylece kare bir matris oluşur.
 Bu yapıcı fonksiyon, temel Matrix sınıfının yapıcı fonksiyonunu çağırarak hem satır hem de sütun sayısını 'size' olarak ayarlar.*/
}

