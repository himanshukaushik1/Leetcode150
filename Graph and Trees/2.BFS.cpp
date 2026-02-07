// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

vector <int> bfs(vector<int> g[], int N);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        vector<int> adj[N];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        vector <int> res = bfs(adj, N);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        cout << endl;
    }
}// } Driver Code Ends


/* You have to complete this function*/

/* Function to do BFS of graph
*  g[]: adj list of the graph
*  N : number of vertices
*/
vector <int> bfs(vector<int> g[], int N) {
    vector<int> v;
    queue<int> q;
    bool visited[N+1];
    memset(visited, false, sizeof(visited));
    q.push(0);
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        if(!visited[temp]){
            visited[temp] = true;
            v.push_back(temp);
        }
        for(int i=0; i<g[temp].size(); i++){
            if(!visited[g[temp][i]]){
                q.push(g[temp][i]);
            }
        }
    }

    return v;
}