/*

Given an array arr[] of N integers arranged in a circular fashion. Your task is to find the maximum contiguous subarray sum.


Example 1:

Input:
N = 7
arr[] = {8,-8,9,-9,10,-11,12}
Output:
22
Explanation:
Starting from the last element
of the array, i.e, 12, and 
moving in a circular fashion, we 
have max subarray as 12, 8, -8, 9, 
-9, 10, which gives maximum sum 
as 22.

*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int arr[], int n){
        
        // Kadane's Algorithm
        // int currSum = INT_MIN, sum = 0;
        // int sum2 = INT_MIN, start = 0;
        // for(int i=0; i<n*2; i++){
        //     sum2 = max(sum2, arr[i%n]);
        //     sum += arr[i%n];
        //     if(sum > currSum and i-start<=n){
        //         currSum = sum;
        //     }
        //     if(sum <= 0){
        //         start = i;
        //         sum = 0;
        //     }
        // }
        // if(currSum == 0)
        //     return sum2;
        // return currSum;
        int maxi = INT_MIN, sum = 0;
        for(int i=0; i<n; i++){
            maxi = max(maxi, arr[i]);
            sum += arr[i];
        }
        int maxSum = arr[0], currMax = 0;
        int minSum = arr[0], currMin = 0;
        for(int i=0; i<n; i++){
            currMax = max(currMax + arr[i], arr[i]);
            maxSum = max(currMax, maxSum);
            
            currMin = min(currMin + arr[i], arr[i]);
            minSum = min(currMin, minSum);
        }
        if(minSum == sum){
            return maxSum;
        }
        return max(maxSum, sum-minSum);
    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends