class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string mapping[10] ={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        queue<string>q;
        vector<string>v;
        if(digits.empty())
            return v;
        string str;
        int cnt=0;
        q.push(str);
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                string str=q.front();
                q.pop();
                if(cnt==digits.size())
                {
                    v.push_back(str);
                    continue;
                }
                int val=digits[cnt]-'0';
                for(int i=0;i<mapping[val].length();i++)
                    q.push(str+mapping[val][i]);
            }
            cnt++;
        }
        return v;
    }
};