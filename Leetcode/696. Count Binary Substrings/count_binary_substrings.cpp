// Leetcode 696. Count Binary Substrings
// https://leetcode.com/problems/count-binary-substrings/
// Runtime: 36ms

class Solution 
{
public:
    int countBinarySubstrings(string s) 
    {
        char lastc = s[0];
        int lastCount = 1;
        int j = 1;
        while (j < s.size() && s[j] == lastc)
        {
            j++;
            lastCount++;
        }

        int currentCount = 0;
        int ret = 0;
        for (int i = j; i < s.size(); i++)
        {
            if (lastc != s[i])
            {
                currentCount++;
            }
            else
            {
                lastc = s[i - 1];
                int tmp = lastCount > currentCount ? currentCount : lastCount;
                ret += tmp;
                lastCount = currentCount;
                currentCount = 1;
            }
        }
        
        // don't forget the end of for-loop
        int tmp = lastCount > currentCount ? currentCount : lastCount;
        ret += tmp;

        return ret;
    }
};
