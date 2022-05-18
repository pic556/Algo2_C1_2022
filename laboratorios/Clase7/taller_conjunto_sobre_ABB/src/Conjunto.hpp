#include <vector>


template <class T>
Conjunto<T>::Conjunto():_raiz(nullptr), length(0){}
//la raiz debe estar vacia y el largo debe ser 0


template <class T>
Conjunto<T>::~Conjunto() {
    destructorNodo(_raiz);
    //meto la raiz en el destructorNodo
}

template<class T>
void Conjunto<T>::destructorNodo(Nodo* n) {
    //si el nodo no es un vacion ENTONCES
    if(n!=nullptr){
        destructorNodo(n->_der);
        //me meto el nodo de dereche x metodo recursivo
        destructorNodo(n->_izq);
        //me meto en nodo de izquierda x metodo recursivo
        delete n;
        //borro el nodo
    }
}

//hice yo
template <class T>
Conjunto<T>::Nodo::Nodo(const T &v) :_valor(v),_izq(nullptr),_der(nullptr){};
//este seria un nodo vacio ,uno nuevo

template <class T>
bool Conjunto<T>::pertenece(const T &clave) const {
    //aca meto la funcion perteneceAux usando la clave y la raiz a evaluar osea ese nodo raiz
    return perteneceAux(clave, _raiz);
}

template <class T>
bool Conjunto<T>::perteneceAux(const T& clave ,Nodo* n) const {
    // inicial el resultado con falso
    bool res = false;
    //veo si el nodo no es vacio
    if(n != nullptr) {
        //el valor del nodo es igual a la clave
        if ((n->_valor) == clave) {
            //entonces es verdadero
            res = true;
            //sino
        } else {
            // si la clave tiene un valor mayor al valor de n ,entonces
            if(clave > n->_valor) {
                //veo por derecha que es lo que pása de manera recursiva
                res = perteneceAux(clave, (n->_der));
            } else {
                //sino veo por izquiersa de manera recursiva
                res = perteneceAux(clave, (n->_izq));
            }
        }
    }
    return res;
}


template <class T>
void Conjunto<T>::insertar(const T& clave) {
    //sino pertence al nodo
    if(!pertenece(clave)){
        //entonces inserto
        insertarAux(_raiz, clave);
    }
}

template <class T>
void Conjunto<T>::insertarAux(Nodo*& n, const T& clave) {
    //me fijo si el nodo no es vacion
    if(n!=nullptr){
        //sino es veo si el valor del nodo es mayor que la clave
        if((n->_valor) > clave){
            //si es asi por derecha
            insertarAux((n->_izq),clave);
        }else{
            //sino por izquierda
            insertarAux((n->_der), clave);
        }
    }else{
        //hago un nuevo nodo donde meto la clave
        n = new Nodo(clave);
    }
}


template <class T>
void Conjunto<T>::remover(const T& clave) {
    //me fijo si la clave pertenece al doo
    if(pertenece(clave)){
        //si es asi hago un nuevo nodo vacio que llamare padre
        Nodo* padre = nullptr;
        //entonces meto todo mas la raiz en removerauxiliar
        removerAux(_raiz, clave, padre);
    }
}

