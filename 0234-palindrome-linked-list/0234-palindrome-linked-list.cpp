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
    
    ListNode* reverse(ListNode* head){
        if(head == NULL || head -> next == NULL){
            return head;
        }
        
        ListNode* newHead = reverse(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return newHead;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head -> next == NULL){
            return true;
        }
        if(head -> next -> next == NULL){
            if(head -> next -> val == head -> val){
                return true;
            }else{
                return false;
            }
        }
        
        
        //Revere the half of the Linked List:
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast -> next != NULL && fast -> next -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        //Even List reversse
        slow -> next = reverse(slow -> next);
        
        //Accessing the temp;
        ListNode *temp = slow -> next;
        slow = head;
         
        while(temp != NULL){
            if(slow -> val != temp -> val){
                return false;
            }
            temp = temp -> next;
            slow  = slow -> next;
        }
        
        return true;
        
//         ListNode* slow = head;
//         ListNode* fast = head;
        
//         int k = 0;
//         long long int x = 0;
//         while(fast -> next != NULL && fast -> next -> next != NULL){
//             x = x + ((slow -> val) * pow(10,k));
//             k++;
//             fast = fast -> next -> next;
//             slow = slow -> next;
//         }
        
//         if(fast != NULL){
//             x = x + ((slow -> val) * pow(10,k));
//         }
//         if(fast -> next != NULL){
//             slow = slow -> next;
//         }
        
//         fast = slow;
//         long long y = 0;
//         k = 0;
//         while( fast != NULL){
//             y=  ((y) * 10) + (fast -> val);
//             k++;
//             fast = fast -> next;
//         }
//         cout<<"x: "<<x <<" y: "<<y<<endl;
//         if(x == y){
//             return true;
//         }
//         return false;
    }
};