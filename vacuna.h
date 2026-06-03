/*
 * PetBudget - vacuna.h
 * Fernanda Jiménez Estrada
 * Clase Vacuna con nombre, precio, frecuencia y si ya fue aplicada
 */

/**
 * #ifndef VACUNA_H_ es un include guard, evita que se importe dos veces el archivo
 */
#ifndef VACUNA_H_
#define VACUNA_H_

#include <string>
#include <sstream>

using namespace std;

class Vacuna {
    /**
    * Los atributos son privados porque ninguna clase o sub-clase necesita acceder directamente a ellos
    */
private:
    string nombre;
    double precio;
    string frecuencia; // "mensual" o "anual"
    bool aplicada;

public:
    /**
     * Constructor por defecto
     * Vacuna(): nombre(""), precio(0), frecuencia(""), aplicada(false) {};
     */
    Vacuna(): nombre(""), precio(0), frecuencia(""), aplicada(false) {};

    /**
    * Constructor con parametros
    */
    Vacuna(string nom, double prec, string frec):
        nombre(nom), precio(prec), frecuencia(frec), aplicada(false) {};
    /**
    * Getter de Vacuna
    */
    string get_nombre()  { return nombre; }
    double get_precio()  { return precio; }
    bool get_aplicada()  { return aplicada; }

    /**
     * marcarAplicada: metodo que marca la vacuna como ya aplicada
     */
    void marcarAplicada() { aplicada = true; }

    /**
     * calcularAporteMensual: metodo que divide el precio entre 12  (la vacunacion es anual)
     * retorna el precio (aporte que se debe hacer mensual) en una variable tipo double
     */
    double calcularAporteMensual() {
        if (aplicada) return 0.0;
        if (frecuencia == "anual") return precio / 12.0;
        return precio;
    }

    /**
     * to_string: metodo que convierte los atributos a string con el fin de poder cout la información
     * retorna el string con la informacion de la vacuna
     */
    string to_string() {
        stringstream aux;
        aux << nombre << " $" << precio << " (" << frecuencia << ")"
            << (aplicada ? " [ya aplicada]" : "") << "\n";
        return aux.str();
    }
};
/**
* endif: cierre de ifndef
*/
#endif // VACUNA_H_
