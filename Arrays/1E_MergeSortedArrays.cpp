/*

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n,
representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array 
nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements 
that should be merged, 
and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
Example 1:

Input: 
n = 4, arr1[] = [1 3 5 7] 
m = 5, arr2[] = [0 2 6 8 9]
Output: 
arr1[] = [0 1 2 3]
arr2[] = [5 6 7 8 9]
Explanation:
After merging the two 
non-decreasing arrays, we get, 
0 1 2 3 5 6 7 8 9.

*/

#include <bits/stdc++.h> 
using namespace std; 


/*
Approach:
    Keep putting the largest number towards the end of first array. 
    Looping should be primarily on second array, because first is anyways already sorted. 
    Eg: m = 10, n = 5. If nums2 is already adjusted in last 5 elements of nums1, the first 10 elements
                       are already sorted anyways.
 */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k=m+n-1, i=m-1, j=n-1;
        if(m==0){
            nums1 = nums2;
            return;
        }
        while(j>=0){
            if(i>=0 and nums1[i]>nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }
    }
};


int main() 
{ 
	// Calling the function
	
	return 0; 
} 
