// proyD.cpp
// Matricula: A01566592
// Nombre: Abigail Velazquez Sanchez
//
//  Algoritmos Grupo 1
//
#include <iostream>
#include <string>
using namespace std;
#define MAX 1000


int LCS(string s1, string s2, long m, long n, int mat[MAX][MAX]){
  
    for (int i = 1; i <= m ; i++) {
        for (int j = 1; j <= n ; j++) {
            if (s1[i-1] == s2[j-1])
                mat[i][j] = mat[i-1][j-1] + 1;
            else
                mat[i][j] = max( mat[i-1][j] , mat[i][j-1] );
        }
    }
    return mat[m][n];
}

int main(){
    int mat[MAX][MAX];
    string s1, s2;
    long m,n;
    int c;
    for (int i = 0; i < MAX; i++) {
           for (int j = 0 ; j < MAX; j++) {
               mat[i][j] = 0;
           }
       }
    cin>>c;
    for (int i = 0; i < c; i++) {
        cin>> s1;
        cin>> s2;
        m = s1.length();
        n = s2.length();
        cout<<"Case "<<i+1<<": "<<LCS(s1, s2 , m,n , mat)<<endl;
    }
    return 0;
}
/*
2
AAAAAAABBAAB
ABAABBAB
XMJYAUZ
MZJAWXU
 */
