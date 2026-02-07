/*
Given an array of integers where each element represents the max number of steps that can be made forward from that element. 
The task is to find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0,
 then cannot move through that element.
*/

// Code Submitted by Himanshu Kaushik (linkedin.com/in/himanshu-kaushik-a7862516b)

#include <bits/stdc++.h>
using namespace std;

int maxJumps(int arr[], int n){
    if(n < 2)
        return 0;
    if(arr[0] == 0)
        return -1;
    int dp[n+1];
    for(int i=0; i<n; i++) dp[i] = INT_MAX;
    dp[0] = 0;
    for(int i=0; i<n-1; i++){
        if(arr[i] == 0)
            continue;
        for(int j=1; j<=min(arr[i], n-i-1 ); j++){
            dp[i+j] = min(dp[i+j], dp[i]+1);
        }
    }
    if(dp[n-1] == INT_MAX)
        return -1;
    return dp[n-1];
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    int arr[n];
	    for(int i=0; i<n; i++)  cin >> arr[i];
	    cout << maxJumps(arr, n) << endl;
	}
	return 0;
}