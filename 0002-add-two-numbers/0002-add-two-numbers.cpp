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
//     ListNode* reverseTheLinkedList(ListNode*head){
//         if(head == NULL ){
//             return head;
//         }
        
//         Node *curr = head;
//         Node *prev = NULL;
        
//         while(curr){
//             Node *temp = curr -> next;
//             curr -> next = prev;
//             prev = curr;
//             curr = temp;
//         }
        
//         head -> next = NULL;
//         return prev;
//     }
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // l1 = reverseTheLinkedList(l1);
        // l2 = reverseTheLinkedList(l2);
        
        int carry = 0;
        ListNode *currl1 = l1;
        ListNode *ans = NULL;
        ListNode *currl2 = l2;
        ListNode *head1 = NULL;
        while(currl1 != NULL && currl2 != NULL){
            int currSum = carry + currl1 -> val + currl2 -> val;
            ListNode *temp = new ListNode(currSum);
            //Now add this sum to the ans linked list
            if(currSum > 9){
                //Back value (10 -> 0(back value))
                int back = currSum % 10;
                //Front value (10 -> 1(front value))
                int front  =( currSum / 10) % 10;
                temp -> val = back;
                carry = front;
            }else{
                carry = 0;
            }
            
            if(ans == NULL){
                ans = temp;
                head1 = temp;
            }else{
                ans -> next=  temp;
                ans = temp;
            }
            currl1 = currl1 -> next;
            currl2 = currl2 -> next;
        }
        
        // l1 is not reached to NULL
        while(currl1 != NULL){
            int currSum = carry + currl1 -> val;
            ListNode *temp = new ListNode(currSum);
            //Now add this sum to the ans linked list
            if(currSum > 9){
                //Back value (10 -> 0(back value))
                int back = currSum % 10;
                //Front value (10 -> 1(front value))
                int front  =( currSum / 10) % 10;
                temp -> val = back;
                carry = front;
            }else{
                carry = 0;
            }
            
            if(ans == NULL){
                ans = temp;
                head1 = temp;
            }else{
                ans -> next=  temp;
                ans = temp;
            }
            
            currl1 = currl1 -> next;
        }
        
        
        while(currl2 != NULL){
            int currSum = carry + currl2 -> val;
            ListNode *temp = new ListNode(currSum);
            //Now add this sum to the ans linked list
            if(currSum > 9){
                //Back value (10 -> 0(back value))
                int back = currSum % 10;
                //Front value (10 -> 1(front value))
                int front  =( currSum / 10) % 10;
                temp -> val = back;
                carry = front;
            }else{
                carry = 0;
            }
            
            if (ans == NULL){
                ans = temp;
                head1 = temp;
            }else{
                ans -> next=  temp;
                ans = temp;
            }
            
            currl2 = currl2 -> next;
        }
        if(carry >= 1){
            ListNode *temp = new ListNode(carry);
            ans -> next = temp;
        }
        
        return head1;
    }
};