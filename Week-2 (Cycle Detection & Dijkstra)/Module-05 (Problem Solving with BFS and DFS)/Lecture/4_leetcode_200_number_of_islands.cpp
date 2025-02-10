#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool vis[305][305];
        vector<pair<int,int>> d = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        int row, col;
    
        bool valid(int i, int j) {
            if(i<0 || i>=row || j<0 || j>=col) 
                return false;
            return true;
        }
    
        void dfs(int si, int sj, vector<vector<char>>& grid) {
            vis[si][sj] = true;
            for(int i=0; i<4; i++) {
                int ci = si + d[i].first;
                int cj = sj + d[i].second;
                if(valid(ci,cj) && !vis[ci][cj] && grid[ci][cj] == '1') {
                    dfs(ci,cj,grid);
                }
            }
        }
    
        int numIslands(vector<vector<char>>& grid) {
            int cnt = 0;
            row = grid.size();
            col = grid[0].size();
            for(int i=0; i<row; i++) {
                for(int j=0; j<col; j++) {
                    if(valid(i,j) && !vis[i][j] && grid[i][j] == '1') {
                        dfs(i,j,grid);
                        cnt++;
                    }
                }
            }
            return cnt;
        }
    };

int main()
{

    return 0;
}