/*
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
*/



#include <bits/stdc++.h> 
using namespace std; 


/*
Approach:
    1. Create another array, select the nums[(i+k)%n] element for new_array[i]
    2. Reverse 0 to k-1, reverse k to n-1, reverse whole array again
 */

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        reverse(nums, 0, n-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, n-1);

    }
    void reverse(vector<int>& nums, int left, int right){
        while(left < right){
            swap(nums[left++], nums[right--]);
        }
    }
};


int main() 
{ 
	// Calling the function
	
	return 0; 
} 
