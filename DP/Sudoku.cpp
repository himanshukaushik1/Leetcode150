// Sudoku Solver using Backtracking(Conditional Recursions with modifications)

#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int sud[9][9], n=9;

bool row(int m, int i)
{
    for(int j=0; j<n; j++)
        if(m == sud[i][j])
            return false;
    return true;
}

bool col(int m, int j)
{
    for(int i=0; i<n; i++)
        if(m == sud[i][j])
            return false;
    return true;
}

bool box(int m, int i, int j)
{
    int box_row = i-(i%3), box_col = j-(j%3);
    for(int i=box_row; i<box_row+3; i++)
    for(int j=box_col; j<box_col+3; j++)
        if(sud[i][j] == m)
            return false;
    return true;
}

bool solve()
{
    bool flag = true;
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        if(sud[i][j] == 0)
        {
            flag = false;
            break;
        }
        if(!flag)
            break;
    }
    if(flag == true) return true;
    for(int k = 1; k<=9; k++)
    {
        if(row(k,i) && col(k,j) && box(k,i,j))
        {
            sud[i][j] = k;
            if(solve())
                return true;
            else 
                sud[i][j] = 0;
        }
    }
    return false;
}

void printSudoku()
{
    int i,j;
    cout << "  ";
    for(i = 0; i<n; i++)
        cout << "   _  ";
    cout << "\n\n";
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            cout << "  |  ";
            cout << sud[i][j];
        }
        cout << "  |\n";
        cout << "  ";
        for(j = 0; j<n; j++)
            cout << "   _  ";
        cout << "\n\n";
    }
}

int main()
{
    int i,j;
    for(i=0; i<n; i++)
    for(j=0; j<n; j++)
        cin >> sud[i][j];
    if(solve())
        printSudoku();
    else
    {
        cout << "No Solution Exists\n";
    }
    return 0;
}

// 0 0 0 0 0 0 6 0 0
// 0 0 0 0 7 2 0 0 3
// 0 9 4 0 0 0 0 5 0
// 0 0 9 2 3 0 0 0 0
// 0 0 0 0 0 4 9 0 0
// 6 1 0 0 0 0 0 0 0
// 0 0 0 8 0 0 0 0 2
// 1 8 0 5 0 0 0 7 0
// 2 5 0 0 0 0 0 0 0

// 0 0 0 0 0 5 0 0 0
// 1 0 0 0 0 0 0 7 0
// 0 0 0 0 0 0 0 0 2
// 6 0 4 0 0 7 0 0 0
// 0 0 0 8 0 0 0 6 0
// 0 0 0 0 0 0 0 0 0 
// 0 0 0 2 0 0 0 0 0
// 0 0 0 3 9 0 0 0 0
// 0 0 0 0 0 0 0 0 0

//   3 1 6 5 7 8 4 9 2
//   5 2 9 1 3 4 7 6 8
//   4 8 7 6 2 9 5 3 1
//   2 6 3 4 1 5 9 8 7
//   9 7 4 8 6 3 1 2 5
//   8 5 1 7 9 2 6 4 3
//   1 3 8 9 4 7 2 5 6
//   6 9 2 3 5 1 8 7 4
//   7 4 5 2 8 6 3 1 9