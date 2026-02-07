/*
Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person 
and follows a certain rule when looting the houses. According to the rule, he will never loot two consecutive houses.
At the same time, he wants to maximize the amount he loots. The thief knows which house has what amount of money but is 
unable to come up with an optimal looting strategy. He asks for your help to find the maximum money he can get if he strictly
 follows the rule. Each house has a[i] amount of money present in it.
*/

// Code Submitted by Himanshu Kaushik (linkedin.com/in/himanshu-kaushik-a7862516b)

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll FindMaxSum(ll arr[], ll n)
{
    if(n <= 0){
        return 0;
    }
    ll ans[n+1];
    ans[0] = arr[0];
    ans[1] = max(ans[0], arr[1]);
    for(int i=2; i<n; i++){
        ans[i] = max(arr[i] + ans[i-2], ans[i-1]);
    }
    return ans[n-1];
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n];
		for(ll i=0;i<n;++i)
			cin>>a[i];
		cout<<FindMaxSum(a,n)<<endl;
	}
	return 0;
}
