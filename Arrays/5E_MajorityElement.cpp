/*

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:
Input: nums = [3,2,3]
Output: 3

Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2

*/


#include <bits/stdc++.h> 
using namespace std; 


/*
Approach:
    1. Create a hashmap to find the occurrences -> space complexity O(n)
    2. Boyer Moore's Voting Algorithm
        consider first as majority element, increase count if it occurs, decrease if it doesn't
        if count becomes 0, then that ith element becomes majority element and count becomes 1

        since, 1 2 1 2 3 will return 3 from above because the last element benefit, we verify if 3 actually
        was a majority element or just last element
    
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = nums[0], n = nums.size(), count = 1, i=0;
        while(i<n){
            if(nums[i] == maj)
                count++;
            else
                count--;
            if(count == 0){
                maj = nums[i];
                count = 1;
            }
            i++;
        }
        count = 0;
        i = 0;
        while(i<n){
            if(nums[i] == maj)
                count++;
            i++;
        }
        if(count > n/2)
            return maj;
        return -1;

    }
};


int main() 
{ 
	// Calling the function
	
	return 0; 
} 
