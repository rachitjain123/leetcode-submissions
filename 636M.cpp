
class FunctionParam
{
public:
    int id;
    int timeStamp;
    int typeEvent;
};
class Solution {
private:
    FunctionParam splitStr(string &str, char delim)
    {
        FunctionParam fn;
        string temp;
        int cnt=0;
        for(int j=0;j<str.length();j++)
        {
            if(str[j]==delim)
            {
                if(cnt==0)
                {
                    fn.id=stoi(temp);
                    cnt++;
                }
                temp.clear();
            }
            else if(str[j]=='s')
                fn.typeEvent=0;
            else if(str[j]=='e')
                fn.typeEvent=1;
            else
                temp.push_back(str[j]);
        }
        fn.timeStamp=stoi(temp);
        return fn;
    }
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> st;
        vector<int>v(n);
        int prevTimeStamp=0;
        for(int i=0;i<logs.size();i++)
        {
            FunctionParam fn = splitStr(logs[i],':');
            if(!fn.typeEvent)            
            {
                if(!st.empty())
                {
                    int idTop = st.top();
                    v[idTop]+=fn.timeStamp-prevTimeStamp-1;
                }
                st.push(fn.id);
            }
            else
            {
                int idTop = st.top();
                if(idTop == fn.id)
                    v[fn.id]+=fn.timeStamp-prevTimeStamp+1;
                st.pop();
            }
            prevTimeStamp = fn.timeStamp;
        }
        return v;
    }
};