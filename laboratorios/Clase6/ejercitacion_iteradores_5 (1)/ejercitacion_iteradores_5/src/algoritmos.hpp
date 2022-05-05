#ifndef ALGO2_LABO_CLASE5_ALGORITMOS_H
#define ALGO2_LABO_CLASE5_ALGORITMOS_H

#include <utility>
#include <iterator>
#include <vector>
#include <iostream>
using namespace std;


//Ejercicio 1

/*
implementar esto
    template<class Contenedor>
    typename Contenedor::value_type minimo(const Contenedor &c)
se asumia la existencia de esto
•   bool operator<(const Contenedor::value_type&, const Contenedor::value_type&)
•   Contenedor::const_iterator Contenedor::begin() const
•   Contenedor::const_iterator Contenedor::end() const
 */


template<class Contenedor>
typename Contenedor::value_type minimo(const Contenedor &c) {
    //Que devuelva el elemento mínimo del contenedor, suponiendo que la colección no es vacía
    typename Contenedor::const_iterator min = c.begin();
    //armo mi iterador
    //digo que min=el primero(begin)
    for (typename Contenedor::const_iterator it = c.begin(); it != c.end(); ++it) {
        //ahora es un ciclo ,empieza hasta que sea fin
        if (*it < *min) {
            // este puntero que va al it es menor al minimo puntero  ,entonces min es it
            min = it;
        }
    }
    return *min;
    //apunto a su direccion de memoria
}





//Ejercicio 2

/*
Implementar la función:
    template<class Contenedor>
    typename Contenedor::value_type promedio(const Contenedor& c);
se asume la existencia de:
    Contenedor::const_iterator Contenedor::begin() const
    Contenedor::const_iterator Contenedor::end() const
    Contenedor::value_type es un tipo numérico, cuyos valores se pueden sumar y dividir por un entero no
    nulo
 */
template<class Contenedor>
typename Contenedor::value_type promedio(const Contenedor &c) {
    //Que devuelva el promedio de los elementos del contenedor, suponiendo que la colección no es vacía.
    typename Contenedor::value_type suma = 0;
    //declaro mi variable suma iniciandola en 0 que es de tipo T
    int length = 0;
    //declaro mi variable longintud en 0
    for (typename Contenedor::const_iterator it = c.begin(); it != c.end(); ++it) {
        //declaro it y empiezo a iterar
        suma = suma + *it;
        //voy sumando a donde apunta el iterador en sud que es de tipo typename
        length++;
        //sumo a 1 la logintd
    }
    return suma / length;
}      //la cuenta clasica de promedio

//Ejercicio 3
/*
Implementar las funciones análogas a los ejercicios 1 y 2 pero esta vez recibiendo iteradores:
    *template<class Iterator>
    typename Iterator::value_type minimoIter(const Iterator& desde, const Iterator& hasta);
    *template<class Iterator>
    typename Iterator::value_type promedioIter(const Iterator& desde, const Iterator& hasta);
 */
template<class Iterator>
typename Iterator::value_type minimoIter(const Iterator &desde, const Iterator &hasta) {
    //busco el minimo [desde ,hasta]
    Iterator min = desde;
    // empiezo declarando variables como iterator min = desde
    for (Iterator it = desde; it != hasta; ++it) {
        //empiezo en desde hasta "hasta"
        if (*it < *min) {
            //misma logica que en el 1
            min = it;
        }
    }
    return *min;
    //logica del 1 a donde apunta el min
}

template<class Iterator>
typename Iterator::value_type promedioIter(const Iterator &desde, const Iterator &hasta) {
    typename Iterator::value_type suma = 0;
    int length = 0;
    for (auto it = desde; it != hasta; ++it) {
        suma = suma + *it;
        length++;
    }
    return suma / length;
}
//lo mismo que  anterior solo que analizando los iteradores y usando AUTO


//Ejercicio 4
/*
Implementar una función que dado un contenedor y un elemento del tipo guardado en el mismo,
 modifique el contenedor recibido por parámetro eliminando todas las apariciones del elemento parámetro.
 La función tendrá la siguiente aridad:

template<class Contenedor>
void filtrar(Contenedor &c, const typename Contenedor::value_type& elem);

 Se aumen las siguientes funciones del contenedor y su iterador:
• Contenedor::iterator Contenedor::begin()
• Contenedor::iterator Contenedor::end()
• Contenedor::iterator Contenedor::erase(Contenedor::iterator)
• bool operator==(const Contenedor::value_type&, const Contenedor::value_type&)
El iterador resultado de erase se encuentra ubicado en la posición siguiente al elemento eliminado.

 */


