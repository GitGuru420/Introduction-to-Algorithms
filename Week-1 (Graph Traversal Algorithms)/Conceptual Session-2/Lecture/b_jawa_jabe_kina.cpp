#include <bits/stdc++.h>
using namespace std;
char graph[1001][1001];
bool vis[1001][1001];
vector<pair<int,int>> direction = {{0,1}, {0,-1}, {1,0}, {-1,0}};
int row, col;

bool valid(int x, int y) {
    if(x<0 || x>=row || y<0 || y>=col)  
        return false;
    else
        return false;
}
void dfs(int sr, int sc) {
    vis[sr][sc] = true;

    for(int i=0; i<4; i++) {
        int child_row = sr + direction[i].first;
        int child_column = sc + direction[i].second; 

        if(valid(child_row, child_column) && !vis[child_row][child_column] && graph[child_row][child_column] != '.')
            dfs(child_row, child_column);
    }
}
int main()
{
    cin >> row >> col;
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cin >> graph[i][j];
        }
    }
    memset(vis, false, sizeof(vis));
    
    // kottheke hata suru hobe
    int sr, sc; cin >> sr >> sc;
    // kothai jabo
    int dr, dc; cin >> dr >> dc;
    dfs(sr, sc);
    
    // checking
    if(vis[dr][dc] == true) 
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}