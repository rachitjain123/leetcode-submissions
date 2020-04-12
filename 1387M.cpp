class Solution {
    int getPower(int num)
    {
        if(num==1) return 0;
        if(num%2==0)
            return 1+getPower(num/2);
        return 1+getPower(3*num+1);
    }
public:
    int getKth(int low, int high, int k) {
        set<pair<int,int> > sorted_vals;
        for(int num=low;num<=high;num++)
        {
            int power=getPower(num);
            sorted_vals.insert({power,num});
        }
        int cnt_removed=0;
        int kth_num=0;
        while(cnt_removed!=k)
        {
            kth_num=(*sorted_vals.begin()).second;
            sorted_vals.erase(sorted_vals.begin());
            cnt_removed++;
        }
        return kth_num;
    }
};