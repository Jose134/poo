#ifndef PERSONA_H
#define PERSONA_H

#include <string>

class Persona {
    private: 
        std::string dni_,
                    nombre_,
                    apellidos_,
                    direccion_,
                    localidad_,
                    provincia_,
                    pais_;

        int edad_;

    public: 
        Persona (
            std::string dni,
            std::string nombre="",
            std::string apellidos="",
            int edad=0,
            std::string direccion="",
            std::string localidad="",
            std::string provincia="",
            std::string pais=""
        );

        std::string getDNI() const { return dni_; }
        void setDNI(std::string dni) { dni_ = dni; }

        std::string getNombre() const { return nombre_; }
        void setNombre(std::string nombre) { nombre_ = nombre; }

        std::string getApellidos() const { return apellidos_; }
        void setApellidos(std::string apellidos) { apellidos_ = apellidos; }

        std::string getDireccion() const { return direccion_; }
        void setDireccion(std::string direccion) { direccion_ = direccion; }

        std::string getLocalidad() const { return localidad_; }
        void setLocalidad(std::string localidad) { localidad_ = localidad; }

        std::string getProvincia() const { return provincia_; }
        void setProvincia(std::string provincia) { provincia_ = provincia; }

        std::string getPais() const { return pais_; }
        void setPais(std::string pais) { pais_ = pais; }

        int getEdad() const { return edad_; }
        bool setEdad(int edad);

        std::string getApellidosyNombre() const { return (apellidos_ + ", " +  nombre_); }
        bool mayor() const { return (edad_ >= 18); }
};

#endif