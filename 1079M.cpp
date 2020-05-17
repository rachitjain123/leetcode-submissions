class Solution {
    vector<int> fact;
    
    int getPerm(string sequence, unordered_set<string> &isCombFound)
    {
        sort(sequence.begin(),sequence.end());
        if(isCombFound.find(sequence) != isCombFound.end())
            return 0;
        isCombFound.insert(sequence);
        vector<int> freq(26);
        for(int i=0;i<sequence.length();i++)
            freq[sequence[i]-'A']++;
        int denom = 1;
        for(int i=0;i<26;i++)
            denom = denom * fact[freq[i]];
        int num_elem = sequence.length();
        
        return fact[num_elem] / denom ;
    }
    
    int calc_combinations(int index, string tiles, unordered_set<string> &isCombFound ,string sequence) {
        int num_permutations=0;
        for(int i=index;i<tiles.length();i++)
        {
            sequence+=tiles[i];
            num_permutations += calc_combinations(i+1,tiles,isCombFound,sequence);
            num_permutations += getPerm(sequence,isCombFound);
            sequence.pop_back();
        }
        return num_permutations;
    }
public:
    int numTilePossibilities(string tiles) {
        fact.push_back(1);
        for(int i=1;i<=7;i++)
            fact.push_back(fact[i-1]*i);
        unordered_set<string> isCombFound;
        return calc_combinations(0,tiles,isCombFound,"");
    }
};