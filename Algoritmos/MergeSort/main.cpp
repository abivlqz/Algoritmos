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

void une(vector<int>&v, vector<int> &aux, int ini, int mit, int fin, int &comp){
    //i = indicador de la comparacion de la parte izq
    //j = indicador de la comparacion de la parte der
    //k = indicador donde deposita en aux el que gana
    int i = ini, j = mit+1, k = ini;
    while (i<=mit && j<= fin) {// i o j?
        comp++;
        if (v[i]<=v[j]){
            aux[k++]= v[i++];
        }
        else{
            aux[k++]= v[j++];
        }
    }
    while (i<=mit) {
        aux[k++]= v[i++];
    }
    while (j<=fin) {
        aux[k++]= v[j++];
    }
    for (int a=ini; a<=fin; a++) {
        v[a] = aux[a];
    }
    
    
}




void merge(vector<int>&v, vector<int> &aux, int ini, int fin, int &comp){
    if (ini< fin) {
        int mit = (ini+fin)/2;
        merge(v, aux, ini, mit, comp);
        merge(v, aux, mit+1, fin, comp);
        une(v,aux,ini,mit,fin,comp);
    }
    
}





void print(vector<int> &v){
    
    for (int i = 0; i<v.size(); i++) {
        cout<<i<<": "<< v[i]<<"   " ;
    }
    cout<<endl;
}



int main(){
    int n , comp = 0;
    cin>> n;
    vector<int> v(n), aux(n);
    for (int i = 0; i<n; i++) {
        cin>>v[i];
    }
    
    merge(v,aux,0,n-1,comp);
    cout<<comp<<endl;
    print(v);
    return 0;
}

