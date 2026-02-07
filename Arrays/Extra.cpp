#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    int func(string s, int k, string charValue){
        map<char, int> m;
        for(int i=0; i<26; i++)
            m['a'+i] = charValue[i];
        int ans = 0;
        vector<int> arr;
        for(auto c:s){
            arr.push_back(m[c]-'0');
        }
        int n = arr.size();

        for(int i=0; i<n; i++){
            cout << arr[i] << " " ;
        }
        cout << endl;
        int j = 0, zeros = 0;
        for(int i=0; i<n; i++){
            if(arr[i] == 0)
                zeros ++;
            while(zeros > k){
                if(arr[j] == 0)
                    zeros --;
                j++;
            }
            ans = max(ans, i-j+1);
        }
        return ans;
    }
    int findZeroes(int arr[], int n, int m) {
        int ans = 0;
        int j = 0, zeros = 0;
        for(int i=0; i<n; i++){
            if(arr[i] == 0)
                zeros ++;
            while(zeros > m){
                
                if(arr[j] == 0)
                    zeros --;
                j++;
            }
            ans = max(ans, i-j+1);
        }

        return ans;
    }  
};

int main() {
    int t;
    int k = 2;
    string s = "giraffe", charValue = "01111001111111111011111111";
    cout << charValue.size() << " \n";
    Solution ob;
    cout << ob.func(s, k, charValue) << endl;
    // cin >> t;
    // while (t--) {
    //     int n, i, m;
    //     cin >> n;
    //     int arr[n];
    //     for (i = 0; i < n; i++) {
    //         cin >> arr[i];
    //     }
    //     cin >> m;
    //     Solution ob;

    //     auto ans = ob.findZeroes(arr, n, m);
    //     cout << ans << "\n";
    // }
    return 0;
}