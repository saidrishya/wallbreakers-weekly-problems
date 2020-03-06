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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * res=NULL;
        if(lists.size()==0) return NULL;
        else if(lists.size()==1){
            res=lists[0];
            return res;
        }
        else{
          priority_queue<int> pq;
          for(ListNode *t : lists){
              while(t!=NULL){
                  pq.push(t->val);
                  t=t->next;
              }
          }
          while(!pq.empty()){
              ListNode *temp = new ListNode(pq.top());
              temp->next=res;
              res=temp;
              pq.pop();
          }
            
        }
return res;
        
        
    }

};
