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
         //base case

         if(head==NULL){
            return NULL;
         }
         //reverse k 
         ListNode*curr=head;
         ListNode*prev=NULL;
         ListNode*forward=NULL;
         int count=0;
         while(curr != NULL && count < k){
            curr = curr->next;
            count++;
        }
        curr = head;
        if(count == k) {
            count = 0;
            while(curr != NULL && count < k){
                forward = curr->next;
                curr->next = prev;
                prev = curr;
                curr = forward;
                count++;
            }
        }else {
            prev = head;
        }
         if(forward!=NULL){
            head->next=reverseKGroup(forward,k);
         }
         return prev;
    }
};