#include <bits/stdc++.h>
using namespace std;

int main()
{   
    int node, edge;     cin >> node >> edge;
    int adjMat[node][node];
    memset(adjMat, 0, sizeof(adjMat));

    while(edge--) {
        int a, b;   cin >> a >> b;
        adjMat[a][b] = 1;   // directed
        adjMat[b][a] = 1;   // undirected
    }

    for(int i=0; i<node; i++) {
        for(int j=0; j<node; j++) {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}