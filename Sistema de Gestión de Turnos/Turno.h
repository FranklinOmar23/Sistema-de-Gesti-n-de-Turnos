#ifndef TURNO_H
#define TURNO_H

#include <string>
#include <fstream>

class Turno {
private:
    int id;
    std::string fecha;
    std::string hora;

public:
    Turno(int id, const std::string& fecha, const std::string& hora);
    Turno(); // Constructor por defecto
    int getId() const;
    void setId(int id);

    std::string getFecha() const;
    void setFecha(const std::string& fecha);

    std::string getHora() const;
    void setHora(const std::string& hora);

    void mostrarInformacion() const;

    void guardar(std::ofstream& out) const;
    void cargar(std::ifstream& in);
};

#endif // TURNO_H
