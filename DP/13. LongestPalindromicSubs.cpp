// Given a string s. Find the length of the longest palindromic subsequence.

// Code Submitted by Himanshu Kaushik (linkedin.com/in/himanshu-kaushik-a7862516b)

#include <bits/stdc++.h>
using namespace std;

int LPS(string str)
{
   string str1 = str;
   reverse(str1.begin(), str1.end());
   int n = str.size();
   int dp[n+1][n+1];
   memset(dp, 0, sizeof(dp));
   for(int i=1; i<=n; i++){
       for(int j=1; j<=n; j++){
           if(str[i-1] == str1[j-1]){
               dp[i][j] = 1+ dp[i-1][j-1];
           }
           else{
               dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
           }
       }
   }
   return dp[n][n];
}

int main() {
    int t;
    string s;
    cin >> t;
    while(t--){
        cin >> s;
        cout << LPS(s) << endl;
    }
	return 0;
}