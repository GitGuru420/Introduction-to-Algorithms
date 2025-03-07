#include <bits/stdc++.h>
using namespace std;

void rec1(int n) {  // O(N)
    if(n>5)
        return;
    cout << n << " ";
    rec1(n+1);
}

void rec2(int n) {  // O(N)
    if(n>5)
        return;
    rec2(n+1);
    cout << n << " ";
}

int rec3(int n) {  // O(N)
    if(n>5) 
        return 0;
    int sum = rec3(n+1);
    return sum + n;
}

int main()
{
    // rec1(1);
    // cout << endl;
    // rec2(1);
    cout << rec3(1) << endl;
    return 0;
}