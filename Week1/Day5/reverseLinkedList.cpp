class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode* p=head;
        ListNode * q=NULL,*r=NULL;
        
        while(p!=NULL)
        {
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        head=q;
        return head;
    }
};