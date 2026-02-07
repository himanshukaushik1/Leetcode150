/*
You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total 
value in the knapsack. Note that we have only one quantity of each item. In other words, given two integer arrays 
val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an 
integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights
of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick it 
(0-1 property).

int dp[1001][1001];

int knapSack(int w, int wt[], int val[], int n) 
{ 
    if(n == 0 or w == 0)
        return 0;
    if(wt[n-1] > w)
        return knapSack(w, wt, val, n-1);
    return max(knapSack(w-wt[i], wt, val, n-1)+val[n-1], knapSack(w, wt, val, n-1));
}

*/
// Code Submitted by Himanshu Kaushik (linkedin.com/in/himanshu-kaushik-a7862516b)

#include<bits/stdc++.h>
using namespace std;

int knapSack(int w, int wt[], int val[], int n) 
{ 
   int dp[n+1][w+1];
   for(int i=0; i<n+1; i++) dp[i][0] = 0;
   for(int j=0; j<w+1; j++) dp[0][j] = 0;
   for(int i=1; i<n+1; i++){
       for(int j=1; j<w+1; j++){
           if(wt[i-1] <= j){
               dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
           }
           else{
               dp[i][j] = dp[i-1][j];
           }
       }
   }
   
   return dp[n][w];
}

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n, w;
        cin>>n>>w;
        int val[n];
        int wt[n];
        
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        for(int i=0;i<n;i++)
            cin>>wt[i];
        
        cout<<knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
 }