class WordDictionary {
    class node
    {
    public:
        node *child[26];
        bool is_word_finished;
        node()
        {
            for(int i=0;i<26;i++)
                child[i]=NULL;
            is_word_finished=false;
        }
    };
    node trie;
    void insert(string word)
    {
        node *tmp=&trie;
        for(int i=0;i<word.length();i++)
        {
            int ix=word[i]-'a';
            if(tmp->child[ix]!=NULL)
                tmp=tmp->child[ix];
            else
            {
                tmp->child[ix]=new node();
                tmp=tmp->child[ix];
            }
            if(i==word.length()-1)
                tmp->is_word_finished=true;
        }
    }
    bool checkIfExistsInTrie(string word,int pos,node *ptr)
    {
        if(pos==word.length())
        {
            if(ptr->is_word_finished)
                return true;
            return false;
        }
        if(word[pos]!='.')
        {
            if(ptr->child[word[pos]-'a']!=NULL)
            {
                ptr=ptr->child[word[pos]-'a'];
                return checkIfExistsInTrie(word,pos+1,ptr);
            }
        }
        else
        {
            for(int i=0;i<26;i++)
            {
                if(ptr->child[i]!=NULL)
                {
                    if(checkIfExistsInTrie(word,pos+1,ptr->child[i]))
                        return true;
                }
            }
        }
        return false;
    }
public:
    /** Initialize your data structure here. */
    WordDictionary() {
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        insert(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        node *ptr=&trie;
        return checkIfExistsInTrie(word,0,ptr);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */