#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> movement = {{0,1}, {0,-1}, {-1,0}, {1,0}};
bool visited[105][105];
char grid[105][105];
int n, m;   

bool valid(int row, int col) {
    if(row<0 || row>=n || col<0 || col>=m)
        return false;
    return true;
}

void depth_first_search(int si, int sj) {
    cout << si << " " << sj << endl;
    visited[si][sj] = true;
    for(int i=0; i<4; i++) {
        int ci = si + movement[i].first;    // ci->child i
        int cj = sj + movement[i].second;   // cj->child j
        if(valid(ci,cj) && !visited[ci][cj])
            depth_first_search(ci,cj);
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
    int si, sj;     cin >> si >> sj;    // si->source i, sj->source j
    depth_first_search(si,sj);

    return 0;
}   