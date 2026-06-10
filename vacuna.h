/*
*
•⁠  ⁠PetBudget
•⁠  ⁠Fernanda Jiménez Estrada
•⁠  ⁠A01206671
•⁠  ⁠09/06/2026
•⁠  ⁠Esta clase define el objeto Vacuna con nombre, precio, frecuencia
•⁠  ⁠y si ya fue aplicada.
*/

#ifndef VACUNA_H_
#define VACUNA_H_

#include <string>
#include <sstream>

using namespace std;

// Declaracion de clase Vacuna
class Vacuna {
    // Declaro variables de instancia privadas
private:
    string nombre;
    double precio;
    string frecuencia;  // "mensual", "trimestral", "anual" o "unico"
    bool aplicada;

    // Declaro metodos publicos
public:
    // constructor por default
    Vacuna(): nombre(""), precio(0), frecuencia(""), aplicada(false) {}

    Vacuna(string nom, double prec, string frec):
        nombre(nom), precio(prec), frecuencia(frec), aplicada(false) {}

    string get_nombre()  { return nombre; }
    double get_precio()  { return precio; }
    bool get_aplicada()  { return aplicada; }

    void marcarAplicada() { aplicada = true; }

    double calcularAporteMensual();
    string to_string();
};

/**
 * calcularAporteMensual divide el precio según la frecuencia.
 *
 * Si la vacuna ya fue aplicada regresa 0.
 * Si es anual divide entre 12, si es trimestral entre 3.
 *
 * @param
 * @return double con el aporte mensual de la vacuna.
 */
double Vacuna::calcularAporteMensual() {
    if (aplicada) return 0.0;
    if (frecuencia == "anual") return precio / 12.0;
    if (frecuencia == "trimestral") return precio / 3.0;
    return precio;
}

/**
 * to_string convierte los atributos a string.
 *
 * Concatena todos los valores de los atributos en un string para ser impreso.
 *
 * @param
 * @return string con los valores y texto concatenado.
 */
string Vacuna::to_string() {
    stringstream aux;
    aux << nombre << " $" << precio << " (" << frecuencia << ")"
        << (aplicada ? " [ya aplicada]" : "") << "\n";
    return aux.str();
}

/**
•⁠  ⁠endif: cierre de ifndef
*/
#endif  // VACUNA_H_
