/*

There are n tree in a forest. Heights of the trees is stored in array tree[ ]. If ith tree is cut at height h, 
the wood obtained is tree[i]-h, given that tree[i]>h. If total wood needed is k (not less, neither more) 
find the height at which every tree should be cut (all trees have to be cut at the same height).


Example 1:

Input:
N = 5, K = 4
tree[] = {2, 3, 6, 2, 4}
Output: 3
Explanation: Wood collected by cutting trees 
at height 3 = 0 + 0 + (6-3) + 0 + (4-3) = 4
hence 3 is to be subtracted from all numbers.

*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int find_height(int tree[], int n, int k);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n;

        int tree[n];
        for(int i=0; i<n; i++)
            cin>>tree[i];
        cin>>k;

        cout<< find_height(tree,n,k) << endl;
    }
    return 1;
}// } Driver Code Ends

 

int find_height(int tree[], int n, int k)
{
    int ans = -1, total = 0;
    sort(tree, tree+n);
    int l=0, h=tree[n-1];
    int mid = k/2;
    while(l<=h){
        mid = (l+h)/2;
        // cout << l << " " << h << " " << mid << endl;

        total = 0;
        for(int i=n-1; i>=0; i--){
            if(tree[i]<=mid)
                break;
            total += (tree[i]-mid);
        }
        if(total == k)
            return mid;
        else if(total > k){
            l = mid+1;
        }
        else{
            h = mid-1;
        }
        
    }
    
    return -1;
}
