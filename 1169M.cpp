class Transaction{
public:
    string name,city;
    int amount,time;
};
class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) 
    {
        map<string,vector<int> >mp;
        vector<Transaction>v;
        vector<string>invalid_transactions;
        for(int i=0;i<transactions.size();i++)
        {
            string str=transactions[i];
            string name,city;
            int amount=0,time=0;
            int ind=0;
            while(str[ind]!=',')
                name+=str[ind++];
            ind++;
            while(str[ind]!=',')
                time=time*10+str[ind++]-'0';
            ind++;
            while(str[ind]!=',')
                amount=amount*10+str[ind++]-'0';
            ind++;
            while(ind!=str.length())
                city+=str[ind++];
            Transaction t;
            t.name=name;
            t.city=city;
            t.time=time;
            t.amount=amount;
            v.push_back(t);
            mp[name].push_back(i);
        }
        for(int i=0;i<transactions.size();i++)
        {
            if(v[i].amount>1000)
            {
                invalid_transactions.push_back(transactions[i]);
                continue;
            }
            vector<int>corr_trans=mp[v[i].name];
            for(auto x:corr_trans)
            {
                if(v[x].city!=v[i].city && abs(v[x].time-v[i].time)<=60)
                {
                    invalid_transactions.push_back(transactions[i]);
                    break;
                }
            }
        }
        return invalid_transactions;
    }
};