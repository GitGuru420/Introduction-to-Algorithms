#include <bits/stdc++.h>
using namespace std;

char graph[1001][1001];
bool vis[1001][1001];
vector<pair<int,int>> movement = {{0,1}, {0,-1}, {1,0}, {-1,0}};
int n, m;

bool valid(int i, int j) {
    if(i<0 || i>=n || j<0 || j>=m) {
        return false;
    }
    return true;
}

void dfs(int sr, int sc) {
    vis[sr][sc] = true;
    
    for(int i=0; i<4; i++) {
        int ci = sr + movement[i].first;
        int cj = sc + movement[i].second;

        if(valid(ci, cj) && !vis[ci][cj] && graph[ci][cj] == '.') {
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
    int count = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(graph[i][j] == '.') {
                if(!vis[i][j]) {
                    count++;
                    dfs(i,j);
                }
            }
        }
    }
    cout << count << endl;
    
    return 0;
}