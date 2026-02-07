// Problem n number of friends, Find the number of ways in which you can pair them or let them stay single

#include<bits/stdc++.h>
#define pb push_back

using namespace std;
int dp[10000];

int solve(int n)
{
    if(dp[n] != -1)
        return dp[n];
    if(n<=2)
        return dp[n];
    return dp[n] = solve(n-1) + (n-1)*solve(n-2);
}

int main()
{
    memset(dp,-1,sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    int n;
    cin >> n;
    cout << solve(n) << endl;

    return 0;
}