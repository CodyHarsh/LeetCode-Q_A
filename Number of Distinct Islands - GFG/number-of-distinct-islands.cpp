//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    void dfs(int row, int  col, vector<pair<int, int>> &temp, int rootx, int rooty,  vector<vector<int>> &visited , vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        
        //vis[currRow][currCol] = 1;
        //current add
        int x = (rootx - row);
        int y = (rooty - col);
        temp.push_back({x,y});
    
        
        int rowTraversal[] = {-1, 0, 1, 0};
        int colTraversal[] = {0, 1, 0, -1};
        
        for(int i = 0; i<4; i++){
            int currRow = row + rowTraversal[i];
            int currCol = col + colTraversal[i];
            //cout<<currRow<<currCol;
            if(currRow >=0 && currRow<n && currCol >=0 && currCol < m && !visited[currRow][currCol] && grid[currRow][currCol] == 1) {
                visited[currRow][currCol] = 1;
                dfs(currRow, currCol, temp, rootx, rooty, visited, grid);
            }
        }
        
    }
    
    
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        
        //We can do by doing it by
        vector<vector<int>> visited(n, vector<int>(m,0));
        int x = visited.size();
        int y  = visited[0].size();
        //cout<<x<<y<<endl;
        set<vector<pair<int,int>>> ans;
        int count = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                //cout<<grid[i][j]<<endl;
                
                if(grid[i][j] == 1 && !visited[i][j]){
                    //cout<<"i: "<<i<<" j: "<<j<<endl;
                    count++;
                    visited[i][j] = 1;
                    vector<pair<int,int>> temp;
                    dfs(i,j, temp, i ,j , visited, grid );
                    ans.insert(temp);
                }
            }
        }
        return ans.size();
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends