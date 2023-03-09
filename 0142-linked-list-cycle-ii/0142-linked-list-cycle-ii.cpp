/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        int start = 0;
        // if(head -> nex)
        bool cycleDetected = false;
        while(fast != NULL &&  fast -> next != NULL){
            if((start != 0 && !cycleDetected) && slow == fast){
                cycleDetected = true;
                slow = head;
            }
            
            if(cycleDetected && slow == fast){
                return slow ;
            }
            
            if(cycleDetected){
                slow = slow -> next;
                fast = fast -> next;
                continue;
            }
            
            slow = slow -> next;
            fast = fast -> next -> next;
            if(start == 0){
                start++;
            }
            
        }
        
        return NULL;
            
    }
};