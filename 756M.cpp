class Solution {
    bool checkPyramid(unordered_set<string> &allowedSet, string bottom, string bottomUp, int ind)
    {
        if(bottomUp.length()==1 && bottom.length()==2)
            return true;
        if(bottomUp.size()==bottom.size()-1)
            return checkPyramid(allowedSet,bottomUp,"",0);
        for(int i=ind;i<bottom.size()-1;i++)
        {
            for(char ch='A';ch<='G';ch++)
            {
                string tupple;
                tupple.push_back(bottom[i]);
                tupple.push_back(bottom[i+1]);
                tupple.push_back(ch);
                if(allowedSet.find(tupple)!=allowedSet.end())
                {
                    bottomUp+=ch;
                    if(!checkPyramid(allowedSet,bottom,bottomUp,ind+1))
                        bottomUp.pop_back();
                    else
                        return true;
                }
            }
            return false;
        }
        return false;
    }
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_set<string>allowedSet;
        for(int i=0;i<allowed.size();i++)
            allowedSet.insert(allowed[i]);
        return checkPyramid(allowedSet,bottom,"",0);
    }
};