#include<bits/stdc++.h>
using namespace std;

int main(){
    string a, b = "";
    cin >> a;
    int i = 0, n = a.length();
    set<char> s = {'a', 'e', 'i', 'o', 'u'};
    int flag = 1;
    while(i<n-1){
        if(s.find(a[i]) != s.end() && s.find(a[i+1]) != s.end()){       // Block vowels
            b = b + a[i];
            i++;
            flag = 1;
        }
        else if(s.find(a[i]) == s.end()){                               // Not a vowel
            b = b + a[i];
            i++;
            flag = 0;
        }
        else{                                                           // next element not a vowel
            if(flag){                                                   // last element of block vowels
                b = b + a[i];
                i++;
                flag = 0;
            }
            else{                                                       // single vowel element (not in any block)
                i++;
            }
        }
    }
    if(s.find(a[n-1]) == s.end())
        b = b + a[n-1];
    cout << b << endl;
    return 0;
}