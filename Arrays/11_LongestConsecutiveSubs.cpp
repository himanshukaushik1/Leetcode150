/*

Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence 
are consecutive integers, the consecutive numbers can be in any order.
 

Example 1:

Input:
N = 7
a[] = {2,6,1,9,4,5,3}
Output:
6

*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
      //Your code here
      int a[1000001];
      memset(a, 0, sizeof(a));
      for(int i=0; i<n; i++){
          a[arr[i]] = 1;
      }
      int count  = 0, ans = 0;
      for(int i=0; i<100001; i++){
        if(a[i] != 0){
            count++;
            ans = max(count, ans);
        }
        else{
            count = 0;
        }
          
      }
      return ans;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends