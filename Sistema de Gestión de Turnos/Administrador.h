#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include "Empleado.h"

class Administrador : public Empleado {
private:
    int nivelAcceso;

public:
    Administrador(); // Constructor por defecto
    Administrador(const std::string& nombre, int id, const std::string& cedula, const std::string& telefono, const std::string& puesto, int nivelAcceso);
    int getNivelAcceso() const;
    void setNivelAcceso(int nivelAcceso);

    void mostrarInformacion() const override;

    void guardar(std::ofstream& out) const override;
    void cargar(std::ifstream& in) override;
};

#endif // ADMINISTRADOR_H
