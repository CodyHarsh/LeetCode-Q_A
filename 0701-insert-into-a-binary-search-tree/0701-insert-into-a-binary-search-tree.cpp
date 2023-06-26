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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            TreeNode *root1 = new TreeNode(val);
            return root1;
        }
        TreeNode *temp = root;
        
        while(temp != NULL){
            if(temp -> left == NULL && val < temp -> val){
                temp -> left = new TreeNode(val);
                return root;
            }
            
            else if (temp -> right == NULL && val > temp -> val){
                temp -> right = new TreeNode(val);
                return root;
            }
            
            if(temp -> val > val && temp -> left){
                temp = temp -> left;
            }else if(temp -> right){
                temp = temp -> right;
            }
        }
        return root;
    }
};