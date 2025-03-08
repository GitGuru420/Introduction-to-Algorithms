#include <bits/stdc++.h>
using namespace std;
long long dp[100];

long long fibo(long long n) {   // O(N)
    if(n<2)
        return n;
    if(dp[n] != -1)
        return dp[n];
    dp[n] = fibo(n-1) + fibo(n-2);
    return dp[n];
}

int main()
{
    memset(dp, -1, sizeof(dp));
    long long n;  cin >> n;
    cout << fibo(n) << endl;
    return 0;
}