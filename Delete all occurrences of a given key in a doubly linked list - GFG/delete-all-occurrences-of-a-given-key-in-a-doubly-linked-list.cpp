//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = new_data;

    new_node->prev = NULL;

    new_node->next = (*head_ref);

    if ((*head_ref) != NULL) (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}

void printList(struct Node* head) {
    if (head == NULL) cout << -1;

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}


// } Driver Code Ends
// User function Template for C++


/* a Node of the doubly linked list 
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // Write your code here
        Node *before2 = NULL;
        bool twoAlready = false;
        Node *curr = *head_ref;
        
        while(curr != NULL){
            //2 is already there already and we have consecutive 2's
            // if(twoAlready && curr -> data == x){
            //     curr = curr -> next;
            //     continue;
            // }
            
            //2 is occured first time:
            if(!twoAlready && (curr) -> data == x ){
                twoAlready = true;
                before2 = (curr )-> prev;
            }
            
            //before this value just 2's are present Eg: 2-> 2-> 10 (currently we are on '10' node).
            else if(twoAlready && (curr) -> data != x){
                //head will be the current node
                twoAlready = false;
                if(before2 == NULL){
                    *head_ref = curr;
                    (*head_ref) -> prev = NULL;
                }else{
                    (curr) -> prev = before2;
                    before2 -> next = curr;
                }
                
                
            }
            
                curr = (curr) -> next;
            
        }
        
        
        if(twoAlready){
            if(before2== NULL){
                (*head_ref) -> data = -1;
                (*head_ref) -> next = NULL;
            }else
                (before2) -> next = NULL;
        }
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        Node* head = new Node();
        head = NULL;

        int n;
        cin >> n;

        vector<int> inp(n);

        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            // push(&head,val);
            inp[i] = val;
        }
        for (int i = n - 1; i >= 0; i--) {
            push(&head, inp[i]);
        }
        int key;
        cin >> key;
        // printList(head);
        // cout << endl;

        Solution obj;

        obj.deleteAllOccurOfX(&head, key);
        printList(head);
        cout << endl;

        // cout << "\n~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends