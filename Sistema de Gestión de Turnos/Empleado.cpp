#include "Empleado.h"
#include <iostream>

Empleado::Empleado() : Persona("", 0, "", ""), puesto("") {} // Implementación del constructor por defecto

Empleado::Empleado(const std::string& nombre, int id, const std::string& cedula, const std::string& telefono, const std::string& puesto)
    : Persona(nombre, id, cedula, telefono), puesto(puesto) {}

std::string Empleado::getPuesto() const {
    return puesto;
}

void Empleado::setPuesto(const std::string& puesto) {
    this->puesto = puesto;
}

void Empleado::mostrarInformacion() const {
    Persona::mostrarInformacion();
    std::cout << "Puesto: " << puesto << std::endl;
}

void Empleado::guardar(std::ofstream& out) const {
    Persona::guardar(out);
    out << puesto << "\n";
}

void Empleado::cargar(std::ifstream& in) {
    Persona::cargar(in);
    std::getline(in, puesto);
}
