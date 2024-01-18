/**
* @file TriangleMatrix.h
* @description TriangleMatrix.h sınıfını gerçekleştirir
* @assignment Proje2
* @date 24.12.23
* @author Harun Kaya  harun.kaya@stu.fsm.edu.tr
*/

#ifndef TRIANGLEMATRIX_H
#define TRIANGLEMATRIX_H

#include "SquareMatrix.hpp"
#include "TriangleMatrix.hpp"

class TriangleMatrix : public SquareMatrix {
public:
/*Yapıcı fonksiyon: Belirli bir boyutta üçgen matris oluşturur. 'size' parametresi, oluşturulacak üçgen matrisin boyutunu (hem satır hem de sütun sayısını) belirtir.
'isUpper' parametresi, oluşturulacak matrisin üst üçgen mi yoksa alt üçgen mi olacağını belirler.
 Eğer 'isUpper' true ise, matris üst üçgen matris olur false ise, alt üçgen matris olur.*/
    TriangleMatrix(size_t size, bool isUpper);
    
};

#endif 
