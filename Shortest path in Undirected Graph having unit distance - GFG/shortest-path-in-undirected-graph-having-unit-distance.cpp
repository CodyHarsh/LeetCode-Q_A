//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int V,int M, int src){
        // code here
        vector<int> adj[V];
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        queue<pair<int,int>>q;
        q.push({src,0});
        
        //Make a dist as an answer and take it as a visited also:
        vector<int> dist(V, -1);
        
        dist[src] = 0;
        while(!q.empty()){
            int val1 = q.front().first, currDist = q.front().second;
            q.pop();
            
            for(auto i: adj[val1]){
                if(dist[i] == -1){
                    dist[i] = currDist + 1;
                    q.push({i, currDist+1});
                }
            }
        
        }
        
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends