#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> include;
vector<int> obj;
int VALOR, n;


// i = objeto actual
// acum = acum total
// total = resto de la suma de los siguientes objetos

void sum_of_subsets(int i, int acum, int total){
   
    // La primera parte de la cond == > alcanza
    // La segunda parte de la cond == > coincida con el valor, o que no me pase con el sig objeto
    if ( (acum + total >= VALOR && acum == VALOR )|| acum + obj[ i + 1] <= VALOR ) {
        
        // Ya encontre una solución
        if (acum == VALOR ) {
            cout<< "Solucion :";
            for (int j = 0 ; j < n; j++) {
                if (include[j]) {
                    cout << obj[j] << " ";
                }
            }
            cout<<endl;
        }else{
            // SI incluir el sig obj
            include[i+1] = true;
            sum_of_subsets(i+1, acum + obj[i + 1], total - obj[i + 1]);
            
            // no incluir al sig objeto
            include[ i+1] = false;
            sum_of_subsets(i + 1, acum, total - obj[i+1]);
        }
    }
}


int main(){
    // n = cantidad de objetos
    // VALOR = El valor que se desea acumular
    cin >> n >> VALOR;
    int dato, total = 0;
    for (int i=0; i<n; i++){
        cin >> dato;
        obj.push_back(dato);
        // total = al inicio tendra la suma de todos los valores
        total += dato;
        include.push_back(false);
    }
    sort(obj.begin(), obj.end());
    sum_of_subsets(-1, 0, total);
}

/*
5 21
10
6
5
16
11
*/
