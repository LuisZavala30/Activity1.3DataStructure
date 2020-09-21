//====================================================================
//
// File: algoritmos.h
// Autor: Luis Angel Zavala
// Description: Este archivo contiene las funciones necesarias
//              para realizar el algoritmo de quickSort y para
//              realizar busqueda binaria.
//
// ===================================================================

#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <iostream>

using namespace std;

// =================================================================
// Encuentra el pivote que se utilizara para la separación
//
// @param A, vector de destino.
// @param low, indice menor.
// @param high, indice mayor.
// @return el numero pivote, sino existe, regresa -1.
// =================================================================
template <class T>
int find_pivot(vector<T> &A, int low, int high) {
	int i;

	for (i = low + 1; i <= high; i++) {
		if (A[low].get_id() > A[i].get_id()) {
			return A[low].get_id();
		} else if (A[low].get_id() < A[i].get_id()){
			return A[i].get_id();
		}
	}
	return -1;
}

// =================================================================
// Separa los elementos. En la izquierda coloca los elementos menores
// al pivote, en la derecha los elementos mayores al pivote.
// @param A, vector de destino
// @param low, indice menor.
// @param high, indice mayor.
// @return punto donde comienzan los elementos mayores o iguales al pivote
// =================================================================
template <class T>
int make_partition(vector<T> &A, int low, int high, int pivot) {
	int i, j;

	i = low;
	j = high;
	while (i < j) {
		swap(A, i , j);
		while (A[i].get_id() < pivot) {
			i++;
		}
		while (A[j].get_id() >= pivot) {
			j--;
		}
	}
	return i;
}

// =================================================================
// Si hay un pivote, separa los elementos
//
// @param A, vector de destino.
// @param low, indice menor.
// @param high, indice mayor.
// =================================================================
template <class T>
void quick(vector<T> &A, int low, int high) {
	int pivot, pos;

	pivot = find_pivot(A, low, high);
	if (pivot != -1) {
		pos = make_partition(A, low, high, pivot);
		quick(A, low, pos - 1);
		quick(A, pos, high);
	}
}

// =================================================================
// Performs the quick sort algorithm.
//
// @param A, Vector de T elementos.
// @param size, Numero de elementos en el vector.
// =================================================================
template <class T>
void quickSort(vector <T> &A, int size) {
	quick(A, 0, size - 1);
}

// =================================================================
// Busqueda binaria para encontrar un numero en un vector.
//
// @param v, Un vector de T elementos.
// @param key, Elemento a buscar.
// @param p, -1 si se busca posInicial, +1 si se busca posFin
// @return El indice del numero buscado, -1 si el numero es menor
//          al primer numero de la lista, -2 si el numero es mayor
//          al ultimo numero de lista
// =================================================================
template <class T>
int binarySearch(vector<T> &v, int key, int p) {
	int low, high, mid;

	low = 0;
	high = v.size() - 1;

	if (key < v[low].get_id()){
        return -1;
	}
	else if (key > v[high].get_id()){
        return -2;
	}
	else{
        while (low <= high) {
            mid = low + ((high - low) / 2);
            if (key == v[mid].get_id()) {
                while((key == v[mid].get_id()) && (mid > 1)){
                    mid = mid + p;
                }
                return mid;
            } else if (key < v[mid].get_id()) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }
    return mid;
}


#endif // ALGORITMOS_H
