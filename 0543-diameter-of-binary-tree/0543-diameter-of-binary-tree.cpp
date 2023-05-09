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
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left, right) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(root == NULL){
            return NULL;
        }
        
        //find the current maximum of children roots:
        int rightDiameter = -1, leftDiameter = -1;
        int x = 0,y = 0;
        if(root -> right){ 
            rightDiameter = diameterOfBinaryTree(root -> left);
            x = maxDepth(root -> right);
        }
        
        if(root -> left){   
             y = maxDepth(root -> left);
             leftDiameter = diameterOfBinaryTree(root -> right);
        }
        
        int rootKaDiameter = x + y;
        
        return max((max(rootKaDiameter, rightDiameter)), leftDiameter);
    }
};