#include <bits/stdc++.h>
using namespace std;
int par[1005];
int group_size[1005];

int find(int node)
{
    cout << node << endl;
    if(par[node] == -1)
        return node;
    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union(int node1, int node2)
{
    int leader1 = find(node1);
    int leader2 = find(node2);
    if(leader1 == leader2)
        return;
    if(group_size[leader1] >= group_size[leader2])
    {
        par[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
    }
    else
    {
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
}

int main()
{
    int n;  cin >> n;
    for(int i=1; i<=n; i++) {
        par[i] = -1;
        group_size[i] = 1;
    }
    vector<pair<int,int>> rmv;
    for(int i=0; i<n-1; i++) {
        int a, b;   cin >> a >> b;
        int leaderA = find(a);
        int leaderB = find(b);
        if(leaderA == leaderB)
            rmv.push_back({a,b});
        else 
            dsu_union(a,b);
    }

    return 0;
}