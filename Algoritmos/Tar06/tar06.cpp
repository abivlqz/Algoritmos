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
#define MAX 16
using namespace std;

void rellenaTrinomio( int mat[MAX][MAX], int rIni, int rFin, int cIni, int cFin, int rOc, int cOc, int &q){
   
    
    if (rIni != rFin && cIni != cFin) {
        int rm =(rIni+rFin)/2;
        int cm =(cIni + cFin)/2;
        q++;
        if (cOc> cm) {//Significa que esta en alguno de los cuadrantes derechos
            if (rOc> rm) {//Significa que esta en el cuadrante derecho inferior

                mat[rm][cm]=q;
                mat[rm+1][cm]=q;
                mat[rm][cm+1]=q;
                rellenaTrinomio(mat, rIni, rm, cIni, cm, rm, cm, q);// izq sup
                rellenaTrinomio(mat, rIni, rm, cm+1, cFin, rm, cm+1, q);// der sup
                rellenaTrinomio(mat, rm+1, rFin, cIni, cm, rm+1, cm, q);// izq inf
                rellenaTrinomio(mat, rm+1, rFin, cm+1, cFin, rOc, cOc, q);// der inf
                
              
            }else{//Significa que esta en el cuadrante derecho superior
                mat[rm][cm]=q;
                mat[rm+1][cm]=q;
                mat[rm+1][cm+1]=q;
                rellenaTrinomio(mat, rIni, rm, cIni, cm, rm, cm, q);// izq sup
                rellenaTrinomio(mat, rIni, rm, cm+1, cFin, rOc, cOc, q);// der sup
                rellenaTrinomio(mat, rm+1, rFin, cIni, cm, rm+1, cm, q);// izq inf
                rellenaTrinomio(mat, rm+1, rFin, cm+1, cFin, rm+1, cm+1, q);// der inf
                
               
            }
        }else{//Significa que esta en alguno de los cuadrantes izquierdos
            if (rOc> rm) {//Significa que esta en el cuadrante izquierdo inferior
                mat[rm][cm]=q;
                mat[rm][cm+1]=q;
                mat[rm+1][cm+1]=q;
                rellenaTrinomio(mat, rIni, rm, cIni, cm, rm, cm, q);// izq sup
                rellenaTrinomio(mat, rIni, rm, cm+1, cFin, rm, cm+1, q);// der sup
                rellenaTrinomio(mat, rm+1, rFin, cIni, cm, rOc, cOc, q);// izq inf
                rellenaTrinomio(mat, rm+1, rFin, cm+1, cFin, rm+1, cm+1, q);// der inf
                
                
            }else{//Significa que esta en el cuadrante izquierdo superior
                mat[rm][cm+1]=q;
                mat[rm+1][cm]=q;
                mat[rm+1][cm+1]=q;
                rellenaTrinomio(mat, rIni, rm, cIni, cm, rOc, cOc, q);// izq sup
                rellenaTrinomio(mat, rIni, rm, cm+1, cFin, rm, cm+1, q);// der sup
                rellenaTrinomio(mat, rm+1, rFin, cIni, cm, rm+1, cm, q);// izq inf
                rellenaTrinomio(mat, rm+1, rFin, cm+1, cFin, rm+1, cm+1, q);// der inf
                
               
            }
            
            
        }
        
        
        
        
        
        
        
        
        
        
        
    }
    
}


int main(){
    int mat[MAX][MAX];
    int n, columna, fila;
    int q = 0;
    cout<<"Ingresa la dimensión N de tu matriz cuadrada *recuerda que debe ser potencia de 2* :"<<endl;
    cin>> n;
    cout<<"Ingresa la fila de la casilla ocupada: "<<endl;
    cin>>fila;
    cout<<"Ingresa la columna de la casilla ocupada: "<<endl;
    cin>>columna;
//    for (int i = 0; i<n; i++) {
//           for (int j = 0; j<n; j++) {
//               mat[i][j]=0;
//           }
//           cout<<endl;
//       }
    mat[fila][columna]= 0;
    
    
    rellenaTrinomio(mat, 0, n-1, 0, n-1, fila, columna, q);
    
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
