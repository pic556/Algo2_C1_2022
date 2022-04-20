#ifndef _LISTA_ALUMNOS_H_
#define _LISTA_ALUMNOS_H_

#include <string>
#include <ostream>

using namespace std;

typedef unsigned long Nat;

class Lista {
public:

    /**
     * Constructor por defecto de la clase Lista.
     */
    Lista();

    /**
     * Constructor por copia de la clase Lista.
     */
    Lista(const Lista& l);

    /**
     * Destructor de la clase Lista.
     */
    ~Lista();

    /**
     * Operador asignacion
     * @param aCopiar
     * @return
     */
    Lista& operator=(const Lista& aCopiar);

    /**
     * Agrega un elemento al principio de la Lista.
     * @param elem elemento a agregar
     */
    void agregarAdelante(const int& elem);

    /**
     * Agrega un elemento al final de la Lista.
     * @param elem elemento a agregar
     */
    void agregarAtras(const int& elem);

    /**
     * Elimina el i-ésimo elemento de la Lista.
     * @param i posición del elemento a eliminar
     */
    void eliminar(Nat i);

    /**
     * Devuelve la cantidad de elementos que contiene la Lista.
     * @return
     */
    int longitud() const;

    /**
     * Devuelve el elemento en la i-ésima posición de la Lista.
     * @param i posición del elemento a devolver.
     * @return referencia no modificable
     */
    const int& iesimo(Nat i) const;
    /**
     * Devuelve el elemento en la i-ésima posición de la Lista.
     * @param i posición del elemento a devolver.
     * @return referencia modificable
     */
    int& iesimo(Nat i);

    /**
     * Muestra la lista en un ostream
     * formato de salida: [a_0, a_1, a_2, ...]
     * @param o
     */
    void mostrar(ostream& o);

    /**
     * Utiliza el método mostrar(os) para sobrecargar el operador <<
     */
    friend ostream& operator<<(ostream& os, Lista& l) {
        l.mostrar(os);
        return os;
    }

private:


    struct Nodo {
        Nodo(const int& data):_next(NULL), _back(NULL), _data(data) {}
        //aca coloco mi Constructor que voy a usar muchas veces
        // ya que estamos en una struc
        Nodo* _next;
        // apuntando al tipo nodo diciendole que es un next(siguiente)
        Nodo* _back;
        // lo mismo pero con back (atras)
        int _data;
        // ahora digo que la data que tiene que haber debe ser entero
    };//aca define variables y funciones del nodo que usare reiterativamente

    //porque nodo no es una clase puedo aun llamarlo , ya que siempre
    // sus variables son "publicas"
    Nodo* _first;//primera parte del nodo(con apuntando  a un tipo nodo)
    Nodo* _last; //ultima parte del nodo( "" "" "" "")
    int _long;// que tan largo es el nodo
};

#include "Lista.hpp"

#endif
