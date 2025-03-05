#include <bits/stdc++.h>
using namespace std;

void maxWater(int n) {
    vector<int> h(n);
    for(int i=0; i<n; i++)
        cin >> h[i];
    int ai, aj;
    vector<int> h2 = h;
    sort(h2.begin(), h2.end(), greater<int>());
    ai = h2[0];
    aj = h2[1];
    int l, r;
    for(int i=0; i<n; i++)  {
        if(ai == h[i])
            l = i;
        if(aj == h[i])
            r = i;
    }
    if(l<r)
        cout << l << " " << r << endl;
    else
        cout << r << " " << l << endl;
}

int main()
{
    int t;  cin >> t;
    while(t--) {
        int n;  cin >> n;
        maxWater(n);
    }
    return 0;
}