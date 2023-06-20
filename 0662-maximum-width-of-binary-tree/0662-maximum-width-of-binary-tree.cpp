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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        
        
        long long ans  = 0;
        q.push({root, 1});
        while(!q.empty()){
            
            //Minimum is the tree root:
            long long a = q.front().second;
            long long b = a;
            //Size of the queue
            long long n = q.size();
            while(n--){
                auto temp = q.front();
                q.pop();
                TreeNode *node = temp.first;
                long long nodeInt = temp.second;
                b = nodeInt;
                // (rootInt -  min)
                long long m = nodeInt - a;
                if(node -> left){
                    q.push({node -> left, 2*m + 1});
                }
                
                if(node -> right){
                    q.push({node -> right, 2*m + 2});
                }
                
            }
            
            ans = max(ans , b - a);
            
        }
        
        return ans + 1;
    }
};