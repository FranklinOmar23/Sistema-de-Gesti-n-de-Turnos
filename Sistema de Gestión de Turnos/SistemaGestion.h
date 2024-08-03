#ifndef SISTEMAGESTION_H
#define SISTEMAGESTION_H

#include "Cliente.h"
#include "Empleado.h"
#include "Turno.h"
#include <vector>
#include <iostream>

class SistemaGestion {
private:
    std::vector<Cliente> clientes;
    std::vector<Empleado> empleados;
    std::vector<Turno> turnos;

    const std::string archivoClientes = "clientes.dat";
    const std::string archivoEmpleados = "empleados.dat";
    const std::string archivoTurnos = "turnos.dat";

    int generarIdTurno();

public:
    SistemaGestion();
    ~SistemaGestion();

    void agregarCliente(const Cliente& cliente);
    void agregarEmpleado(const Empleado& empleado);
    void agregarTurno(const Turno& turno);

    void mostrarClientes() const;
    void mostrarEmpleados() const;
    void mostrarTurnos() const;

    void guardarDatos() const;
    void cargarDatos();
};

#endif // SISTEMAGESTION_H
