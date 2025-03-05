#include <bits/stdc++.h>
using namespace std;

class Edge {
    public: 
        int a, b;
        long long w;
        Edge(int a, int b, long long w) {
            this->a = a;
            this->b = b;
            this->w = w;
        }
};

vector<Edge> edgeList;
int n, e;   
long long dis[1005];

bool bellman_ford() {
    for(int i=1; i<n; i++) {
        for(auto edge : edgeList) {
            int a, b;
            long long w;
            a = edge.a;
            b = edge.b;
            w = edge.w;
            if(dis[a] != LLONG_MAX && dis[a]+w< dis[b]) {
                dis[b] = dis[a]+w;
            }
        }
    }

    bool cycle = false;
    for(auto edge : edgeList) {
        int a, b;
        long long w;
        a = edge.a;
        b = edge.b;
        w = edge.w;
        if(dis[a] != LLONG_MAX && dis[a]+w< dis[b]) {
            cycle = true;
            break;
        }
    }
    return cycle;
}

int main()
{
    cin >> n >> e;
    while(e--) {
        int a, b, w;    cin >> a >> b >> w;
        edgeList.push_back(Edge(a,b,w));
    }

    for(int i=1; i<=n; i++) {
        dis[i] = LLONG_MAX;
    }
    int s, t;   cin >> s >> t;
    dis[s] = 0;

    bool cycle = bellman_ford();
    if(!cycle) {
        while(t--) {
            int d;   cin >>  d;
            if(dis[d] == LLONG_MAX)
                cout << "Not Possible" << endl;
            else
                cout << dis[d] << endl;
        }
    }
    else {
        cout << "Negative Cycle Detected" << endl;
    }

    return 0;
}