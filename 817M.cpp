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
    int numComponents(ListNode* head, vector<int>& G) 
    {
        set<int>st;
        for(int i=0;i<G.size();i++)
            st.insert(G[i]);
        int num_conn=0;
        while(head!=NULL)
        {
            if(st.find(head->val)==st.end())
                head=head->next;
            else
            {
                while(head!=NULL && st.find(head->val)!=st.end())
                    head=head->next;
                num_conn++;
            }
        }
        return num_conn;
    }
};