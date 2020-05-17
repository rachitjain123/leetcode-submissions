
// DP
class Solution {
public:
    string getHappyString(int n, int k) {
	    /*
		
	     At level 1 :  split into 3 buckets:  [1 .. 2^(n-1)] [2^(n-1)+1 .. 2*2^(n-1)] [2*2^(n-1)+1 ... 3*2^(n-1)]
		 For all the other levels (2 to n) split into buckets of 2. 
		 Consider for n = 3, we get the following tree. 
		
                  a           b          c                  : Level - 1 
		         / \         / \        / \ 
               b     c     a     c     a    b               : Level - 2
		      / \   / \   / \   / \   / \   / \
             a   c a   b b   c a   b b   c a   c            : Level - 3
             1   2 3   4 5   6 7   8     ...   12           : String lexographic ordering. 
     
	     There are 12 different happy string of length 3 ["aba", "abc", "aca", "acb", "bab", "bac", 
										                  "bca", "bcb", "cab", "cac", "cba", "cbc"]. 
		 You will find the 5th string = "bab".
		 
		 To find the 5th string, at level 1 pick the bucket, '5' will fall in. The 3 buckets in level 1 are: [1...4],[5...12],[13...16]. 
		 
		 1) If we fall in the first bucket append 'a' to the result. If we fall in second bucket append 'b'. Othewise 'c'.
		 2 ) At each level futher down, there are two directions to pick from. If k lies in the first half of the bucket pick 
		     the next lexographic successor of the current character, or pick the second lexographic successor. 
		 
		 Lexographic successor: a: [b,c], b: [a,c], c: [a,b].
		 
	    */
        if (k > 3*pow(2,n-1)) return "";
    
        unordered_map <char, vector<char>> map;
        
        string result = "";
        
        map['a'] = {'b','c'};
        map['b'] = {'a','c'};
        map['c'] = {'a','b'};
        
        int powL = pow(2,n-1);
        
        if (k <= powL) {
            result.append("a");        
        } else if (k <= 2*powL) {
            result.append("b");
            k = k - powL;
        } else {
            result.append("c");
            k = k - 2*powL;
        }
     
        while (result.size() < n) {
            char lastChar = result[result.size()-1];
            powL = powL/2;
            if (k <= powL) {
                result += map[lastChar][0];
            } else {
                result += map[lastChar][1];
                k = k-powL;
            }
        }
        
        return result;
    }
};


// BackTracking
class Solution {
    int numHappy;
    string kthString;
    void generateHappyStrings(int n, string str)
    {
        if(str.length() > n)
            return;
        if(str.size() == n)
        {
            numHappy--;
            if(numHappy==0)
                kthString=str;
            return;
        }
        for(char ch='a';ch<='c';ch++)
        {
            if(str.empty() || str.back()!= ch)
            {
                str.push_back(ch);
                generateHappyStrings(n,str);
                str.pop_back();
            }
        }
    }
public:
    string getHappyString(int n, int k) {
        numHappy = k;
        generateHappyStrings(n,"");
        return kthString; 
    }
};
