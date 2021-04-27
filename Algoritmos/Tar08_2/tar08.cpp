//
//  tar08.cpp
//  Algoritmos
//
//  Abigail Guadalupe Velazquez Sanchez A01566592 Grupo1
//  Creado el 24/03/2021
#include <iostream>
#include <climits>
#include <cmath>
#include <fstream>
#include <sstream>
using namespace std;

// numCasos - Cant Cases, n - Cant Nodos, m - Cant Arcos, q - Cant de Consultas
int numCasos,n,m,q;

// mat = matriz de costos
// p   = matriz de recorridos
void inicializarMatrices(int mat[100][100], int p[100][100]){
    
    for (int i = 0; i<100; i++) {
        mat[i][i] = p[i][i] = 0;
        for (int j = i+1; j<100; j++) {
            mat[i][j] = mat[j][i] = INT_MAX;
            p[i][j] = p[j][i] = -1;
        }
    }
    
    
}

void floyd(int mat[100][100], int p[100][100], int n){
    
    for (int k = 0 ; k< n; k++) {
        for (int i = 0; i<n; i++) {
            for (int j = 0 ; j<n; j++) {
                if (mat[i][k] != INT_MAX && mat[k][j] != INT_MAX && mat[i][k] < mat[i][j] && mat[k][j] < mat[i][j] ){
                    mat[i][j] = max(mat[i][k],mat[k][j]);
                    p[i][j] = k;
                }
            }
        }
    }

}


void obtenerInfo(fstream& nuevoArchivo, int mat[100][100], int p[100][100], int matq[100][100]){
    
    int a,b,c,d,e;
    string firstLine,carac,lines,arcos,info,queries;
    //Se lee la primera linea que indica el numero de productos del programa
    getline(nuevoArchivo,firstLine);
    // Convierte el string a int
    stringstream stoInt(firstLine);
    stoInt>>numCasos;
    while (!nuevoArchivo.eof()) {
        for (int i = 0; i<=numCasos; i++) {
            inicializarMatrices(mat, p);
            //Lee linea por linea el txt
            getline(nuevoArchivo,lines);
            //Lee en la linea i un string hasta que se encuentre con un espacio
            stringstream linestream(lines);
            while (!linestream.eof()) {
                
                linestream>>n >>m>>q;
            }
            for (int j = 0; j<m; j++) {
            //Lee linea por linea el txt
                getline(nuevoArchivo,arcos);
                //Lee en la linea i un string hasta que se encuentre con un espacio
                stringstream linestream1(arcos);
                while (!linestream1.eof()) {
                    
                    linestream1>>a>>b>>c;
                    mat[a-1][b-1] = mat[b-1][a-1] = c;
                }
                
                
            }
            
            floyd(mat, p, n);
            for (int k = 0 ; k<q; k++) {
                //Lee linea por linea el txt
                getline(nuevoArchivo,queries);
                //Lee en la linea i un string hasta que se encuentre con un espacio
                stringstream linestream2(queries);
                while (!linestream2.eof()) {
                    
                    linestream2>>d>>e;
                    if (mat[d-1][e-1] == INT_MAX) {
                       // cout<< "no path"<<endl;
                        matq[i][k]=-1;
                    }else{
                       // cout<< mat[a-1][b-1]<<endl;
                        matq[i][k]=mat[d-1][e-1];
                    }
                }
            }
        }
    }
    nuevoArchivo.close();

}

int main(){
    int mat[100][100];
    int p[100][100];
    int matq[100][100];
    char nombreArchivo[30];
    //Preguntamos el nombre del archivo
    cout<<"Ingresa el nombre de tu archivo CON extension "<<endl;
    cin.getline(nombreArchivo, 30);
    //Declaramos y abrimos el archivo
    fstream nuevoArchivo;
    nuevoArchivo.open(nombreArchivo);
    if (nuevoArchivo.is_open()) {
        obtenerInfo(nuevoArchivo, mat, p, matq);
        for(int i = 0; i<numCasos; i++){
            cout<<"Case "<<i+1<<":"<<endl;
            for (int j = 0; j<q; j++) {
                if (matq[i][j]!=-1)
                    cout<<matq[i][j]<<endl;
                else
                    cout<<"no path"<<endl;

            }
        }
        
    }else{
        cout<<"No se ha encontrado el archivo o no se ha podido abrir "<<endl;
    }
    
   
    
    
}
/*
 2
 7 9 3
 1 2 50
 1 3 60
 2 4 120
 2 5 90
 3 6 50
 4 6 80
 4 7 70
 5 7 40
 6 7 140
 1 7
 2 6
 6 2
 7 6 3
 1 2 50
 1 3 60
 2 4 120
 3 6 50
 4 6 80
 5 7 40
 7 5
 1 7
 2 4
*/



