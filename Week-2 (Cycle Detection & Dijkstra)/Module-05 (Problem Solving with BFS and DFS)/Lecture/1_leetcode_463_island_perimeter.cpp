#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool visited[105][105];
        vector<pair<int,int>> movement = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        int row, col;
        int cnt;
    
        bool valid(int i, int j) {
            if(i<0 || i>=row || j<0 || j>=col)
                return false;
            return true;
        }
    
        void dfs(int si, int sj, vector<vector<int>>& grid) {
            visited[si][sj] = true;
            for(int i=0; i<4; i++) {
                int ci = si + movement[i].first;
                int cj = sj + movement[i].second;
                if(!valid(ci,cj))
                    cnt++;
                else if(valid(ci,cj) && grid[ci][cj] == 0)
                    cnt++;
                else if(valid(ci,cj) && !visited[ci][cj] && grid[ci][cj] == 1) 
                    dfs(ci,cj,grid);
            }
        }
    
        int islandPerimeter(vector<vector<int>>& grid) {
            cnt = 0;
            row = grid.size();
            col = grid[0].size();
            memset(visited, false, sizeof(visited));
            for(int i=0; i<row; i++) {
                for(int j=0; j<col; j++) {
                    if(!visited[i][j] && grid[i][j] == 1) {
                        dfs(i,j,grid);
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