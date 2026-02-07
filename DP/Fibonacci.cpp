// Direct Formula ->  Fn = {[(√5 + 1)/2] ^ n} / √5

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

array<int, 100000> f;

int Fib(int n)
{
    if(n<=1) return n;
    if(f[n])
        return f[n];
    
    f[n] = Fib(n-1) + Fib(n-2);
    return f[n];
}
int main()
{
    f.fill(0);
    f[0] = 0;
    f[1] = 1;
    
    int n;
    cin >> n;
    for(int i =1; i<=n; i++)
        cout << Fib(i) << "  ";
    cout << endl;
    return 0;
}