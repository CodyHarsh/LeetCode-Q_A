class Solution {
public:
    void dfs(int node, vector<int> & vis, vector<int> adj[] ){
        if(vis[node]){
            return;
        }
        
        vis[node] = 1;
        
        for(int i: adj[node]){
            if(!vis[i])
            dfs(i, vis, adj);
        }
        
    }
    
    int findCircleNum(vector<vector<int>>& adj) {
        int V= adj.size();
        vector<int> adjLs[V];
        for(int i = 0; i<V; i++){
            for(int j = 0; j<V; j++){
                if(adj[i][j] == 1 && i != j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        vector<int> vis(V,0);
        int count = 0;
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                count++;
                dfs(i, vis, adjLs);
            }
        }
        return count;
    }
};