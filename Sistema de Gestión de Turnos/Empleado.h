#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "Persona.h"

class Empleado : public Persona {
private:
    std::string puesto;

public:
    Empleado(); // Constructor por defecto
    Empleado(const std::string& nombre, int id, const std::string& cedula, const std::string& telefono, const std::string& puesto);
    std::string getPuesto() const;
    void setPuesto(const std::string& puesto);

    void mostrarInformacion() const override;

    void guardar(std::ofstream& out) const override;
    void cargar(std::ifstream& in) override;
};

#endif // EMPLEADO_H
