//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        
        queue<Node *> q;
        Node *targetNode = NULL;
        unordered_map<Node*, Node*> map;
        q.push(root);
        while(!q.empty()){
            Node *curr = q.front();
            q.pop();
            
            if(curr -> data == target){
                targetNode = curr;
            }
            
            if(curr -> left){
                q.push(curr -> left);
                map[curr -> left] = curr;
            }
            
            if(curr -> right){
                q.push(curr -> right);
                map[curr -> right] = curr;
            }
        }
        
        q.push(targetNode);
        unordered_map<Node*, bool> visited;
        visited[targetNode] = true;
        
        int minTime = 0;
        while(!q.empty()){
            minTime++;
            int n = q.size();
            
            while(n--){
                Node *curr = q.front();
                q.pop();
                
                if(map[curr] && !visited[map[curr]]){
                    visited[map[curr]]= true;
                    q.push(map[curr]);
                }
                
                if(curr -> left && !visited[curr -> left]){
                    visited[curr -> left] = true;
                    q.push(curr -> left);
                }
                
                if(curr -> right && !visited[curr -> right]){
                    visited[curr -> right] = true;
                    q.push(curr -> right);
                }

            }
            

        }
        
        
        return minTime - 1;
        
        
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends