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
    vector<int> rightSideView(TreeNode* root) {
        //Level Order Traversal with root -> right -> left
        if(root == NULL){
            return {};
        }
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            int k =1;
            while(n--){
                TreeNode *temp = q.front();
                q.pop();
                
                if(k == 1){
                    ans.push_back(temp -> val);
                    k++;
                }
                if(temp -> right != NULL)
                    q.push(temp -> right);
                if(temp -> left != NULL)
                    q.push(temp -> left);
            }
            k =1;
        }
        return ans;
    }
};