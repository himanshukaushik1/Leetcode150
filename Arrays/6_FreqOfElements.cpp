/*

Given an array A[] of n positive integers which can contain integers from 1 to n where elements can be repeated or can be absent 
from the array. Your task is to count the frequency of all elements from 1 to n.


Example 1:

Input:
n = 5
A[] = {2,3,2,3,5}
Output:
0 2 2 0 1

*/

// **************** IMPORTANT ******************

#include<bits/stdc++.h> 
using namespace std; 

//Function to count the frequency of all elements from 1 to N in the array.
void frequencycount(vector<int>& arr,int n)
{ 
    int mod = 100000;
    for(int i=0; i<n; i++){
        arr[(arr[i])%mod-1] = arr[(arr[i])%mod-1] + mod;
    }
    for(int i=0; i<n; i++)
        arr[i] /= mod;
}

int main() 
{ 
	long long t;
	
	//testcases
	cin >> t;
	
	while(t--){
	    
	    int n;
	    //size of array
	    cin >> n; 
	    
	    vector<int> arr(n,0);
	    
	    //adding elements to the vector
	    for(int i = 0;i<n;i++){
	        cin >> arr[i]; 
	    }

        //calling frequncycount() function
		frequencycount(arr,n); 
		
		//printing array elements
	    for (int i =0; i<n; i++) 
			cout<<arr[i]<<" ";
	    cout<<endl;
	}	
	return 0; 
}
