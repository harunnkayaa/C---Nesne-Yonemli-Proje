/**
* @file Complex.cpp
* @description IdentityMatrix.h sınıfını gerçekleştirir
* @assignment Proje2
* @date 24.12.23
* @author Harun Kaya  harun.kaya@stu.fsm.edu.tr
*/

#ifndef IDENTITYMATRIX_H
#define IDENTITYMATRIX_H

#include "SquareMatrix.hpp"

class IdentityMatrix : public SquareMatrix {
public:
// Yapıcı fonksiyon  Belirli bir boyutta birim matris oluşturur.
    // size parametresi  oluşturulacak kare matrisin satır ve sütun sayısını belirtir.
    IdentityMatrix(size_t size);
};

#endif 
