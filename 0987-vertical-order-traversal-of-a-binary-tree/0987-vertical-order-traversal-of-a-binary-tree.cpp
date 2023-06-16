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
    //By Recursion:
    
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //Level Order Traversal:
        if(root == NULL){
            return {};
        }
        
        //In question [1,-1] 1-> represent horizontal lvl order and -1 -> represents vertical order
        
        
        //Make the queue with array of 3 size:
        //queue <TreeNode * pair<verticalOrder, Level>>
        queue<pair<TreeNode*, pair<int, int>>> todo;
        
        //Make an map with which stores the value 
        map<int , map<int, multiset<int>>> nodes;
        
        //IN map: first int represents: vertical order: second int represent lvl order, Multiset is storing it in sorted form.
        
        todo.push({root, {0,0}});
        
        while(!todo.empty()){
                pair<TreeNode*, pair<int, int>> temp = todo.front();
                todo.pop();
                nodes[temp.second.first][temp.second.second].insert(temp.first -> val);
                if(temp.first -> left)
                todo.push({temp.first -> left, {temp.second.first - 1, temp.second.second + 1}});
                if(temp.first -> right)
                todo.push({temp.first -> right, {temp.second.first + 1, temp.second.second + 1}});
        }
        
        
        vector<vector<int>> ans;
        for(auto p: nodes){
            vector<int> col;
            for(auto q: p.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
        
    }
};