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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map<int, int> map;
        for(int i=0;i<inorder.size();i++){
            map[inorder[i]]=i;
        }
       return  buildTrees(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1, map);
    
    }
    
    
    TreeNode* buildTrees(vector<int> &preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd, unordered_map<int, int> &map){
        
        //Find the preStart Element
        if(preStart > preEnd || inStart > inEnd){
            return NULL;
        }
        int firstElement = preorder[preStart];
        
        //First Half:
        int inLocation = map[firstElement];
        int numsLeft =inLocation - inStart; 
        TreeNode *root = new TreeNode(firstElement);
        
        root -> left = buildTrees(preorder, inorder, preStart+1, preStart + numsLeft , inStart, inLocation - 1, map);
        
        root -> right= buildTrees(preorder, inorder, preStart + numsLeft + 1, preEnd, inLocation+1, inEnd, map);
        
        return root;
        
    }
};