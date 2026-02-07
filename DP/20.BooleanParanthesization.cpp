/*
Given a boolean expression with following symbols.

Symbols
    'T' ---> true
    'F' ---> false

And following operators filled between symbols

Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR

Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

For Example:
The expression is "T | T & F ^ T", it evaluates true
in 4 ways ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T)
and (T|((T&F)^T)).
*/

// Code Submitted by Himanshu Kaushik (linkedin.com/in/himanshu-kaushik-a7862516b)
#include <bits/stdc++.h>
using namespace std;
int mod = 1003;
unordered_map<string, int> m;
int booleanPar(string s, int i, int j, bool isTrue){
    if(i>j)
        return 0;
    if(i == j){
        if(isTrue)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }
    string ns = to_string(i) + " " + to_string(j) + " ";
    if(isTrue)
        ns = ns + "T";
    else 
        ns = ns + "F";
    
    if(m.find(ns) != m.end())
        return m[ns];
    int temp = 0, lf, lt, rf, rt;
    for(int k=i+1; k<j; k+=2){
        string ns1 = to_string(i) + " " + to_string(k-1) + " F";
        if(m.find(ns1) != m.end())
            lf = m[ns1];
        else
            lf = booleanPar(s, i, k-1, false);
        string ns2 = to_string(i) + " " + to_string(k-1) + " T";
        if(m.find(ns2) != m.end())
            lt = m[ns2];
        else
            lt = booleanPar(s, i, k-1, true);
        string ns3 = to_string(k+1) + " " + to_string(j) + " F";
        if(m.find(ns3) != m.end())
            rf = m[ns3];
        else
            rf = booleanPar(s, k+1, j, false);
        string ns4 = to_string(k+1) + " " + to_string(j) + " T";
        if(m.find(ns4) != m.end())
            rt = m[ns4];
        else
            rt = booleanPar(s, k+1, j, true);
        
        if(s[k] == '&'){
            if(isTrue){
                temp += lt*rt;
            }
            else{
                temp += lf*rf;
                temp += lf*rt;
                temp += lt*rf;
            }
        }
        else if(s[k] == '^'){
            if(isTrue){
                temp += lf*rt;
                temp += lt*rf;
            }
            else{
                temp += lf*rf;
                temp += lt*rt;
            }
        }
        else if(s[k] == '|'){
            if(isTrue){
                temp += lt*rf;
                temp += lt*rt;
                temp += lf*rt;
            }
            else{
                temp += lf*rf;
            }
        }
        temp = temp%1003;
    }
    return m[ns] = temp%1003;
}

int main() {
	int t, n;
	cin >> t;
	while(t--){
	    cin >> n;
	    string s;
	    cin >> s;
        m.clear();
	    cout << booleanPar(s, 0, n-1, true) << endl;
	}
	
	return 0;
}