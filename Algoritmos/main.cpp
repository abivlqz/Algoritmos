//
//  main.cpp
//  Algoritmos
//
//  Created by Aby Velazquez on 09/02/21.
//  Copyright © 2021 Abi Velazquez. All rights reserved.
//

#include <iostream>
using namespace std;


int sumaImparIt(int A[], int n){
   int s=0;
   for (int i = 0; i<n; i++) {
       if (A[i]%2!=0) {
           s+=A[i];
       }
   }
    return s;
   }





int sumaImparRec(int n,int A[]){
    if(n>0){
        if (A[n-1]%2!=0)
            return A[n-1]+ sumaImparRec(n-1, A);
        else
            return sumaImparRec(n-1, A);
    }else{
        return 0;
    }
}

int main() {
    // insert code here...
    int A[5]={17,3,7,33,9};
    int n=5;
    
    cout<<sumaImparRec(n, A)<<endl;
    
    cout<<sumaImparIt(A,n)<<endl;
    
//    for (int i = 0; i<n; i++) {
//        B[i][i] = A[i];
//        for (int j = i+1; j<n; j++) {
//            B[i][j]= B[j][i] = B[i][j-1]+A[j];
//
//        }
//    }
    
    
//    for (int i = 0; i<n; i++) {
//       int acum=0;
//        for (int j = i; j<n; j++) {
//            acum+=A[j];
//            B[i][j]= B[j][i] = acum;
//        }
//    }
    
  
    
    
   
    return 0;
}
