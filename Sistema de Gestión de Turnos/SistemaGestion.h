#ifndef SISTEMAGESTION_H
#define SISTEMAGESTION_H

#include "Cliente.h"
#include "Empleado.h"
#include "Administrador.h"
#include "Turno.h"
#include <vector>
#include <iostream>

class SistemaGestion {
public:
    std::vector<Cliente> clientes;
    std::vector<Empleado> empleados;
    std::vector<Administrador> administradores;
    std::vector<Turno> turnos;

    const std::string archivoClientes = "clientes.dat";
    const std::string archivoEmpleados = "empleados.dat";
    const std::string archivoAdministradores = "administradores.dat";
    const std::string archivoTurnos = "turnos.dat";

public:
    SistemaGestion();
    ~SistemaGestion();

    int generarIdTurno();  // Genera ID único para turnos

    void agregarCliente(const Cliente& cliente);
    void agregarEmpleado(const Empleado& empleado);
    void agregarAdministrador(const Administrador& administrador);
    void agregarTurno(const Turno& turno);

    void mostrarClientes() const;
    void mostrarEmpleados() const;
    void mostrarAdministradores() const;
    void mostrarTurnos() const;

    void guardarDatos() const;
    void cargarDatos();
};

#endif // SISTEMAGESTION_H