template<class Contenedor>
void filtrar(Contenedor &c, const typename Contenedor::value_type &elem) {
    // 2 variables ,una contenedor y otra elemento
    for (typename Contenedor::iterator it = c.begin(); it != c.end(); ++it) {
        // aca devuelta al for
        if (elem == *it) {
            //si el elem == a la direccion del iterador
            //c.erase(it--);
            it = c.erase(it);
            it--;
            //lo borro y restocedo
        }
    }
}

//Ejercicio 5


/*
Implementar una función que decida si los elementos —dispuestos en el orden en el que los devuelve el iterador—
están ordenados de manera estrictamente creciente.
    template<class Contenedor>
    bool ordenado(Contenedor &c);
Se asumen las mismas condiciones que el ejercicio 1.

 */
template<class Contenedor>
bool ordenado(Contenedor &c) {
    bool res = true;
    //ya me planteo un boolenao
    typename Contenedor::const_iterator mayor = c.begin();
    //la variable mayor empieza siendo el comienzo
    mayor++;
    for (typename Contenedor::const_iterator menor = c.begin(); mayor != c.end(); ++menor) {
        //menor aca siendo un iterador de prinipio hasta que sea distinto del final
        if (*menor > *mayor) {
            //el menor direccion  es mayor  que el mayor direccion ?
            res = false;
            //si es asi falso
            break;
        }
        ++mayor;
        //sino aumento al mayor
    }
    return res;
}


/*
Implementar una operación que dado un contenedor y un elemento devuelva una tupla con dos nuevos contenedores
del mismo tipo que el recibido por parámetro. El primer contenedor deberá tener todos los elementos menores al
elemento. El segundo deberá tener los elementos mayores o iguales. La aridad será la siguiente:

    template<class Contenedor>
    std::pair<Contenedor, Contenedor> split(const Contenedor & c, const typename Contenedor::value_type& elem)
Se asumen las siguientes funciones:

• bool operator<(const Contenedor::value_type&, const Contenedor::value_type&)
• Contenedor::const_iterator Contenedor::begin() const
• Contenedor::const_iterator Contenedor::end() const
• Contenedor::iterator Contenedor::insert(const Contenedor::const_iterator&, const Contenedor::value_type&) const


 */
//Ejercicio 6
template<class Contenedor>
pair<Contenedor, Contenedor> split(const Contenedor &c, const typename Contenedor::value_type &elem) {
    // defino el primer contenedor
    Contenedor prim;
    //defino el segundo contenedor
    Contenedor seg;
    // empezamos el for y el iterador
    for (typename Contenedor::const_iterator it = c.begin(); it != c.end(); ++it) {
        if (*it < elem) {
            //si la direccion del iterador es menor al elemento
            prim.insert(prim.end(), *it);
            //inserto en el primero esa direccion del iterador
        } else {
            seg.insert(seg.end(), *it);
            //sino segunda
        }
    }
    pair<Contenedor, Contenedor> res = make_pair(prim, seg);
    //hago la tupla y returnamos
    return res;
}


/*
Implementar una función que dados tres contenedores del mismo tipo, agregue los elementos de los primeros dos
al final del tercero. Se asume como precondición que los elementos de c1 y c2 se encuentran ordenados de manera
creciente (no necesariamente estricta). Los elementos se deben agregar a res de manera creciente (no estricta).
Por ejemplo, si c1 es la lista [10, 11, 15] y c2 es la lista [5, 7, 13, 20], se deben agregar a res los elementos
[5, 7, 10, 11, 13, 15, 20] en ese orden.

    template <class Contenedor>
    void merge(const Contenedor& c1, const Contenedor & c2, Contenedor & res);

Se asume sobre Contenedor lo mismo que en el ejercicio 6.
 */
//Ejercicio 7
template<class Contenedor>
void merge(const Contenedor &c1, const Contenedor &c2, Contenedor &res) {
    typename Contenedor::const_iterator itc1 = c1.begin();
    typename Contenedor::const_iterator itc2 = c2.begin();
    while (itc1 != c1.end() and itc2 != c2.end()) {
        if (*itc1 <= *itc2) {
            res.insert(res.end(), *itc1);
            itc1++;
        } else {
            res.insert(res.end(), *itc2);
            itc2++;
        }
    }
    if (itc1 == c1.end() and itc2 != c2.end()) {
        while (itc2 != c2.end()) {
            res.insert(res.end(), *itc2);
            itc2++;
        }
    } else {
        while (itc1 != c1.end()) {
            res.insert(res.end(), *itc1);
            itc1++;
        }
    }
}


#endif //ALGO2_LABO_CLASE5_ALGORITMOS_H
