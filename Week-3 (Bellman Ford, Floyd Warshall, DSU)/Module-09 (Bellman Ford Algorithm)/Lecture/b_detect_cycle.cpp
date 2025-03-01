#include <bits/stdc++.h>
using namespace std;
int n, e;   

class Edge {
    public:
        int a, b, c;
        Edge(int a, int b, int c) {
            this->a = a;
            this->b = b;
            this->c = c;
        }
};

vector<Edge> edgeList;
int dis[1005];

void bellman_ford() {
    for(int i=0; i<n-1; i++) {
        for(auto edge : edgeList) {
            int a, b, c;
            a = edge.a;
            b = edge.b;
            c = edge.c;
            if(dis[a] != INT_MAX && dis[a]+c < dis[b]) {
                dis[b] = dis[a]+c;
            }
        }
    }
    bool cycle = false;
    for(auto edge : edgeList) {
        int a, b, c;
        a = edge.a;
        b = edge.b;
        c = edge.c;
        if(dis[a] != INT_MAX && dis[a]+c < dis[b]) {
            cycle = true;
            break;
        }
    }
    if(cycle)
        cout << "Negative weighted cycle detected" << endl;
    else {
        for(int i=0; i<n; i++) {
            cout << i << " -> " << dis[i] << endl;
        }
    }
}
int main()
{
    cin >> n >> e;
    while(e--) {
        int a, b, c;   cin >> a >> b >> c;
        edgeList.push_back(Edge(a,b,c));
    }

    for(int i=0; i<n; i++) {
        dis[i] = INT_MAX;
    }
    dis[0] = 0; // let source distance is 0

    bellman_ford();

    return 0;
}