#ifndef PERSONA_H
#define PERSONA_H

#include <string>

//Represents a person
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
        //Constructor
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

        std::string getDNI() const { return dni_; }  //Returns person's DNI
        void setDNI(std::string dni) { dni_ = dni; } //Sets person's DNI (WARNING: doesn't check if its a valid DNI)

        std::string getNombre() const { return nombre_; }        //Returns person's name
        void setNombre(std::string nombre) { nombre_ = nombre; } //Sets person's name

        std::string getApellidos() const { return apellidos_; }              //Returns person's surnames
        void setApellidos(std::string apellidos) { apellidos_ = apellidos; } //Sets person's surnames

        std::string getDireccion() const { return direccion_; }              //Returns person's address
        void setDireccion(std::string direccion) { direccion_ = direccion; } //Sets person's address

        std::string getLocalidad() const { return localidad_; }              //Returns person's locality
        void setLocalidad(std::string localidad) { localidad_ = localidad; } //Sets person's locality

        std::string getProvincia() const { return provincia_; }              //Returns person's province
        void setProvincia(std::string provincia) { provincia_ = provincia; } //Sets person's province

        std::string getPais() const { return pais_; }    //Returns person's country
        void setPais(std::string pais) { pais_ = pais; } //Sets person's country

        int getEdad() const { return edad_; } //Returrns person's age
        bool setEdad (int edad) {             //Sets person's age (checks if the given age is greater than 0)
            if (edad < 0) {
                return false;
            }
            
            edad_ = edad;
            return true;
        }

        std::string getApellidosyNombre() const { return (apellidos_ + ", " +  nombre_); } //Returns person's full name
        bool mayor() const { return (edad_ >= 18); } //Returns true if the person is an adult, false otherwise
};

#endif