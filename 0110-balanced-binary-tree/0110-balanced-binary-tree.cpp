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
    
    
    bool check =  true;
    int isBalanced1(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        
        if(check == false){
            return 0;
        }
        
        //if(root -> right != NULL)
        int left = isBalanced1(root -> left);
        int right = isBalanced1(root -> right);
        if(abs(left - right) > 1){
            check = false;
            return 0;
        }
        
        return max(left ,right) +1;
    } 
    bool isBalanced(TreeNode* root) {
        if(root== NULL){
            return 1;
        }
        
        isBalanced1(root);
        if(check == false){
            return false;
        }
        
        return true;
        
    }
};