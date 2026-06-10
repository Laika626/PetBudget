/*
*
* PetBudget
* Fernanda Jiménez Estrada
* A01206671
* 09/06/2026
* Esta clase define el objeto abstracto Mascota que contiene las clases heredadas
* Perro y Gato.
*/

#ifndef MASCOTA_H_
#define MASCOTA_H_

#include <string>
#include <sstream>

using namespace std;

//Declaracion de clase Mascota que es abstracta
class Mascota {

    //Declaro variables de instancia
protected:
    string nombre;
    int edadMeses;
    string padecimientos[10];
    int numPadecimientos;
    bool esCachorro;
    string tipo;

    //Declaro los métodos que va a tener el objeto
public:
    Mascota(): nombre(""), edadMeses(0), numPadecimientos(0),
               esCachorro(false), tipo("") {}; //constructor por default

    Mascota(string nom, int edad, string tip):
        nombre(nom), edadMeses(edad), numPadecimientos(0), tipo(tip) {
        esCachorro = (edad < 12);
    };

    string get_nombre()   { return nombre; }
    string get_tipo()     { return tipo; }
    int get_edad()        { return edadMeses; }
    bool get_esCachorro() { return esCachorro; }

    void agregarPadecimiento(string padecimiento) {
        if (numPadecimientos < 10) {
            padecimientos[numPadecimientos] = padecimiento;
            numPadecimientos++;
        }
    }

    virtual double calcularGastosFijos() = 0;    //método abstracto será sobreescrito
    virtual double calcularAhorroMensual() = 0;  //método abstracto será sobreescrito
    virtual double calcularGastoMensual() = 0;   //método abstracto será sobreescrito
    virtual double calcularEsquemaInicial() = 0; //método abstracto será sobreescrito
    virtual string to_string() = 0;              //método abstracto será sobreescrito
    virtual string toStringDesglose() = 0;       //método abstracto será sobreescrito
};

/**
 * endif: cierre de ifndef
 */
#endif // MASCOTA_H_