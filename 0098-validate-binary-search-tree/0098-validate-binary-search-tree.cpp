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
    bool isValidBST2(TreeNode *root, long start, long end){
        if(root == NULL){
            return true;
        }
        
        if(root -> val <= start || root -> val >= end){
            return false;
        }
        
        bool a1 = isValidBST2(root -> right, root -> val, end);
        bool a2 = isValidBST2(root -> left, start , root -> val);
        if(a1 && a2){
            return true;
        }
        
        return false;
        
    }
    bool isValidBST(TreeNode* root) {
       return isValidBST2(root,LONG_MIN, LONG_MAX);
    }
};