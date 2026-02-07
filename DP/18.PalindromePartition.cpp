/*
Given a string, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. 
For example, “aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”. Determine the fewest cuts needed for 
palindrome partitioning of a given string. For example, minimum 3 cuts are needed for “ababbbabbababa”. The three cuts are 
“a|babbbab|b|ababa”.
*/

// Code Submitted by Himanshu Kaushik (linkedin.com/in/himanshu-kaushik-a7862516b)

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll int dp[1001][1001];

bool isPalindrome(string s, int i, int j){
    while(i<j){
        if(s[i] != s[j])
            return false;
        i++; 
        j--;
    }
    return true;
}

ll int palindromePartition(string s, int i, int j){
    if(dp[i][j] != -1)
        return dp[i][j];
    if(i>=j){
        return dp[i][j] = 0;
    }
    if(isPalindrome(s, i, j))
        return dp[i][j] = 0;
    ll int ans = INT_MAX;
    for(int k=i; k<j; k++){
        ll left = 0;
        if(dp[i][k] != -1)
            left = dp[i][k];
        else
            left = palindromePartition(s, i, k);
            
        ll right = 0;
        if(dp[k+1][j] != -1)
            right = dp[k+1][j];
        else
            right = palindromePartition(s, k+1, j);
        ll int temp = left + right + 1;
        ans = min(ans, temp);
    }
    return dp[i][j] = ans;
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    string s;
	    cin >> s;
	    int n = s.size();
	    for(int i=0; i<=n; i++){
	        for(int j=0; j<=n; j++)
	            dp[i][j] = -1;
	    }
	    
	    cout << palindromePartition(s, 0, s.size()-1) << endl;
	}
	return 0;
}