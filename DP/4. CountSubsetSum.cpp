/*
Given an array of integers and a sum, the task is to count all subsets of given array with sum equal to given sum.

*/
// Code Submitted by Himanshu Kaushik (linkedin.com/in/himanshu-kaushik-a7862516b)

#include <iostream>
using namespace std;
#define ll long long

// Count the number of possible subsets with a given sum.

ll SubsetSum(int arr[], int n, int sum){
    ll dp[n+1][sum+1];
    int mod = 1000000007;
    for(int i=0; i<sum+1; i++) dp[0][i] = 0;
    for(int i=0; i<n+1; i++) dp[i][0] = 1;
    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j-arr[i-1]]%mod + dp[i-1][j]%mod;
            }
            else{
                dp[i][j] = dp[i-1][j]%mod;
            }
        }
    }
    return dp[n][sum]%mod;
}

int main() {
	//code
	int t, n, sum;
	cin >> t;
	while(t--){
	    cin >> n;
	    int arr[n];
	    for(int i=0; i<n; i++) cin >> arr[i];
	    cin >> sum;
	    cout << SubsetSum(arr, n, sum) << "\n";
	}
	return 0;
}