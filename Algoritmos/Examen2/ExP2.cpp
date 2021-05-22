#include <iostream>
// Robot
// Matricula: A01566592
// Nombre: Abigail Velazquez Sanchez

using namespace std;
#define MAX 100
#define INF INT_MAX
//Complejidad: O (n^2)
int robot(int mat[MAX][MAX], int n, int m){
// Aquí va tu codigo
    int Acum[MAX][MAX];
    int r = n+1;
    int c = m+1;
    // Agrego una columna y fila mas que tengan valores infinitos
    // hara facil al calculo del costo sin tener problemas al salirse de los limites de la matriz
    for (int i = 0; i < r; i++) {
        Acum[i][0] = INF;
    }
    for (int j = 0; j < c; j++) {
        Acum[0][j] = INF;
    }
    Acum[1][0] = 0;
    // Busca el menor camino ya sea a su izq o arriba, y se lo suma al costo de ese cuadrante
    for (int i = 1; i < r; i++) {
        for (int j = 1; j < c; j++) {
            Acum[i][j] = mat[i-1][j-1] + min(Acum[i][j-1],Acum[i-1][j]);
        }
    }
    return Acum[r-1][c-1];
}

void print(int mat[MAX][MAX], int n, int m){
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
         cout << mat[i][j]<< " ";
        }
        cout << endl;
    }
}

int main(){
    int n, m;
    int mat[MAX][MAX];
    cin >> n  >> m;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> mat[i][j];
        }
    }
//    print(mat, n, m);
    cout << robot(mat, n, m)<<endl;
}

/*
5 4
2  2 15  1
5  1 15  1
5  3 10  1
5  2  1  1
8 13  2 15

Resp 27
*/

