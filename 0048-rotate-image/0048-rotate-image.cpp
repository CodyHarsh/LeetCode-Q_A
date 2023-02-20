class Solution {
public:
    
    /*
    Step 1: First reverse the array
    1 2 3       7 8 9
    4 5 6  ->   4 5 6
    7 8 9 `     1 2 3
    Step 2: Than Transpost the array. It means swap(arr[i][j], arr[j][i])
    7 8 9       7 4 1
    4 5 6  ->   8 5 2
    9 6 3       9 6 3
    
    O(n^2);
    
    
    */
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        for(int i = 0; i<matrix.size(); i++){
            for(int j = i+1; j<matrix[i].size(); j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};