class Solution {
    bool isOp(char ch)
    {
        if(ch=='+' || ch=='-' || ch=='*')
            return true;
        return false;
    }
    int cal(int n1, int n2, char op)
    {
        if(op=='+')
            return n1+n2;
        if(op=='-')
            return n1-n2;
        return n1*n2;
    }
    vector<int> getDifferentWays(int low, int high, vector<int> &numbers, vector<char> &operators, map<pair<int,int>, vector<int> > & memo)
    {
        if(low==high)
            return vector<int>{numbers[low]};
        if(memo.find({low,high})!=memo.end())
            return memo[{low,high}];
        vector<int>res,left,right;
        for(int i=low;i<high;i++)
        {
            left = getDifferentWays(low,i,numbers,operators,memo);
            right = getDifferentWays(i+1,high,numbers,operators,memo);
            
            for(int k=0;k<left.size();k++)
            {
                for(int l=0;l<right.size();l++)
                    res.push_back(cal(left[k],right[l],operators[i]));
            }
        }
        return memo[{low,high}]=res;
    }
public:
    vector<int> diffWaysToCompute(string input) {
        string num;
        vector<int>numbers;
        vector<char>operators;
        map<pair<int,int>, vector<int> > memo;
        for(int i=0;i<input.length();i++)        
        {
            if(isOp(input[i]))
            {
                numbers.push_back(stoi(num));
                operators.push_back(input[i]);
                num.clear();
            }
            else
                num+=input[i];
        }
        numbers.push_back(stoi(num));
        return getDifferentWays(0,numbers.size()-1,numbers,operators,memo);
    }
};