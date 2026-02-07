// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/

bool traverse(int node, vector<int> adj[], int visited[]){
    bool flag = false;
    for(int i=0; i<adj[node].size(); i++){
        if(visited[adj[node][i]] == 2)
            return true;
        visited[adj[node][i]] ++;
        flag = traverse(adj[node][i], adj, visited);
        if(flag)
            return flag;
        visited[adj[node][i]]--;
    }
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    bool flag = false;
    int visited[V+1];
    memset(visited, 0, sizeof(visited));
    for(int i=0; i<V; i++){
        visited[i] = 1;
        flag = traverse(i, adj, visited);
        if(flag)
            return flag;
        memset(visited, 0, sizeof(visited));
        visited[i] = 0;
    }
    return flag;
    
}

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends