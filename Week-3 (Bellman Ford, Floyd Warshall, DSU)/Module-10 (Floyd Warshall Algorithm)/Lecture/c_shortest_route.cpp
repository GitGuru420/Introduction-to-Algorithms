#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e, q;   cin >> n >> e >> q;
    int adjMat[n][n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i==j)
                adjMat[i][j] = 0;
            else
                adjMat[i][j] = INT_MAX;
        }
    }

    while(e--) {
        int a, b, c;    cin >> a >> b >> c;
        adjMat[a][b] = c;
        adjMat[b][a] = c;
    }

    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(adjMat[i][k] != INT_MAX && adjMat[k][j] != INT_MAX && adjMat[i][k] + adjMat[k][j] < adjMat[i][j])
                    adjMat[i][j] = adjMat[i][k] + adjMat[k][j];
            }
        }
    }

    while(q--) {
        int s, d;   cin >> s >> d;
        if(adjMat[s][d] == INT_MAX)
            cout << -1 << endl;
        else
            cout << adjMat[s][d] << endl;
    }

    return 0;
}