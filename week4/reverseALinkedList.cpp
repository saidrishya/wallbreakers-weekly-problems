class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return head;
        ListNode *t=NULL;
        while(head){
            ListNode *x = head->next;
            head->next=t;
            t=head;
            head=x;
        }
        return t;
    }
};
