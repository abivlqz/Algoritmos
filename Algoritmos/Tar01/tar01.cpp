//
//  tar01.cpp
//  Algoritmos
//
//  Abigail Guadalupe Velazquez Sanchez A01566592 Grupo1
//  Creado el 13/02/2021
/*  Este programa solicita al usuario un tipo de dato string que contenga varios caracteres duplicados y continuos con excepcion de un caracter, el programa encuentra y devuelve este caracter unico dentro del string
*/

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


// Funcion findChar que recibe de parametro un string con caracteres repetidos excepto uno
// y busca y despliega en pantalla ese unico caracter que no se repite
void findChar(string str){
    int low = 0;
    int high = (int(str.size())-1);
    bool found = false;
    
    while (low<= high && found == false ) {
        int central = (low+high)/2;
        
        //Si sus caracteres vecinos son distintos es el unico
        if (str[central] != str[central-1] && str[central] != str[central+1] ) {
            found = true;
            cout<<str[central]<<endl;
            
        } // Si su caracter vecino de la derecha es su pareja
        else if ( str[central] == str[central+1] ){
            // Si la cantidad de caracteres a la derecha es impar, el caracter esta a la derecha de la pareja
            if ( (high-(central+2))%2 == 0 )
                low = central +2;
            else // Si es par esta a la izquierda
                high = central -1;
            
        } // Si su caracter vecino de la izquierda es su pareja
        else{
            // Si la cantidad de caracteres a la izquierda es impar, el caracter esta a la izquierda de la pareja
            if ( ((central-2)-low)%2 == 0 )
                high = central -2;
            else  // Si es par esta a la derecha
                low = central +1;
        }
    }
   
}


// Programa principal
int main(){
    
    string str;
    cout<<"Ingrese su string :"<<endl;
    getline(cin, str);
    findChar(str);
    
    return 0;
}
