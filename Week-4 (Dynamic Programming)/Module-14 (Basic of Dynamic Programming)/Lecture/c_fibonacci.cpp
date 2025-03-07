#include <bits/stdc++.h>
using namespace std;

int fibo(int n) {   // O(2^N)
    if(n<2)
        return n;
    return fibo(n-1) + fibo(n-2);
}

int main()
{
    cout << fibo(5) << endl;
    cout << fibo(6) << endl;
    cout << fibo(8) << endl;
    return 0;
}