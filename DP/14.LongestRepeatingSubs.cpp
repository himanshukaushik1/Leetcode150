//Given a string str, find length of the longest repeating subseequence such that the two subsequence don’t have same string character at same position, i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.

// Code Submitted by Himanshu Kaushik (linkedin.com/in/himanshu-kaushik-a7862516b)

#include <bits/stdc++.h>
using namespace std;

int lcsrep(string s1, int n){
    string s2 = s1;
    int dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            if(s1[i-1] == s2[j-1] and i != j)
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][n];
}

int main() {
	int t, n;
	cin >> t;
	while(t--){
	    cin >> n;
	    string s;
	    cin >> s;
	    cout << lcsrep(s, n) << endl;
	}
	return 0;
}