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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k<2) return head;
        int c=1;
        ListNode *p=head;
        while(c<k){
            p=p->next;
            if(p==NULL) return head;
            c++;                       
        }
        ListNode *n=p->next;
        p->next=NULL;
        ListNode *p1=head, *p2=head->next;
        while(p2){
            ListNode* temp = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = temp;
        }
        head->next=reverseKGroup(n,k);
        return p1;
    }
};
