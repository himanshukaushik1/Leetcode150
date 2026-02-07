/*
You are given an amount denoted by value. You are also given an array of coins. The array contains the denominations of the 
give coins. You need to find the minimum number of coins to make the change for value using the coins of given denominations. 
Also, keep in mind that you have infinite supply of the coins.
If making the change is not possible then print "Not Possible"
*/

// Code Submitted by Himanshu Kaushik (linkedin.com/in/himanshu-kaushik-a7862516b)

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll dp[1001][1001];

ll func(int coins[], int n, int value){
    if(dp[n][value] != -1) return dp[n][value];
    
    if(n == 0){
        return dp[n][value] = INT_MAX-1;
    }
    else if(value == 0){
        return dp[n][value] = 0;
    }
    else if(n == 1){
        if(value% coins[n-1] == 0)
            return dp[n][value] = value/coins[n-1];
        else
            return dp[n][value] = INT_MAX-1;
    }
    if(coins[n-1] <= value){
        return dp[n][value] = min(1+func(coins, n, value-coins[n-1]), func(coins, n-1, value));
    }
    else{
        return dp[n][value] = func(coins, n-1, value);
    }
}

long long minimumNumberOfCoins(int coins[],int n,int value)
{
    memset(dp, -1, sizeof(dp));
    ll v = func(coins, n, value);
    if(v == INT_MAX-1 || v == INT_MAX)
        return -1;
    return v;
}

int main() {
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
	    int value;
	    cin>>value;
	    int numberOfCoins;
	    cin>>numberOfCoins;
	    int coins[numberOfCoins];
	    
	    for(int i=0;i<numberOfCoins;i++)
	    cin>>coins[i];
	    
	    int answer=minimumNumberOfCoins(coins,numberOfCoins,value);
	    if(answer==-1)
	    cout<<"Not Possible"<<endl;
	    else
	    cout<<answer<<endl;
	    
	}
	return 0;
}