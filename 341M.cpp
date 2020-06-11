/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    vector<int> FlattenedList;
    void flattenList(vector<NestedInteger> & nestedList)
    {
        for(int i=0;i<nestedList.size();i++)
        {
            if(nestedList[i].isInteger())
                FlattenedList.push_back(nestedList[i].getInteger());
            else
                flattenList(nestedList[i].getList());
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        flattenList(nestedList);
        reverse(FlattenedList.begin(),FlattenedList.end());
    }
    
    int next() {
        int nextNo = FlattenedList[FlattenedList.size()-1];
        FlattenedList.pop_back();
        return nextNo;
    }
    
    bool hasNext() {
        return FlattenedList.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */