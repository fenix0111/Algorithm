// Leetcode 521. Longest Uncommon Subsequence I
// https://leetcode.com/problems/longest-uncommon-subsequence-i/

// wtf...
class Solution 
{
public:
    int findLUSlength(string a, string b) 
    {
        if (a.compare(b) == 0)
            return -1;
        
        return a.length() > b.length() ? a.length() : b.length();
    }
};
