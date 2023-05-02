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
};