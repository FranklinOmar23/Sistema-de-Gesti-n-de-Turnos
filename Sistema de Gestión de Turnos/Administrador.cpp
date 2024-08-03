#include "Administrador.h"
#include <iostream>

Administrador::Administrador(const std::string& nombre, int id, const std::string& cedula, const std::string& telefono, const std::string& puesto, int nivelAcceso)
    : Empleado(nombre, id, cedula, telefono, puesto), nivelAcceso(nivelAcceso) {}

int Administrador::getNivelAcceso() const {
    return nivelAcceso;
}

void Administrador::setNivelAcceso(int nivelAcceso) {
    this->nivelAcceso = nivelAcceso;
}

void Administrador::mostrarInformacion() const {
    Empleado::mostrarInformacion();
    std::cout << "Nivel de acceso: " << nivelAcceso << std::endl;
}
