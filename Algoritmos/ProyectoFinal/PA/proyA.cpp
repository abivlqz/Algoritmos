// proyA.cpp
// Matricula: A01566592
// Nombre: Abigail Velazquez Sanchez
//
//  Algoritmos Grupo 1
//
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
#define MAX 100

float findMedian(int arr1[MAX], int arr2[MAX], int n){
    bool encontrado = false;
    int inf1, inf2, sup1, sup2,mid1, mid2;
    inf1 = inf2 = 0;
    sup1 = sup2 = n-1;
    mid1 = (inf1 + sup1)/2;
    mid2 = ceil((inf2 + sup2)/2.0);
    // Mientras no se haya encontrado, o los pivotes no se encuentren en extremos opuestos
    // de los arreglos (que quiere decir que esos son los dos numeros de en medio) , se sigue buscando.
    while (!encontrado && !(mid1 == n-1 && mid2 == 0) && !(mid1 == 0 && mid2 == n-1)) {
        if ( (arr1[mid1] > arr2[mid2 - 1] && arr1[mid1] < arr2[mid2 + 1]) && (arr2[mid2] > arr1[mid1 - 1] && arr2[mid2] < arr1[mid1 + 1]) ) {
            encontrado = true;
        }
        else{
            if ( arr1[mid1] < arr2[mid2 - 1] )
                inf1 = mid1 + 1;
            else if ( arr1[mid1] > arr2[mid2 + 1] )
                sup1 = mid1 - 1;
            
            if ( arr2[mid2] < arr1[mid1 - 1] )
                inf2 = mid2 + 1;
            else if ( arr2[mid2] > arr1[mid1 + 1] )
                sup2 = mid2 - 1;
        }
        if (!encontrado) {
             mid1 = (inf1 + sup1)/2;
             mid2 = ceil((inf2 + sup2)/2.0);
        }
    }
    return ( float(arr1[mid1]) + float(arr2[mid2]) )/2;
}
// Programa Principal
int main(){
    int arr1[MAX] ;
    int arr2[MAX] ;
    int t,n; // t num de casos, n es el tamaño de los pares de arreglos
    cin>> t;
    for (int c = 0; c < t; c++) {
        cin>> n;
        for (int i = 0 ; i < n ; i++) {
               cin>> arr1[i];
        }
           
        for (int i = 0 ; i < n ; i++) {
               cin>> arr2[i];
        }
        cout << fixed;
        cout << setprecision(2);
        cout<<"Median case "<<c+1<<": "<<findMedian(arr1, arr2, n)<<endl;
    }
    return 0;
}
/*
2
5
1
4
7
8
10
2
9
11
14
15
3
3
5
6
1
2
4
 */

/*
4
4
1
2
3
4
5
6
7
8
4
5
6
7
8
1
2
3
4
4
1
3
5
7
2
4
6
8
4
1
2
5
8
3
4
6
7
 */
