class Solution {
public:
    /*
    int minimumLocation(vector<vector<int>>& mat, int row, int col, int dist,vector<vector<int>>& matrix){
        if(row >= 0 && row< mat.size() && col >=0 && col<mat[0].size()){
            if( matrix[row][col] == 0)
                return dist;
        }
        
        int left, right, upper, down;
        
        
        if(row - 1 >= 0)
            upper = minimumLocation(mat, row-1 , col , dist+1,matrix);
        
        if(row + 1 < mat.size())
            down = minimumLocation(mat, row + 1, col, dist+1, matrix);
        
        if(col - 1 >= 0)
            left = minimumLocation(mat, row, col-1, dist+1, matrix);
        
        if(col + 1 < mat[row].size())
            right = minimumLocation(mat, row, col+1, dist+1, matrix);
        
        return min(min((min(left, right)), upper), down);
        
        
    }
    */
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        queue<vector<int>> q;
        vector<vector<int>> visited(n, vector<int>(m,0));
        vector<vector<int>> ans(n, vector<int>(m,0));
        
        //Pushing 1's into the queue
        for(int i = 0; i<matrix.size(); i++){
            for(int j = 0; j<matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    vector<int> temp  = {i,j,0};
                    visited[i][j] = 1;
                    q.push(temp);                    
                }
            }
        }
        
        
        //Now we will do a bfs traversal to visit the unvisited and mark them as visit 
        
        while(!q.empty()){
            vector<int> temp = q.front();
            int r = temp[0] , c = temp[1], dist = temp[2];
            cout<<r<<c<<dist<<endl;
             visited[r][c] = 1;
             ans[r][c] =dist;
             q.pop();
            
            //Upper
             if(r - 1 >= 0){
                 if(!visited[r-1][c]){
                     visited[r-1][c] = 1;
                     vector<int> temp = {r-1, c, dist+1};
                     q.push(temp);
                 }
             }
                 
            //Lower
            if(r + 1 < matrix.size()){
                if(!visited[r+1][c]){
                    visited[r+1][c] = 1;
                     vector<int> temp = {r+1, c, dist+1};
                     q.push(temp);
                 }
            }
            
            //Left
            if(c - 1 >= 0){
                if(!visited[r][c-1]){
                    visited[r][c-1] = 1;
                     vector<int> temp = {r, c-1, dist+1};
                     q.push(temp);
                 }
            }

            if(c + 1 < matrix[0].size()){
                if(!visited[r][c+1]){
                    visited[r][c+1]= 1;
                     vector<int> temp = {r, c+1, dist+1};
                     q.push(temp);
                 }
            }
        }
            
        
        
        return ans;
    }
};