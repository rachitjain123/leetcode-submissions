class Solution {
public:
    string removeDuplicates(string s, int k) {
        int len=s.length();
        stack<pair<char,int> > st;
        for(int i=0;i<len;i++)
        {
            if(!st.empty() && st.top().second == k)
            {
                char current=st.top().first;
                while(!st.empty() && st.top().first == current)
                    st.pop();
            }
            if(!st.empty() && st.top().first == s[i])
                st.push({s[i],st.top().second+1});
            else
                st.push({s[i],1});
        }
        if(!st.empty() && st.top().second == k)
        {
            char current=st.top().first;
            while(!st.empty() && st.top().first == current)
                st.pop();
        }
        string ans;
        while(!st.empty())
        {
            ans+=st.top().first;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};