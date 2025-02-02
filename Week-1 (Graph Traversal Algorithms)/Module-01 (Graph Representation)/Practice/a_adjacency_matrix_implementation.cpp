#include <bits/stdc++.h>
using namespace std;

int main()
{
    int node, edge; cin >> node >> edge;
    int adj_mat[node][node];
    memset(adj_mat, 0, sizeof(adj_mat));

    // Before connection to edge
    for(int i=0; i<node; i++) {
        for(int j=0; j<node; j++) {
            cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }

    while(edge--) {
        int a, b;   cin >> a >> b;
        adj_mat[a][b] = 1;  // directed graph --> only this line
        adj_mat[b][a] = 1;  // undirected graph --> line 12 & 13
    }
    cout << endl;

    // After connection to edge
    for(int i=0; i<node; i++) {
        for(int j=0; j<node; j++) {
            cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}