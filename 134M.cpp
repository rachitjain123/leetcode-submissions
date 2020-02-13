class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_tank=0;
        int cur_tank=0;
        int start=0;
        for(int i=0;i<gas.size();i++)
        {
            total_tank+=gas[i]-cost[i];
            cur_tank+=gas[i]-cost[i];
            if(cur_tank<0)
            {
                start=i+1;
                cur_tank=0;
            }
        }
        if(total_tank>=0)
            return start;
        return -1;
    }
};