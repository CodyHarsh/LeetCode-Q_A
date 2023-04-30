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
    
    
    //For merging two sorted linked list:
    ListNode* mergeTwoLinkedList( ListNode * s, ListNode *mid){
        if(mid == NULL)
            return s;
        if(s == NULL) return mid;
            
        ListNode* left = s;
        ListNode* right = mid;
        
        
        ListNode *ans = new ListNode(-1);
        ListNode *temp = ans;
        while(left != NULL && right != NULL){
            if(left -> val < right -> val){
                temp -> next = left;
                temp = left;
                left = left -> next;
            }else{
                temp -> next = right;
                temp = right;
                right = right -> next;
            }
        }
        
        
        while(left != NULL){
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        
        while(right != NULL){
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
        
        
        return ans -> next;
    }
    
    //For Finding the middle Element function
    ListNode *middle(ListNode* head){
        //Find the middle element of the linked list using slow and fast:
        ListNode *fast = head;
        ListNode *slow = head;
        
        while(fast -> next != NULL && fast -> next -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
       return slow;
    }
    
    //The recursion part of the linked list
    ListNode* mergeSort(ListNode * head){ 
        //Base Case:
        if(head == NULL || head -> next == NULL){
            return head;
        }
        
        ListNode* mid = middle(head);
        ListNode *left = head;
        ListNode *right = mid -> next;
        mid -> next = NULL;
        //Pehle left sort kar d
        left = mergeSort(left);
        right = mergeSort(right);
        
        //Merge Two Linked List
        
        return mergeTwoLinkedList (left, right);
    }
    
    //Given Functio by leetcode:
    ListNode* sortList(ListNode* head) {
        //Merge Sort Method
        return mergeSort(head);
        
    
        //This is the approach which is done using the  recursive function
        /*
        if(head == NULL || head -> next == NULL){
            return head;
        }
        
        ListNode* newHead = sortList(head -> next);
        //cout<<newHead -> val<<endl;
        
        if(newHead == NULL){
            newHead = head;
            return head;
        }
        
        if(newHead -> val >= head -> val){
            head -> next = newHead;
            return head;
        }
        
        ListNode *temp = newHead;
        ListNode *prev = NULL;
        bool append = false;
        while(temp !=  NULL){
            if(temp -> val > head -> val ){
                append = true;
                temp = prev -> next;
                prev -> next = head;
                head -> next = temp;
                break;
            }
            prev = temp;
            temp = temp -> next;
        }
        if(!append){
            cout<<prev -> val;
            prev -> next = head;
            head -> next = NULL;
        }
        return newHead;
        
        */
    }
};