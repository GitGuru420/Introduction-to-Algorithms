/*
Problem 1: Convert Adjacency List To Adjacency Matrix

Problem Statement:
Given an adjacency list, convert it into an n × n adjacency matrix representation.

Example:
Input:
3 2
0 1
0 2

Output:
0 1 1
1 0 0
1 0 0
*/

#include <bits/stdc++.h>
using namespace std;

void listToMatrix(int node, int edge) {
    vector<int> adjList[node];
    while(edge--) {
        int a, b;   cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    int adjMat[node][node];
    memset(adjMat, 0, sizeof(adjMat));

    for(int i=0; i<node; i++) {
        for(int j : adjList[i]) {
            adjMat[i][j] = 1;
        }
    }

    for(int i=0; i<node; i++) {
        for(int j=0; j<node; j++) {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }

}

int main()
{
    int node, edge;     cin >> node >> edge;
    listToMatrix(node, edge);

    return 0;
}