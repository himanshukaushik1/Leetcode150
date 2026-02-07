/*
Given a sequence of matrices, find the most efficient way to multiply these matrices together. 
The problem is not actually to perform the multiplications, but merely to decide in which order to 
perform the multiplications. There are many options to multiply a chain of matrices because matrix multiplication is associative 
i.e. no matter how one parenthesize the product, the result will be the same.

Example:
 if you had four matrices A, B, C, and D, you would have:

    (ABC)D = (AB)(CD) = A(BCD) = ....
However, the order in which one parenthesize the product affects the number of simple arithmetic operations needed 
to compute the product, or the efficiency.

For example:

A: 10 × 30 matrix
B : 30 × 5 matrix
C : 5 × 60 matrix
Then,
     (AB)C = (10×30×5) + (10×5×60) 
           = 1500 + 3000 
           = 4500 operations
     A(BC) = (30×5×60) + (10×30×60) 
           = 9000 + 18000 
           = 27000 operations.
Given an array arr[] which represents the chain of matrices such that the ith matrix Ai is of dimension arr[i-1] x arr[i].
 Your task is to write a function that should print the minimum number of multiplications needed to multiply the chain.
*/

// Code Submitted by Himanshu Kaushik (linkedin.com/in/himanshu-kaushik-a7862516b)

#include <bits/stdc++.h>
using namespace std;
#define ll long long 

ll int dp[1000][1001];

ll int mcm(int arr[], int i, int j){
    if(dp[i][j] != -1)
        return dp[i][j];
    if(i>=j){
        return dp[i][j] = 0;
    }
    ll int ans = INT_MAX;
    for(int k=i; k<j; k++){
        ll temp = mcm(arr, i, k) + mcm(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
        ans = min(ans, temp);
    }
    return dp[i][j] = ans;
}

int main() {
	int t, n;
	cin >> t;
	while(t--){
	    cin >> n;
	    int arr[n];
	    memset(dp, -1, sizeof(dp));
	    for(int i=0; i<n; i++) cin >> arr[i];
	    cout << mcm(arr, 1, n-1) << endl;
	    
	}
	return 0;
}