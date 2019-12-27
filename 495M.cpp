class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        stack<pair<int,int> >st;
        int total_time=0;
        for(int i=0;i<timeSeries.size();i++)
        {
            if(st.empty()||st.top().second<timeSeries[i])
                st.push({timeSeries[i],timeSeries[i]+duration-1});
            else
            {
                int l=st.top().first;
                int r=timeSeries[i]+duration;
                st.pop();
                st.push({l,r-1});
            }
        }
        while(!st.empty())
        {
            int l=st.top().first;
            int r=st.top().second;
            total_time+=r-l+1;
            st.pop();
        }
        return total_time;
    }
};



// Efficient solution
class Solution {
  public int findPoisonedDuration(int[] timeSeries, int duration) {
    int n = timeSeries.length;
    if (n == 0) return 0;

    int total = 0;
    for(int i = 0; i < n - 1; ++i)
      total += Math.min(timeSeries[i + 1] - timeSeries[i], duration);
    return total + duration;
  }
}