#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;   cin >> n >> e;
    int adj_mat[n][n];
    // adj_mat er sob value 0 diye initialize kora
    /*
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            adj_mat[i][j] = 0;
        }
    }
    */
    // shortcut
    memset(adj_mat, 0, sizeof(adj_mat));    // all values are 0

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i == j)
                adj_mat[i][j] = 1;
        }
    }

    for(int i=0; i<e; i++) {
        int a, b;   cin >> a >> b;
        adj_mat[a][b] = 1;
        adj_mat[b][a] = 1;
    }

    // print adj_mat
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}