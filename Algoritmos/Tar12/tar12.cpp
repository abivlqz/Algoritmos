//
//  tar12.cpp
//  Algoritmos
//
//  Abigail Guadalupe Velazquez Sanchez A01566592 Grupo1
//  Creado el 25/04/2021
//
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <climits>
using namespace std;

#define INF INT_MAX
#define Edge pair<int, int>         // Donde llego, y su costo
#define Graph vector<vector<Edge>> // Listas de adyacencias
#define Vertex pair<int, int>  // Distance from source, vertex ID

//Complejidad : O (n log n)
vector<int> Dijkstra(Graph& G, int source){
    vector<int> Dist;
    Dist.assign(G.size(), INF);
    Dist[source] = 0;
    priority_queue<Vertex, vector<Vertex>, greater<Vertex> > queue;
    Vertex vx(0,source);
    queue.push(vx);
    while (!queue.empty()) {
        int u = queue.top().second;
        queue.pop();
        for (int i = 0; i < G[u].size(); i++) {
            Edge e = G[u][i];
            int v = e.first;
            int w = e.second;
            if (Dist[v] > Dist[u] + w) {
                Dist[v] = Dist[u] + w;
                Vertex vtx(Dist[v], v);
                queue.push(vtx);
            }
        }
    }
    return Dist;
}
// Programa Principal
int main()
{
    int c,nodes, edges, w,mayor,room;
    char uChar,vChar;
    Graph G;
    // Read from stdin
    cin>> c;
    for (int i = 0; i<c; i++) {
        cin >> nodes >> edges;
        G.resize(nodes);
        for (int x = 0; x < edges; x++)
        {   // Read char nodes and turn them to a numeric ascii code
            cin >> uChar >> vChar >> w;
            // Edge from u->v
            Edge edge1(vChar-65, w);
            G[uChar-65].push_back(edge1);

            // Edge from v->u
            Edge edge2(uChar-65, w);
            G[vChar-65].push_back(edge2);
        }
        // Dijsktra algorithm
        vector<int> distances = Dijkstra(G, 0);
        mayor = distances[0];
        room = 0;
        // Look for the largest lowest path
        for (int j = 0; j < nodes; j++)
        {
            if (distances[j] != INF && distances[j] >mayor){
                    mayor = distances[j];
                    room = j;
                }
        }
        // Print the name of the room, e.g turning node 1 into 'B'
        cout<<"Case "<<i+1<<": "<<char(room +65)<<endl;
    }
    return 0;
}
/*
2
5 7
A B 5
A C 4
A D 7
B E 3
C D 2
C E 4
D E 1
4 6
A B 1
A C 1
A D 1
B C 1
B D 1
C D 1
*/
