class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long int>pq;
        set<int>st;
        pq.push(-1);
        st.insert(-1);
        while(!pq.empty())
        {
            n--;
            long long int tp=pq.top();
            pq.pop();
            if(n==0)
                return -tp;
            if(st.find(tp*2)==st.end())
            {
                pq.push(tp*2);
                st.insert(tp*2);
            }
            if(st.find(tp*3)==st.end())
            {
                pq.push(tp*3);
                st.insert(tp*3);
            }
            if(st.find(tp*5)==st.end())
            {
                pq.push(tp*5);
                st.insert(tp*5);
            }
        }
        return 0;
    }
};