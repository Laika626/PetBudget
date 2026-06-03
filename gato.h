/*
 * PetBudget - gato.h
 * Fernanda Jiménez Estrada
 * Clase Gato que hereda de Mascota
 * Sobreescribe calcularGastoMensual() y to_string()
 */
 
#ifndef GATO_H_
#define GATO_H_
 
#include <string>
#include <sstream>
#include "mascota.h"
#include "vacuna.h"
#include "gasto.h"
 
using namespace std;
 
class Gato: public Mascota {
    /**
     * Los atributos son private, solo la clase puede acceder a ellos
     */
private:
    bool positivoLeucemia;
    Vacuna vacunas[10];
    int numVacunas;
    Gasto gastos[10];
    int numGastos;
 
public:
    /**
     * Constructor por defecto
     * Gato(): Mascota("", 0, "gato"), positivoLeucemia(false),
            numVacunas(0), numGastos(0) {};
     */
    Gato(): Mascota("", 0, "gato"), positivoLeucemia(false),
            numVacunas(0), numGastos(0) {};

    /**
      * Constructor con parametros
      */
    Gato(string nom, int edad, bool leucemia):
        Mascota(nom, edad, "gato"), positivoLeucemia(leucemia),
        numVacunas(0), numGastos(0) {
        cargarEsquemaVacunacion();
    };

    /**
     * Getters de gato
     */
    bool get_positivoLeucemia() { return positivoLeucemia; }
    int get_numVacunas()        { return numVacunas; }
 
    /**
     * cargarEsquemaVacunacion: metodo que precarga vacunas según edad y resultado de leucemia
     */
    void cargarEsquemaVacunacion() {
        if (esCachorro) {
            vacunas[0] = Vacuna("Trivalente Felina", 350, "anual");
            vacunas[1] = Vacuna("Refuerzo Trivalente", 350, "anual");
            vacunas[2] = Vacuna("Refuerzo Trivalente 2", 350, "anual");
            vacunas[3] = Vacuna("Rabia", 200, "anual");
            numVacunas = 4;
            if (!positivoLeucemia) {
                vacunas[4] = Vacuna("Leucemia Felina", 400, "anual");
                vacunas[5] = Vacuna("Refuerzo Leucemia Felina", 400, "anual");
                numVacunas = 6;
            }
        } else {
            vacunas[0] = Vacuna("Trivalente Felina", 350, "anual");
            vacunas[1] = Vacuna("Rabia", 200, "anual");
            numVacunas = 2;
            if (!positivoLeucemia) {
                vacunas[2] = Vacuna("Leucemia Felina", 400, "anual");
                numVacunas = 3;
            }
        }
        // Desparasitacion trimestral: 4 x $100 = $400 anuales
        gastos[0] = Gasto("Desparasitacion", 400, "anual");
        numGastos = 1;
    }
 
    /**
     * marcarVacunaAplicada: metodo para marcar una vacuna como ya aplicada por su índice
     * parametro: int indice de la vacuna
     */
    void marcarVacunaAplicada(int indice) {
        if (indice >= 0 && indice < numVacunas)
            vacunas[indice].marcarAplicada();
    }
 
    /**
     * mostrarVacunas: metodo que imprime las vacunas del gato
     */
    void mostrarVacunas() {
        for (int i = 0; i < numVacunas; i++)
            cout << "  [" << i << "] " << vacunas[i].to_string();
    }
 
    /**
     * agregarGasto: metodo que agrega un gasto extra manual al gato
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
     * regresa un double del  total mensual
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
     * regresa un string con la información del gato
     */
    string to_string() {
        stringstream aux;
        aux << "Gato: " << nombre << " | Leucemia: "
            << (positivoLeucemia ? "Positivo" : "Negativo")
            << " | Edad: " << edadMeses << " meses"
            << " | " << (esCachorro ? "Cachorro" : "Adulto")
            << " | Total mensual: $" << calcularGastoMensual() << "\n";
        return aux.str();
    }
};

/**
 * endif: cierre de ifndef
 */
#endif // GATO_H_