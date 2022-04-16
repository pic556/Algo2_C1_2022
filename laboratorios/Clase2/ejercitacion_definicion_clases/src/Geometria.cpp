#include <iostream>

using namespace std;

using uint = unsigned int;

// Ejercicio 1

class Rectangulo {
    public:
        Rectangulo(uint alto, uint ancho);
        uint alto();
        uint ancho();
        float area();


    private:
        int alto_;
        int ancho_;

};

Rectangulo::Rectangulo(uint alto, uint ancho) : alto_(alto),ancho_(ancho){
};
//utilizo en privado y en privado de alto_ puse la variable alto//ancho analogo ,ahora que arme
//mi esquema con rectangulo puedo usarlo en funciones posteriores

uint Rectangulo::alto() {
    return this->alto_;
}
// regreso lo que coloco en privado ,llamando a alto() a travez de rectangulo y pidiendo un uint

// Completar definición: ancho
uint Rectangulo::ancho() {
    return this->ancho_;
}
// Completar definición: area
float Rectangulo::area() {
    return this->ancho_*alto_;
}
// Ejercicio 2

// Clase Elipse
//primero hice la clase ,vi como es la escritura de lo publico ,privado y sus llamados
class Elipse {
    public:
        Elipse(uint a, uint b);
        uint r_a();
        uint r_b();
        float area();

    private:
        int r_a_;
        int r_b_;
};
//todo lo de abajo es la interfaz
Elipse::Elipse(uint a, uint b):r_a_(a),r_b_(b){};

uint Elipse::r_a(){
    return this->r_a_;
}
uint Elipse::r_b(){
    return this->r_b_;
}
float Elipse::area(){
    float PI = 3.14;
    return PI * r_a_ * r_b_;
}


// Ejercicio 3

class Cuadrado {
    public:
        Cuadrado(uint lado);
        uint lado();
        float area();

    private:
        Rectangulo r_;
};

Cuadrado::Cuadrado(uint lado): r_(lado, lado) {}
//define cuadrado con lado tanto para ancho como alto
//luego en privados solo entra Rectangulo que es una clase que ya definimos
// que tiene alto y ancho

uint Cuadrado::lado() {
    return this-> r_.alto();
}//lamo a otra clase que anda por privado y saco el alto

float Cuadrado::area() {
    return this-> r_.area() ;
}//lo mismo con la altura

// Ejercicio 4
// Clase Circulo
class Circulo {
public:
    Circulo(uint lado);
    uint radio();
    float area();

private:
    Elipse e_;
};
// 2 radios necesitabas para usar la clase Elipse
Circulo::Circulo(uint radio):e_(radio,radio){}

uint Circulo::radio(){
    return this-> e_.r_a();
}

float Circulo::area(){
     return this-> e_.area();
}


// Ejercicio 5

ostream& operator<<(ostream& os, Rectangulo r) {
    os << "Rect(" << r.alto() << ", " << r.ancho() << ")";
    return os;
}

// ostream Elipse
ostream& operator<<(ostream& os, Elipse e) {
    os << "Elipse(" << e.r_a()<< ", " << e.r_b() << ")";
    return os;
}
// Ejercicio 6

ostream& operator<<(ostream& os, Circulo c) {
    os << "Circ(" << c.radio()  << ")";
    return os;
}

ostream& operator<<(ostream& os, Cuadrado cu) {
    os << "Cuad(" << cu.lado()  << ")";
    return os;
}