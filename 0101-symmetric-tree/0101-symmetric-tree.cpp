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
    //Recursively: 
    bool isSymmetric1(TreeNode *left1 , TreeNode * right1){
        if(left1 == NULL && right1 == NULL){
            return true;
        }
        
        if(left1 == NULL || right1 == NULL){
            return false;
        }
        
        if(left1 -> val != right1 -> val){
            return false;
        }
        
        //Check for recursion:
        bool a1 = isSymmetric1(left1 -> right, right1 -> left);
        bool a2 = isSymmetric1(left1 -> left, right1 -> right);
        if(a1 == false || a2 == false){
            return false;
        }
        return a1==a2;
    }
    bool isSymmetric(TreeNode* root) {
        //Recusively:
        //return isSymmetric1(root -> left, root -> right);
        
        
        //Iteratively:
        queue<TreeNode * > q;
        
        q.push(root -> left);
        q.push(root -> right);
        
        while(!q.empty()){
            TreeNode *leftNode = q.front();
            q.pop();
            TreeNode *rightNode = q.front();
            q.pop();
            if(leftNode == NULL && rightNode == NULL) continue;
            
            if(leftNode == NULL || rightNode == NULL) return false;
            
            if(leftNode -> val != rightNode -> val) return false;
            
            q.push(leftNode -> right);
            q.push(rightNode -> left);
            q.push(leftNode -> left);
            q.push(rightNode -> right);
        }
        return true;
    }
};