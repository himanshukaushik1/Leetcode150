/*

Given two sorted arrays arr1 and arr2 of size M and N respectively and an element K. The task is to find the element that 
would be at the k’th position of the final sorted array.
 
Example 1:

Input:
arr1[] = {2, 3, 6, 7, 9}
arr2[] = {1, 4, 8, 10}
k = 5
Output:
6

https://www.geeksforgeeks.org/k-th-element-two-sorted-arrays/

*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int ans = 0, i = 0, j = 0, count = 0;
        while(i<n and j<m){
            if(arr1[i] < arr2[j]){
                ans = arr1[i];
                if(++count == k)
                    break;
                i++;
            }
            else{
                ans = arr2[j];
                if(++count == k)
                    break;
                j++;
            } 
        }
        if(count != k){
            while(i<n){
                ans = arr1[i++];
                if(++count == k)
                    break;
            }
            while(j<m){
                ans = arr2[j++];
                if(++count == k)
                    break;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends