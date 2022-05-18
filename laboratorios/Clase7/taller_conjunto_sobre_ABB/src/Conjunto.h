#ifndef CONJUNTO_H_
#define CONJUNTO_H_

#include <assert.h>
#include <string>
#include <iostream>

using namespace std;

template <class T>
class Conjunto
{
    public:

        // Constructor. Genera un conjunto vacío.
        Conjunto();

        // Destructor. Debe dejar limpia la memoria.
        ~Conjunto();

        // Inserta un elemento en el conjunto. Si este ya existe,
        // el conjunto no se modifica.
        void insertar(const T&);

        // Decide si un elemento pertenece al conjunto o no.
        bool pertenece(const T&) const;

        // Borra un elemento del conjunto. Si este no existe,
        // el conjunto no se modifica.
        void remover(const T&);

        // Siguiente elemento al recibido por párametro, en orden.
        const T& siguiente(const T& elem);

        // Devuelve el mínimo elemento del conjunto según <.
        const T& minimo() const;

        // Devuelve el máximo elemento del conjunto según <.
        const T& maximo() const;

        // Devuelve la cantidad de elementos que tiene el conjunto.
        unsigned int cardinal() const;

        // Muestra el conjunto.
        void mostrar(std::ostream&) const;

    private:

        /**
         * Completar con lo que sea necesario...
         **/

        struct Nodo
        {
            // El constructor, toma el elemento al que representa el nodo.
            Nodo(const T& v);
            // El elemento al que representa el nodo.
            T _valor;
            // Puntero a la raíz del subárbol izquierdo.
            Nodo* _izq;
            // Puntero a la raíz del subárbol derecho.
            Nodo* _der;
        };

        // Puntero a la raíz de nuestro árbol.
        Nodo* _raiz;
        int length;
        //Defino el largo del arbol PARA DEFINIR EL CONTRUCTOR
        void destructorNodo(Nodo*);
        //Defino al destructor de NOdo para ayudar a DESTRUCTOR
        bool perteneceAux(const T& ,Nodo*)const;
        //Defino el pertenece auxiliar para ayudar a PERTENECE
        void insertarAux(Nodo*&, const T&);
        //Defino el insertar  auxiliar para ayudar a INSERTAR
        void removerAux(Nodo* n, const T& clave, Nodo* padre);
        //defino remover auxiliar para ayudar a REMOVER
        const T& maximoNodo(Nodo*)const;
        const T& minimoNodo(Nodo*)const;
        //maximo y minimo nodo me ayudara para distintas clases
        const T& siguienteAux(const T& clave ,Nodo* n, vector<Nodo*> v) const;
        //Defino el siguiente auxiliar para ayudar a sigiuiente
        unsigned int cardinalAux(Nodo*) const;
        // defino el cardinaaux

};

template<class T>
std::ostream& operator<<(std::ostream& os, const Conjunto<T>& c) {
	 c.mostrar(os);
	 return os;
}

#include "Conjunto.hpp"

#endif // CONJUNTO_H_
