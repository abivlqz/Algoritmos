
//
//  main.cpp
//  Algoritmos
//
//  Created by Aby Velazquez on 09/02/21.
//  Copyright © 2021 Abi Velazquez. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void print(vector<int>& v){
    for (int i = 0; i<v.size(); i++) {
        cout<<i<< ":  " << v[i]<<endl;
    }
    
}

void particion(vector<int>&v, int inicio, int fin, int& pivote, int &comp){
    int elempivote = v[inicio], j=inicio,temp;
    
    for (int i=inicio+1; i<=fin; i++) {
        comp++;
        if (elempivote>v[i]) {
            j++;
            temp = v[i];
            v[i]=v[j];
            v[j]= temp;
        }
    }
    pivote = j;
    temp = v[inicio];
    v[inicio]= v[j];
    v[j]= temp;
    
    
}

// Complejidad: Mejor Caso = O (n log n) , Peor Caso = O(n^2, Caso Promedio O(n log n)
void quick( vector<int>& v, int inicio, int fin, int &comp){
    int pivote;
    if (inicio<fin) {
        particion(v,inicio,fin,pivote,comp);
        quick(v,inicio,pivote-1,comp);
        quick(v,pivote+1,fin,comp);
    }
    
}


int main(){
    
    int n ,comp= 0;
    cin>>n;
    vector<int>v(n);
    for (int i = 0; i<n; i++) {
        cin>>v[i];
    }
    quick(v, 0, n-1, comp);
    print(v);
    cout<<"-----"<<endl;
    cout<<comp<<endl;
    
    
    return 0;
}
