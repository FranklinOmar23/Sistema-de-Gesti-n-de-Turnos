#include "Cliente.h"
#include <iostream>

Cliente::Cliente() : Persona("", 0, "", ""), turno() {} // Implementación del constructor por defecto

Cliente::Cliente(const std::string& nombre, int id, const std::string& cedula, const std::string& telefono, const Turno& turno)
    : Persona(nombre, id, cedula, telefono), turno(turno) {}

Turno Cliente::getTurno() const {
    return turno;
}

void Cliente::setTurno(const Turno& turno) {
    this->turno = turno;
}

void Cliente::mostrarInformacion() const {
    Persona::mostrarInformacion();
    turno.mostrarInformacion();
}

void Cliente::guardar(std::ofstream& out) const {
    Persona::guardar(out);
    turno.guardar(out);
}

void Cliente::cargar(std::ifstream& in) {
    Persona::cargar(in);
    turno.cargar(in);
}
