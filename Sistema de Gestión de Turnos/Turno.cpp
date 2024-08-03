#include "Turno.h"
#include <iostream>

Turno::Turno(int id, const std::string& fecha, const std::string& hora)
    : id(id), fecha(fecha), hora(hora) {}

int Turno::getId() const {
    return id;
}

void Turno::setId(int id) {
    this->id = id;
}

std::string Turno::getFecha() const {
    return fecha;
}

void Turno::setFecha(const std::string& fecha) {
    this->fecha = fecha;
}

std::string Turno::getHora() const {
    return hora;
}

void Turno::setHora(const std::string& hora) {
    this->hora = hora;
}

void Turno::mostrarInformacion() const {
    std::cout << "ID Turno: " << id << "\n"
        << "Fecha: " << fecha << "\n"
        << "Hora: " << hora << std::endl;
}

void Turno::guardar(std::ofstream& out) const {
    out << id << "\n" << fecha << "\n" << hora << "\n";
}

void Turno::cargar(std::ifstream& in) {
    in >> id;
    in.ignore();
    std::getline(in, fecha);
    std::getline(in, hora);
}