template <class T>
void Conjunto<T>::removerAux(Nodo* n, const T& clave, Nodo* padre) {
    // si el valor de es igual al de la clave
    if ((n->_valor) == clave) {
        //si el valor de n por izquierda es vacio y derecha tambien
        if ((n->_izq) == nullptr && (n->_der) == nullptr) {
            //si es vacio el padre
            if (padre == nullptr){
                // entonces la raiz es vacia
                _raiz = nullptr;
            }else{
                //sino es vacio el padre ,me fijo si el padre por derecha es igual al nodo
                if(padre->_der == n){
                    //entonces asigno que el padre de la derecha deba ser vacio
                    padre->_der = nullptr;
                }else{
                    //si el padre por izquierda  es igual al nodo ,le asigno vacio
                    padre->_izq = nullptr;
                }
            }
            //ahora borro n
            delete n;
        }else{
            // si el valor de n por izquierda es vacio pero por derecha nodo
            if ((n->_izq) == nullptr && (n->_der) != nullptr) {
                //al n valor asigno el minimo nodo de derecha
                n->_valor = minimoNodo(n->_der);
                //padre asigno como n
                padre = n;
                //hago recursion con n de derecha , n valor y el padre
                removerAux(n->_der, n->_valor, padre);
            }else{
                //sino digo el valor de n es como el maximo de n izquierda
                n->_valor= maximoNodo(n->_izq);
                //padre tiene el valor de n
                padre = n;
                //recursion con n porizquierda ,n valor y padre
                removerAux(n->_izq, n->_valor, padre);
            }
        }
    }else{
        // si el valor de n  no es igual al de la clave
        //padre locoloc con el valor de n
        padre = n;
        if ((n->_valor) > clave) {
            //si el valor de n es mayor a la clave veo por izquierda
            removerAux((n->_izq), clave, padre);
        } else {
            //si el valor de n es menor entonces veo por derecha
            removerAux((n->_der), clave, padre);
        }
    }
}

template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    //inicializo un vector v que contenga nodos
    vector<Nodo*> v;
    return siguienteAux(clave, _raiz, v);
}

template <class T>
const T& Conjunto<T>::siguienteAux(const T& clave ,Nodo* n, vector<Nodo*> v) const {
    //inicilizo un nodo res que valga n , osea raiz
    Nodo *res = n;
    //if el valor de n es igual a la clave
    if (n->_valor== clave) {
        //si n de la derecha no es vacio
        if((n->_der) != nullptr) {
            //res digo es que es res de derecha
            res = res->_der;
            //hago que retorne el minimo osea el lado mas izquierdo xq acordate que estas en raiiz
            return minimoNodo(res);
        } else {
            //si n valor  no es igual a la clave
            int i = 0;
            //inicilizo un i
            //mientra n valor sea mayor a uno de los valores de los nodos dentro del voctor
            while((n->_valor) > (v[i]->_valor)){
                i++;
            };
            //regreso el nodo que sea mayor a n valor y retorno su valor
            return v[i]->_valor;
        }
        //if el valor de n no es igual a la clave
    } else {
        //agrego al vector de nodos res osea n
        v.push_back(res);
        //la vlave es mayor al valor de n
        if (clave > n->_valor) {
            //veo por derecha
            return siguienteAux(clave, (n->_der), v);
        } else {
            //veo por izquierda sino
            return siguienteAux(clave, (n->_izq), v);
        }
    }
}


template <class T>
const T& Conjunto<T>::maximoNodo(typename Conjunto<T>::Nodo* n)const {
    //mientras el lado derecho de n no sea vacio me apunto a su derecha
    while(n->_der != nullptr){
        n = n->_der;
    }
    return (*n)._valor;
}

template <class T>
const T& Conjunto<T>::minimoNodo(typename Conjunto<T>::Nodo* n)const {
    //mientras el lado izquierdo de n no sea vacio me apunto a su izquierda
    while(n->_izq != nullptr){
        n = n->_izq;
    }
    return (*n)._valor;
}


template <class T>
const T& Conjunto<T>::minimo() const {
    Nodo *res = _raiz;
    while(res->_izq != nullptr){
        res = res->_izq;
    }
    return (*res)._valor;
}

template <class T>
const T& Conjunto<T>::maximo() const {
    Nodo *res = _raiz;
    while(res->_der != nullptr){
        res = res->_der;
    }
    return (*res)._valor;
}

template <class T>
unsigned int Conjunto<T>::cardinal() const {
    return cardinalAux(_raiz);
}

template <class T>
unsigned int Conjunto<T>::cardinalAux(Nodo* n) const{
    unsigned int res = 0;
    if(n != nullptr){
        res = 1 + cardinalAux(n->_izq) + cardinalAux(n->_der);
    }
    return res;
}


template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {
    assert(false);
}

