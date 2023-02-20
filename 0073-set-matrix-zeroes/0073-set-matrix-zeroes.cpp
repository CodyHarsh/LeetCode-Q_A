class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col = matrix[0].size();
        bool zeroCol = false;
        for(int i = 0;i<col; i++){
            if(matrix[0][i] == 0){
                zeroCol = true;
                break;
            }
        }
        for(int i = 0;i<matrix.size(); i++){
            if(matrix[i][0] == 0){
                matrix[0][0] = 0;
                break;
            }
        }
        
        for(int i = 1; i<matrix.size();i++){
            for(int j = 0; j<matrix[i].size(); j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        //
        for(int i = 1; i<col; i++){
            if(matrix[0][i] == 0){
                for(int j = 0;j<matrix.size(); j++){
                    matrix[j][i] = 0;
                }
            }
        }
        
         for(int i = 1; i<matrix.size(); i++){
            if(matrix[i][0] == 0){
                for(int j = 0;j<col; j++){
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(matrix[0][0] == 0){
            for(int i = 0; i<matrix.size(); i++){
                matrix[i][0] = 0;
            }
        }
        
        if(zeroCol){
            for(int i =0;i<col; i++){
                matrix[0][i] = 0;
            }
        }
        
        
    }
};