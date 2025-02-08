#include <bits/stdc++.h>
using namespace std;
char graph[100][100];
bool vis[100][100];
vector<pair<int,int>> movement = {{-1,0}, {1,0}, {0,-1}, {0,1}};
int n, m;   

bool valid(int ci, int cj) {
    if(ci<0 || ci>=n || cj<0 || cj>=m)
        return false;
    return true;
}

void dfs(int si, int sj) {
    cout << si << " " << sj << endl;
    vis[si][sj] = true;

    for(int i=0; i<4; i++) {
        int ci = si + movement[i].first;
        int cj = sj + movement[i].second;
        if(valid(ci,cj) && !vis[ci][cj]) {
            dfs(ci, cj);
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> graph[i][j];
        }
    }
    memset(vis, false, sizeof(vis));
    int si, sj; cin >> si >> sj;
    dfs(si, sj);
    
    return 0;
}