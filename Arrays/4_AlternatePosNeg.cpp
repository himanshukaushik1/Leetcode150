/*

Given an unsorted array Arr of N positive and negative numbers. Your task is to create an array of alternate positive and negative numbers without changing the relative order of positive and negative numbers.
Note: Array should start with positive number.
 

Example 1:

Input: 
N = 9
Arr[] = {9, 4, -2, -1, 5, 0, -5, -3, 2}
Output:
9 -2 4 -1 5 -5 0 -3 2

*/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends

#define pb push_back

//User function template for C++
class Solution{
public:

	void rearrange(int a[], int n) {
	    // code here
	    vector<int> pos, neg;
	    for(int i=0; i<n; i++){
	        if(a[i] >= 0)
	            pos.pb(a[i]);
	        else
	            neg.pb(a[i]);
	    }
	    int i=0, j=0, k=0;
	   // for(int it=0; it<pos.size(); it++)
	   //     cout << pos[it] << " ";
	   // cout << endl;
	   // for(int it=0; it<neg.size(); it++)
	   //     cout << neg[it] << " ";
	   // cout << endl;
	    while(i<n and j<pos.size() and k<neg.size()){
	        a[i++] = pos[j++];
	        a[i++] = neg[k++];
	    }
	    while(i<n and j<pos.size())
	        a[i++] = pos[j++];
	    while(i<n and k<neg.size())
	        a[i++] = neg[k++];
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends