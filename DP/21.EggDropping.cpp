/*

Suppose you have N eggs and you want to determine from which floor in a K-floor building you can drop an egg such that it doesn't break. 
You have to determine the minimum number of attempts you need in order find the critical floor in the worst case while using the best strategy.
There are few rules given below. 

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.

*/
// Code Submitted by Himanshu Kaushik (linkedin.com/in/himanshu-kaushik-a7862516b)

#include<bits/stdc++.h>
using namespace std;

int eggDrop(int e, int f) 
{
    int dp[e+1][f+1];
    for(int i=0; i<=e; i++){
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
    for(int j=1; j<=f; j++){
        dp[0][j] = INT_MIN;
        dp[1][j] = j;
    }
    for(int i=2; i<=e; i++){
        for(int j=2; j<=f; j++){
            int temp = 0;
            dp[i][j] = INT_MAX;
            for(int k=1; k<=j; k++){
                temp = 1 + max(dp[i-1][k-1], dp[i][j-k]);
                dp[i][j] = min(temp, dp[i][j]);
            }
        }
    }
    
    return dp[e][f];
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;

        cout<<eggDrop(n, k)<<endl;
    }
    return 0;
}
