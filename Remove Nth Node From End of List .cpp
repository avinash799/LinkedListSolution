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
    // Function to reverse the linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode*forward=NULL;
        while (curr != NULL) {
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }

    void DeletionNode(int position, ListNode* &head) {
        if (position == 1) {
            ListNode* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        } else {
            ListNode* curr = head;
            ListNode* prev =NULL;
            int cnt = 1;
            while (cnt < position) {
                prev = curr;
                curr = curr->next;
                cnt++;
            }
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
     
        head = reverseList(head);
        DeletionNode(n, head);
        head = reverseList(head);

        return head;
    }
};