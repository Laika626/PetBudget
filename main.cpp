/**
 * menuGastosExtra permite agregar gastos extra manuales al gato.
 *
 * Sobrecarga para recibir un apuntador a Gato.
 * Sigue pidiendo gastos hasta que el usuario elija terminar.
 *
 * @param gato apuntador al objeto Gato al que se le agregan gastos.
 * @return
 */

#include <iostream>
#include "presupuesto.h"
#include <string>

using namespace std;

// Sobrecarga: menu de gastos extra para Perro
void menuGastosExtra(Perro* perro);
// Sobrecarga: menu de gastos extra para Gato
void menuGastosExtra(Gato* gato);

/**
 * menuGastosExtra permite agregar gastos extra manuales al perro.
 *
 * Sobrecarga para recibir un apuntador a Perro.
 * Sigue pidiendo gastos hasta que el usuario elija terminar.
 *
 * @param Perro* perro
 * @return
 */
void menuGastosExtra(Perro* perro) {
    int opcion;
    cout << "\nAgregar gastos extra a " << perro->get_nombre() << "\n";
    cout << "1. Agregar gasto\n2. Terminar\nOpcion: ";
    cin >> opcion;
    while (opcion == 1) {
        string desc, frec;
        double precio;
        cout << "Descripcion: "; cin >> desc;
        cout << "Precio: ";      cin >> precio;
        cout << "Frecuencia (mensual/trimestral/anual): "; cin >> frec;
        perro->agregarGasto(desc, precio, frec);
        cout << "1. Agregar gasto\n2. Terminar\nOpcion: ";
        cin >> opcion;
    }
}

/**
 * menuGastosExtra permite agregar gastos extra manuales al gato.
 *
 * Sobrecarga para recibir un apuntador a Gato.
 * Sigue pidiendo gastos hasta que el usuario elija terminar.
 *
 * @param Gato* gato
 * @return
 */
void menuGastosExtra(Gato* gato) {
    int opcion;
    cout << "\nAgregar gastos extra a " << gato->get_nombre() << "\n";
    cout << "1. Agregar gasto\n2. Terminar\nOpcion: ";
    cin >> opcion;
    while (opcion == 1) {
        string desc, frec;
        double precio;
        cout << "Descripcion: "; cin >> desc;
        cout << "Precio: ";      cin >> precio;
        cout << "Frecuencia (mensual/trimestral/anual): "; cin >> frec;
        gato->agregarGasto(desc, precio, frec);
        cout << "1. Agregar gasto\n2. Terminar\nOpcion: ";
        cin >> opcion;
    }
}

int main() {
    Presupuesto presupuesto;  // se crea vacio, sin mascotas
    int opcion;

    do {
        cout << "\n========================================\n";
        cout << "             PETBUDGET                  \n";
        cout << "========================================\n";
        cout << "1. Agregar perro\n";
        cout << "2. Agregar gato\n";
        cout << "3. Ver resumen\n";
        cout << "4. Ver desglose completo\n";
        cout << "5. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            string nombre, raza;
            int edad;
            cout << "\nNombre del perro: "; cin >> nombre;
            cout << "Edad en meses: ";      cin >> edad;
            cout << "Raza: ";               cin >> raza;

            // crear el perro con new — devuelve un apuntador Perro*
            // el constructor llama automaticamente cargarEsquemaVacunacion()
            Perro* perro = new Perro(nombre, edad, raza);

            menuGastosExtra(perro);  // agregar gastos extra manuales

            // guardar como Mascota* en el arreglo — aqui entra el polimorfismo
            presupuesto.agregarMascota(perro);
            cout << "\nPerro agregado correctamente.\n";

        } else if (opcion == 2) {
            string nombre;
            int edad;
            char leucemia;
            bool positivoLeucemia = false;

            cout << "\nNombre del gato: ";                  cin >> nombre;
            cout << "Edad en meses: ";                      cin >> edad;
            cout << "Positivo a leucemia felina? (s/n): ";  cin >> leucemia;

            // convertir la respuesta s/n a bool
            if (leucemia == 's' || leucemia == 'S')
                positivoLeucemia = true;

            // crear el gato con new — devuelve un apuntador Gato*
            // el constructor llama automaticamente cargarEsquemaVacunacion()
            Gato* gato = new Gato(nombre, edad, positivoLeucemia);

            menuGastosExtra(gato);  // agregar gastos extra manuales

            // guardar como Mascota* en el arreglo — aqui entra el polimorfismo
            presupuesto.agregarMascota(gato);
            cout << "\nGato agregado correctamente.\n";

        } else if (opcion == 3) {
            // muestra resumen separando ahorro mensual y gastos fijos
            presupuesto.mostrarResumen();

        } else if (opcion == 4) {
            // muestra desglose completo por vacuna y gasto
            presupuesto.mostrarDesglose();

        } else if (opcion != 5) {
            cout << "Opcion invalida.\n";
        }
    // el programa corre hasta que el usuario elija salir
    } while (opcion != 5);
        cout << "\nHasta luego!\n";
    return 0;
}
