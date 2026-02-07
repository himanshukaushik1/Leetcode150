/*

Given an positive integer N and a list of N integers A[]. Each element in the array denotes the maximum length of jump you can cover. 
Find out if you can make it to the last index if you start at the first index of the list.
Example 1:

Input:
N = 6
A[] = {1, 2, 0, 3, 0, 0} 
Output:
1

*/

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//User function Template for C++

class Solution {
  public:
    int canReach(int A[], int N) {
        int i, m = A[0];
        for(i=0; i<=m; i++){
            if(i+A[i] > m) 
                m=i+A[i];
            if(m >= N-1) 
                return 1;
        }
        return 0;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}  // } Driver Code Ends