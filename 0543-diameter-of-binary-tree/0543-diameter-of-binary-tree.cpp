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
    int maxDepth(TreeNode* root, int &maxi ) {
        if(root == NULL) return 0;
        
       
        int left = maxDepth(root->left, maxi);
        
        int right = maxDepth(root->right, maxi);
        
        maxi =  max((left + right), maxi);
        return 1 + max(left ,right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(root == NULL){
            return NULL;
        }
        int maxi = 0;
        //find the current maximum of children roots:
        maxDepth(root , maxi);
        return maxi;
    }
};