#include "Lista.h"

Lista::Lista() : _first(NULL), _last(NULL), _long(0) {}
//mi constructor por defecto va a ser con el primero y final estando vacios
// una longitud 0  ya que no tiene que haber ningun elemento.

Lista::Lista(const Lista& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

Lista::~Lista() {
    while (_first != nullptr) {
        // mientras el primero de la lista sea distinto de null hago
        Nodo *n = _first;
        // obtengo el lugar donde se apunta  el nodo n y asigno que es primero
        _first = _first->_next;
        // primero ahora es el siguiente
        _long--;
        //la longitud le voy restando 1 en 1
        delete n;
        // borro el nodo n,
    }
}


Lista& Lista::operator=(const Lista& aCopiar) {
    // al puntero nodo first lo igualo con acopiar first
    Nodo* first = (aCopiar._first);
    // por el largo que tenga en acopiar
    for(int i = 0; i < (aCopiar._long);i++){
        // itero hasta llegar al largo de a copiar
        agregarAtras(first->_data);
        // agrego atras la data de first
        first = (first)->_next;
        //first es igual a la siguiente de first
    }
    _long = aCopiar._long;
    // igual el largo de copia con el de privado de lista//
}
//[1,2,3,4]
//agrego atras [1]
//agregro atras[1,2]
//agrego atras[1,2,3]
//agrego atras[1,2,3,4]



void Lista::agregarAdelante(const int& elem) {
    //tengo un nuevo nodo n donde cargo ese elemento
    Nodo *n = new Nodo(elem);
    //otro nodo primero donde digo que es igual al first nodo
    Nodo *primero = _first;
    //del  nodo n voy al next = primero osea que vale ahora firts
    // el next de n vale  primero
    n->_next = primero;
    //first digo que es igual a n
    _first = n;
    //aumento la longitud 1 a 1
    _long++;
    //si primero es nulo el last = first
    //sino lo es el back de primero = n
    if (primero != nullptr) {
        primero-> _back = n;
    } else {
        _last = _first;
    }
}
// n = [|elem|]
// p = [||]_first
// n = [p|elem|] = [[||]_first | elem |]
// [||]_first = n = [|elem|]
// long+1
//si primero no es vacio
    // p = [||]_first.back = n --> [n||]_first = [elem||]_first
//si primero es vacio
    //[||]_last =  [||]_first = [|elem|]


void Lista::agregarAtras(const int& elem) {
    Nodo *n = new Nodo(elem);
    Nodo *ultimo = _last;
    n->_back = ultimo;
    _last = n;
    _long++;
    if (ultimo != nullptr) {
        ultimo -> _next = n;
    } else {
        _first = _last;
    }
}
// n = [|elem|]
// u = [||]_last
// n = [|elem|u] = [| elem | [||]_last]
// [||]_last = n = [|elem|]
// long+1
//si primero no es vacio
// u = [||]_last.next = n --> [||n]_last = [||elem]_last
//si primero es vacio
//[||]_first =  [||]_last = [|elem|]

void Lista::eliminar(Nat i) {
    // puntero nodo n  = [||]_first
    Nodo *n = _first;
    // si i == 0
    if (i == 0){
        //  n  = [||]_first
        Nodo* n = _first;
        //   [||]_first = [||!!!!]_first.next
        _first = _first->_next;
        //long -1
        _long--;
        // borras n ,borras  [||]_first
        delete n;
        //  si i!=0
    } else {
        // p = 0
        int p = 0;
        // si p es menor o igual a i  y n  no sea null
        while ( p <= i && (n != nullptr)) {
            // si p es distinto de i
            if (p != i) {
                // n  = [||!!!!]_first
                n = n-> _next;
            } else {
                // p == i
                //n  = [!!!!!||nose]_first
                if (n->_back != nullptr) {
                    //la parte de atras siguiente es cambianda por el siguiente general de n
                    (n->_back)->_next = n-> _next;
                }
                //n  = [nose||!!!!!]_first
                if (n->_next != nullptr) {
                    //la parte aldenta de atras  es cambianda por la parte de atras en general de n
                    (n->_next)-> _back = n-> _back;
                }
                //borro n
                delete n;
                //long-1
                _long--;
            }
            //aumento en 1 p
            p++;
        }
    }
}

/*
 * [0,1,2,3] i = 2
 * n= first
 * p=0 y p <=2 y n no es null
 * p!=1
 * n=n.siguiente[1]
 * p=1
 * n=n.siguiente[2]
 * p=2
 * n.back != nullo
 * n.back.next [2]  = n.next  [3]osea  te posicionas en el siguiente
 * [0,1,3]
 * borrar n ,osea borro 2
 * longitud resto 1
 *
 *
 * si i= 0 y [0]
 * n=first
 * first = first.next
 * long -1
 * borrar n
 * y solo queda el siguiente que aca es vacio
 */

int Lista::longitud() const {
    return _long;
}


const int& Lista::iesimo(Nat i) const {
    // digo n = primero del nodo
    Nodo* n = _first;
    // con j = 0
    int j = 0;
    // mientras j sea menor a i
    while (j < i){
        // yo en n avanzo al siguiente del nodo n
        n = n -> _next;
        // j aumento en 1
        j++;
    }
    // regreso la data que obtengo de n
    return n -> _data;
}


int& Lista::iesimo(Nat i) {
    Nodo* n = _first;
    int j = 0;
    while (j < i){
        n = n -> _next;
        j++;
    }
    return n -> _data;
}
//el mismo

void Lista::mostrar(ostream& o) {
    // Completar
}
