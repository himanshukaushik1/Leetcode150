//Catalan Number:  C0 = 1 and C(n+1) = Summation (i=0 to n) C(i)*C(n-i)

// Problem : n*m grid with values(Gold Values). Move Right, RightUp or RightDown Collecting the gold, begin from anywhere 
//          in first column. Find Maximum number of Gold you can collect. 

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

int matrix[100][100], n, m;

void solve()
{
    int r=0, ru=0, rd=0;
    for(int j=0; j<m; j++)
    {
        for(int i=0; i<n; i++)
        {
            if(j == 0)
            {
                continue;
            }
            if(i == 0 and i+1<n)
            {
                ru = 0;
                r = matrix[i][j-1];
                rd = matrix[i+1][j-1];
            }
            else if(i == n-1 and i-1>=0)
            {
                rd = 0;
                r = matrix[i][j-1];
                ru = matrix[i-1][j-1];
            }
            else
            {
                r = matrix[i][j-1];
                ru = matrix[i-1][j-1];
                rd = matrix[i+1][j-1];
            }
            matrix[i][j] += max(r,max(rd,ru));
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
    int Maxi = 0;
    for(int i=0; i<n; i++)
    {
        Maxi = max(Maxi, matrix[i][m-1]);
    }
    cout << Maxi <<endl;

}

int main()
{
    cin >> n >>m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> matrix[i][j];
    solve();
    return 0;
}