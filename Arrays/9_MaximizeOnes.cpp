/*

Given a binary array arr of size N and an integer M. Find the maximum number of consecutive 1's produced by flipping at most M 0's.
 

Example 1:

Input:
N = 3
arr[] = {1, 0, 1}
M = 1
Output:
3

*/


// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends

// ********************** Sliding window technique where at a time only k zeros are allowed per window *************************************
class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m) {
        int ans = 0;
        int j = 0, zeros = 0;
        for(int i=0; i<n; i++){
            if(arr[i] == 0)
                zeros ++;
            while(zeros > m){
                
                if(arr[j] == 0)
                    zeros --;
                j++;
            }
            ans = max(ans, i-j+1);
        }

        return ans;
    }  
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends