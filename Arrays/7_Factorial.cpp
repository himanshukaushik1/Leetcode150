/*

You are given an array A of integers of length N. You need to calculate factorial of each number. The answer can be very large, so print it modulo 109 + 7.
NOTE: Array is not sorted 

Example 1:

Input:
N = 5
A[] = {0, 1, 2, 3, 4}
Output:
1 1 2 6 24

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long


class Solution{
public:
	vector<ll> factorial(vector<ll> a, int n) {
	    ll mod = 1000000007;
	    ll m = 0;
	    for(int i=0; i<n; i++)
	        m = max(m, a[i]);
	    vector<ll> fac(100001);
	    fac[0] = 1;
	    fac[1] = 1;
	    for(int i=2; i<=100000; i++){
	        fac[i] = (fac[i-1]%mod * i%mod)%mod;
	    }
	    vector<ll> ans(n);
		for(int i=0; i<n; i++){
		    ans[i] = fac[a[i]];
		}
		return ans;
	}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<ll> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<ll> res = ob.factorial(a, n);
        for (i = 0; i < n; i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}