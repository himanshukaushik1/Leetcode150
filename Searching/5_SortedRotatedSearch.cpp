/*

Given a sorted and rotated array A of N distinct elements which is rotated at some point, and given an element K. 
The task is to find the index of the given element K in the array A.

Example 1:

Input:
N = 9
A[] = {5 6,7,8,9,10,1,2,3}
K = 10
Output: 5

*/

// *************************************************IMPORTANT***************************************

// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

int Search(vector<int> ,int );

//User code will be pasted here

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        vector<int> vec(n);
        
        for(int i =0;i<n;i++) 
            cin >> vec[i];
        
        int target;
        cin >> target;
        
        cout << Search(vec,target) << "\n";
         
    }
}// } Driver Code Ends


//User function template for C++

// vec : given vector of elements
// K : given value whose index we need to find 
int Search(vector<int> vec, int k) {
    int l =0, h = vec.size()-1, mid;
    while(l<=h){
        mid = (l+h)/2;
        if(vec[mid] == k)
            return mid;
        if(vec[mid] <= vec[h]){
            if(vec[h]>=k and vec[mid]<=k){
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
        else{
            if(vec[l] <=k and vec[mid]>=k)
                h = mid-1;
            else
                l = mid+1;
        }
        
    }
    return -1;
}