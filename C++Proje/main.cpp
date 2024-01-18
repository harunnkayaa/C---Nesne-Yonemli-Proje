/**
* @file main.cpp
* @description main.cpp sınıfını gerçekleştirir
* @assignment Proje2
* @date 24.12.23
* @author Harun Kaya  harun.kaya@stu.fsm.edu.tr
*/


#include "Matrix.hpp"
#include "Complex.hpp"
#include "Vector.hpp"
#include "Imaginary.hpp"
#include <iostream>
#include "SquareMatrix.hpp"
#include "IdentityMatrix.hpp"
#include "TriangleMatrix.hpp"


using namespace std;

int main() {
    // Complex sınıfı için temel testler
    cout<<"//////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout<<endl;
    cout<<endl;
    cout << "Complex Class Tests:" << endl;
    cout<<endl;


    // Aritmetik işlemler
    Complex c1(2, -1); // 2 - 1i
    Complex c2(5, 4); // 5 + 4i
    cout << "c1: "; c1.print();
    cout << "c2: "; c2.print();
    
    Complex c4 = c1 + c2; 
    Complex c5 = c1 - c2; 
    Complex c6 = c1 * c2;
    Complex c7 = c1 / c2;
    cout<<endl;

    // Complex sınıfı nesnelerimi doğrudan cout ile yazdırıyorum  operator<< aşırı yüklemem sayesinde,
    cout << "Toplam: " << c4 << endl;
    cout << "Fark: " << c5 << endl;
    cout << "Carpim: " << c6 << endl;
    cout << "Bolum: " << c7 << endl;


    // Atama işlemleri
    Complex c3 = c1;
    cout << "c3 (ilk deger c1'e esit): " << c3 << endl;
    c3 += c2;
    cout << "c3 += c2 ->  c3: " << c3 << endl;
    c3 -= c2;
    cout << "c3 -= c2 ->  c3: " << c3 << endl;
    c3 *= c2;
    cout << "c3 *= c2 ->  c3: " << c3 << endl;
    c3 /= c2;
    cout << "c3 /= c2 ->  c3: " << c3 << endl;

    // Karşılaştırma işlemleri
    if (c1 == c2)
        cout << "c1 ve c2 esit." << endl;
    else
        cout << "c1 ve c2 esit degil." << endl;
        cout<<endl;
        cout<<endl;

  
    cout<<"//////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;

    cout<<endl;
    cout<<endl;
    // Matrix sınıfı için temel testler
    cout << "\nMatrix Class Testi:" << endl;
    cout<<endl;
       
    Matrix m1(2, 2); // 2x2 Matris
    m1(0, 0) = c1; 
    m1(0, 1) = c2;
    m1(1, 0) = c2; 
    m1(1, 1) = c1;

    Matrix m2(2, 2); // 2x2 Matris
    m2(0, 0) = c2; 
    m2(0, 1) = c1;
    m2(1, 0) = c1; 
    m2(1, 1) = c2;

    // Toplama ve çıkarma
    Matrix m3 = m1 + m2;
    Matrix m4 = m1 - m2;

    // Matris çarpımı
    Matrix m5 = m1 * m2;

    // Bilgileri yazdır
    cout << "Matrix m1:" << endl;
    cout<<endl;
    m1.print();
    cout<<endl;
    cout<<endl;
    cout << "Matrix m2:" << endl; 
    cout<<endl;
    m2.print();
    cout<<endl; cout<<endl;
    cout << "m1 + m2:" << endl; cout<<endl;
    m3.print(); 
    cout<<endl;
    cout<<endl;
    cout << "m1 - m2:" << endl; 
    cout<<endl;
    m4.print();
    cout<<endl;
    cout<<endl;
    cout << "m1 * m2:" << endl; 
    cout<<endl;
    cout<<endl;
    m5.print();

cout<<endl;
cout<<endl;
    cout << "+= Operatoru Testi: " << endl; cout<<endl;
    Matrix m8(2, 2), m9(2, 2);
    m8(0, 0) = 1; m8(0, 1) = 2;
    m8(1, 0) = 3; m8(1, 1) = 4;
    cout<<" m8 matrisim: "<< endl;
    m8.print();
    cout<<endl;
    m9(0, 0) = 1; m9(0, 1) = 1;
    m9(1, 0) = 1; m9(1, 1) = 1;
    cout<<" m9 matrisim: "<< endl;
    m9.print();
    m8 += m9;
    cout<<endl;
    cout << "+= Operatoru Testi Sonucu: " << endl;
    m8.print(); 
    cout<<endl;
    cout<<endl;

    cout << "-= Operatoru Testi: "<<endl; cout<<endl;
    Matrix m10(2, 2), m11(2, 2);
    m10(0, 0) = Complex(2,3); m10(0, 1) = Complex(2,3);
    m10(1, 0) = Complex(2,3); m10(1, 1) = Complex(2,3);
    cout<<" m10 matrisim: " << endl;
    m10.print();
    cout<<endl;
    m11(0, 0) = Complex(1,2);; m11(0, 1) =Complex(0,3);;
    m11(1, 0) = Complex(2,1); m11(1, 1) = Complex(1,1);
    cout<<" m11 matrisim: " << endl;
    m11.print();
    cout<<endl;
    m10 -= m11;
    cout << "-= Operatoru Testi Sonucu: " << endl;
    m10.print(); cout<<endl; cout<<endl;


// buna bakilacak
    cout << "*= Operatoru Testi: "<<endl;
   
    cout<<" m11 matrixim : "<<endl;
    m11.print();
     cout<<" m1 matrixim : "<<endl;
     m1.print();
    cout<<endl;
    m1 *= m11;
    cout << "*= Operatoru Testi Sonucu: " << endl;
    m1.print();
    cout<< endl;
    cout<< endl;
    cout << "== Opretaroru Testi: "<<endl;
    cout<<" m8 matrixim: "<<endl;
    m8.print();
    cout<<" m9 matrixim: "<<endl;
    m9.print();
    cout<<endl;
    cout << ((m8 == m9) ? "Esit" : "Esit degil") << endl;

    
    cout << "\nMatrix Transpose and Determinant Tests:" << endl;
    Matrix m6(2, 2);
    m6(0, 0) = Complex(1, 0); // 1
    m6(0, 1) = Complex(0, 1); // i
    m6(1, 0) = Complex(0, -1); // -i
    m6(1, 1) = Complex(2, 0); // 2

    // Transpoze
    Matrix m7 = m6.transpose();

 Matrix mat(3, 3);
    mat(0, 0) = Complex(1, 0);
    mat(0, 1) = Complex(3, 0);
    mat(0, 2) = Complex(3, 0);
    mat(1, 0) = Complex(4, 0);
    mat(1, 1) = Complex(6, 0);
    mat(1, 2) = Complex(6, 0);
    mat(2, 0) = Complex(8, 0);
    mat(2, 1) = Complex(8, 0);
    mat(2, 2) = Complex(9, 0);
    cout<<endl;

    cout << "Matrix:\n";
    mat.print();

    double det = mat.determinant();
    cout << "Determinant: " << det << endl;
    cout<<endl;

    // Bilgileri yazdır
    cout << "Original Matrix:" << endl; m6.print();
    cout<<endl;
    cout << "Transposed Matrix:" << endl; m7.print();

    cout<<"//////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;

    cout<<endl;
    cout<<endl;
   

   Vector v1(3); // Boyutu 3 olan bir vektör oluşturuluyor
    Vector v2(3); // Boyutu 3 olan başka bir vektör oluşturuluyor

    // Elemanları ayarlama
    v1.setElement(0, Complex(4, 2));
    v1.setElement(1, Complex(1, 2));
    v1.setElement(2, Complex(5, 3));

    v2.setElement(0, Complex(4, 8));
    v2.setElement(1, Complex(8, 7));
    v2.setElement(2, Complex(1, 4));

    // Vektörleri yazdırma
    std::cout << "v1: "<<endl;
    v1.print();

    std::cout << "v2: "<<endl;
    v2.print();

    // Vektör boyutunu alma
    size_t size1 = v1.getSize();
    size_t size2 = v2.getSize();
    cout << "v1 size: " << size1 << endl;
    cout << "v2 size: " << size2 << endl;



    // Vektörleri toplama
    Vector v4 = v1 + v2;
    cout << "v1 + v2: ";
    v4.print();

    // Vektörleri çıkarma
    Vector v5 = v1 - v2;
    cout << "v1 - v2: ";
    v5.print();

    

    // Vektörlerin iç çarpımını hesaplama
    Complex dotProduct = v1 * v2;
    cout<< "dot profduct oncesi v1 ve v2 vektorleri : "<<endl;
    cout<<"v1 : "<<endl;
    v1.print();
    cout<<endl;
    cout<<"v2 : "<<endl;
    v2.print();
    cout<<endl;
    cout << "v1 * v2: " << dotProduct <<endl;

    // Vektörleri kopyalama
    Vector v3 = v1;
    cout << "v3 (v1 in kopyasi ): ";
    v3.print();

    // Vektörleri eşitlik kontrolü
    bool isEqual = (v1 == v2);
    cout << "v1 == v2: " << (isEqual ? "esit" : "esit degil") << endl;

    // Vektörlerin toplama ve atama operatörü
     cout << "v1 += v2: islemi oncesi v1 ve v2 : "<<endl;;
    v1.print();
    cout<<endl;
    v2.print();
     cout<<endl;
    v1 += v2;
    cout << "v1 += v2: islemi sonrasi v1 : "<<endl;
    v1.print();
     cout<<endl;
    // Vektörlerin çıkarma ve atama operatörü
     cout << "v1 -= v2: islemi oncesi v1 ve v2 : "<<endl;;
    v1.print();
     cout<<endl;
    v2.print();
     cout<<endl;
    v1 -= v2;
     cout << "v1 -= v2: islemi sonrasi v1 " << endl;
    v1.print();
    cout<<endl;

     cout << "v1 *= c : islemi oncesi v1  "<<endl;
    v1.print();
     cout<<endl;
      cout << "v1 *= c : islemi oncesi c  "<<endl;;
    Complex c(2,2);
    c.print();
    
    v1 *= c;
    cout << "v1 *= c: islemi sonrasi v1 " << endl;
    v1.print();
    cout<<endl;
    cout<<"----------------------------------------------------------------------" << endl;

    SquareMatrix sqMatrix(3);
    sqMatrix(0, 0) = Complex(3, 0);
    sqMatrix(0, 1) = Complex(2, 3);
    sqMatrix(0, 2) = Complex(2, 0);
    sqMatrix(1, 0) = Complex(4, 2);
    sqMatrix(1, 1) = Complex(6, 1);
    sqMatrix(1, 2) = Complex(8, 0);
    sqMatrix(2, 0) = Complex(3, 2);
    sqMatrix(2, 1) = Complex(2, 1);
    sqMatrix(2, 2) = Complex(7, 1);

    cout << "Square Matrix:" << endl;
    sqMatrix.print();

    // IdentityMatrix testi
    IdentityMatrix idMatrix(3);
    cout << "Identity Matrix:" << endl;
    idMatrix.print();

    // TriangleMatrix testi
    TriangleMatrix triMatrix(3, true); // Üst üçgen matris
    cout << "Triangle Matrix (Upper):" << endl;
    triMatrix.print();
    cout<<endl;

    Matrix sumMatrix = sqMatrix + idMatrix;
    cout << " Square + Identity :" << endl;
    sumMatrix.print();
    cout<<endl;


    Matrix multMatrix = sqMatrix * idMatrix;
    cout << "Carpim (Square * Identity):" << endl;
    multMatrix.print();
    cout<<endl;

Matrix triTranspose = triMatrix.transpose();
cout << "Triangle Transpose:" << endl;
triTranspose.print();


cout<<endl;

double detTri = triMatrix.determinant();
cout << "Triangle Matrixin determinanti : " << detTri << endl;




    return 0;
}


