#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define ar array

void solve(ll n)
{
    int i2,i3,i5;
    i2 = i3 = i5 = 0;
    ar<ll, 1000> a;
    a.fill(0);
    a[0] = 1;
    int next2, next3, next5;
    next2 = 2 ; next3 = 3; next5 = 5;  
    for(ll i=1; i<n; i++)
    {
        a[i] = min(next2, min(next3, next5));
        if(a[i] == next2)
        {
            i2++;
            next2 = a[i2] * 2;
        }
        if(a[i] == next3)
        {
            i3++;
            next3 = a[i3] * 3;
        }
        if(a[i] == next5)
        {
            i5++;
            next5 = a[i5] * 5;
        }
    }
    for(ll i=0; i<n; i++)
    {
        cout << a[i] << "  ";
    }
    cout << "\n";
    cout << a[n-1] << endl;
}

int main()
{
    ll n;
    cin >> n;
    solve(n);
    return 0;
}