/*
 * Proyecto PetBudget
 * Fernanda Jiménez Estrada
 * A01206671
 * 09/06/2026
 *
 * Archivo: perro.h
 *
 * Esta clase define el objeto Perro, que hereda de Mascota.
 * Maneja el esquema de vacunacion canino de acuerdo con la edad
 * de la mascota y calcula sus gastos mensuales.
 */

#ifndef PERRO_H_
#define PERRO_H_

#include <string>
#include <sstream>
#include <iostream>
#include "mascota.h"
#include "vacuna.h"
#include "gasto.h"

using namespace std;

// Declaro objeto Perro que hereda de Mascota
class Perro: public Mascota {
// Variables de instancia privadas del objeto
 private:
    string raza;
    Vacuna vacunasInicial[10];
    int numVacunasInicial;
    Vacuna vacunasAdulto[10];
    int numVacunasAdulto;
    Gasto gastos[10];
    int numGastos;
    Gasto desparasitacion;

// Metodos publicos del objeto
 public:
    Perro(): Mascota("", 0, "perro"), raza(""), numVacunasInicial(0),
             numVacunasAdulto(0), numGastos(0) {}  // constructor por default

    Perro(string nom, int edad, string raza_):
        Mascota(nom, edad, "perro"), raza(raza_), numVacunasInicial(0),
        numVacunasAdulto(0), numGastos(0) {
        cargarEsquemaVacunacion();
    }

    string get_raza() { return raza; }

    void cargarEsquemaVacunacion();
    void agregarGasto(string desc, double precio, string frec);
    double calcularEsquemaInicial();
    double calcularAhorroMensual();
    double calcularGastosFijos();
    double calcularGastoMensual();
    string to_string();
    string toStringDesglose();
};

/**
 * cargarEsquemaVacunacion precarga las vacunas según si es cachorro o adulto.
 *
 * Siempre carga el esquema de adulto para el ahorro mensual.
 * Si es cachorro también carga el esquema inicial como gasto único.
 *
 * @param
 * @return
 */
void Perro::cargarEsquemaVacunacion() {
    // esquema de adulto siempre se carga para calcular ahorro mensual
    vacunasAdulto[0] = Vacuna("Polivalente Sextuple", 500, "anual");
    vacunasAdulto[1] = Vacuna("Rabia", 200, "anual");
    numVacunasAdulto = 2;

    // desparasitacion trimestral
    desparasitacion = Gasto("Desparasitacion", 100, "trimestral");

    // esquema inicial solo para cachorros
    if (esCachorro) {
        vacunasInicial[0] = Vacuna("Puppy DP (Moquillo + Parvovirus)",
            300, "unico");
        vacunasInicial[1] = Vacuna("Polivalente Sextuple", 500, "unico");
        vacunasInicial[2] = Vacuna("Refuerzo Polivalente", 500, "unico");
        vacunasInicial[3] = Vacuna("Rabia", 200, "unico");
        numVacunasInicial = 4;
    }
}

/**
 * agregarGasto agrega un gasto extra manual al perro.
 *
 * @param string desc, double precio, string frec
 * @return
 */
void Perro::agregarGasto(string desc, double precio, string frec) {
    if (numGastos < 10) {
        gastos[numGastos] = Gasto(desc, precio, frec);
        numGastos++;
    }
}

/**
 * calcularEsquemaInicial suma el costo del esquema inicial de cachorro.
 *
 * @param
 * @return double con el costo total del esquema inicial.
 */
double Perro::calcularEsquemaInicial() {
    double total = 0;
    for (int i = 0; i < numVacunasInicial; i++)
        total += vacunasInicial[i].get_precio();
    return total;
}

/**
 * calcularAhorroMensual suma las vacunas de adulto y desparasitacion.
 *
 * @param
 * @return double con el ahorro mensual.
 */
double Perro::calcularAhorroMensual() {
    double total = 0;
    for (int i = 0; i < numVacunasAdulto; i++)
        total += vacunasAdulto[i].calcularAporteMensual();
    total += desparasitacion.calcularAporteMensual();
    return total;
}

/**
 * calcularGastosFijos suma los gastos mensuales fijos del usuario.
 *
 * @param
 * @return double con los gastos fijos mensuales.
 */
double Perro::calcularGastosFijos() {
    double total = 0;
    for (int i = 0; i < numGastos; i++)
        if (gastos[i].esMensual())
            total += gastos[i].calcularAporteMensual();
    return total;
}

