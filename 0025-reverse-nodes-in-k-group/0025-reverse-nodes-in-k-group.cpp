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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1){
            return head;
        }
        if(head == NULL || head -> next == NULL){
            return head;
        }
        
     //Step 1: find the size of the ll
        int size = 0;
        ListNode *curr = head;
        while(curr){
            curr = curr -> next;
            size++;
        }
        
        int repeat = size/k;
        //cout<<repeat<<endl;
        int x = repeat;
        curr = head;
        ListNode *prev = NULL;
        ListNode *lastOccured = head;
        while(repeat > 0){
            prev = curr;
            int m = 0;
            ListNode *prev1 = NULL;
            
            while(m != k){
                ListNode *temp = curr -> next;
                curr -> next = prev1;
                prev1 = curr;
                curr = temp;
                m++;
            }
            
            if(repeat == x){
                head = prev1;
                lastOccured = prev;
            }else{
                lastOccured -> next = prev1;
                lastOccured = prev;
            }
            prev -> next = curr;
            repeat--;
            
        }
        
        return head;
    }
};