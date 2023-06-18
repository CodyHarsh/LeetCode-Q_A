/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q){
            return root;
        }
        
        TreeNode *left1 = NULL, *right1 = NULL;
        if(root-> left){
            left1 = lowestCommonAncestor(root -> left, p, q);
        }
        if(root -> right){
            right1 = lowestCommonAncestor(root -> right, p, q);
        }
        
        if(right1 == NULL){
            return left1;
        }
        if(left1 == NULL){
            return right1;
        }
        if(left1 && right1){
            return root;
        }
        
        return NULL;
    }
};