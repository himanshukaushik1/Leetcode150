/*
Given an array arr[] of N positive integers. Find maximum value of |arr[i] – arr[j]| + |i – j|, (0 <= i, j <= N – 1)

Example 1:

Input:
N = 4 
arr[] = {1, 2, 3, 1}
Output:
4
Explanation:
Choosing i=0 and j=2, will result in
|1-3|+|0-2| = 4

Case 1: A[i] > A[j] and i > j
|A[i] - A[j]| = A[i] - A[j]
|i -j| = i - j
hence, f(i, j) = (A[i] + i) - (A[j] + j)

Case 2: A[i] < A[j] and i < j
|A[i] - A[j]| = -(A[i]) + A[j]
|i -j| = -(i) + j
hence, f(i, j) = -(A[i] + i) + (A[j] + j)

Case 3: A[i] > A[j] and i < j
|A[i] - A[j]| = A[i] - A[j]
|i -j| = -(i) + j
hence, f(i, j) = (A[i] - i) - (A[j] - j)

Case 4: A[i] < A[j] and i > j
|A[i] - A[j]| = -(A[i]) + A[j]
|i -j| = i - j
hence, f(i, j) = -(A[i] - i) + (A[j] - j)

*/

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
    map<string, int> mp;
    public:
//   int func(int arr[], int i, int j, int N){
//         if(j<=i or i >= N or j<0)
//             return 0;
//         string s = to_string(i) + to_string(j);
//         if(mp.find(s) != mp.end())
//             return mp[s];
//         return mp[s] = max(abs(arr[i]-arr[j]) + abs(i-j), max(func(arr, i+1, j, N), func(arr, i, j-1, N)));
//   }
    int maxValue(int arr[], int n) {
        int max1 = INT_MIN, min1 = INT_MAX; 
        int max2 = INT_MIN, min2 = INT_MAX; 
      
        for (int i = 0; i < n; i++) { 
            max1 = max(max1, arr[i] + i); 
            min1 = min(min1, arr[i] + i); 
            max2 = max(max2, arr[i] - i); 
            min2 = min(min2, arr[i] - i); 
        } 
      
        return max(max1 - min1, max2 - min2); 
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int arr[N];
        
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.maxValue(arr,N) << endl;
    }
    return 0;
}  // } Driver Code Ends