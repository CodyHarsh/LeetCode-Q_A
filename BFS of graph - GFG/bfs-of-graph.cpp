//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int v, vector<int> adj[]) {
        // Code here
        queue<int> temp;
        vector<int> visited(v,0);
        temp.push(0);
        vector<int> ans;
        visited[0] = 1;
        while(!temp.empty()){
            int currValue = temp.front();
            temp.pop();
            ans.push_back(currValue);
            for(int i = 0; i<adj[currValue].size(); i++){
                    if(!visited[adj[currValue][i]]){
                        temp.push(adj[currValue][i]);
                        visited[adj[currValue][i]] = 1;
                    }
            }
            
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends