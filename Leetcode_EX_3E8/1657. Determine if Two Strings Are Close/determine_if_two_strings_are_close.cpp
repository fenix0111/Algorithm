// Leetcode 1657. Determine if Two Strings Are Close
// https://leetcode.com/problems/determine-if-two-strings-are-close/
// time complexity: O(nlogn)
// space complexity: O(1)

// two strings are close if
// 1, has same set of characters
// 2, patterns of occurences are same, e.g. aabbbcccc and bbaaacccc are closed string
class Solution 
{
public:
    bool closeStrings(string word1, string word2) 
    {
        if (word1.length() != word2.length())
        {
            return false;
        }
        
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);
        for (char c : word1)
        {
            v1[c - 'a']++;
        }
        
        for (char c : word2)
        {
            if (v1[c - 'a'] == 0)
            {
                return false;
            }
            
            v2[c - 'a']++;
        }
        
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        
        for (int i = 0; i < v1.size(); i++)
        {
            if (v1[i] != v2[i])
            {
                return false;
            }
        }
        
        return true;
    }
};
