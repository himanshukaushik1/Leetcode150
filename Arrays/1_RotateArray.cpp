/*

Given an unsorted array arr[] of size N, rotate it by D elements in the counter-clockwise direction. 

 

Example 1:

Input:
N = 5, D = 2
arr[] = {1,2,3,4,5}
Output: 3 4 5 1 2
Explanation: 1 2 3 4 5  when rotated
by 2 elements, it becomes 3 4 5 1 2.

*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//Function to rotate an array by d elements in counter-clockwise direction. 

void rotateArr(int arr[], int d, int n){
    // code here
    d = d%n;
    
    // Works with long long 
        // int mod = 100001;
        // for(int i = 0; i<n; i++){
        //     arr[i] = (arr[(i+d)%n]%mod)*mod + arr[i]%mod;
        // }
        // for(int i=0; i<n; i++)
        //     arr[i] /= mod;
    reverse(arr, arr+n);
    reverse(arr, arr+n-d);
    reverse(arr+n-d, arr+n);
}

// { Driver Code Starts.

int main() {
	int t;
	//taking testcases
	cin >> t;
	
	while(t--){
	    int n, d;
	    
	    //input n and d
	    cin >> n >> d;
	    
	    int arr[n];
	    
	    //inserting elements in the array
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	    
	    //calling rotateArr() function
	    rotateArr(arr, d,n);
	    
	    //printing the elements of the array
	    for(int i =0;i<n;i++){
	        cout << arr[i] << " ";
	    }
	    cout << endl;
	}
	return 0;
}  // } Driver Code Ends