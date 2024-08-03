#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <fstream>

class Persona {
protected:
    std::string nombre;
    int id;
    std::string cedula;
    std::string telefono;

public:
    Persona(const std::string& nombre, int id, const std::string& cedula, const std::string& telefono);
    virtual ~Persona() = default;

    std::string getNombre() const;
    void setNombre(const std::string& nombre);

    int getId() const;
    void setId(int id);

    std::string getCedula() const;
    void setCedula(const std::string& cedula);

    std::string getTelefono() const;
    void setTelefono(const std::string& telefono);

    virtual void mostrarInformacion() const;

    virtual void guardar(std::ofstream& out) const;
    virtual void cargar(std::ifstream& in);
};

#endif // PERSONA_H
