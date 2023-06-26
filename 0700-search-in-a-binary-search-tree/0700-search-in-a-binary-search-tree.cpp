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
    bool ans = false;
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL){
            return NULL;
        }
        
        if(root -> val == val){
            ans = true;
            return root;
        }
        
        
        TreeNode *left1, *right1;
        if(val >= root -> val && root -> right){
            left1 = searchBST(root -> right,val);
        }
        if(ans){
            return left1;
        }
        if(val <= root -> val && root -> left){
            right1 = searchBST(root -> left, val);
        }
        
        
        if(ans){
            return right1;
        }
        
        return NULL;
    }
};