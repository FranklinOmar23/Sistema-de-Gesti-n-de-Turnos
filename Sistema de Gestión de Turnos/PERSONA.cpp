#include "Persona.h"
#include <iostream>

Persona::Persona(const std::string& nombre, int id, const std::string& cedula, const std::string& telefono)
    : nombre(nombre), id(id), cedula(cedula), telefono(telefono) {}

std::string Persona::getNombre() const {
    return nombre;
}

void Persona::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}

int Persona::getId() const {
    return id;
}

void Persona::setId(int id) {
    this->id = id;
}

std::string Persona::getCedula() const {
    return cedula;
}

void Persona::setCedula(const std::string& cedula) {
    this->cedula = cedula;
}

std::string Persona::getTelefono() const {
    return telefono;
}

void Persona::setTelefono(const std::string& telefono) {
    this->telefono = telefono;
}

void Persona::mostrarInformacion() const {
    std::cout << "Nombre: " << nombre << "\n"
        << "ID: " << id << "\n"
        << "Cedula: " << cedula << "\n"
        << "Telefono: " << telefono << std::endl;
}

void Persona::guardar(std::ofstream& out) const {
    out << nombre << "\n" << id << "\n" << cedula << "\n" << telefono << "\n";
}

void Persona::cargar(std::ifstream& in) {
    std::getline(in, nombre);
    in >> id;
    in.ignore();
    std::getline(in, cedula);
    std::getline(in, telefono);
}
