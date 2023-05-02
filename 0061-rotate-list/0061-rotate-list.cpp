/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    //Appraoch 2:

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL){
            return head;
        }
        
        //Step 1: Find the size:
        int size = 1;
        ListNode *curr = head;
        while(curr -> next){
            size++;
            curr = curr -> next;
        }
        
        //Step 2: connect the last node with first node so it become circular
        curr -> next = head;
        
        
        //Step 3: if the k is greater than the size of the linked list:
        int n = k % size;
        
        //Step 4: travel from starting node to size - k nodes:
        int travel = size - n;
        
        //travelling till n not become's 0 and 
        while(travel--){
            curr = curr -> next;
        }
        
        
        //Step 5: Making the curr -> next NULL as the left behind is k digits and connect the left behind digits with head:
        head = curr -> next;
        curr -> next = NULL;
        return head;

    }
    
    
    /*
    //Approach 1: Using the rotation logic:
    ListNode *rotate(ListNode *head){
        
        ListNode *prev = NULL;
        ListNode *cur = head;
        
        while(cur){
            ListNode *next = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL){
            return head;
        }
        //Finding the size of the list:
        int size = 0;
        ListNode *curr = head;
        while(curr){
            size++;
            curr = curr -> next;
        }
        
        
        //if the k value is greater than size of linked list: 
        int k1 = k%size; 
        
        //Rotate first n-k elements:
        int n = 1; 
        ListNode *rotate1 = head;
        ListNode *curr1 = head;
        while(n != size - k1){
            curr1 = curr1 -> next;
            n++;
        }
        
        ListNode *temp = curr1 -> next;
        curr1 -> next= NULL;
        rotate1 = rotate(head); 
        
        //Rotate last k elements:
        ListNode *rotate2 = rotate(temp);
        
        //Join the rotate1 and rotate2:
        curr1 = rotate1;
        while(curr1 -> next){
            curr1 = curr1 -> next;
        }
        
         curr1 -> next = rotate2;
         
        //Rotate the whole array:
        return rotate(rotate1);
    }
    
    */
};