/*
 * PetBudget - presupuesto.h
 * Fernanda Jiménez Estrada
 * Clase Presupuesto que gestiona todas las mascotas y calcula el total mensual
 * Usa polimorfismo con arreglo de apuntadores a Mascota
 */

#ifndef PRESUPUESTO_H_
#define PRESUPUESTO_H_

#include <string>
#include <iostream>
#include <sstream>
#include "perro.h"
#include "gato.h"

using namespace std;
/**
 *constante global que define el máximo de mascotas (100) que puedes trabajar con el programa.
 */
const int MAX = 100;

class Presupuesto {
    /**
     *mascotas es un arreglo de apuntadores a Mascota.
     *con esto guardamos tanto Perro* como Gato* en el mismo arreglo
     */
private:
    Mascota* mascotas[MAX]; // apuntador para usar polimorfismo
    int numMascotas;

public:
    /**
     * Presupuesto(): numMascotas(0) {};
     */
    Presupuesto(): numMascotas(0) {};

    /**
     * agregarMascota: metodo que agrega un perro al arreglo de mascotas
     * Sobrecarga para Perro
     * parametro: Perro* perro
     */
    void agregarMascota(Perro* perro) {
        if (numMascotas < MAX) {
            mascotas[numMascotas] = perro;
            numMascotas++;
        }
    }

    /**
     * agregarMascota: metodo agrega un gato al arreglo de mascotas
     * Sobrecarga para Gato
     * parametro: Gato* gato
     */
    void agregarMascota(Gato* gato) {
        if (numMascotas < MAX) {
            mascotas[numMascotas] = gato;
            numMascotas++;
        }
    }

    /**
     * calcularTotalMensual: metodo que suma el gasto mensual de todas las mascotas
     * @return double total mensual
     */
    double calcularTotalMensual() {
        double total = 0;
        for (int i = 0; i < numMascotas; i++)
            total += mascotas[i]->calcularGastoMensual();
        return total;
    }

    /**
     * mostrarMascotas: metodo que imprime todas las mascotas registradas
     */
    void mostrarMascotas() {
        for (int i = 0; i < numMascotas; i++)
            cout << mascotas[i]->to_string();
    }

    /**
     * mostrarResumen: metodo que imprime el resumen completo del presupuesto mensual
     */
    void mostrarResumen() {
        cout << "========================================\n";
        cout << "          RESUMEN PETBUDGET             \n";
        cout << "========================================\n";
        if (numMascotas == 0) {
            cout << "No hay mascotas registradas.\n";
            return;
        }
        mostrarMascotas();
        cout << "----------------------------------------\n";
        cout << "Total a apartar mensualmente: $"
             << calcularTotalMensual() << "\n";
        cout << "========================================\n";
    }
};

/**
 * endif: cierre de ifndef
 */
#endif // PRESUPUESTO_H_