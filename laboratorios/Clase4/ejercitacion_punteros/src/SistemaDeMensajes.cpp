#include <iostream>
#include "SistemaDeMensajes.h"
#include "ConexionJugador.h"

SistemaDeMensajes::SistemaDeMensajes():_conns(){}
void SistemaDeMensajes::registrarJugador(int id, string ip){
    desregistrarJugador(id);
    if (registrado(id)) {
        _conns[id] = nullptr;
    }
    else{
        _conns[id] = new ConexionJugador(ip);
    }
}

SistemaDeMensajes::~SistemaDeMensajes(){
    for (int id = 0; id < 4; id++) {
        delete _conns[id];
    }
    for(Proxy* pr : _proxys){
        delete pr;
    }
}

void SistemaDeMensajes::desregistrarJugador(int id){
    if (registrado(id)) {
        delete _conns[id];
        _conns[id] = nullptr;
    }
}
void SistemaDeMensajes::enviarMensaje(int id, string mensaje){
    _conns[id]->enviarMensaje(mensaje);
}
bool SistemaDeMensajes::registrado(int id) const{
    return _conns[id] != nullptr;
}
string SistemaDeMensajes::ipJugador(int id) const{
    _conns[id]->ip();
}


#if EJ != 6
Proxy *SistemaDeMensajes::obtenerProxy(int id) {
    Proxy* conJugador = new Proxy(_conns[id]);
    _proxys.push_back(conJugador);
    return  conJugador;
}
#else
Proxy *SistemaDeMensajes::obtenerProxy(int id) {
    Proxy* conJugador = new Proxy(&(_conns[id]));
    this->_proxys.push_back(conJugador);
    return  conJugador;
}
#endif

