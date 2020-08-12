// Leetcode 331. Verify Preorder Serialization of a Binary Tree
// https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
// time complexity: O(length of preorder)
// space complexity: O(length of preorder)

// using stack
class Solution 
{
public:
    bool isValidSerialization(string preorder) 
    {
        stack<string> pile;  // always check whether the stack is empty
        
        int i = 0;
        string sentinel = "#";
        while (i < preorder.size())
        {
            if (preorder[i] == ',')
            {
                i++;
                continue;
            }
            
            string tmp = "";  // number or sentinel("#")
                
            while (i < preorder.size() && preorder[i] != ',')
            {
                tmp.push_back(preorder[i]);
                i++;
            }
            
            if (tmp.compare(sentinel) == 0)
            {
                while (!pile.empty() && pile.top().compare(sentinel) == 0)
                {
                    pile.pop();
                    if (pile.empty())
                    {
                        return false;
                    }
                    pile.pop();
                }
            }
            
            pile.push(tmp);
        }        
        
        // there should be only one sentinel remaining in the stack at the end
        return pile.size() == 1 && pile.top().compare(sentinel) == 0;
    }
};
