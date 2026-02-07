/*

Given an array Arr of N numbers and another number target, find three integers in the array such that 
the sum is closest to target. Return the sum of the three integers.

Example 1:

Input:
N = 6, target = 2
A[] = {-7,9,8,3,1,1}
Output: 2
Explanation: There is one triplet with sum
2 in the array. Triplet elements are -7,8,
1 whose sum is 2.

*/

// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value
class Solution{
  public:
    int threeSumClosest(vector<int> arr, int target) {
        int n = arr.size();
        int diff = INT_MAX, ans = INT_MIN;        
        sort(arr.begin(), arr.end());
        
        /*
        // When all numbers are distinct
        
        vector<int>::iterator l, u;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int temp = target - arr[i] - arr[j];
                l = lower_bound(arr.begin(), arr.end(), temp);
                u = upper_bound(arr.begin(), arr.end(), temp);
                if(diff> abs(temp- *l)){
                    diff = abs(temp - *l);
                    ans = *l + arr[i] + arr[j];
                }
                if(diff> abs(temp- *u)){
                    diff = abs(temp - *u);
                    ans = *u + arr[i] + arr[j];
                }
            }
        }*/
        /*for(int i=0; i<n; i++){
            int l = i+1, r = n-1;
            while(l<r){
                int temp = arr[i] + arr[l] + arr[r];
                if(temp == target)
                    return temp;
                if(temp<target){
                    l++;
                }
                else{
                    r--;
                }
                if(diff==abs(target-temp)){
                    ans = max(ans, temp);
                }
                else{
                    diff = min(diff, abs(target-temp));
                }
            }
        }
        return ans;*/
        int res = INT_MIN, minDiff = INT_MAX;
        
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < arr.size(); i++){
        
            int sum = arr[i];
            int l = i+1, h = arr.size()-1;
            
            while(l < h){
                int temp = sum + arr[l] + arr[h];
                
                int diff = abs(target - temp);
                
                if(diff == 0)
                    return temp;
                else if(temp < target)
                    l++;
                else
                    h--;
                
                if(minDiff == diff){
                    res = max(res, temp);
                }
                else {
                    minDiff = min(diff, minDiff);
                    if(minDiff == diff)
                        res = temp;
                }
            
            }
        }
        
        return res;

    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while(t--) {
        
        int n,target;
        cin >> n >> target;
        
        vector<int> vec(n);
        
        for(int i = 0 ; i < n ; ++ i ) 
            cin >> vec[i];
        Solution obj;
        cout << obj.threeSumClosest(vec, target) << "\n";
    }
}

//Position this line where user code will be pasted.
  // } Driver Code Ends