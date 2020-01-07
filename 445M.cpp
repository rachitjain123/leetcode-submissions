/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode *res;
    int calculateSize(ListNode *l)
    {
        int size=0;
        while(l!=NULL)
        {
            l=l->next;
            size++;
        }
        return size;
    }
    int calSum(ListNode *l1, ListNode *l2)
    {
        if(l1==NULL && l2==NULL)
            return 0;
        int carry=calSum(l1->next,l2->next);
        if(res==NULL)
            res=new ListNode(0);
        else
        {
            ListNode *tmp=new ListNode(0);
            tmp->next=res;
            res=tmp;
        }
        int sum=l1->val+l2->val+carry;
        res->val=sum%10;
        return sum/10;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *tmp=l1;
        int sz1=calculateSize(tmp);
        tmp=l2;
        int sz2=calculateSize(tmp);
        ListNode* dummy=new ListNode(0);
        ListNode* head=dummy;
        for(int i=0;i<abs(sz1-sz2);i++)
        {
            dummy->next=new ListNode(0);
            dummy=dummy->next;
        }
        head=head->next;
        if(sz1<sz2)
        {
            dummy->next=l1;
            l1=head;
        }
        else if(sz1>sz2)
        {
            dummy->next=l2;
            l2=head;
        }
        int carry=calSum(l1,l2);
        if(carry>0)
        {
            ListNode *tmp=new ListNode(carry);
            tmp->next=res;
            res=tmp;
        }
        return res;
    }
};