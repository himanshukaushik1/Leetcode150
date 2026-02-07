#include <bits/stdc++.h>
// #include <vector>     
// #include <algorithm>  for sort
// #include <set>

using namespace std;

// void dispMap(map<int,int> m)
// {
//     for(auto it = m.begin(); it!=m.end(); it++)
//     {
//         cout << (*it) << " : " << m[*it] << "\n";
//     }
// }

void vectorDemo()
{
    vector<int> a = {1};
    // cout << a[0] << "\t";

    // sort(a.begin(), a.end()); 
    
    bool p = binary_search(a.begin(),a.end(),4);
    cout<<p;
    cout << "\nWorking\n";

    a.push_back(5);

    vector<int>:: iterator it = lower_bound(a.begin(), a.end(),5);
    vector<int>:: iterator it1 = upper_bound(a.begin(), a.end(),5);
    
    auto it3 = a.begin();

    // cout << it1;
}

void setDemo()
{
    set<int> s;
    s.insert(1);
    s.insert(5);
    s.insert(-10);
    for(auto it = s.begin(); it!= s.end(); it++)
        cout << *it << " ";

    auto it = s.find(5);
    if(it == s.end())
        cout << "\n Not present \n";
    else
        cout << "\nPresent\n";

    auto it1 = s.lower_bound(2);
    cout << *it1 <<endl;
    auto it2 = s.upper_bound(2);
    cout << *it2 <<endl;    
    cout << *(--it2) <<endl;  
    s.erase(1);

    for(auto it = s.begin(); it!= s.end(); it++)
        cout << *it << " ";
}

void mapDemo()
{
    map<int, int> a;
    a[1] = 100;
    a[2] = 200;
    a[3] = 300;

    map<char, int> b;
    string s = " himanshu ";
    for(char c:s)
        b[c]++;
    cout << b['h'] ;     

}

void setPair()
{

    set< pair<int, int> > s;
    s.insert({1,2});
    s.insert({3,4});
    for(auto it = s.begin(); it!= s.end(); it++)
    {
        // pair< int, int> c = *it;
        cout << (*it).first << "\t";
    }
    cout << INT64_MAX << "\t" << LONG_LONG_MAX;
}

int main()
{
    // string s = "Himanshu";
    // cout << s.size() << endl;
    // vector<int> v = {0,0,0};
    // v[0] = 1;
    // cout << v[0];
    map<pair<int,int>,int> m;
    m[{1,2}] = 1;
    m[{1,3}] = 2;
    cout << m[{1,2}] << m[{1,3}];

    return 0;
}