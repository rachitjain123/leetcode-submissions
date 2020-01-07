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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head=new ListNode(0);
        ListNode *cur=head;
        int sum=0,carry=0;
        while(l1!=NULL || l2!=NULL)
        {
            int v1=0,v2=0;
            if(l1!=NULL)
                v1=l1->val;
            if(l2!=NULL)
                v2=l2->val;
            sum=v1+v2+carry;
            cur->next=new ListNode(sum%10);
            cur=cur->next;
            carry=sum/10;
            if(l1!=NULL)
                l1=l1->next;
            if(l2!=NULL)
                l2=l2->next;
        }
        if(carry>0)
        {
            ListNode *tmp=new ListNode(carry);
            cur->next=tmp;
        }
        return head->next;
    }
};