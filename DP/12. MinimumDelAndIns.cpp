/*
Given two strings ‘str1’ and ‘str2’ of size m and n respectively. The task is to remove/delete and insert 
minimum number of characters from/in str1 so as to transform it into str2. It could be possible that the same 
character needs to be removed/deleted from one point of str1 and inserted to some another point.

Input:
1
4 3
heap pea 

Output:
3
*/
// Code Submitted by Himanshu Kaushik (linkedin.com/in/himanshu-kaushik-a7862516b)

#include <bits/stdc++.h>
using namespace std;

int lcs(int x, int y, string s1, string s2){
    int dp[x+1][y+1];
    memset(dp, 0, sizeof(dp));
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
	int t, x, y;
	cin >> t;
	while(t--){
	    cin >> x >> y;
	    string s1, s2;
	    cin >> s1 >> s2;
	    cout << (x+y) - 2*lcs(x,y,s1,s2) << endl;           // Main Logic
	}
	
	return 0;
}