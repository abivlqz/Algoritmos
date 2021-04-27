//
//  tar06.cpp
//  Algoritmos
//
//  Abigail Guadalupe Velazquez Sanchez A01566592 Grupo1
//  Creado el 07/03/2021
/*  Este programa solicita al usuario un tipo de dato entero N que sera la dimension de una matriz cuadrada, despues solicita la fila y la columna inicial de la casilla ocupada, rellena la matriz con trimonios en forma de L sin qque quede ningun lugar vacio y despliega en pantalla la matriz resultante completamente llena donde se pueden visualizar dichos trimonios
*/

#include <stdio.h>
#include <iostream>
#define MAX 32
using namespace std;

// Funcion recursiva rellenaTriomino que recibe de parametro una matriz cuadrada, los limites de la matriz, la fila y columna con la casilla ocupada y un entero con que
// llenar cada triomino, no regresa nada, modifica la matriz cuadrada solamente
void rellenaTriomino( int mat[MAX][MAX], int rIni, int rFin, int cIni, int cFin, int rOc, int cOc, int &q){
   
    if (rIni != rFin && cIni != cFin) {
        int rm =(rIni+rFin)/2;
        int cm =(cIni + cFin)/2;
        q++;
        if (cOc> cm) {//Significa que esta en alguno de los cuadrantes derechos
            if (rOc> rm) {//Significa que esta en el cuadrante derecho inferior
                mat[rm][cm]=mat[rm+1][cm]=mat[rm][cm+1]=q;
                rellenaTriomino(mat, rIni, rm, cIni, cm, rm, cm, q);// izq sup
                rellenaTriomino(mat, rIni, rm, cm+1, cFin, rm, cm+1, q);// der sup
                rellenaTriomino(mat, rm+1, rFin, cIni, cm, rm+1, cm, q);// izq inf
                rellenaTriomino(mat, rm+1, rFin, cm+1, cFin, rOc, cOc, q);// der inf
                
            }else{//Significa que esta en el cuadrante derecho superior
                mat[rm][cm]=mat[rm+1][cm]=mat[rm+1][cm+1]=q;
                rellenaTriomino(mat, rIni, rm, cIni, cm, rm, cm, q);// izq sup
                rellenaTriomino(mat, rIni, rm, cm+1, cFin, rOc, cOc, q);// der sup
                rellenaTriomino(mat, rm+1, rFin, cIni, cm, rm+1, cm, q);// izq inf
                rellenaTriomino(mat, rm+1, rFin, cm+1, cFin, rm+1, cm+1, q);// der inf
             }
        }else{//Significa que esta en alguno de los cuadrantes izquierdos
            if (rOc> rm) {//Significa que esta en el cuadrante izquierdo inferior
                mat[rm][cm]=mat[rm][cm+1]=mat[rm+1][cm+1]=q;
                rellenaTriomino(mat, rIni, rm, cIni, cm, rm, cm, q);// izq sup
                rellenaTriomino(mat, rIni, rm, cm+1, cFin, rm, cm+1, q);// der sup
                rellenaTriomino(mat, rm+1, rFin, cIni, cm, rOc, cOc, q);// izq inf
                rellenaTriomino(mat, rm+1, rFin, cm+1, cFin, rm+1, cm+1, q);// der inf
                
            }else{//Significa que esta en el cuadrante izquierdo superior
                mat[rm][cm+1]=mat[rm+1][cm]=mat[rm+1][cm+1]=q;
                rellenaTriomino(mat, rIni, rm, cIni, cm, rOc, cOc, q);// izq sup
                rellenaTriomino(mat, rIni, rm, cm+1, cFin, rm, cm+1, q);// der sup
                rellenaTriomino(mat, rm+1, rFin, cIni, cm, rm+1, cm, q);// izq inf
                rellenaTriomino(mat, rm+1, rFin, cm+1, cFin, rm+1, cm+1, q);// der inf
            }
        }
    }
}

// Programa principal
int main(){
    int mat[MAX][MAX];
    int n, columna, fila;
    int q = 0;
    cout<<"Ingresa la dimensión N de tu matriz cuadrada *recuerda que debe ser potencia de 2* :"<<endl;
    cin>> n;
    cout<<"Ingresa la fila de la casilla ocupada: ";
    cin>>fila;
    cout<<endl;
    cout<<"Ingresa la columna de la casilla ocupada: ";
    cin>>columna;
    cout<<endl;
    mat[fila][columna] = q;
    rellenaTriomino(mat, 0, n-1, 0, n-1, fila, columna, q);

    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            cout<<mat[i][j] << "\t" ;
        }
        cout<<endl;
        cout<<endl;
    }
    return 0;
}
