/*

Given a sorted array Arr[](0-index based) consisting of N distinct integers and an integer k, 
the task is to find the index of k, if it’s present in the array Arr[]. Otherwise, find the index where k must be inserted 
to keep the array sorted.


Example 1:

Input:
N = 4
Arr = {1 , 3, 5, 6}
k = 5
Output: 2
Explaination: Since 5 is found at index 2 
as arr[2] = 5, the output is 2.

*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int searchInsertK(vector<int> arr, int N, int k)
    {
        if(binary_search(arr.begin(), arr.end(), k)){
            return lower_bound(arr.begin(), arr.end(), k) - arr.begin();
        }
        return upper_bound(arr.begin(), arr.end(), k)-arr.begin();
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<int>Arr(N);
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.searchInsertK(Arr, N, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends