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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         unordered_map<int, int> map;
         for(int i = 0; i<inorder.size(); i++){
             map[inorder[i]] = i;
         }
        
         return buildTrees(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1, map);
    }
    
    TreeNode *buildTrees(vector<int> &inorder, vector<int> &postorder, int poStart,int poEnd,int inStart, int inEnd, unordered_map<int, int> &map){
        if(inStart > inEnd || poStart > poEnd){
            return NULL;
        }
        //Loaction Of Root Element in inorder
        int rootElement = map[postorder[poEnd]];
        
        TreeNode *root = new TreeNode(postorder[poEnd]);
        int leftSideSize = inEnd - rootElement;
        //int x = 
        
        root -> left = buildTrees(inorder, postorder, poStart, poEnd - leftSideSize-1, 
                                   inStart, rootElement - 1, map);
        
        root -> right = buildTrees(inorder, postorder,  (poEnd - leftSideSize),poEnd -1, rootElement + 1, inEnd, map);
        
        return root;
        
    }
};