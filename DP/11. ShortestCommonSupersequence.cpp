/*
Given two strings str1 and str2, find the length of the smallest string which has both, str1 and str2 as its sub-sequences.
Note: str1 and str2 can have both uppercase and lowercase letters.
*/
// Code Submitted by Himanshu Kaushik (linkedin.com/in/himanshu-kaushik-a7862516b)

#include <bits/stdc++.h>
using namespace std;

int lcs(int x, int y, string s1, string s2){
    int dp[x+1][y+1];
    for(int i=0; i<=x; i++) dp[i][0] = 0;
    for(int j=0; j<=y; j++) dp[0][j] = 0;
    for(int i=1; i<=x; i++){
        for(int j=1; j<=y; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[x][y];
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    string s1, s2;
	    cin >> s1 >> s2;
	    cout << s1.size()+s2.size() - lcs(s1.size(), s2.size(), s1, s2) << endl;    // Main Logic
	}
	
	return 0;
}