/*

Given an array A[] of size N, construct a Product Array P (of same size N) such that P[i] is equal to the product of all the elements of A except A[i].

Example 1:

Input:
N = 5
A[] = {10, 3, 5, 6, 2}
Output:
180 600 360 300 900

*/

// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

vector<long long int> productExceptSelf(vector<long long int>&, int );

// your code will be pasted here

int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        
        vec = productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}// } Driver Code Ends


//User function template for C++

// nums: given vector
// return the Product vector P that hold product except self at each index
vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
    vector<long long int> p(n);
    long long int prod = 1;
    int zeros = 0, ind;
    for(int i=0; i<n; i++){
        if(nums[i] == 0){
            zeros ++;
            ind = i;
        }
        else{
            prod *= nums[i];
        }
    }
    if(zeros == 1){
        for(int i=0; i<n; i++){
            p[i] = 0;
        }
        p[ind] = prod;
    }
    else if(zeros > 1){
        for(int i=0; i<n; i++){
            p[i] = 0;
        }
    }
    else{
        for(int i=0; i<n; i++){
            p[i] = prod/nums[i];
        }
    }
    return p;
}
