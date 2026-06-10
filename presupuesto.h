/*
*
* PetBudget
* Fernanda Jiménez Estrada
* A01206671
* 09/06/2026
* Esta clase define el objeto Presupuesto que gestiona todas las mascotas
* y calcula el total mensual usando polimorfismo.
*/

#ifndef PRESUPUESTO_H_
#define PRESUPUESTO_H_

#include <string>
#include <iostream>
#include "perro.h"
#include "gato.h"

using namespace std;

const int MAX = 100;

//Declaracion de clase Presupuesto
class Presupuesto {

//Variables de instancia privadas del objeto
private:
    Mascota* mascotas[MAX]; //arreglo de apuntadores para usar polimorfismo
    int numMascotas;

//Metodos publicos del objeto
public:
    Presupuesto(): numMascotas(0) {}; //constructor por default

    void agregarMascota(Perro* perro);
    void agregarMascota(Gato* gato);
    double calcularTotalMensual();
    void mostrarResumen();
    void mostrarDesglose();
};

/**
 * agregarMascota agrega un perro al arreglo de mascotas.
 *
 * Sobrecarga para recibir un apuntador a Perro.
 *
 * @param Perro* perro
 * @return
 */
void Presupuesto::agregarMascota(Perro* perro) {
    if (numMascotas < MAX) {
        mascotas[numMascotas] = perro;
        numMascotas++;
    }
}

/**
 * agregarMascota agrega un gato al arreglo de mascotas.
 *
 * Sobrecarga para recibir un apuntador a Gato.
 *
 * @param Gato* gato
 * @return
 */
void Presupuesto::agregarMascota(Gato* gato) {
    if (numMascotas < MAX) {
        mascotas[numMascotas] = gato;
        numMascotas++;
    }
}

/**
 * calcularTotalMensual suma el gasto mensual de todas las mascotas.
 *
 * Usa polimorfismo para llamar calcularGastoMensual() de cada mascota.
 *
 * @param
 * @return double con el total mensual de todas las mascotas.
 */
double Presupuesto::calcularTotalMensual() {
    double total = 0;
    for (int i = 0; i < numMascotas; i++)
        total += mascotas[i]->calcularGastoMensual();
    return total;
}

/**
 * mostrarResumen imprime el resumen por mascota separando
 * ahorro mensual y gastos fijos.
 *
 * @param
 * @return
 */
void Presupuesto::mostrarResumen() {
    cout << "========================================\n";
    cout << "          RESUMEN PETBUDGET             \n";
    cout << "========================================\n";
    if (numMascotas == 0) {
        cout << "No hay mascotas registradas.\n";
        return;
    }
    for (int i = 0; i < numMascotas; i++) {
        cout << mascotas[i]->to_string();
        cout << "----------------------------------------\n";
    }
    cout << "Total a apartar mensualmente: $"
         << calcularTotalMensual() << "\n";
    cout << "========================================\n";
}

/**
 * mostrarDesglose imprime el desglose completo por vacuna y gasto.
 *
 * Usa polimorfismo para llamar toStringDesglose() de cada mascota.
 *
 * @param
 * @return
 */
void Presupuesto::mostrarDesglose() {
    cout << "========================================\n";
    cout << "         DESGLOSE PETBUDGET             \n";
    cout << "========================================\n";
    if (numMascotas == 0) {
        cout << "No hay mascotas registradas.\n";
        return;
    }
    for (int i = 0; i < numMascotas; i++) {
        cout << mascotas[i]->toStringDesglose();
        cout << "----------------------------------------\n";
    }
    cout << "Total a apartar mensualmente: $"
         << calcularTotalMensual() << "\n";
    cout << "========================================\n";
}

/**
 * endif: cierre de ifndef
 */
#endif // PRESUPUESTO_H_