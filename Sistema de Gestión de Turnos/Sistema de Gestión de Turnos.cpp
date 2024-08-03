#include "SistemaGestion.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

#ifdef _WIN32
#define CLEAR "CLS"
#else
#define CLEAR "clear"
#endif

void mostrarMenu() {
    std::cout << "1. Agregar Cliente\n";
    std::cout << "2. Agregar Empleado\n";
    std::cout << "3. Agregar Turno\n";
    std::cout << "4. Mostrar Clientes\n";
    std::cout << "5. Mostrar Empleados\n";
    std::cout << "6. Mostrar Turnos\n";
    std::cout << "7. Salir\n";
    std::cout << "Seleccione una opcion: ";
}

int main() {
    SistemaGestion sistema;
    int opcion;

    do {
        system(CLEAR); // Limpiar la consola
        mostrarMenu();
        std::cin >> opcion;

        switch (opcion) {
        case 1: {
            std::string nombre, cedula, telefono;
            int id;
            std::cout << "Ingrese nombre: ";
            std::cin >> nombre;
            std::cout << "Ingrese ID: ";
            std::cin >> id;
            std::cout << "Ingrese cedula: ";
            std::cin >> cedula;
            std::cout << "Ingrese telefono: ";
            std::cin >> telefono;

            int turnoId = sistema.generarIdTurno();
            std::string fecha, hora;
            std::cout << "Ingrese fecha del turno (DD/MM/YYYY): ";
            std::cin >> fecha;
            std::cout << "Ingrese hora del turno (HH:MM): ";
            std::cin >> hora;
            Turno turno(turnoId, fecha, hora);

            Cliente cliente(nombre, id, cedula, telefono, turno);
            sistema.agregarCliente(cliente);
            break;
        }
        case 2: {
            std::string nombre, cedula, telefono, puesto;
            int id;
            std::cout << "Ingrese nombre: ";
            std::cin >> nombre;
            std::cout << "Ingrese ID: ";
            std::cin >> id;
            std::cout << "Ingrese cedula: ";
            std::cin >> cedula;
            std::cout << "Ingrese telefono: ";
            std::cin >> telefono;
            std::cout << "Ingrese puesto: ";
            std::cin >> puesto;
            Empleado empleado(nombre, id, cedula, telefono, puesto);
            sistema.agregarEmpleado(empleado);
            break;
        }
        case 3: {
            int id;
            std::string fecha, hora;
            std::cout << "Ingrese ID del turno: ";
            std::cin >> id;
            std::cout << "Ingrese fecha (DD/MM/YYYY): ";
            std::cin >> fecha;
            std::cout << "Ingrese hora (HH:MM): ";
            std::cin >> hora;
            Turno turno(id, fecha, hora);
            sistema.agregarTurno(turno);
            break;
        }
        case 4:
            system(CLEAR); // Limpiar la consola antes de mostrar los clientes
            sistema.mostrarClientes();
            break;
        case 5:
            system(CLEAR); // Limpiar la consola antes de mostrar los empleados
            sistema.mostrarEmpleados();
            break;
        case 6:
            system(CLEAR); // Limpiar la consola antes de mostrar los turnos
            sistema.mostrarTurnos();
            break;
        case 7:
            std::cout << "Saliendo...\n";
            break;
        default:
            std::cout << "Opcion no valida\n";
            break;
        }

        if (opcion != 7) {
            std::cout << "Presione cualquier tecla para continuar...";
            std::cin.ignore();
            std::cin.get();
        }
    } while (opcion != 7);

    return 0;
}
