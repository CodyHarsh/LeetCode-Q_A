//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool detect(int src, vector<int> adj[], int vis[]) {
        // Code here
        queue<pair<int,int>> q;
        q.push({src,-1});
       
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            vis[x] = 1;
            q.pop();
            
            
            for(int i: adj[x]){
                if(!vis[i]){
                    q.push({i, x});
                    vis[i] = 1;
                }
                else if(i != y){
                    return 1;
                }
            }
        }
        
        return 0;
    }
    
    bool isCycle(int V, vector<int> adj[]){
        int vis[V]= {0};
        
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                bool ans = detect(i, adj, vis);
                if(ans) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends