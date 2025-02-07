#include <bits/stdc++.h>
using namespace std;

int main()
{   
    int node, edge;     cin >> node >> edge;
    vector<pair<int,int>> edgeList;

    while(edge--) {
        int a, b;   cin >> a >> b;
        edgeList.push_back({a,b});
    }

    for(auto pr : edgeList) {
        cout << "{" << pr.first << "," << pr.second << "}" << " ";
    }

    return 0;
}