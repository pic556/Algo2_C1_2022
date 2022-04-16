#include "gtest-1.8.1/gtest.h"
#include "../src/Libreta.h"
#include "../src/Truco.h"
#include <map>
#include <cmath>

using namespace std;

// Ejercicio 4
TEST(Aritmetica, suma) {
    int valor_calculado = 15 +7;
    int valor_esperado = 22;
    EXPECT_EQ(valor_calculado,valor_esperado);
}

// Ejercicio 5
TEST(Aritmetica, potencia) {
    int x;
    float  valor_calculado = pow(10, 2) ;
    int valor_esperado=100;
    EXPECT_EQ(valor_calculado,valor_esperado);
}

// Ejercicios 6..9
TEST(Aritmetica, potencia_general) {
    for (int i = -5; i <= 5; ++i) {
        if (i != 0) {
            EXPECT_EQ(pow(i, 2), i * i);
        }
    }
}

TEST(Diccionario, obtener) {
    map<int, int> d;
    d.insert(make_pair(1,1));
    EXPECT_EQ(d.at(1), 1);
}


TEST(Map, definir) {
    map<int, int> m;
    EXPECT_EQ(m.count(5), 0);
    m.insert(make_pair(5, 10));
    EXPECT_EQ(m.count(5), 1);
}

TEST(Truco, inicio) {
    Truco t;
    EXPECT_EQ(t.puntaje_j1(), 0);
    EXPECT_EQ(t.puntaje_j2(), 0);
}

TEST(Truco, buenas) {
    Truco t;
    EXPECT_FALSE(t.buenas(1));
    for (int i = 0; i < 15; ++i) {
        t.sumar_punto(1);
    }
    EXPECT_FALSE(t.buenas(1));
    t.sumar_punto(1);
    EXPECT_TRUE(t.buenas(1));
    t.sumar_punto(1);
    t.sumar_punto(1);
    EXPECT_TRUE(t.buenas(1));
}
