class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.length()==1)
            return "";
        int i=0,j=palindrome.length()-1;
        while(i<j)
        {
            if(i!=j && palindrome[i]!='a')
            {
                palindrome[i]='a';
                break;
            }
            i++;
            j--;
        }
        if(i>=j)
            palindrome[palindrome.length()-1]='b';
        return palindrome;
    }
};