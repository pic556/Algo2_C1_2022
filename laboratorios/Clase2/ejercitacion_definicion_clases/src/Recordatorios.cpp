#include <iostream>
#include <list>

using namespace std;

using uint = unsigned int;

// Pre: 0 <= mes < 12
uint dias_en_mes(uint mes) {
    uint dias[] = {
        // ene, feb, mar, abr, may, jun
        31, 28, 31, 30, 31, 30,
        // jul, ago, sep, oct, nov, dic
        31, 31, 30, 31, 30, 31
    };
    return dias[mes - 1];
}

// Ejercicio 7, 8, 9 y 10

// Clase Fecha
class Fecha {
  public:
    Fecha(int mes, int dia);
    uint mes();
    uint dia();
    bool operator==(Fecha o);
    void incrementar_dia();

  private:
    int mes_;
    int dia_;
};
Fecha::Fecha(int mes, int dia):mes_(mes),dia_(dia){};

uint Fecha::mes(){
    return this->mes_;
}
uint Fecha::dia(){
    return this->dia_;
}

//8
ostream& operator<<(ostream& os, Fecha f) {
    os << f.dia()<< "/" << f.mes();
    return os;
}

bool Fecha::operator==(Fecha o) {
    bool igual_dia = this->dia() == o.dia();
    bool igual_mes = this->mes() == o.mes();
    return igual_dia == igual_mes;
}

void Fecha::incrementar_dia(){
    if (dia() == dias_en_mes(mes())) {// aca el dia es el ultimo por eso igualar a la cantidad de dias de
        dia_ = 1;//de un mes
        if(mes() == 11){//los meses se cuentan desde 0  a 1|
            mes_ = 1;
        } else{
            mes_++;
        }
    } else {
        dia_++;
    }
}

// Ejercicio 11, 12

// Clase Horario
class Horario {
public:
    Horario(uint hora, uint min);
    uint hora();
    uint min();
    bool operator<(Horario h);

private:
    int hora_;
    int min_;
};

Horario::Horario(uint hora, uint min):hora_(hora),min_(min){};
uint Horario::hora(){
    return this->hora_;
}
uint Horario::min(){
    return this->min_;
}

ostream& operator<<(ostream& os, Horario h) {
    os << h.hora()<< ":" << h.min();
    return os;
}

bool Horario::operator<(Horario h) {
    bool comparacion = false;
    if (hora() == h.hora()){
        if (min() <h.min()){
            comparacion = true;
        }
    }
    return comparacion;
}


// Ejercicio 13

// Clase Recordatorio
class Recordatorio {
public:
    Recordatorio(Fecha f, Horario h ,string s);
    Fecha f();
    Horario h();
    string s();
private:
    Fecha f_;
    Horario h_;
    string s_;
};

Recordatorio::Recordatorio(Fecha f, Horario h ,string s): f_(f),h_(h),s_(s) {}//obligatorio para que se devuelvan
Fecha Recordatorio::f() {
    return f_;
}

string Recordatorio::s() {
    return s_;
}

Horario Recordatorio::h() {
    return h_;
}


ostream& operator<<(ostream& os, Recordatorio r) {
    os << r.s() << " " << "@" << " " << r.f().dia() << "/" << r.f().mes() << " " << r.h().hora() << ":" << r.h().min();
    return os;
}

// Ejercicio 14
// Clase Agenda
class Agenda {
public:
    Agenda(Fecha fecha_inicial);
    void agregar_recordatorio(Recordatorio rec);
    void incrementar_dia();
    list<Recordatorio> recordatorios_de_hoy();
    Fecha hoy();

private:
    //siguiendo los ejemplos de ejercicios anteriores agrego recordatorios_de_hoy y hoy_
    list<Recordatorio> recordatorios_de_hoy_;
    Fecha hoy_;
};


Agenda::Agenda(Fecha fecha_incial ): hoy_(fecha_incial),recordatorios_de_hoy_(){
}

Fecha Agenda::hoy() {
    return hoy_;
}

//para agregar recordatorios pense en usar recordatoios_de_hoy y colorca ahi los de rec
void Agenda::agregar_recordatorio(Recordatorio rec) {
    recordatorios_de_hoy_.push_back(rec);
}

//Use la funcion del punto 10 incrementar_dia en hoy_
void Agenda::incrementar_dia() {
    hoy_.incrementar_dia();
}


bool comparaciondeHorarios (Recordatorio r , Recordatorio m) {
    //horario r debe ser menor a m para que sea true,utilizo la funcion que hice
    // en el ejercicio 12
    return  r.h().operator<(m.h());
}


list<Recordatorio> Agenda::recordatorios_de_hoy() {
    list <Recordatorio>::iterator it;

    for( it = recordatorios_de_hoy_.begin(); it != recordatorios_de_hoy_.end(); ){
        if( !(it->f().operator==(hoy()))  ){
            it = recordatorios_de_hoy_.erase(it);
        }else{
            it++;
        }
    }
    recordatorios_de_hoy_.sort(comparaciondeHorarios);
    return recordatorios_de_hoy_;
}




//para imprimir
ostream& operator<<(ostream& os, Agenda a){
    os << a.hoy() << endl;
    os << "=====" << endl;

    list <Recordatorio> l = a.recordatorios_de_hoy();
    int longitud = l.size();

    for( int i=0; i<longitud;i++){

        os << l.front() << endl;
        l.pop_front();
    }
    return os;
}


