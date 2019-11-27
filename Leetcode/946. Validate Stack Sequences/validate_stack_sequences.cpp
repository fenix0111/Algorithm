// Leetcode 946. Validate Stack Sequences
// https://leetcode.com/problems/validate-stack-sequences/
// Runtime: 8ms

// Related:
// 331. Verify Preorder Serialization of a Binary Tree
// 726. Number of Atoms
// 1209. Remove All Adjacent Duplicates in String II

class Solution 
{
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        int i = 0;
        int j = 0;
        int sz = pushed.size();
        
        stack<int> tmp;
        while (i < sz || j < sz)
        {
            if (tmp.empty())
            {
                tmp.push(pushed[i]);
                i++;
            }
            else
            {
                if (tmp.top() == popped[j])
                {
                    tmp.pop();
                    j++;
                }
                else
                {
                    if (i < sz)
                    {
                        tmp.push(pushed[i]);
                        i++;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};
