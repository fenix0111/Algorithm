// Leetcode 1047. Remove All Adjacent Duplicates In String
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
// time complexity: O(n)
// space complexity: O(n)

class Solution 
{
public:
    string removeDuplicates(string s) 
    {
        string result = "";
        stack<char> pile;
        
        for (char c : s)
        {
            if (!pile.empty() && pile.top() == c)
            {
                pile.pop();
            }
            else
            {
                pile.push(c);
            }
        }
        
        while (!pile.empty())
        {
            result.push_back(pile.top());
            pile.pop();
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
