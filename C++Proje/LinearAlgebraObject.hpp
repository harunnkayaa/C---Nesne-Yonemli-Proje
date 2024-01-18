/**
* @file LinearAlgebraObject.h
* @description LinearAlgebraObject.h sınıfını gerçekleştirir
* @assignment Proje2
* @date 24.12.23
* @author Harun Kaya  harun.kaya@stu.fsm.edu.tr
*/

#ifndef LINEARALGEBRAOBJECT_H
#define LINEARALGEBRAOBJECT_H

class LinearAlgebraObject {
public:
    // Soyut print fonksiyonu: Türetilmiş sınıflar tarafından gerçekleştirilmek üzere tanımlanır.
    // Bu fonksiyon nesnenin içeriğini yazdırmak için kullanılır
    virtual void print() const = 0; // Soyut yazdırma fonksiyonu
    virtual ~LinearAlgebraObject() {}
};



#endif 
