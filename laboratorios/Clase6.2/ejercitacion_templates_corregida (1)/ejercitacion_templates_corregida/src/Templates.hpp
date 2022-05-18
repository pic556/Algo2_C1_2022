using namespace std;

/*
Convertir la función int doble(int) en una función genérica que dependa de un
 parámetro class T (usando template<class T>) de tal manera que permita operar sobre cualquier tipo numérico. Para esto,
 crear un archivo Templates.hpp en la carpeta src
 *
 */
template<class T>
T cuadrado(T x) {
return  x * x;
}

template<class Contenedor, class Elem>
bool contiene(Contenedor s, Elem c) {
    for (int i = 0; i < s.size(); i++) {
        //SI RECORRO EL CONTENEDOR Y VEO QUE UNO DE SUS ELEMENTOS ES IGUAL A ELEM
        //ENTONCES ESTA CONTENIDO
        if (s[i] == c) {
            return true;
        }
    }
    return false;
}

template<class Contenedor>
bool esPrefijo(Contenedor a, Contenedor b) {
    if (a.size() >= b.size()) return false;
    int i = 0;
    while (i < a.size()) {
        if (a[i] != b[i]) return false;
        i++;
    }
    return true;
}


template<class Contenedor, class Elem>
Elem maximo(Contenedor c) {
    Elem m = c[0];
    int i = 1;
    while (i < c.size()) {
        if (m < c[i]) m = c[i];
        i++;
    }
    return m;
}