//
//  tar10.cpp
//  Algoritmos
//
//  Abigail Guadalupe Velazquez Sanchez A01566592 Grupo1
//  Creado el 16/04/2021
//

#include <stdio.h>
#include <iostream>
#define MAX 11
using namespace std;

void calcula(int OG[MAX][MAX], int Acum[MAX][MAX],int n){
    // Copiar los datos de la ultima linea del triangulo
    for (int i = 0; i<n; i++) {
         Acum[n-1][i] = OG[n-1][i];
    }
    
    // Calcular el lado mas costoso y sumarlo a la matriz de Acum
    for (int i = n-2; i>=0; i--) {
        for (int j = 0; j<=i; j++) {
            Acum[i][j] = OG[i][j] + max(Acum[i+1][j], Acum[i+1][j+1]);
             
        }
    }
}



int main(){
    int OG[MAX][MAX]; // Matriz original con los datos del triangulo
    int Acum[MAX][MAX]; // Matriz que contendrá los datos acumulados
    int c, n;// cantidad de cases, y n cantidad de lineas
    for (int i=0; i<MAX; i++){
        for (int j=0; j<MAX; j++){
            Acum[i][j] = 0;
            
        }
    }
    
    cin>>c;
    for (int i = 0; i<c; i++) {
        cin>>n;
        for (int i = 0; i< n ; i++){
            for (int j=0; j<=i; j++){
                cin>>OG[i][j];
            }
        }
        calcula(OG, Acum, n);
        cout<<Acum[0][0]<<endl;
    }
    return 0;
}
/*
2
3
1
2 1
1 2 3
4
1
1 2
4 1 2
2 3 1 1
*/
