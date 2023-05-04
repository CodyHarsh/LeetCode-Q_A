/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode* root , vector<vector<int>> &ans){
        
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
         vector<vector<int>> ans;
        if(root == NULL){
            return {};
        }
       
        vector<int> temp;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> temp;
            
            for(int i =0; i<n; i++){
                //Find the top value: 
                TreeNode *rootValues = q.front();
                q.pop();
                
                //Push the top values in the array:
                if(rootValues -> left != NULL)
                q.push(rootValues -> left);
                if(rootValues -> right != NULL)
                q.push(rootValues -> right);
                
                //Add this value to the vector;
                temp.push_back(rootValues -> val);
                //q.pop();
            }
            
            //add this temp vector to ans:
            ans.push_back(temp);
            
        }
        return ans;
    }
};