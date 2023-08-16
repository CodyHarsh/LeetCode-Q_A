class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        
        
        //Make An Queue
        //Queue will contain vector of 3 size 
        //vector 0th index will be = row location
        //vector 1st index will be = coloumn location
        //vectore 2nd index will be = current timing
        queue<vector<int>> bfs;
        
        
        // Now we will store the indexes values from grid which have value 2:
       
        vector<int> temp = {sr,sc,0};
        bfs.push(temp);
        int curr = grid[sr][sc];
        
        
        //Now we will run the queue till it is not empty:
        int lastTime = 0;
        while(!bfs.empty()){
            vector<int> temp  = bfs.front();
            bfs.pop();
            int row = temp[0];
            int col = temp[1];
            int currMin = temp[2];
            vis[row][col] = 1;
            lastTime = currMin;
            cout<<"row: "<<row<<" col: "<<col<<" lastMin: "<<currMin<<endl;
            
            //Make upper adjacent 2/Rotten 
            if(row-1 >= 0 && vis[row-1][col] == 0 && grid[row-1][col] == curr){
                grid[row-1][col] = color;
                vector<int> temp2 = {row-1, col, currMin +1};
                bfs.push(temp2);
            }
            
            //Make lower adjacent 2/Rotten
            if(row+1 < n && vis[row+1][col] == 0 && grid[row+1][col] == curr){
                grid[row+1][col] = color;
                vector<int> temp2 = {row+1, col, currMin +1};
                bfs.push(temp2);
            }
            
            
            //Make left adjacent 2/Rotten
            if(col-1 >= 0 && vis[row][col-1] == 0 && grid[row][col-1] == curr){
                grid[row][col-1] = color;
                vector<int> temp2 = {row, col-1, currMin +1};
                bfs.push(temp2);
            }
            
            
            //Make right adjacent 2/Rotten
            if(col+1 < m && vis[row][col+1] == 0 && grid[row][col+1] == curr){
                grid[row][col+1] = color;
                vector<int> temp2 = {row, col+1, currMin +1};
                bfs.push(temp2);
            }
            
            /*
            // 
                0 1 2
              0 2 2 1
              1 2 1 0
              2 0 1 1
            */
        }
        
        grid[sr][sc] = color;
        
        return grid;

        
        
    }
};