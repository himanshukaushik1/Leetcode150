/*
Given an array, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.
*/
// Code Submitted by Himanshu Kaushik (linkedin.com/in/himanshu-kaushik-a7862516b)

// Check for possibility of half of the given sum. In the top-down approach matrix (dp), with all the given numbers (n) and sum/2
// check in reverse.

#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int MinSubsetSum(int arr[], int n){
    int total = 0;
    for(int i=0; i<n; i++)  total += arr[i];
    int sum = total;
    total /= 2;
    bool dp[n+1][total+1];
    for(int j=0; j<total+1; j++) dp[0][j] = false;
    for(int i=0; i<n+1; i++) dp[i][0] = true;
    for(int i=1; i<n+1; i++){       // Subset Sum Partition Logic
        for(int j=1; j<total+1; j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    int temp = -1;
    for(int j=total; j>=0; j--){
        if(dp[n][j]){
            temp = sum - 2*j;
            break;
        }
    }
    return temp;
}

int main() {
	int t, n;
	cin >> t;
	while(t--){
	    cin >> n;
	    int arr[n];
	    for(int i=0; i<n; i++)  cin >> arr[i];
	    cout << MinSubsetSum(arr, n) << "\n";
	}
	return 0;
}
