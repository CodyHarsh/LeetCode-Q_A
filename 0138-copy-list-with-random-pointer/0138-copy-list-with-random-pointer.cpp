/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return head;
        }
        Node *curr = head;
        
        //Traverse the current:
        while(curr){
            Node *temp = new Node(curr -> val);
            temp -> next = curr -> next;
            
            curr -> next = temp;
            curr = curr -> next -> next;
        }
        
        curr = head;
        
        //Change the random
        while(curr){
            if(curr -> random == NULL){
                curr -> next -> random = NULL;
            }else{
                curr -> next -> random = curr -> random -> next;
            }
            curr = curr -> next -> next;
        }
        
        curr = head -> next;
        
        //Change
        Node *ans = head -> next;
        Node *prev = head;
        curr = head -> next;
        
        
        while(curr){
            if(prev != NULL){
                prev -> next = prev -> next -> next;
                prev = prev -> next;
            }
            if(curr -> next != NULL)
            curr -> next = curr -> next -> next;
            curr = curr -> next;
        }
        return ans;
        
    }
};