/**
 * calcularGastoMensual suma el ahorro mensual y los gastos fijos.
 *
 * @param
 * @return double con el total mensual a apartar.
 */
double Perro::calcularGastoMensual() {
    return calcularAhorroMensual() + calcularGastosFijos();
}

/**
 * to_string convierte los atributos a string.
 *
 * Muestra el resumen del perro separando ahorro mensual y gastos fijos.
 * Incluye nota según si es cachorro o adulto.
 *
 * @param
 * @return string con los valores y texto concatenado.
 */
string Perro::to_string() {
    stringstream aux;
    aux << nombre << " (Perro "
    << (esCachorro ? "cachorro" : "adulto") << ")\n";
    if (esCachorro)
        aux << "  Esquema inicial (gasto unico): $"
        << calcularEsquemaInicial() << "\n";
    aux << "  Ahorro mensual:        $"
    << calcularAhorroMensual() << "/mes\n";
    aux << "  Gastos fijos:          $"
    << calcularGastosFijos() << "/mes\n";
    aux << "  Total a apartar:       $"
    << calcularGastoMensual() << "/mes\n";
    if (esCachorro) {
        aux << "  Nota: Esquema inicial es un gasto unico que debes cubrir\n";
        aux << "  inmediatamente, no es parte del presupuesto mensual.\n";
        aux << "  El ahorro mensual esta calculado para que cuando tu\n";
        aux << "  mascota cumpla 12 meses tengas cubierto su primer \n";
        aux << "  esquema de adulto.\n";
    } else {
        aux << "  Nota: este presupuesto asume que tu mascota acaba de\n";
        aux << "  recibir sus vacunas y desparasitacion. Tienes\n";
        aux << "  aproximadamente 12 meses para ahorrar para las proximas\n";
        aux << "  vacunas y 3 meses para la siguiente desparasitacion\n";
    }
    return aux.str();
}

/**
 * toStringDesglose convierte los atributos a string con desglose completo.
 *
 * Muestra cada vacuna y gasto con su aporte mensual.
 * Incluye nota según si es cachorro o adulto.
 *
 * @param
 * @return string con los valores y texto concatenado.
 */
string Perro::toStringDesglose() {
    stringstream aux;
    aux << nombre << " (Perro "
    << (esCachorro ? "cachorro" : "adulto") << ")\n";
    if (esCachorro) {
        aux << "  Esquema inicial de vacunacion (gasto unico):\n";
        for (int i = 0; i < numVacunasInicial; i++)
            aux << "    " << vacunasInicial[i].get_nombre()
                << "  $" << vacunasInicial[i].get_precio() << "\n";
        aux << "   Total esquema inicial: $"
        << calcularEsquemaInicial() << "\n\n";
    }
    aux << "  Ahorro mensual (para esquema de adulto):\n";
    for (int i = 0; i < numVacunasAdulto; i++)
        aux << "    " << vacunasAdulto[i].get_nombre()
            << "  $" << vacunasAdulto[i].get_precio()
            << " -> $" << vacunasAdulto[i].calcularAporteMensual() << "/mes\n";
    aux << "    " << desparasitacion.to_string();
    aux << "    Total ahorro: $" << calcularAhorroMensual() << "/mes\n\n";
    aux << "  Gastos fijos mensuales:\n";
    if (numGastos == 0) {
        aux << "    Ninguno\n";
    } else {
        for (int i = 0; i < numGastos; i++)
            aux << "    " << gastos[i].to_string();
    }
    aux << "    Total fijos: $" << calcularGastosFijos() << "/mes\n\n";
    if (esCachorro) {
        aux << "  Nota: Esquema inicial es un gasto unico que debes cubrir\n";
        aux << "  inmediatamente, no es parte del presupuesto mensual.\n";
        aux << "  El ahorro mensual esta calculado para que cuando tu\n";
        aux << "  mascota cumpla 12 meses tengas cubierto su primer \n";
        aux << "  esquema de adulto.\n";
    } else {
        aux << "  Nota: este presupuesto asume que tu mascota acaba de\n";
        aux << "  recibir sus vacunas y desparasitacion. Tienes\n";
        aux << "  aproximadamente 12 meses para ahorrar para las proximas\n";
        aux << "  vacunas y 3 meses para la siguiente desparasitacion\n";
    }
    aux << "  Total a apartar mensualmente: $"
    << calcularGastoMensual() << "/mes\n";
    return aux.str();
}

/**
 * endif: cierre de ifndef
 */
#endif  // PERRO_H_
