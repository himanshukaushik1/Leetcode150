/*

Given an integer x, find the square root of x. If x is not a perfect square, then return floor(√x).

Example 1:

Input:
x = 5
Output: 2

*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

 // } Driver Code Ends
// Function to find square root
// x: element to find square root
#define ll long long
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        if(x<=1)
            return x;
        ll int l = 1, h = x-1, mid;
        ll int ans = 0;
        while(l<=h){
            mid = (l+h)/2;
            if(x-mid*mid <= 0.000006 and x>=mid*mid){
                return mid;
            }
            if(mid*mid < x){
                l = mid+1;
                ans = mid;
            }
            else
                h = mid-1;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}
  // } Driver Code Ends