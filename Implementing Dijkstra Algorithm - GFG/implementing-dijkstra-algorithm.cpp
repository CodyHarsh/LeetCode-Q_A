//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int src)
    {
        // Code here
        
        //Make a min heap / Min priority queueu:
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> q;
        
        //Now save the {dist, source} and min priority queue:
        q.push({0, src});
        
        //Now make a distance vector with infinity:
        vector<int> dist(v, INT_MAX);
        
        
        //Make src dist 0:
        dist[src] = 0;
        
        
        while(!q.empty()){
            int val = q.top().second, currDist = q.top().first;
            q.pop();
            
            for(auto i: adj[val]){
                int edge = i[0];
                int edgeDist = i[1];
                int edgeiNewDist = currDist + edgeDist;
                if(dist[edge] > edgeiNewDist){
                    //than add that in queue and update dist:
                    q.push({edgeiNewDist, edge});
                    dist[edge] = edgeiNewDist;
                }
            }
        }
        
        return dist;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends