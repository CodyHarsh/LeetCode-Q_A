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
    TreeNode* bstFromPreorder1(vector<int> &preorder, int minNode , int maxNode, int &curr){
        if(preorder.size() <= curr){
            return NULL;
        }
        if( preorder[curr] > minNode && preorder[curr] < maxNode){
            TreeNode *root = new TreeNode(preorder[curr]);
            
            if(curr+1 < preorder.size() && preorder[curr+1] < preorder[curr])
            root -> left = bstFromPreorder1(preorder, minNode, preorder[curr], ++curr);
            if(curr+1 < preorder.size() && preorder[curr+1] > preorder[curr])
            root -> right = bstFromPreorder1(preorder, preorder[curr], maxNode, ++curr);
            return root;
        }
        curr--;
        return NULL;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int curr = 0;
        return bstFromPreorder1(preorder, INT_MIN, INT_MAX, curr);
        
    }
};