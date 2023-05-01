// Leetcode 2405. Optimal Partition of String
// https://leetcode.com/problems/optimal-partition-of-string/description/

class Solution
{
public:
    int partitionString(string s)
    {
        int result = 1;

        int len = s.length();
        int counter[26] = { 0 };
        for (int i = 0; i < len; i++)
        {
            if (counter[s[i] - 'a'] == 1)
            {
                result++;
                reset_counter(counter);
            }

            counter[s[i] - 'a']++;
        }

        return result;    
    }

    void reset_counter(int* counter)
    {
        memset(counter, 0, sizeof(int) * 26);
    }
};
