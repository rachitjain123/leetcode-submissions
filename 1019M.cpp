/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>v;
        while(head!=NULL)
        {
            v.push_back(head->val);
            head=head->next;
        }
        stack<int>st;
        for(int i=0;i<v.size();i++)
        {
            while(!st.empty() && v[st.top()]<v[i])
            {
                v[st.top()]=v[i];
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty())
        {
            v[st.top()]=0;
            st.pop();
        }
        return v;
    }
};