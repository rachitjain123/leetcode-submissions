class CombinationIterator {
    vector<string>res;
    int cntr;
    void recur(string characters, int combinationLength, string str,int ind) 
    {
        if(str.size()>combinationLength)
            return;
        if(str.size()==combinationLength)
        {
            res.push_back(str);
            cout<<str<<endl;
            return;
        }
        for(int i=ind;i<characters.size();i++) 
        {
            str+=characters[i];
            recur(characters,combinationLength,str,i+1);
            str.pop_back();
        }
    }
    
    
public:
    CombinationIterator(string characters, int combinationLength) {
        recur(characters, combinationLength, "", 0);
        cntr=0;
    }
    
    string next() {
        return res[cntr++];
    }
    
    bool hasNext() {
        return cntr<res.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */