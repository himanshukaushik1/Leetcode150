//Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
// For Example:
// ab: Number of insertions required is 1. bab or aba
// aa: Number of insertions required is 0. aa
// abcd: Number of insertions required is 3. dcbabcd

// Code Submitted by Himanshu Kaushik (linkedin.com/in/himanshu-kaushik-a7862516b)

#include <bits/stdc++.h>
using namespace std;

int lcs(string s1, int n){
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    int dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][n];
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    string s;
	    cin >> s;
	    cout << s.size() - lcs(s, s.size()) << endl;
	}
	return 0;
}