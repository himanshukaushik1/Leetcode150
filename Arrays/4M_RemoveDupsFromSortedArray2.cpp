/*
Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that 
each unique element appears at most twice. The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you must instead have the 
result be placed in the first part of the array nums. More formally, if there are k elements after 
removing the duplicates, then the first k elements of nums should hold the final result. It does not 
matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place 
with O(1) extra memory.

Example 1:

Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,0,1,1,1,1,2,3,3]
Output: 7, nums = [0,0,1,1,2,3,3,_,_]

*/


#include <bits/stdc++.h> 
using namespace std; 


/*
Approach:
    Start from third element.
    Check if this third element is repeated or not. 
        If repeated, increase j to find the condition when it is not repeated.
            when found, assign the ith to jth num 
        else, keep finding 
    
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), i = 2, j = 2;
        if(n<=2){
            return n;
        }
        while(i<n and j<n){
            if(nums[i-2] == nums[j]){
                j++;
            }
            else{
                nums[i++] = nums[j++];
            }
        }
        return i;
    }
};


int main() 
{ 
	// Calling the function
	
	return 0; 
} 
