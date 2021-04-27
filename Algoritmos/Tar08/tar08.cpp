//
//  tar08.cpp
//  Algoritmos
//
//  Abigail Guadalupe Velazquez Sanchez A01566592 Grupo1
//  Creado el 24/03/2021
#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

// mat = matriz de costos
void leeArcos(int mat[100][100],  int m){
    int a,b,c;
    //inicializar
    for (int i = 0; i<100; i++) {
        mat[i][i]  = 0;
        for (int j = i+1; j<100; j++) {
            mat[i][j] = mat[j][i] = INT_MAX;
            
        }
    }
    
    // Lectura
    for (int i = 1; i<=m; i++) {
        cin>> a >> b >> c;
        mat[a-1][b-1] = mat[b-1][a-1] = c;
    }
}

void floyd(int mat[100][100],  int n){
    
    for (int k = 0 ; k< n; k++) {
        for (int i = 0; i<n; i++) {
            for (int j = 0 ; j<n; j++) {
                mat[i][j] = min(mat[i][j],max(mat[i][k],mat[k][j]));
            }
        }
    }

}


void consulta(int mat[100][100],  int q,  int c){
    int a,b;
    for (int i = 0 ; i<q; i++) {
        cin >> a >> b;
        if (mat[a-1][b-1] == INT_MAX) {
           cout<< "no path"<<endl;
            
        }else{
            cout<< mat[a-1][b-1]<<endl;
            
        }
    }
}

int main(){
    int mat[100][100];
    int n=0, m=0, q=0,c=0;
    // c - Cant Cases
    // n - Cant Nodos
    // m - Cant Arcos
    // q - Cant de Consultas
    cin>>c;
    for (int i = 0; i<c; i++) {
        cin >> n >> m >> q; //nodos , arcos , consultas
        leeArcos(mat, m);
        floyd(mat, n);
        cout<<"Queries for Case "<<i+1<<":"<<endl;
        consulta(mat, q,i);
       
    }
    
    
}
/*
 2
 7 9 3
 1 2 50
 1 3 60
 2 4 120
 2 5 90
 3 6 50
 4 6 80
 4 7 70
 5 7 40
 6 7 140
 1 7
 2 6
 6 2
 7 6 3
 1 2 50
 1 3 60
 2 4 120
 3 6 50
 4 6 80
 5 7 40
 7 5
 1 7
 2 4
*/


