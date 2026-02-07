/*

Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order without using any extra space. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.
 

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


void merge(int arr1[], int arr2[], int n, int m) { 
	int i = 0, j = 0, k = n-1;
	while(i<=k and j<m){
		if(arr1[i]<arr2[j])
			i++;
		else{
			swap(arr2[j++], arr1[k--]);
		}
	}
	sort(arr1, arr1+n);
	sort(arr2, arr2+m);
} 

int main() 
{ 
	
	int ar1[] = { 1, 5, 9, 10, 15, 20 };
    int ar2[] = { 2, 3, 8, 13 };
    int m = sizeof(ar1) / sizeof(ar1[0]);
    int n = sizeof(ar2) / sizeof(ar2[0]);
    merge(ar1, ar2, m, n);

    cout << "After Merging \nFirst Array: ";
    for (int i = 0; i < m; i++)
        cout << ar1[i] << " ";
    cout << "\nSecond Array: ";
    for (int i = 0; i < n; i++)
        cout << ar2[i] << " ";
	return 0; 
} 
