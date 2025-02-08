/*
Given a graph in 2D matrix , Answer the Following Questions. 

5 8
~~~~~~~~
~..~...~
~~~~.~.~
~..~...~
~~~~~~~~

Here '.' indicates cities and '~' indicates river. 

2. Determine if we could go from one city to another by vehicle
*/

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

        if(valid(child_row, child_col) && !vis[child_row][child_col] && graph[child_row][child_col] == '.') {
            dfs(child_row, child_col);
        }
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
    int sr, sc; cin >> sr >> sc;
    int dr, dc; cin >> dr >> dc;

    dfs(sr, sc);

    if(vis[dr][dc]) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    
    return 0;
}