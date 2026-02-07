// Given an array of integers, find the length of the longest (strictly) increasing subsequence from the given array.

// Code Submitted by Himanshu Kaushik (linkedin.com/in/himanshu-kaushik-a7862516b)

#include<bits/stdc++.h>
using namespace std;

int longestSubsequence(int, int[]);

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];

        cout << longestSubsequence(n, a) << endl;
    }
}

#define lb lower_bound
#define pb push_back

int longestSubsequence(int n, int a[])
{
    vector<int> v;
    v.pb(a[0]);
    for(int i=1; i<n; i++){
        if(v[v.size()-1]<a[i])
            v.pb(a[i]);             // If a[i] is a larger number than v[n-1], it is added to v 
        else{
            int j = lb(v.begin(), v.end(), a[i])-v.begin();
            v[j] = a[i];
                            // Else, v[j] is replaced with a[i], j is index of lb of a[i]
        }
    }
    return v.size();
}
