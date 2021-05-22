//
//  tar10.cpp
//  Algoritmos
//
//  Abigail Guadalupe Velazquez Sanchez A01566592 Grupo1
//  Creado el 16/04/2021
//

#include <stdio.h>
#include <iostream>
#define MAX 50
using namespace std;

int calcula(int mat[MAX][MAX],int n,int m){
    int r = n+2;
    int c = m+2;
    if ((n<3 && m<2)||(n<2&&m<3)) {
        return 0;
    }else{
        mat[2][2] = 1;
        
        for (int i = 3; i<r; i++) {
            for (int j = 2; j<c; j++) {
                mat[i][j] = mat[i-1][j-2] + mat[i-2][j-1];
            }
        }
       return mat[r-1][c-1];
    }
    
    
}



int main(){
    int mat[MAX][MAX]; // Matriz original con los datos del triangulo
    int n, m;// cantidad de renglones y columnas del chessboard
    for (int i=0; i<MAX; i++){
        for (int j=0; j<MAX; j++){
            mat[i][j] = 0;
            
        }
    }
    
    cin>>n>>m;
    cout<<calcula(mat, n, m)<<endl;
   
    return 0;
}
