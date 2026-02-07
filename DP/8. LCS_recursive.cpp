/*
Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.
Recursive approach
*/

// Code Submitted by Himanshu Kaushik (linkedin.com/in/himanshu-kaushik-a7862516b)

#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

int lcs(int, int, string, string);

int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        
        cout << lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

int dp[1001][1001];
int lcsrec(int x, int y, string s1, string s2){
    if(dp[x][y] != -1) return dp[x][y];
    
    if(x == 0 or y == 0) return dp[x][y] = 0;
    if(s1[x-1] == s2[y-1]){
        return dp[x][y] = 1 + lcsrec(x-1, y-1, s1, s2);
    }
    else{
        return dp[x][y] = max(lcsrec(x-1, y, s1, s2), lcsrec(x, y-1, s1, s2));
    }
}

int lcs(int x, int y, string s1, string s2){
    memset(dp, -1, sizeof(dp));
    // for(int i=0; i<x; i++) dp[i][0] = 0;
    // for(int j=0; j<y; j++) dp[0][j] = 0;
    
    return lcsrec(x, y, s1, s2);
}
