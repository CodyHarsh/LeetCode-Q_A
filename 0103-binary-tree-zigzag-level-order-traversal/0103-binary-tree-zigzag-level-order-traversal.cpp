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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(root == NULL){
            return {};
        }
        vector<vector<int>> ans;
        queue<TreeNode *> st;
        bool oddEven = true;
        
        st.push(root);
        
        while(!st.empty()){
            vector<int> temp;
            int n = st.size();
        
             while(n--){
                 TreeNode* val1 = st.front();
                 temp.push_back(val1 -> val);
                 st.pop();
                 if(val1 ->right)
                 st.push(val1 -> right);
                 if(val1 -> left)
                 st.push(val1 -> left);
             }
            if(oddEven){
                reverse(temp.begin(), temp.end());
                oddEven = false;
            }else{
                oddEven = true;
            }
            
            ans.push_back(temp);
                
        }
        
        return ans;
     
    }
};