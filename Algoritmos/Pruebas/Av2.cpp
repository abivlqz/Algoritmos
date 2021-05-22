// proyA.cpp
// Matricula: A01566592
// Nombre: Abigail Velazquez Sanchez
//
//  Algoritmos Grupo 1
//
#include <iostream>
#include <iomanip>
using namespace std;
#define MAX 100

float findMedian(int arr1[MAX], int arr2[MAX], int n){
    bool encontrado = false;
    bool m2cambio = false;
    int inf1, inf2, sup1, sup2;
    inf1 = inf2 = 0;
    sup1 = sup2 = n-1;
    int mid1 = (inf1 + sup1)/2;
    int mid2 = (inf2 + sup2)/2;
    
    // Mientras no se haya encontrado, o los pivotes no se encuentren en extremos opuestos
    // de los arreglos (que quiere decir que esos son los dos numeros de en medio) , se sigue buscando.
    while (!encontrado && !(mid1 == n-1 && mid2 == 0) && !(mid1 == 0 && mid2 == n-1)) {
        
        if ( (arr1[mid1-1] < arr2[mid2-1] && arr1[mid1+1] > arr2[mid2+1]) || (arr1[mid1-1] > arr2[mid2-1] && arr1[mid1+1] < arr2[mid2+1])  ) {
            encontrado = true;
        }else{
            
            if ((arr1[mid1-1] < arr2[mid2-1] ) {
                inf1 = mid1 + 1;
            // && arr1[mid1+1] < arr2[mid2+1])
            }else if ((arr1[mid1-1] > arr2[mid2-1] && arr1[mid1+1] > arr2[mid2+1]) ){
                sup1 = mid1 - 1;
            }
            
            if ((arr2[mid2-1] < arr1[mid1-1] && arr2[mid2+1] < arr1[mid1+1])) {
                inf2 = mid2 + 1;
                m2cambio = true;
            }else if ((arr2[mid2-1] > arr1[mid1-1] && arr2[mid2+1] > arr1[mid1+1]) ){
                sup2 = mid2 - 1;
                m2cambio = true;
            }
            
            
        }
        if (!encontrado) {
            // Se actualiza el valor central de un arreglo
            mid1 = (inf1 + sup1)/2;
            // Se hace un "techo" para el 2ndo arreglo , si el valor central da 0.5, se redondea a 1
            if ( (inf2 + sup2) % 2 != 0 && m2cambio)
                mid2 = ((inf2 + sup2)/2) + 1;
            else
                mid2 = (inf2 + sup2)/2;
                   
            m2cambio = false;
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
