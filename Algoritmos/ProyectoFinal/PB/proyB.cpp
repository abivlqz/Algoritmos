// proyB.cpp
// Matricula: A01566592
// Nombre: Abigail Velazquez Sanchez
//
//  Algoritmos Grupo 1
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 100

void beagleBall (vector<long long> soldados, vector<long long> pelotas, long long n, long long q ){
    long long acumPelotas = 0;
    vector<long long>::iterator up;
    for ( int i = 0; i < q; i++) {
        acumPelotas += pelotas[i];
        if (acumPelotas > soldados[n-1] ) {
            acumPelotas = 0;
        }
        up = upper_bound (soldados.begin(), soldados.end(), acumPelotas);
        cout<< n - ( up - soldados.begin() ) <<endl;
    }
}


// Programa Principal
int main(){
    vector<long long> soldados;
    vector<long long> pelotas;
    long long n,q;
    long long soldAcum = 0;
    long long dato;
    cin>> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> dato;
        soldAcum += dato;
        soldados.push_back(soldAcum);
    }
    for (int i = 0; i < q; i++) {
        cin >> dato;
        pelotas.push_back(dato);
    }
    
    beagleBall(soldados, pelotas, n, q);
   
    return 0;
}
/*
5 8 
1 4 2 3 5
1 2 4 1 3 5 7 2
*/
/*
5 5
1 2 1 2 1
3 10 1 1 1
 */
