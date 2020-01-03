class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) 
    {
        int lastIndex = A.size() - 1;
        vector<int> ret;
        int currentMax = A.size();
        
        
        do
        {
            while (lastIndex >= 0 && A[lastIndex] == currentMax)
            {
                lastIndex--;
                currentMax--;
            }
            
            int index = lastIndex - 1;
            
            
            if (index >= 0)
            {
                while (index > 0 && A[index] != currentMax)
                {
                    index--;
                }
                
                ret.push_back(index + 1);
                reverse(A.begin(), A.begin() + index + 1);
                reverse(A.begin(), A.begin() + lastIndex + 1);
                ret.push_back(lastIndex + 1);
            }
            
            lastIndex--;
            currentMax--;
            
        } while (lastIndex > 0);
        
        return ret;
    }
};