class Solution {
public:
    struct NODE
    {
        bool is_word_finshed;
        struct NODE *child[26];
        NODE()
        {
            for(int i=0;i<26;i++)
                child[i]=NULL;
            is_word_finshed=false;
        }
    };
    NODE trie;
    void insert(string str)
    {
        NODE *tmp=&trie;
        for(int i=0;i<str.length();i++)
        {
            int ix=str[i]-'a';
            if(tmp->child[ix]==NULL)
            {
                tmp->child[ix]=new NODE();
                tmp=tmp->child[ix];
            }
            else
                tmp=tmp->child[ix];
            if(i==str.length()-1)
                tmp->is_word_finshed=true;
        }
    }
    string replaceWords(vector<string>& dict, string sentence) 
    {
        for(int i=0;i<dict.size();i++)
            insert(dict[i]);
        string str;
        NODE *head=&trie;
        vector<string>fwords;
        string tempstr;
        for(int i=0;i<sentence.length();i++)
        {
            if(sentence[i]==' ')
            {
                fwords.push_back(tempstr);
                tempstr="";
            }
            else
                tempstr+=sentence[i];
        }	
        if(tempstr.length())
            fwords.push_back(tempstr);
        for(int i=0;i<fwords.size();i++)
        {
            head=&trie;
            tempstr="";
            for(int j=0;j<fwords[i].length();j++)
            {
                int ix=fwords[i][j]-'a';
                head=head->child[ix];
                if(head==NULL)
                {
                    break;
                }
                else if(head->is_word_finshed==true)
                {
                    tempstr+=fwords[i][j];
                    fwords[i]=tempstr;
                    break;
                }
                else
                    tempstr+=fwords[i][j];
            }
        }
        string res;
        int len=fwords.size();
        for(int i=0;i<len-1;i++)
        {
            res+=fwords[i];
            res+=' ';
        }
        res+=fwords[len-1];
        return res;
    }
};