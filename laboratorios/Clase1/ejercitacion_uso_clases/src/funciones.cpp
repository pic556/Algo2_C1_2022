#include <vector>
#include "algobot.h"

using namespace std;

// Ejercicio 1
int cant_rep(vector<int> s,int n){
    int j = 0;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i]==n){
            j++;
        }
    }
    return j;
}

vector<int> quitar_repetidos(vector<int> s) {
    vector<int> sin_rep;
    for (int i = 0; i < s.size(); ++i) {
        if(cant_rep(sin_rep,s[i])==0){
            sin_rep.push_back(s[i]);
        }
    }
    return sin_rep;
}

// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {
    set<int> c;
    vector<int> res_2;
    for (int i = 0; i < s.size(); ++i) {
        if(c.count(s[i])==0){ //reviso que no esten en mi conjunto
            c.insert(s[i]); //inserto en mi conjunto y quede solo los unicos que no se repiten
            res_2.push_back(s[i]); // y con eso meto en un nuevo vector
        }
    }
    return res_2;
}

// Ejercicio 3
bool mismos_elementos(vector<int> a, vector<int> b) {
    set<int> c1,c2;
    int v = 0;
    for (int i_1 = 0; i_1 < a.size(); ++i_1) {
        c1.insert(a[i_1]);
    }
    for (int i_2 = 0; i_2 < b.size(); ++i_2) {
        if(c1.count(b[i_2])==1){
            v++;
        }
    }
    return v==c1.size();
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    set<int> c1,c2;
    int v = 0;
    for (int i_1 = 0; i_1 < a.size(); ++i_1) {
        c1.insert(a[i_1]);
    }
    for (int i_2 = 0; i_2 < b.size(); ++i_2) {
        if(c1.count(b[i_2])==1){
            v++;
        }
    }
    return v==c1.size();
}


// Ejercicio 5
map<int, int> contar_apariciones(vector<int> s) {
    map<int, int>  m;
    for (int i = 0; i < s.size(); ++i) {
        m[s[i]]=cant_rep(s,s[i]); // defino algo en el diccionario m[s[1]]= #apariciones de 1 en s
    }
    return m;
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {
    vector<int> no_num_rep;
    for (int i = 0; i < s.size(); ++i) {
        if(cant_rep(no_num_rep,s[i])==0 & cant_rep(s,s[i])==1){
            no_num_rep.push_back(s[i]);
        }
    }
    return no_num_rep;
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    set<int> res_7;
    for ( set<int>::iterator i=a.begin(); i!=a.end();i++) { //defino a i como iterador de conjunto de enteros
        if (b.count(*i)==1){  //la forma de ingresar a la variable es con *i
            res_7.insert(*i); //inserto en el nuevo conjunto
        }
    }
    return res_7;
}

// Ejercicio 8
set<int> conju_del_digito_menos_sig(vector<int> s,int n){
    set<int> res_c8;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i] % 10 == n){
            res_c8.insert(s[i]);
        }
    }
    return res_c8;
}

map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    map<int, set<int>> res_8;
    for (int i = 0; i < s.size() ; ++i) {
        res_8[s[i] % 10] = conju_del_digito_menos_sig(s,s[i] % 10);
    }
    return res_8;
}

// Ejercicio 9

char caracter_Traductido(vector<pair<char, char>> tr , char ch){
    for (int i = 0; i < tr.size(); ++i) {
        if (tr[i].first==ch){
            return tr[i].second;
        }
    } return ch;
}

vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    vector<char> res_9;
    for (int i = 0; i < str.size(); ++i) {
        str[i]=caracter_Traductido(tr,str[i]);
    }
    res_9 = str;
    return  res_9;
}

// Ejercicio 10

bool integrantes_repetidos(vector<Mail> s) {
    for (Mail m1: s) {
        for (Mail m2: s) {
            if (m1.libretas() != m2.libretas()) {
                for (LU libreta: m1.libretas()) {
                    if (m2.libretas().count(libreta) > 0) return true;
                }
            }
        }
    }
    return false;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
    map<set<LU>, Mail> res;
    for(Mail m1 : s) {
        if ((res.count(m1.libretas()) == 0) || res[m1.libretas()].fecha() < m1.fecha() && m1.adjunto())
            res[m1.libretas()] = m1;
    }
    return res;
}