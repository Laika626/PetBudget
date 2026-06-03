/*
 * PetBudget - main.cpp
 * Fernanda Jiménez Estrada
 * Programa principal con menú interactivo
 * Compilar: g++ mascota.h vacuna.h gasto.h perro.h gato.h presupuesto.h main.cpp
 */

// iostream permite usar cout y cin para entrada y salida de datos
// presupuesto.h incluye todas las clases del proyecto (Perro, Gato, Mascota, Vacuna, Gasto)
#include <iostream>
#include "presupuesto.h"

using namespace std;

/**
 * menuVacunas para Perro (sobrecarga)
 * Muestra las vacunas precargadas y permite marcar las que ya tiene aplicadas
 * Recibe un apuntador a Perro para trabajar sobre el mismo objeto creado en main
 */
void menuVacunas(Perro* perro) {
    // muestra el nombre del perro y su lista de vacunas con índices
    cout << "\nVacunas de " << perro->get_nombre() << ":\n";
    perro->mostrarVacunas();

    int opcion;
    cout << "Ingresa el numero de vacuna ya aplicada (-1 para terminar): ";
    cin >> opcion;

    // sigue pidiendo números de vacunas hasta que el usuario ingrese -1
    // cada vacuna marcada como aplicada regresa 0 en calcularAporteMensual()
    while (opcion != -1) {
        perro->marcarVacunaAplicada(opcion);
        cout << "Ingresa el numero de vacuna ya aplicada (-1 para terminar): ";
        cin >> opcion;
    }
}

/**
 * menuVacunas para Gato (sobrecarga)
 */
void menuVacunas(Gato* gato) {
    // muestra el nombre del gato y su lista de vacunas con índices
    cout << "\nVacunas de " << gato->get_nombre() << ":\n";
    gato->mostrarVacunas();

    int opcion;
    cout << "Ingresa el numero de vacuna ya aplicada (-1 para terminar): ";
    cin >> opcion;

    // sigue pidiendo números de vacunas hasta que el usuario ingrese -1
    while (opcion != -1) {
        gato->marcarVacunaAplicada(opcion);
        cout << "Ingresa el numero de vacuna ya aplicada (-1 para terminar): ";
        cin >> opcion;
    }
}

/**
 * menuGastosExtra para Perro (sobrecarga)
 * Permite al usuario agregar medicamentos u otros gastos específicos del perro
 */
void menuGastosExtra(Perro* perro) {
    int opcion;
    cout << "\nAgregar gastos extra a " << perro->get_nombre() << "\n";
    cout << "1. Agregar gasto\n2. Terminar\nOpcion: ";
    cin >> opcion;

    // sigue pidiendo gastos mientras el usuario elija la opción 1
    while (opcion == 1) {
        string desc, frec;
        double precio;

        // pedir los datos del gasto al usuario
        cout << "Descripcion: "; cin >> desc;
        cout << "Precio: ";      cin >> precio;
        cout << "Frecuencia (mensual/anual): "; cin >> frec;

        // agregar el gasto al arreglo de gastos del perro
        perro->agregarGasto(desc, precio, frec);

        cout << "1. Agregar gasto\n2. Terminar\nOpcion: ";
        cin >> opcion;
    }
}

/**
 * menuGastosExtra para Gato (sobrecarga)
 */
void menuGastosExtra(Gato* gato) {
    int opcion;
    cout << "\nAgregar gastos extra a " << gato->get_nombre() << "\n";
    cout << "1. Agregar gasto\n2. Terminar\nOpcion: ";
    cin >> opcion;

    // sigue pidiendo gastos mientras el usuario elija la opción 1
    while (opcion == 1) {
        string desc, frec;
        double precio;

        // pedir los datos del gasto al usuario
        cout << "Descripcion: "; cin >> desc;
        cout << "Precio: ";      cin >> precio;
        cout << "Frecuencia (mensual/anual): "; cin >> frec;

        // agregar el gasto al arreglo de gastos del gato
        gato->agregarGasto(desc, precio, frec);

        cout << "1. Agregar gasto\n2. Terminar\nOpcion: ";
        cin >> opcion;
    }
}

int main() {
    // crear el presupuesto vacío, sin mascotas, conforme el usuario agregue mascotas se irá llenando
    Presupuesto presupuesto;
    int opcion;

    do {
        // mostrar menú principal
        cout << "\n========================================\n";
        cout << "             PETBUDGET                  \n";
        cout << "========================================\n";
        cout << "1. Agregar perro\n";
        cout << "2. Agregar gato\n";
        cout << "3. Ver resumen\n";
        cout << "4. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            // pedir datos del perro al usuario
            string nombre, raza;
            int edad;
            cout << "\nNombre del perro: "; cin >> nombre;
            cout << "Edad en meses: ";      cin >> edad;
            cout << "Raza: ";               cin >> raza;

            // new devuelve un apuntador Perro*
            // el constructor llama a cargarEsquemaVacunacion() que precarga las vacunas según si es cachorro o adulto
            Perro* perro = new Perro(nombre, edad, raza);

            // si es cachorro (menos de 12 meses) preguntar qué vacunas ya tiene, para no cobrar las que ya están aplicadas
            if (perro->get_esCachorro()) {
                cout << "\nEs cachorro. Indica que vacunas ya tiene aplicadas.\n";
                menuVacunas(perro); // sobrecarga para Perro
            }

            // agregar medicamentos u otros gastos extra manuales
            menuGastosExtra(perro);

            presupuesto.agregarMascota(perro);
            cout << "\nPerro agregado correctamente.\n";

        } else if (opcion == 2) {
            // pedir datos del gato al usuario
            string nombre;
            int edad;
            char leucemia;
            bool positivoLeucemia = false;

            cout << "\nNombre del gato: ";                  cin >> nombre;
            cout << "Edad en meses: ";                      cin >> edad;
            cout << "Positivo a leucemia felina? (s/n): ";  cin >> leucemia;

            // convertir la respuesta s/n a bool, si es positivo no se cargan las vacunas de leucemia felina
            if (leucemia == 's' || leucemia == 'S')
                positivoLeucemia = true;

            // crear el gato con new
            Gato* gato = new Gato(nombre, edad, positivoLeucemia);

            // si es cachorro (menos de 12 meses) preguntar qué vacunas ya tiene
            if (gato->get_esCachorro()) {
                cout << "\nEs cachorro. Indica que vacunas ya tiene aplicadas.\n";
                menuVacunas(gato);
            }

            // agregar medicamentos u otros gastos extra manuales
            menuGastosExtra(gato);

            presupuesto.agregarMascota(gato);
            cout << "\nGato agregado correctamente.\n";

        } else if (opcion == 3) {
            // mostrar todas las mascotas y el total mensual
            presupuesto.mostrarResumen();

        } else if (opcion != 4) {
            cout << "Opcion invalida.\n";
        }

    // el programa sigue corriendo hasta que el usuario elija la opción 4
    } while (opcion != 4);

    cout << "\nHasta luego!\n";
    return 0;
}