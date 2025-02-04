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

void listToMatrix(int n, int e) {
    vector<int> adj_list[n];
    while(e--) {
        int a, b;   cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int adj_mat[n][n];
    memset(adj_mat, 0, sizeof(adj_mat));
    for(int i=0; i<n; i++) {
        for(int j : adj_list[i]) {
            adj_mat[i][j] = 1;
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n, e;   cin >> n >> e;
    listToMatrix(n, e);
    
    return 0;
}