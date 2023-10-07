//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int v,int M, vector<vector<int>>& edges){
        // code here
        
        //Make a 2d vector:
        vector<vector<int>> adj(v, vector<int> (v, -1));
        
        for(auto i : edges){
            int a = i[0] , b = i[1],c =  i[2];
            adj[a][b] = c;
        }
        
        //Take a visiting array:
        vector<int> dist(v, -1);
        dist[0] = 0;
        
        //Make a queue
        queue<pair<int,int>> q;
        q.push({0,0});
        
        while(!q.empty()){
            int temp = q.front().first, currDist = q.front().second;
            q.pop();
            
            //Now we will traverse through the adjacents of it:
            for(int i = 0; i<v; i++){
                if(adj[temp][i] >= 0 ){
                    int x = currDist + adj[temp][i];
                    if( dist[i] == -1 || dist[i] > x){
                        dist[i] = x;
                        q.push({i,x});
                    }
                    
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends