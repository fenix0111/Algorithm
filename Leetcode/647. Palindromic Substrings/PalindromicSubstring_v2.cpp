// Runtime: 4ms

// reference
// https://leetcode.com/problems/palindromic-substrings/discuss/307395/Java%3A-1ms-faster-than-100-less-memory-than-100

class Solution 
{
public:
    int countSubstrings(string s) 
    {
        int count = 0;
        int sz = s.size();
        for (int i = 0; i < sz; i++) 
        {
            // in case of odd length
            int left = i;
            int right = i;
            while (left >= 0 && right < sz && s[left] == s[right]) 
            {
                count++;
                left--;
                right++;
            }
            
            // in case of even length
            left = i;
            right = i + 1;
            while (left >= 0 && right < sz && s[left] == s[right]) 
            {
                count++;
                left--;
                right++;
            }
        }
        return count;
    }
};
