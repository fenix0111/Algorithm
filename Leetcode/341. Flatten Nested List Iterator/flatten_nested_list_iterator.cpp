// Leetcode 341. Flatten Nested List Iterator
// https://leetcode.com/problems/flatten-nested-list-iterator/
// Runtime: 20ms

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
class NestedIterator 
{
    vector<int> vec;
    int idx;
    
public:
    void flatten(vector<int> &v, vector<NestedInteger> &vni)
    {
        for (int i = 0; i < vni.size(); i++)
        {
            NestedInteger ni = vni[i];
            if (ni.isInteger())
            {
                v.push_back(ni.getInteger());
            }
            else
            {
                flatten(v, ni.getList());
            }
        }
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) 
    {
        idx = 0;
        flatten(vec, nestedList);
    }

    int next() 
    {
        int ret = vec[idx++];
        return ret;
    }

    bool hasNext() 
    {
        return idx < vec.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
