class Solution {
public:
    
    void dfs(int row, int col, vector<vector<int>> &visit, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        if(grid[row][col] == 0){
            return;
        }
        
        int rowTraverse[4] = {-1, 0, 1, 0}; 
        int colTraverse[4] = {0, 1, 0, -1};
        
        for(int i =0 ; i<4; i++){
            int numRow = row + rowTraverse[i];
            int numCol = col + colTraverse[i];
            
            
            if(numRow >= 0 && numRow < n && numCol >=0 && numCol < m && !visit[numRow][numCol] && grid[numRow][numCol] != 0){
                //Make it visited first
                visit[numRow][numCol] = 1;
                
                //Call the dfs for the same
                dfs(numRow, numCol, visit, grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> visit(n, vector<int> (m,0));
        
        
        //Traverse the col
        for(int i= 0; i<n ;i++){
            //first col
            if(!visit[i][0] && grid[i][0] == 1){
                 visit[i][0] = 1;
                 dfs(i,0, visit, grid);
            }
            
            
            //Last Col
            if(!visit[i][m-1] && grid[i][m-1] == 1){
                 visit[i][m-1] = 1;
                 dfs(i,m-1, visit, grid);
            }
        }
        
        //Traverse the coloumns
        
        for(int i = 0; i<m; i++){
            //first row
            if(!visit[0][i] && grid[0][i]==1){
                visit[0][i] = 1;
                 dfs(0,i, visit, grid);
            }
            
            if(!visit[n-1][i] && grid[n-1][i]== 1){
                 visit[n-1][i]=1;
                 dfs(n-1,i, visit, grid);
            }
        }
        
        int count =0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                //cout<<visit[i][j]<< " ";
                if(grid[i][j] == 1 && !visit[i][j]){
                    count++;
                } 
            }
            
            cout<<endl;
        }
        
        return count;
    }
};