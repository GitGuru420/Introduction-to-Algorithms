#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> movement = {{0,1}, {0,-1}, {-1,0}, {1,0}};
bool visited[1005][1005];
char mat[105][105];
int n, m;   

bool valid(int i, int j) {
    if(i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}
void dfs(int si, int sj) {
    cout << si << " " << sj;
    visited[si][sj] = true;

    for(int i=0; i<4; i++) {
        int ci = si + movement[i].first;
        int cj = sj + movement[i].second;
        if(valid(ci, cj) == true && !visited[ci][cj]) 
            dfs(ci, cj);
    }
}

int main()
{
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
           cin >> mat[i][j];
        }
    }
    memset(visited, false, sizeof(visited));
    int si, sj; cin >> si >> sj;
    dfs(si, sj);

    return 0;
}