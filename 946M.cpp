class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int ind=0;
        for(int i=0;i<pushed.size();i++)
        {
            st.push(pushed[i]);
            while(ind<popped.size() && !st.empty() && st.top()==popped[ind])
            {
                st.pop();
                ind++;
            }
        }
        return st.empty();
    }
};