// ===========================================================
//
// File: registro.h
// Autor: Luis Angel Zavala
// Descripcion: Este archivo contiene la clase registro
//              con sus respectivos metodos para el guardado
//              de los datos contenidos en bitacora.txt
//
//============================================================
#ifndef REGISTRO_H
#define REGISTRO_H

#include <vector>
#include <string>
#include "utility.h"

using namespace std;

class Registro{
    private:
        int id;
        string mes;
        int dia;
        string hora;
        string ip;
        string razon;
    public:
        Registro(string datos);
        string to_string();
        int get_id(){return id;}
};

// ==================================================
// Constructor de la clase  registro
// @param string con linea de datos de bitacora.txt
// @return
//
// ==================================================
Registro::Registro(string datos){
    vector<string> aux;
    aux = split(datos, ' ');
    mes = aux[0];
    dia = stoi(aux[1]);
    hora = aux[2];
    ip = aux[3];
    for(int i = 4; i < aux.size(); i++){
        razon = razon+" "+ aux[i];
    }

    id = fecha_to_dias(mes,dia);
}

// =========================================================================
// to_string convierte los atributos a string.
// concatena todos los valores de los atributos en un string para ser impreso
//
// @param
// @return string con los valores y texto concatenado.
// ==========================================================================
string Registro :: to_string(){
    stringstream aux;
    aux << mes << " "<< dia<<" "<<hora<<" "<<ip<<" "<<razon<<"\n";
    return aux.str();
}

#endif
