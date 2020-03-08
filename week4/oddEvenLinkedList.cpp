class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
       if(!head || !head->next)
        return head;
    
    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenSaved = head->next;
    
    while(even && even->next)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next=odd->next;
        even = even->next;
    }
    odd->next = evenSaved;
    
    return head;

    }
};
