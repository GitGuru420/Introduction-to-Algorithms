#include <bits/stdc++.h>
using namespace std;

void rec1(int n) {
    if(n>5)
        return;
    cout << n << " ";
    rec1(n+1);
}

void rec2(int n) {
    if(n>5)
        return;
    rec2(n+1);
    cout << n << " ";
}

int main()
{
    rec1(1);
    cout << endl;
    rec2(1);
    return 0;
}