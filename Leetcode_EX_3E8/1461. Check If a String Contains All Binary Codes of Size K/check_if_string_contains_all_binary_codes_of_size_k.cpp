// Leetcode 1461. Check If a String Contains All Binary Codes of Size K
// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
// time complexity: O(n)
// space complexity: O(pow(2,k))

class Solution 
{
public:
    bool hasAllCodes(string s, int k) 
    {
        int maxnum = 0; // mask
        int c = k - 1;
        while (c >= 0)
        {
            maxnum |= (1 << c);
            c--;
        }
        
        // boolean table
        vector<bool> tbl(maxnum + 1, false);
        
        int diff = s.length() - k + 1;
        int num = stoi(s.substr(0, k), nullptr, 2);
        tbl[num] = true;
        for (int i = k; i < s.length(); i++)
        {
            int c = s[i] - '0';
            num <<= 1;
            num &= maxnum;
            num += c;
            tbl[num] = true;
        }
        
        for (int i = 0; i <= maxnum; i++)
        {
            if (!tbl[i])
                return false;
        }
        
        return true;
    }
};
