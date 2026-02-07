/*

Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.
 

Example 1:

Input:
N = 3 
A[] = {1,2,3} 
Output:
-1
Explanation:
Since, each element in 
{1,2,3} appears only once so there 
is no majority element.

*/

#include<bits/stdc++.h>
using namespace std;

// ************** BOYER MOORE VOTING ALGORITHM *****************

int majorityElement(int a[], int n)
{
    int maxInd = 0, count = 1;                                      // 1 1 2 5 1 1 2 3 1 1 2 3 
    for(int i=1; i<n; i++){
        if(a[i] != a[maxInd]){
            count--;
        }
        else
            count ++;
        if(count == 0){
            maxInd = i;
            count = 1;
        }
    }
    count = 0;
    for(int i=0; i<n; i++)
        if(a[i] == a[maxInd]) count ++;
    if(count > n/2)
        return a[maxInd];
    return -1;
}

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        cout << majorityElement(arr, n) << endl;
    }

    return 0;
}
