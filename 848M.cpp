class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        long long int sum=0;
        for(int i=shifts.size()-1;i>=0;i--)
        {
            sum+=shifts[i];
            S[i]='a'+(S[i]-'a'+sum)%26;
        }
        return S;
    }
};