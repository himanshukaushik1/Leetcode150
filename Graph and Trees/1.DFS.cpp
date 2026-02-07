// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/* Function to do DFS of graph

g : adjacency list of graph
N : number of vertices

return a list containing the DFS traversal of the given graph
*/

vector <int> dfs(vector<int> g[], int N)
{
    stack<int> s;
    s.push(0);
    vector<int> v;
    bool visited[N+1];
    memset(visited, false, sizeof(visited));
    while(!s.empty()){
        int temp = s.top();
        s.pop();
        if(!visited[temp]){
            v.push_back(temp);
            visited[temp] = true;
        }
        for(int i=g[temp].size()-1; i>=0; i--){
            if(!visited[g[temp][i]]){
                s.push(g[temp][i]);
            }
        }
    }
    return v;

}
/*
vector <int> dfs(vector<int> g[], int N)
{
    stack<int> s;
    s.push(0);
    vector<int> v;
    bool visited[N+1];
    memset(visited, false, sizeof(visited));
    while(!s.empty()){
        int temp = s.top();
        if(!visited[temp]){
            v.push_back(temp);
            visited[temp] = true;
        }
        
        for(int i=0; i<g[temp].size(); i++){
            
            if(!visited[g[temp][i]]){
                visited[g[temp][i]] = true;
                v.push_back(g[temp][i]);
                s.push(g[temp][i]);
                break;
            }
        }
        if(s.top() == temp)
            s.pop();
    }
    return v;

}
*/
// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {

        int N, E;
        cin>>N>>E;
        
        vector<int> g[N];
        bool vis[N];
        
        memset(vis, false, sizeof(vis));
        
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector <int> res = dfs(g, N);
        for (int i = 0; i < res.size (); i++)
            cout << res[i] << " ";
        cout<<endl;

    }
}  // } Driver Code Ends