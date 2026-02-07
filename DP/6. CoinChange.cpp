/*
    Unbounded Knapsack
    You have an infinite supply of coins, each having some value.
    Find out the number of ways to use the coins to sum-up to a certain required value.
*/
// Code Submitted by Himanshu Kaushik (linkedin.com/in/himanshu-kaushik-a7862516b)


#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

ll numberOfWays(int coins[],int numberOfCoins,int value)
{
    
    ll ways[value+1]={0}; //We declare an array that will contain the number of--
    //ways to make change for all values from 0 to value
    //This is done as we are working from bottom up. So, obviously, we need to make change for smaller values--
    //before we can make change for the given values.
    ways[0]=1; //We can make change for 0 in 1 ways, that is by choosing nothing.
    vector<int> coinsSet;
    
    for(int i=0;i<numberOfCoins;i++)
    {
        coinsSet.push_back(coins[i]);
    }
    
    for(auto coin:coinsSet) //Using a coin, one at a time
    {
        for(int i=1;i<value+1;i++)
        {
            if(i>=coin) //Since it makes no sense to create change for value smaller than coin's denomination
            {
                ways[i] = ways[i] + ways[i-coin];
               //Write your code here
               //We can make change for i by adding number of ways we previously made change for i-coin
            }
        }
    }
    
    return ways[value];
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
	    
	    cout<<numberOfWays(coins,numberOfCoins,value)<<endl;
	    
	}
	return 0;
}