// =========================================================
// autor: Luis Angel Zavala Robles
// matricula: A01706481
//
// main.cpp realiza la lectura y el procesado de los datos
// contenidos en bitacora.txt. Hace llamada a la funcion quickSort
// de algoritmos.h para ordenarlos y posteriormente realiza la
// busqueda mediante binarySearch de los elementos pertenecientes
// al rango de fechas indicado por el usuario.
// Finalmente crea un archivo txt con los datos ordenados.
//
// ==========================================================

#include <iostream>
#include <fstream>
#include <vector>
#include "algoritmos.h"
#include "registro.h"

#define filename "bitacora.txt"
#define outputfile "bitacoraOrdenada.txt"

int main(int argc, char* arg[]){
    ifstream input;
    ofstream output;
    vector<Registro> data;
	string line, mesInicio, mesFin;
	int idInicio, idFin,diaInicio, diaFin, posFin, posInicial;

	posInicial = 0;
	posFin = 0;

// Lectura del archivo bitacora.txt y creacion de objetos.
    input.open(filename);
	if (input.is_open()) {
		while (getline(input, line)) {
            Registro reg(line);
            data.push_back(reg);
		}
	}

	quickSort(data, data.size());

	do{
        cout << "Formato para ingreso de fechas: 3 primeras letras el mes en ingles con la primera letra en mayuscula, espacio, numero de dias. (Ejemplo: Jan 21)"<<endl;
        cout << "Fecha de Inicio: ";
        cin >> mesInicio >> diaInicio;
        cout << "Fecha de Fin: ";
        cin >> mesFin >> diaFin;

        idInicio = fecha_to_dias(mesInicio,diaInicio);
        idFin = fecha_to_dias(mesFin, diaFin);

        if(idInicio > idFin){
            cout << "La fecha de inicio debe ser menor a la fecha de fin. Intentelo de nuevo"<<endl;
        }
	} while(idInicio > idFin);


    posInicial = binarySearch(data, idInicio, -1);
    posFin = binarySearch(data, idFin, 1);


// Impresion de los datos entre las fechas seleccionadas
    if((posInicial<0)|| (posFin < 0)){
        if((posInicial< 0)&&(posFin < 0)){
            if(posInicial == posFin){
                cout << "No se han encontrado registros en el rango seleccionado"<<endl;
            }
            else{
                for(int i=0; i< data.size(); i++){
                    cout<< data[i].to_string();
                }
            }
        }

        else if(posInicial < posFin){
            for(int i=0; i<posFin; i++){
                cout << data[i].to_string();
            }
        }
        else if(posInicial > posFin){
            for (int i=posInicial+1; i<data.size(); i++){
                cout << data[i].to_string();
            }
        }
    }
    else if ((posInicial>0)&&(posFin>0)){
        for(int i=posInicial+1; i<posFin; i++){
            cout << data[i].to_string();
        }
    }

//  Creación del archivo txt ordenado
	output.open(outputfile);
	if (output.is_open()) {
		for (int i = 0; i < data.size(); i++) {
				output << data[i].to_string();
		}
	}
}



