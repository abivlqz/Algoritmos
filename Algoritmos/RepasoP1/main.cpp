/*
  Matricula: A00823326
  Nombre: Gustavo Alejandro Vasquez Acosta
*/

#include <iostream>
#include <vector>

int count = 0;

int encontrarMayor(std::vector<int> &d, long fin){
    if (fin == 1){
        return 0;
    }
    else{
        int mayor = 0;
        for (int i = 0; i<fin-1; i++){
            if (d[i] > d[i+1] && d[i] > d[mayor]){
                mayor = i;
            }
            else if (d[i+1] > d[i] && d[i+1] > d[mayor]){
                mayor = i+1;
            }
        }
        return mayor;
}
}

std::string juego(std::vector<int> &d){
    if (d.size() == 0){
        return "NADIE GANA";
    }
    if (d.size() == 1){
        return "BETO";
    }
    long i = d.size();
    while (i!=0){
        count++;
        i =  encontrarMayor(d, i);
    }
    if (count%2 == 0){
        return "PEPE";
    }
    else
        return "BETO";
}


int main(){
    int n;
    std::cin >> n;
    std::vector<int> datos(n);
    for (int i=0; i<n; i++){
        std::cin>>datos[i];
    }
    std::cout << juego(datos)<<"\n";
}

/*
Ejemplo 1
4
1 2 4 3

Ejemplo 2
4
1 4 3 2

Ejemplo 3
6
8 10 5 12 13 9

*/

