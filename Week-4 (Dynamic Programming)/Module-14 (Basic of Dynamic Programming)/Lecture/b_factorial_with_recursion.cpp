#include <bits/stdc++.h>
using namespace std;

int fact(int n) {   // O(N)
    if(n==1)
        return 1;
    // int mul = fact(n-1);
    return fact(n-1) * n;
}

int main()
{
    cout << fact(5) << endl;
    return 0;
}