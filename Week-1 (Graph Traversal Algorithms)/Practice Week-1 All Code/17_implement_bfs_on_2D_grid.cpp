#include <bits/stdc++.h>
using namespace std;
char graph[100][100];
bool vis[100][100];
int level[100][100];
vector<pair<int,int>> movement = {{-1,0}, {1,0}, {0,-1}, {0,1}};
int n, m;   

bool valid(int ci, int cj) {
    if(ci<0 || ci>=n || cj<0 || cj>=m)
        return false;
    return true;
}

void bfs(int si, int sj) {
    queue<pair<int,int>> q;
    q.push({si,sj});
    vis[si][sj] = true;
    level[si][sj] = 0;

    while(!q.empty()) {
        pair<int,int> par = q.front();
        q.pop();

        int par_i = par.first;
        int par_j = par.second;

        cout << par_i << " " << par_j << endl;

        for(int i=0; i<4; i++) {
            int ci = par_i + movement[i].first;
            int cj = par_j + movement[i].second;

            if(valid(ci,cj) && !vis[ci][cj]) {
                q.push({ci,cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
            }
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
    memset(level, -1, sizeof(level));
    int si, sj; cin >> si >> sj;
    bfs(si, sj);
    int di, dj; cin >> di >> dj;
    cout << level[di][dj] << endl;
    
    return 0;
}