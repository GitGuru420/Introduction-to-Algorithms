#include <bits/stdc++.h>
using namespace std;

char graph[1001][1001];
bool vis[1001][1001];
vector<pair<int,int>> direction = {{0,1}, {0,-1}, {1,0}, {-1,0}};
int row, col;

bool valid(int x, int y) {  // x->row, y->col
    if(x<0 || x>=row || y<0 || y>=col) {
        return false;
    }
    else {
        return true;
    }
}

void dfs(int sr, int sc) {
    vis[sr][sc] = true;
    
    for(int i=0; i<4; i++) {
        int child_row = sr + direction[i].first;
        int child_col = sc + direction[i].second;

        if(valid(child_row, child_col) && !vis[child_row][child_col] && (graph[child_row][child_col] == '.' || graph[child_row][child_col] == 'B')) {
            dfs(child_row, child_col);
        }
    }
}

int main()
{
    cin >> row >> col;
    int sr, sc, dr, dc;
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cin >> graph[i][j];
            if(graph[i][j] == 'A') {
                sr = i;
                sc = j;
            }
            if(graph[i][j] == 'B') {
                dr = i;
                dc = j;
            }
        }
    }
    memset(vis, false, sizeof(vis));

    dfs(sr, sc);

    if(vis[dr][dc]) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    
    return 0;
}