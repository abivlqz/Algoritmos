//
//  tar09.cpp
//  Algoritmos
//
//  Abigail Guadalupe Velazquez Sanchez A01566592 Grupo1
//  Creado el 09/04/2021
#include <iostream>
#include <climits>
using namespace std;

#define MAX 51

void calcula(int D[MAX][MAX], int d[MAX], int n){
// Inicializar la diag princ con 0s
    for (int i = 0; i<=n; i++) {
        D[i][i] = 0;
    }
    
    int j, aux, men;
    for (int diag = 1; diag<= n-1; diag++) {
        for (int i = 1; i<= n-diag; i++) {
            j = i+ diag;
            men = INT_MAX;
            for (int k =i ; k<j; k++) {
                aux = D[i][k] + D[k+1][j];
                if (aux < men) {
                    men = aux;
                }
            }
            D[i][j] = men + d[j] - d[i-1];
        }
    }
}

int main(){
    int d[MAX]; // Las dimenciones de las matrices
    int D[MAX][MAX];
    int c,l,n;// cantidad de pedazos a cortar y longitud de la madera
    // cantidad de matrices a mult.
    for (int i=0; i<MAX; i++){
        for (int j=0; j<MAX; j++){
            D[i][j] = 0;
        }
    }
    
    cin >>l;
    while (l!=0) {
         cin >>c;
         n=++c;
         d[0]= 0;
         d[n]=l;
         for (int i=1; i<n; i++){
             cin >> d[i];
         }
         calcula(D,d, n);
         cout << "The minimum cutting is "<<D[1][n]<<"."<< endl;
         cin >>l;
    }
}

/*
100
3
25 50 75
10
4
4 5 7 8
0
 */


