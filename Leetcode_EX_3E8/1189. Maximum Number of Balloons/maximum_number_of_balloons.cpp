// Leetcode 1189. Maximum Number of Balloons
// https://leetcode.com/problems/maximum-number-of-balloons/
// time complexity : O(n)
// space complexity : O(1)

class Solution 
{
public:
    int maxNumberOfBalloons(string text) 
    {
        int counter[26] = { 0 };
        for (char c : text)
        {
            counter[c - 'a']++;
        }
        
        int result = 0;
        int b = counter['b' - 'a'];
        int a = counter['a' - 'a'];
        int l = counter['l' - 'a'] > 1 ? counter['l' - 'a'] / 2 : 0;        
        int o = counter['o' - 'a'] > 1 ? counter['o' - 'a'] / 2 : 0;
        int n = counter['n' - 'a'];
        result = min({b, a, l, o, n});
        
        return result;
    }
};
