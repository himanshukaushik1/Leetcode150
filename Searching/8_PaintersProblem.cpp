/*

Dilpreet wants to paint his dog's home that has n boards with different lengths. The length of ith board is given by arr[i] 
where arr[] is an array of n integers. He hired k painters for this work and each painter takes 1 unit time to paint 1 unit of the board. 
The problem is to find the minimum time to get this job done if all painters start together with the constraint that any painter 
will only paint continuous boards, say boards numbered {2,3,4} or only board {1} or nothing but not boards {2,4,5}.

Example 1:

Input:
n = 5
k = 3
arr[] = {5,10,30,20,15}
Output: 35
Explanation: The most optimal way will be:
Painter 1 allocation : {5,10}
Painter 2 allocation : {30}
Painter 3 allocation : {20,15}
Job will be done when all painters finish
i.e. at time = max(5+10, 30, 20+15) = 35

*/

// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//

class Solution
{
    public:
    int Painters(int arr[], int n, int mid){
        int painters = 1;
        long long sum = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];
            if(sum>mid){
                painters++;
                sum = arr[i];
            }
        }
        return painters;
    }
    long long minTime(int arr[], int n, int k)
    {
        long long sum = 0;
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            sum += arr[i];
            maxi = max(maxi, arr[i]);
        }
        long long int l = maxi, h = sum, mid, ans = INT_MAX;
        while(l<=h){
            mid = (l+h)/2;
            int painters = Painters(arr, n, mid);
            if(painters<=k){
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}  // } Driver Code Ends