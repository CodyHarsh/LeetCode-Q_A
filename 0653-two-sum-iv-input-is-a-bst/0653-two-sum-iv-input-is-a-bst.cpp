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
    set<int> map;
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL){
            return false;
        }
        
        
        bool a1 = false,a2 = false;
        if(root -> left){
           a1 =  findTarget(root -> left, k);
        }
        if(root -> right){
            a2= findTarget(root -> right, k);
        }
           
         if(a1 || a2){
             return true;
         }   
        int diff = k - root -> val;
        auto it = map.find(diff);
        if(it != map.end()){
            return true;
        }
        map.insert(root -> val);
        return false;
    }
};