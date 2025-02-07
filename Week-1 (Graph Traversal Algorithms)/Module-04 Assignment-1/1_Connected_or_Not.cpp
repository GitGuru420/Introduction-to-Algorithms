#include <bits/stdc++.h>
using namespace std;
vector<int> adjList[1000];

void bfs(int qa, int qb) {
    if(qa == qb) {
        cout << "YES" << endl;
        return;
    }
    queue<int> q;
    q.push(qa);

    while(!q.empty()) {
        int par = q.front();
        q.pop();

        for(int child : adjList[par]) {
            if(child == qb) {
                cout << "YES" << endl;  return;
            }
        }
        cout << "NO" << endl;
    }
}
int main()
{
    int n, e;   cin >> n >> e;
    while(e--) {
        int a, b;   cin >> a >> b;
        adjList[a].push_back(b);
    }
    int q;  cin >> q;
    while(q--) {
        int qa, qb; cin >> qa >> qb;
        bfs(qa, qb);
    }

    return 0;
}