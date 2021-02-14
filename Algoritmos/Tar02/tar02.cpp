//
//  tar02.cpp
//  Algoritmos
//
//  Abigail Guadalupe Velazquez Sanchez A01566592 Grupo1
//  Creado el 13/02/2021
/*  Este programa solicita al usuario un tipo de dato string que contenga varios ceros y unos y de tamaño 1-200,000, y despliega en pantalla la longitud final del string si se eliminan n-veces los pares de unos y ceros ya sea 10 o 01
*/

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

// Funcion findLong que recibe de parametro un string con numeros 1s y 0s junto con el tamaño del string
// y despliega en pantalla el numero de caracteres que sobran despues de eliminar cualquier
// uno y cero que esten juntos
void findLong(string str, int n){
    int numCeros = 0;
    int numOnes = 0;
    // Cuenta el numero de 0s y el numero de 1s en el string
    for (int i = 0; i<n; i++) {
        if (str[i] == '0')
            numCeros++;
        else
            numOnes++;
    }
    // Imprime la diferencia, que es igual a la cantidad de numeros resultantes
    // despues de la operacion de eliminar 0s y 1s que esten consecutivos
    if (numCeros>=numOnes)
        cout<<numCeros-numOnes<<endl;
    else
        cout<<numOnes-numCeros<<endl;
}

// Programa principal
int main(){
    string str;
    int n=0;
    // Verifica que el string tenga una longitud inicial de 1 a 200,000
    while (n<1 || n>200000) {
        cout<<"Ingrese la longitud del string desde 1 a 200,000"<<endl;
        cin>>n;
    }
    cout<<"Ingrese su string :"<<endl;
    cin>>str;
    findLong(str,n);
    
    return 0;
}
