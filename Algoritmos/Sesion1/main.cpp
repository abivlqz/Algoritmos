//
//  main.cpp
//  Algoritmos
//
//  Created by Aby Velazquez on 09/02/21.
//  Copyright © 2021 Abi Velazquez. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;


////Numeros divisibles entre 3 y 5, o divisibles entre 15
//int encontrarDiv(int inf, int sup){
//    int cantidad=0;
//    for (int x= inf; x<=sup; x++) {
//        if (x%15==0) {
//            cout<<endl;
//            cout<<x<<endl;
//            cantidad++;
//        }
//    }
//    return cantidad;
//}

// 2da version y o(n)
//Numeros divisibles entre 3 y 5, o divisibles entre 15
int encontrarDiv(int inf, int sup){
    int cantidad=0;
    
    int inicio= inf;
    if (inf%15 != 0) {
        inicio= inicio + 15 - inf%15;
    }
    
    for (int x= inf; x<=sup; x+15) {
       cantidad++;
        
    }
    return cantidad;
}
//

// 100/15 - 10/15== 6 sup 100, inf 10==
// 100/15 - 15/15 +1

int cuantos( int inf, int sup){
    if (inf%15==0)
        return sup/15 -inf/15 +1;
   else
       return sup/15 -inf/15;
}

int main(){
    int inf,sup;
    cout<<"Ingresa tu limite inferior: "<<endl;
    cin>>inf;
    cout<<"Ingresa tu limite superior: "<<endl;
    cin>>sup;
    
    cout<<"La cantidad de numeros divisibles es " <<encontrarDiv(inf,sup)<<endl;
    return 0;
}


