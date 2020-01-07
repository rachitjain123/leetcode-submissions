class MagicDictionary {
    unordered_set<string>mp;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        mp.clear();
        for(auto x:dict)
            mp.insert(x);
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for(int i=0;i<word.size();i++)
        {
            for(char ch='a';ch<='z';ch++)
            {
                if(word[i]==ch)
                    continue;
                char tmp=word[i];
                word[i]=ch;
                if(mp.find(word)!=mp.end())
                {
                    word[i]=tmp;
                    return true;
                }
                word[i]=tmp;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */