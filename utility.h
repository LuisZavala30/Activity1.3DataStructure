// ==============================================
// File: utility.h
// Este archivo contiene funciones utiles
// requeridas para el manejo de los datos
// de la bitacora y su transformación.
//
// ==============================================

#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(const string &s, char delimiter)
{
   vector<string> tokens;
   string token;
   istringstream tokenStream(s);
   while ( getline(tokenStream, token, delimiter) ) {
      tokens.push_back(token);
   }
   return tokens;
}

// =================================================================
// Swap the content of two localities (i, j) in vector v.
//
// @param v, a vector of T elements.
// @param i, an index in the vector.
// @param j, an index in the vector.
// =================================================================
template <class T>
void swap(vector<T> &v, int i, int j) {
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

// =============================================================
// Convierte el mes y dia en un numero entre 1-365
//
// @param mes, Un string con las iniciales del mes a convertir
// @param dia, Un entero con el dia a convertir
// =============================================================
int fecha_to_dias(string mes, int dia){
    int total = 0;

    if (mes=="Jan"){
        total = dia;
        return total;
    }
    else if(mes=="Feb"){
        total = 31 + dia;
        return total;
    }
    else if(mes=="Mar"){
        total = 59 + dia;
        return total;
    }
    else if(mes=="Apr"){
        total = 90 + dia;
        return total;
    }
    else if(mes=="May"){
        total = 120 + dia;
        return total;
    }
    else if(mes=="Jun"){
        total = 151 + dia;
        return total;
    }
    else if(mes=="Jul"){
        total = 181 + dia;
        return total;
    }
    else if(mes=="Aug"){
        total = 212 + dia;
        return total;
    }
    else if(mes=="Sep"){
        total = 243 + dia;
        return total;
    }
    else if(mes=="Oct"){
        total = 273 + dia;
        return total;
    }
    else if(mes=="Nov"){
        total = 304 + dia;
        return total;
    }
    else if(mes=="Dec"){
        total = 334 + dia;
        return total;
    }

    return 0;
}

#endif
