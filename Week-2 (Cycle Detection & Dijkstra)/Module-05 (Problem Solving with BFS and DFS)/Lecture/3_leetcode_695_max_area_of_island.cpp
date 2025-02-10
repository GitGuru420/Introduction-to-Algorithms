#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool visited[55][55];
        vector<pair<int,int>> d = {{0,-1}, {0,1}, {-1,0}, {1,0}};
        int row, col, cnt, mx;
    
        bool valid(int i, int j) {
            if(i<0 || i>=row || j<0 || j>=col) 
                return false;
            return true;
        }
    
        void dfs(int si, int sj, vector<vector<int>>& grid) {
            visited[si][sj] = true;
            cnt++;
            for(int i=0; i<4; i++) {
                int ci = si + d[i].first;
                int cj = sj + d[i].second;
                if(valid(ci,cj) && !visited[ci][cj] && grid[ci][cj] == 1) {
                    dfs(ci, cj, grid);
                }
            }
        }
    
        int maxAreaOfIsland(vector<vector<int>>& grid) {
            row = grid.size();
            col = grid[0].size();
            mx = 0;
            memset(visited, false, sizeof(visited));
            for(int i=0; i<row; i++) {
                for(int j=0; j<col; j++) {
                    if(!visited[i][j] && grid[i][j] == 1) {
                        cnt = 0;
                        dfs(i, j, grid);
                        mx = max(cnt, mx);
                    }
                }
            }
            return mx;
        }
    };

int main()
{

    return 0;
}