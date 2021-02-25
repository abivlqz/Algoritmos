//
//  tar05.cpp
//  Algoritmos
//
//  Created by Aby Velazquez on 25/02/21.
//  Copyright © 2021 Abi Velazquez. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


int encuentraCasillas(int i, int j, int n, int A[][100]){
    
    if (i <=1 && j <=0) {
        return 0;
    }else{
        if (j<=0) {
             return encuentraCasillas(i-1, n, n, A);
        }
        else{
            if ( A[i-1][j-1]>100 )
                return 1 + encuentraCasillas(i, j-1,n, A);
            else
                return encuentraCasillas(i, j-1, n, A);
        }
    }
  
}


int main(){
    
    int A[100][100];
    int n = 2;
    
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            cout<<" Ingresa el valor para A[ "<<i<<"],[ "<<j<<"]"<<endl;
            cin>>A[i][j];
        }      
    }
    
   
    
    cout<<"El numero de elementos mayores a 100 es: " << encuentraCasillas(n,n,n, A) <<endl;
    
    
    return 0;
}

