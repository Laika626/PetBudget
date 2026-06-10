/*
* Proyecto PetBudget
 * Fernanda Jiménez Estrada
 * A01206671
 * 09/06/2026
 *
 * Archivo: gasto.h
 *
 * Esta clase define el objeto Gasto, que guarda la descripcion,
 * precio y frecuencia de un gasto extra o medicamento agregado
 * manualmente por el usuario.
 */

/**
 * #ifndef GASTO_H_ es un include guard, evita que se importe dos veces el archivo
 */
#ifndef GASTO_H_
#define GASTO_H_

#include <string>
#include <sstream>

using namespace std;

class Gasto {
    /**
     * Los atributos son privados porque ninguna clase o sub-clase necesita acceder directamente a ellos
     */
private:
    string descripcion;
    double precio;
    string frecuencia;   // "mensual" o "anual"

public:
    /**
     * Constructor por defecto
     * Gasto(): descripcion(""), precio(0), frecuencia("") {}
     */
    Gasto(): descripcion(""), precio(0), frecuencia("") {}

    /**
     * Constructor con parametros
     */
    Gasto(string desc, double prec, string frec):
        descripcion(desc), precio(prec), frecuencia(frec) {}
    /**
    * Getters de gasto
    */
    string get_descripcion() { return descripcion; }
    double get_precio()      { return precio; }
    string get_frecuencia() { return frecuencia; }

    /**
     * calcularAporteMensual: metodo que divide el precio entre 12 si el gasto es anual,
     * retorna el precio (aporte que se debe hacer mensual) en una variable tipo double
     */
    double calcularAporteMensual() {
        if (frecuencia == "anual")      return precio / 12.0;
        if (frecuencia == "trimestral") return precio / 3.0;
        return precio;
    }

    bool esMensual() {
        return frecuencia == "mensual";
    }

    /**
    * to_string convierte los atributos a string.
    *
    * Concatena la informacion del gasto para poder imprimirla.
    *
    * @param
    * @return string con los valores y texto concatenado.
    */
    string to_string() {
        stringstream aux;
        aux << descripcion << " $" << precio << " (" << frecuencia << ")\n";
        return aux.str();
    }
};

/**
 * endif: cierre de ifndef
 */
#endif   // GASTO_H_
