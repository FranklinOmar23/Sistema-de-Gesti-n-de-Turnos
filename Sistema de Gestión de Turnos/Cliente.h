#ifndef CLIENTE_H
#define CLIENTE_H

#include "Persona.h"
#include "Turno.h"

class Cliente : public Persona {
private:
    Turno turno;

public:
    Cliente(); // Constructor por defecto
    Cliente(const std::string& nombre, int id, const std::string& cedula, const std::string& telefono, const Turno& turno);
    Turno getTurno() const;
    void setTurno(const Turno& turno);

    void mostrarInformacion() const override;

    void guardar(std::ofstream& out) const override;
    void cargar(std::ifstream& in) override;
};

#endif // CLIENTE_H
