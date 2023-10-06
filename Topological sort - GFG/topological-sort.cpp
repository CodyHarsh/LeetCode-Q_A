//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    //Using BFS or Kahn's algoirthm:
	    
	    //Making the indegree array:
	    vector<int> indegree(V, 0);
	    
	    for(int i =0; i<V; i++){
	        for(auto j: adj[i]){
	            indegree[j]++;
	        }
	    }
	    
	    
	    queue<int> q;
	    //We have to find the 0's in indegree and add it into the queue
	    for(int i = 0; i<V; i++){
	        if(indegree[i] == 0){
	            q.push(i);
	        }
	    }
	    
	    vector<int> ans;
	    
	    //int n  = 10; 1 to 10: for(auto: )
	    
	    //Now traverse it and find the 0's till queue is empty:
	    while(!q.empty()){
	        int temp  = q.front();
	        q.pop();
	        ans.push_back(temp);
	        //Now check for the 0's in thed company:
	        
	        for(auto i: adj[temp]){
	            indegree[i]--;
	             if(indegree[i] == 0){
	                  //Now check if anyone have become 0 or not:
	                  q.push(i);
	             }
	        }
	        
	        
	       
	    }
	    
	   
	    return ans;
	    
	    
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends