/*
* PetBudget - mascota.h
 * Fernanda Jiménez Estrada
 * Clase base Mascota con métodos virtuales
 */

/**
 * #ifndef MASCOTA_H_ es un include guard, evita que se importe dos veces el archivo
 */
#ifndef MASCOTA_H_
#define MASCOTA_H_

#include <string>
#include <sstream>

using namespace std;

class Mascota {
    /**
     * Los atributos son protected porque las sub-clase necesita acceder directamente a ellos
     */
protected:
    string nombre;
    int edadMeses;
    string padecimientos[10];
    int numPadecimientos;
    bool esCachorro;
    string tipo;

public:
    /**
     * Constructor por defecto
     * Mascota(): nombre(""), edadMeses(0), numPadecimientos(0),
               esCachorro(false), tipo("") {};
     */
    Mascota(): nombre(""), edadMeses(0), numPadecimientos(0),
               esCachorro(false), tipo("") {};

    /**
     * Constructor con parametros
     */
    Mascota(string nom, int edad, string tip):
        nombre(nom), edadMeses(edad), numPadecimientos(0), tipo(tip) {
        esCachorro = (edad < 12);
    };

    /**
     * Getters de mascota
     */
    string get_nombre()     { return nombre; }
    string get_tipo()       { return tipo; }
    int get_edad()          { return edadMeses; }
    bool get_esCachorro()   { return esCachorro; }

    /**
      * agregarPadecimiento: metodo para agregar un padecimiento al arreglo
      * Parametro: string con el padecimiento
    */
    void agregarPadecimiento(string padecimiento) {
        if (numPadecimientos < 10) {
            padecimientos[numPadecimientos] = padecimiento;
            numPadecimientos++;
        }
    }

    /**
     * calcularGastoMensual: metodo que regresa 0 por default, cada subclase (perro/gato) lo sobreescribe
     * regresa un double de gasto mensual
     */
    virtual double calcularGastoMensual() {
        return 0.0;
    }

    /**
     * to_string: metodo que convierte los atributos a string, cada subclase (perro/gato) lo sobreescribe
     * regresa un string con la información de la mascota
     */
    virtual string to_string() {
        stringstream aux;
        aux << "Mascota: " << nombre << " | Edad: " << edadMeses
            << " meses | " << (esCachorro ? "Cachorro" : "Adulto") << "\n";
        return aux.str();
    }
};

/**
 * endif: cierre de ifndef
 */
#endif // MASCOTA_H_