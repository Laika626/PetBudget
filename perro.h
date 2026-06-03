/*
 * PetBudget - perro.h
 * Fernanda Jiménez Estrada
 * Clase Perro que hereda de Mascota
 * Sobreescribe calcularGastoMensual() y to_string()
 */
 
#ifndef PERRO_H_
#define PERRO_H_
 
#include <string>
#include <sstream>
#include "mascota.h"
#include "vacuna.h"
#include "gasto.h"
 
using namespace std;
 
class Perro: public Mascota {
    /**
     * Los atributos son private, solo la clase puede acceder a ellos
     */
private:
    string raza;
    Vacuna vacunas[10];
    int numVacunas;
    Gasto gastos[10];
    int numGastos;
 
public:
    /**
     * Constructor por defecto
     * Perro(): Mascota("", 0, "perro"), raza(""), numVacunas(0), numGastos(0) {};
     */
    Perro(): Mascota("", 0, "perro"), raza(""), numVacunas(0), numGastos(0) {};

     /**
      * Constructor con parametros
      */
    Perro(string nom, int edad, string raza_):
        Mascota(nom, edad, "perro"), raza(raza_), numVacunas(0), numGastos(0) {
        cargarEsquemaVacunacion();
    };

    /**
     * Getters de perro
     */
    string get_raza()        { return raza; }
    int get_numVacunas()     { return numVacunas; }
 
    /**
     * cargarEsquemaVacunacion: metodo que precarga vacunas dependiendo si es cachorro o adulto
     */
    void cargarEsquemaVacunacion() {
        if (esCachorro) {
            vacunas[0] = Vacuna("Puppy DP (Moquillo + Parvovirus)", 300, "anual");
            vacunas[1] = Vacuna("Polivalente Sextuple", 500, "anual");
            vacunas[2] = Vacuna("Refuerzo Polivalente", 500, "anual");
            vacunas[3] = Vacuna("Rabia", 200, "anual");
            numVacunas = 4;
        } else {
            vacunas[0] = Vacuna("Polivalente Sextuple", 500, "anual");
            vacunas[1] = Vacuna("Rabia", 200, "anual");
            numVacunas = 2;
        }
        // Desparasitacion trimestral: 4 x $100 = $400 anuales
        gastos[0] = Gasto("Desparasitacion", 400, "anual");
        numGastos = 1;
    }
 
    /**
     * marcarVacunaAplicada: metodo que marca una vacuna como ya aplicada por su índice
     * regresa un int indice de la vacuna
     */
    void marcarVacunaAplicada(int indice) {
        if (indice >= 0 && indice < numVacunas)
            vacunas[indice].marcarAplicada();
    }
 
    /**
     * mostrarVacunas imprime las vacunas del perro
     */
    void mostrarVacunas() {
        for (int i = 0; i < numVacunas; i++)
            cout << "  [" << i << "] " << vacunas[i].to_string();
    }
 
    /**
     * agregarGasto: metodo que agrega un gasto extra manual al perro
     * parametros: string descripcion, double precio, string frecuencia
     */
    void agregarGasto(string desc, double precio, string frec) {
        if (numGastos < 10) {
            gastos[numGastos] = Gasto(desc, precio, frec);
            numGastos++;
        }
    }
 
    /**
     * calcularGastoMensual: metodo que sobreescribe el metodo de Mascota
     * regresa un double total mensual
     */
    double calcularGastoMensual() {
        double total = 0;
        for (int i = 0; i < numVacunas; i++)
            total += vacunas[i].calcularAporteMensual();
        for (int i = 0; i < numGastos; i++)
            total += gastos[i].calcularAporteMensual();
        return total;
    }
 
    /**
     * to_string: metodo que sobreescribe el metodo de Mascota
     * regresa un string con la información del perro
     */
    string to_string() {
        stringstream aux;
        aux << "Perro: " << nombre << " | Raza: " << raza
            << " | Edad: " << edadMeses << " meses"
            << " | " << (esCachorro ? "Cachorro" : "Adulto")
            << " | Total mensual: $" << calcularGastoMensual() << "\n";
        return aux.str();
    }
};
/**
 * endif: cierre de ifndef
 */
#endif // PERRO_H_