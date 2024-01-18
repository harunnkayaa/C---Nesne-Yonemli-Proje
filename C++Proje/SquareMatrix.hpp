/**
* @file SquareMatrix.h
* @description SquareMatrix.h sınıfını gerçekleştirir
* @assignment Proje2
* @date 24.12.23
* @author Harun Kaya  harun.kaya@stu.fsm.edu.tr
*/

#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H

#include "Matrix.hpp"

class SquareMatrix : public Matrix {
public:
// Yapıcı fonksiyon: Belirli bir boyutta kare matris oluşturur 'size' parametresi, oluşturulacak kare matrisin hem satır hem de sütun sayısını belirtir.
    SquareMatrix(size_t size);
   

 
};

#endif 
