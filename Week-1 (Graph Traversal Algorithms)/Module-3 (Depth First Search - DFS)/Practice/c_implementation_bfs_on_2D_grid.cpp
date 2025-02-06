#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> movement = {{0,1}, {0,-1}, {-1,0}, {1,0}};
bool visited[105][105];
char grid[105][105];
int n, m;   
int level[105][105];

bool valid(int row, int col) {
    if(row<0 || row>=n || col<0 || col>=m)
        return false;
    return true;
}

void breadth_first_search(int si, int sj) {
    queue<pair<int,int>> q;
    q.push({si,sj});
    visited[si][sj] = true;
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

            if(valid(ci,cj) && !visited[ci][cj]) {
                q.push({ci,cj});
                visited[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    char grid[n][m];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> grid[i][j];
        }
    }
    memset(visited, false, sizeof(visited));
    memset(level, -1, sizeof(level));
    int si, sj;     cin >> si >> sj;    // si->source i, sj->source j
    breadth_first_search(si,sj);
    int di, dj;     cin >> di >> dj;    // di->destination i, dj->destination j
    cout << level[di][dj] << endl;

    return 0;
}   