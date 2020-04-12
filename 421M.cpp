class Solution {
    struct NODE
    {
        
        int val;
        struct NODE *child[2];
        NODE()
        {
            for(int i=0;i<2;i++)
                child[i]=NULL;
        }
    };
    NODE trie;
    void insert(int num)
    {
        NODE *tmp=&trie;
        for(int i=31;i>=0;i--)
        {
            bool bit = (1<<i) & num;
            if(tmp->child[bit]==NULL)
            {
                tmp->child[bit]=new NODE();
                tmp=tmp->child[bit];
            }
            else
                tmp=tmp->child[bit];
        }
        tmp->val=num;
    }
    int getMaxXor(int num)
    {
        NODE *tmp=&trie;
        for(int i=31;i>=0;i--)
        {
            bool bit = (1<<i) & num;
            if(tmp->child[1-bit]!=NULL)
                tmp=tmp->child[1-bit];
            else if(tmp->child[bit]!=NULL)
                tmp=tmp->child[bit];
        }
        return (int)((tmp->val)^num);
    }
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxXor=0;
        for(int i=0;i<nums.size();i++)
            insert(nums[i]);
        for(int i=0;i<nums.size();i++)
            maxXor=max(maxXor,getMaxXor(nums[i]));
        return maxXor;
    }
};