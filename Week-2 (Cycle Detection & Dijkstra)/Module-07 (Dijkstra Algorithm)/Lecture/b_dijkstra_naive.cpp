#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> adjList[100];
int dis[100];

void dijkstra(int src) {
    queue<pair<int,int>> q;
    q.push({src,0});
    dis[src] = 0;

    while(!q.empty()) {     // O(V)
        pair<int,int> par = q.front();
        q.pop();
        int par_node = par.first;
        int par_dis = par.second;

        for(auto child : adjList[par_node]) {   // O(E)
            int child_node = child.first;
            int child_dis = child.second;

            if(par_dis + child_dis < dis[child_node]) {
                dis[child_node] = par_dis + child_dis;
                q.push({child_node,dis[child_node]});
            }
        }
    }
}
// Time Complexity: O(VE)

int main()
{
    int n, e;   cin >> n >> e;
    while(e--) {
        int a, b, c;    cin >> a >> b >> c;
        adjList[a].push_back({b,c});
        adjList[b].push_back({a,c});
    }
    // memset(dis, INT_MAX, sizeof(dis));
    for(int i=0; i<n; i++) {
        dis[i] = INT_MAX;
    }

    dijkstra(0);
    for(int i=0; i<n; i++) {
        cout << i << " -> " << dis[i] << endl;
    }

    return 0;
}