/*

Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 
 

Example 1:

Input:
N = 6
arr[] = {3,0,0,2,0,4}
Output:
10

https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1#

*/

// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n){
        // Code here
        int l[n], r[n];
        r[n-1] = arr[n-1];
        l[0] = arr[0];
        for(int i=1; i<n; i++)
            l[i] = max(l[i-1], arr[i]);
        for(int i=n-2; i>=0; i--)
            r[i] = max(r[i+1], arr[i]);
        
        int ans = 0;
        for(int i=0; i<n; i++){
            if(min(l[i], r[i])>arr[i])
                ans+= min(l[i], r[i]) - arr[i];
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends