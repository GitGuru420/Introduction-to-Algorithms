#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;   cin >> n >> e;
    long long adjMat[n+5][n+5];
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i==j)
                adjMat[i][j] = 0;
            else
                adjMat[i][j] = LLONG_MAX;
        }
    }

    while(e--) {
        long long a, b, w;    cin >> a >> b >> w;
        adjMat[a][b] = min(adjMat[a][b], w);
    }

    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(adjMat[i][k] != LLONG_MAX && adjMat[k][j] != LLONG_MAX && adjMat[i][k] + adjMat[k][j] < adjMat[i][j])
                    adjMat[i][j] = adjMat[i][k] + adjMat[k][j];
            }
        }
    }

    int q;  cin >> q;
    while(q--) {
        int x, y;   cin >> x >> y;
        if(adjMat[x][y] == LLONG_MAX)
            cout << -1 << endl;
        else
            cout << adjMat[x][y] << endl;
    }

    return 0;
}