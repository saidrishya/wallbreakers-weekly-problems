class Solution {
public:
    ListNode *getIntersectionNode(ListNode *A, ListNode *B) {
        if(A==NULL || B==NULL) return NULL; 
        int m=len(A);
        int n=len(B);
        if(m>n){
            int d=m-n;
            while(d--){
                A=A->next;
            }
        }
        else{
            int d=n-m;
            while(d--){
                B=B->next;
            }
        }
        ListNode *res;
        while(A && B){
            if(A==B) {
                res=A;
                break;
            }
            else{
                A=A->next;
                B=B->next;
            }
        }
return res;
    }
private:
    int len(ListNode *h){
        int c=0;
        while(h){ c++; h=h->next; }
        return c;
    }
};
