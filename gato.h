/*
*
* PetBudget
* Fernanda Jiménez Estrada
* A01206671
* 09/06/2026
* Esta clase define el objeto Gato que hereda de Mascota.
* Maneja el esquema de vacunación felino según la edad
* y el resultado del test de leucemia felina.
*/

#ifndef GATO_H_
#define GATO_H_

#include <string>
#include <sstream>
#include <iostream>
#include "mascota.h"
#include "vacuna.h"
#include "gasto.h"

using namespace std;

//Declaro objeto Gato que hereda de Mascota
class Gato: public Mascota {

//Variables de instancia privadas del objeto
private:
    bool positivoLeucemia;
    Vacuna vacunasInicial[10];
    int numVacunasInicial;
    Vacuna vacunasAdulto[10];
    int numVacunasAdulto;
    Gasto gastos[10];
    int numGastos;
    Gasto desparasitacion;

//Metodos publicos del objeto
public:
    Gato(): Mascota("", 0, "gato"), positivoLeucemia(false),
            numVacunasInicial(0), numVacunasAdulto(0), numGastos(0) {}; //constructor por default

    Gato(string nom, int edad, bool leucemia):
        Mascota(nom, edad, "gato"), positivoLeucemia(leucemia),
        numVacunasInicial(0), numVacunasAdulto(0), numGastos(0) {
        cargarEsquemaVacunacion();
    };

    bool get_positivoLeucemia() { return positivoLeucemia; }

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
 * cargarEsquemaVacunacion precarga las vacunas según edad y resultado de leucemia.
 *
 * Siempre carga el esquema de adulto para el ahorro mensual.
 * Si es cachorro también carga el esquema inicial como gasto único.
 * La vacuna de leucemia felina solo se incluye si el resultado es negativo.
 *
 * @param
 * @return
 */
void Gato::cargarEsquemaVacunacion() {
    //esquema de adulto siempre se carga para calcular ahorro mensual
    vacunasAdulto[0] = Vacuna("Trivalente Felina", 350, "anual");
    vacunasAdulto[1] = Vacuna("Rabia", 200, "anual");
    numVacunasAdulto = 2;
    if (!positivoLeucemia) {
        vacunasAdulto[2] = Vacuna("Leucemia Felina", 400, "anual");
        numVacunasAdulto = 3;
    }

    //desparasitacion trimestral
    desparasitacion = Gasto("Desparasitacion", 100, "trimestral");

    //esquema inicial solo para cachorros
    if (esCachorro) {
        vacunasInicial[0] = Vacuna("Trivalente Felina", 350, "unico");
        vacunasInicial[1] = Vacuna("Refuerzo Trivalente", 350, "unico");
        vacunasInicial[2] = Vacuna("Refuerzo Trivalente 2", 350, "unico");
        vacunasInicial[3] = Vacuna("Rabia", 200, "unico");
        numVacunasInicial = 4;
        if (!positivoLeucemia) {
            vacunasInicial[4] = Vacuna("Leucemia Felina", 400, "unico");
            vacunasInicial[5] = Vacuna("Refuerzo Leucemia Felina", 400, "unico");
            numVacunasInicial = 6;
        }
    }
}

/**
 * agregarGasto agrega un gasto extra manual al gato.
 *
 * @param string desc, double precio, string frec
 * @return
 */
void Gato::agregarGasto(string desc, double precio, string frec) {
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
double Gato::calcularEsquemaInicial() {
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
double Gato::calcularAhorroMensual() {
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
double Gato::calcularGastosFijos() {
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
double Gato::calcularGastoMensual() {
    return calcularAhorroMensual() + calcularGastosFijos();
}

/**
 * to_string convierte los atributos a string.
 *
 * Muestra el resumen del gato separando ahorro mensual y gastos fijos.
 * Incluye nota según si es cachorro o adulto.
 *
 * @param
 * @return string con los valores y texto concatenado.
 */
string Gato::to_string() {
    stringstream aux;
    aux << nombre << " (Gato " << (esCachorro ? "cachorro" : "adulto") << ")\n";
    if (esCachorro)
        aux << "  Esquema inicial (gasto unico): $" << calcularEsquemaInicial() << "\n";
    aux << "  Ahorro mensual:        $" << calcularAhorroMensual() << "/mes\n";
    aux << "  Gastos fijos:          $" << calcularGastosFijos() << "/mes\n";
    aux << "  Total a apartar:       $" << calcularGastoMensual() << "/mes\n";
    if (esCachorro) {
        aux << "  Nota: el esquema inicial es un gasto unico que debes cubrir\n";
        aux << "  de inmediato y no esta incluido en el presupuesto mensual.\n";
        aux << "  El ahorro mensual esta calculado para que cuando tu mascota\n";
        aux << "  cumpla 12 meses tengas cubierto su primer esquema de adulto.\n";
    } else {
        aux << "  Nota: este presupuesto asume que tu mascota acaba de recibir\n";
        aux << "  sus vacunas y desparasitacion. Tienes aproximadamente 12 meses\n";
        aux << "  para ahorrar para las proximas vacunas y 3 meses para la\n";
        aux << "  siguiente desparasitacion.\n";
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
string Gato::toStringDesglose() {
    stringstream aux;
    aux << nombre << " (Gato " << (esCachorro ? "cachorro" : "adulto") << ")\n";
    if (esCachorro) {
        aux << "  Esquema inicial de vacunacion (gasto unico):\n";
        for (int i = 0; i < numVacunasInicial; i++)
            aux << "    " << vacunasInicial[i].get_nombre()
                << "  $" << vacunasInicial[i].get_precio() << "\n";
        if (!positivoLeucemia)
            aux << "    *Leucemia Felina solo si resultado es negativo\n";
        aux << "    Total esquema inicial: $" << calcularEsquemaInicial() << "\n\n";
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
        aux << "  Nota: el esquema inicial es un gasto unico que debes cubrir\n";
        aux << "  de inmediato y no esta incluido en el presupuesto mensual.\n";
        aux << "  El ahorro mensual esta calculado para que cuando tu mascota\n";
        aux << "  cumpla 12 meses tengas cubierto su primer esquema de adulto.\n\n";
    } else {
        aux << "  Nota: este presupuesto asume que tu mascota acaba de recibir\n";
        aux << "  sus vacunas y desparasitacion. Tienes aproximadamente 12 meses\n";
        aux << "  para ahorrar para las proximas vacunas y 3 meses para la\n";
        aux << "  siguiente desparasitacion.\n\n";
    }
    aux << "  Total a apartar mensualmente: $" << calcularGastoMensual() << "/mes\n";
    return aux.str();
}

/**
 * endif: cierre de ifndef
 */
#endif // GATO_H_