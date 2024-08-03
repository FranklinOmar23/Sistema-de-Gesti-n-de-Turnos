#include "SistemaGestion.h"
#include <fstream>

SistemaGestion::SistemaGestion() {
    cargarDatos();
}

SistemaGestion::~SistemaGestion() {
    guardarDatos();
}

int SistemaGestion::generarIdTurno() {
    return turnos.size() + 1;
}

void SistemaGestion::agregarCliente(const Cliente& cliente) {
    clientes.push_back(cliente);
    agregarTurno(cliente.getTurno());
}

void SistemaGestion::agregarEmpleado(const Empleado& empleado) {
    empleados.push_back(empleado);
}

void SistemaGestion::agregarTurno(const Turno& turno) {
    turnos.push_back(turno);
}

void SistemaGestion::mostrarClientes() const {
    for (const auto& cliente : clientes) {
        cliente.mostrarInformacion();
    }
}

void SistemaGestion::mostrarEmpleados() const {
    for (const auto& empleado : empleados) {
        empleado.mostrarInformacion();
    }
}

void SistemaGestion::mostrarTurnos() const {
    for (const auto& turno : turnos) {
        turno.mostrarInformacion();
    }
}

void SistemaGestion::guardarDatos() const {
    // Guardar clientes
    std::ofstream outClientes(archivoClientes);
    for (const auto& cliente : clientes) {
        cliente.guardar(outClientes);
    }
    outClientes.close();

    // Guardar empleados
    std::ofstream outEmpleados(archivoEmpleados);
    for (const auto& empleado : empleados) {
        empleado.guardar(outEmpleados);
    }
    outEmpleados.close();

    // Guardar turnos
    std::ofstream outTurnos(archivoTurnos);
    for (const auto& turno : turnos) {
        turno.guardar(outTurnos);
    }
    outTurnos.close();
}

void SistemaGestion::cargarDatos() {
    // Cargar clientes
    std::ifstream inClientes(archivoClientes);
    while (inClientes.peek() != EOF) {
        Cliente cliente;
        cliente.cargar(inClientes);
        clientes.push_back(cliente);
    }
    inClientes.close();

    // Cargar empleados
    std::ifstream inEmpleados(archivoEmpleados);
    while (inEmpleados.peek() != EOF) {
        Empleado empleado;
        empleado.cargar(inEmpleados);
        empleados.push_back(empleado);
    }
    inEmpleados.close();

    // Cargar turnos
    std::ifstream inTurnos(archivoTurnos);
    while (inTurnos.peek() != EOF) {
        Turno turno;
        turno.cargar(inTurnos);
        turnos.push_back(turno);
    }
    inTurnos.close();
}
