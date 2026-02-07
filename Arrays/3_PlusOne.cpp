/*

Given a non-negative number represented as a list of digits, add 1 to the number (increment the number represented by the digits). The digits are stored such that the most significant digit is first element of array.
 

Example 1:

Input: 
N = 3
arr[] = {1, 2, 4}
Output: 
1 2 5
Explanation:
124+1 = 125, and so the Output

*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function Template for C++

class Solution {
  public:
    vector<int> increment(vector<int> arr ,int n) {
        // code here
        int carry = 1;
        for(int i=n-1; i>=0; i--){
            if(arr[i] + 1 >9){
                arr[i] = (arr[i]+1)%10;
            }
            else{
                arr[i] += 1;
                carry = 0;
                break;
            }
        }
        if(carry){
            arr.insert(arr.begin(), 1);
        }
        return arr;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        char c;
        
        cin>>N;
        vector<int> arr(N);
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> res = ob.increment(arr,N);
        for(int i: res)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends