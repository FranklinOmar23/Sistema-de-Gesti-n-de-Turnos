#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include "Empleado.h"

class Administrador : public Empleado {
private:
    int nivelAcceso;

public:
    Administrador(const std::string& nombre, int id, const std::string& cedula, const std::string& telefono, const std::string& puesto, int nivelAcceso);
    int getNivelAcceso() const;
    void setNivelAcceso(int nivelAcceso);

    void mostrarInformacion() const override;
};

#endif // ADMINISTRADOR_H
