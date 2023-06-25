/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree txo a single string.
    string serialize(TreeNode* root) {
        
        if(root == NULL){
            return "";
        }
        
        string cipher = "";
        queue<TreeNode *> q;
        q.push(root);
        cipher += to_string(root -> val);
        while(!q.empty()){
            TreeNode *curr = q.front();
            q.pop();
            
            cipher += 'm';
            string leftValue = "n";
            if(curr -> left){
                leftValue = to_string(curr -> left -> val);
                q.push(curr -> left);
            }
            cipher += leftValue;
            
            //Putting the right tree in the string
            string rightValue = "n";
            cipher+= 'm';
            if(curr -> right){
                rightValue = to_string(curr -> right -> val);
                q.push(curr -> right);
            }
            
             cipher += rightValue;
        }
        
        int n = cipher.size();
        while(n >= 1){
            if(cipher[n-1] == 'n' || cipher[n-1] == 'm'){
                cipher.pop_back();
                n--;
            }else{
                break;
            }
        }
        
        cout<<cipher<<endl;
        return cipher;
        
    }

    // Decodes your encoded data to tree.
    
    int findTheValue(int &start, int &end, string temp){
            if(start >= end){
                return 3000;
            }
            string firstValue = "";
            if(temp[start] == 'n'){
                start += 2;
                return 2000;
            }
            while(start < end && temp[start] != 'm'){
                firstValue += temp[start];
                start++;
            }
            
            start++;
            cout<<start<<endl;
            return stoi(firstValue);
           
    }
    
    TreeNode* deserialize(string data) {
        if(data.size() == 0){
            return NULL;
        }
        
        int n = data.size();
        int j = 0;
        int x = findTheValue(j , n, data);
        TreeNode *root = new TreeNode(x);
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty() && j < n){
            TreeNode *temp = q.front();
            q.pop();
            
            int leftValue = 3000, rightValue = 3000;
            
            leftValue = findTheValue(j,n, data);
            if(leftValue != 2000 &&  leftValue != 3000){
                TreeNode *left1 = new TreeNode(leftValue);
                temp -> left = left1;
                q.push(left1);
            }else{
                temp -> left = NULL;
            }
            
            if(j<n)
                rightValue = findTheValue(j,n, data);
            if(rightValue !=2000 && rightValue != 3000){
                TreeNode *right1 =  new TreeNode(rightValue);
                temp -> right = right1;
                q.push(right1);
            }else{
                temp -> right = NULL;
            }
            
            //cout<<i
            cout<<"LeftValue: "<<leftValue<<" RightValue: "<<rightValue<<endl;
             
        }
        
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));