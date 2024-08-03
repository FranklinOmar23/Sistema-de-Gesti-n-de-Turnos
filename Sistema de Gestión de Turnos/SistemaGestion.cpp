#include "SistemaGestion.h"
#include <fstream>

SistemaGestion::SistemaGestion() {
    cargarDatos();  // Carga los datos al iniciar
}

SistemaGestion::~SistemaGestion() {
    guardarDatos();  // Guarda los datos al finalizar
}

int SistemaGestion::generarIdTurno() {
    return static_cast<int>(turnos.size()) + 1;  // Genera un ID único basado en el tamaño de la lista de turnos
}

void SistemaGestion::agregarCliente(const Cliente& cliente) {
    clientes.push_back(cliente);
    agregarTurno(cliente.getTurno());  // Agrega el turno del cliente a la lista de turnos
}

void SistemaGestion::agregarEmpleado(const Empleado& empleado) {
    empleados.push_back(empleado);
}

void SistemaGestion::agregarAdministrador(const Administrador& administrador) {
    administradores.push_back(administrador);
}

void SistemaGestion::agregarTurno(const Turno& turno) {
    turnos.push_back(turno);
}

void SistemaGestion::mostrarClientes() const {
    for (const auto& cliente : clientes) {
        cliente.mostrarInformacion();  // Muestra información de todos los clientes
    }
}

void SistemaGestion::mostrarEmpleados() const {
    for (const auto& empleado : empleados) {
        empleado.mostrarInformacion();  // Muestra información de todos los empleados
    }
}

void SistemaGestion::mostrarAdministradores() const {
    for (const auto& administrador : administradores) {
        administrador.mostrarInformacion();  // Muestra información de todos los administradores
    }
}

void SistemaGestion::mostrarTurnos() const {
    for (const auto& turno : turnos) {
        turno.mostrarInformacion();  // Muestra información de todos los turnos
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

    // Guardar administradores
    std::ofstream outAdministradores(archivoAdministradores);
    for (const auto& administrador : administradores) {
        administrador.guardar(outAdministradores);
    }
    outAdministradores.close();

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

    // Cargar administradores
    std::ifstream inAdministradores(archivoAdministradores);
    while (inAdministradores.peek() != EOF) {
        Administrador administrador;
        administrador.cargar(inAdministradores);
        administradores.push_back(administrador);
    }
    inAdministradores.close();

    // Cargar turnos
    std::ifstream inTurnos(archivoTurnos);
    while (inTurnos.peek() != EOF) {
        Turno turno;
        turno.cargar(inTurnos);
        turnos.push_back(turno);
    }
    inTurnos.close();
}
