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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
            return NULL;
        }
        ListNode *prev = NULL;
        ListNode *curr = head;
        int k = 0;
        while(curr != NULL){
            k++;
            curr = curr -> next;
        }
        cout<<k<<endl;
        //3
        int size = k;
        int index = k - n + 1;
        curr = head;
        k = 1;
        while(curr != NULL){
            if(k == index){
                cout<<curr -> val<< "   "<<endl; 
                cout<<k<<endl;
                //If head is changing
                if(k == 1){
                    if(head -> next == NULL){
                        return NULL;
                    }
                    head = head -> next;
                    break;
                }
                //If tail is changing
                if(k == size){
                    prev -> next = NULL;
                    break;
                }
                //If middle is changing
                prev -> next = curr -> next;
                break;
            }
            
            prev = curr;
            curr = curr -> next;
            k++;
        }
        //curr -> next = NULL;
        return head;
    }
};