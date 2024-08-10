class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(struct Node *head) {
        
          if (head == NULL) return 0;
         
       Node*slow=head;
       Node*fast=head;
       Node*temp=head;
       while(fast!=NULL && fast->next!=NULL ){
           slow=slow->next;
           fast=fast->next->next;
           if(fast==slow){
               int len=1;
               Node*temp=fast;
               while(temp->next!=fast){
                   len++;
                   temp=temp->next;
               }
               return len;
           }
       }
       return 0;
    }
};