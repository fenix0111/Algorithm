// Leetcode 1014. Best Sightseeing Pair
// https://leetcode.com/problems/best-sightseeing-pair/
// time complexity: O(n)
// space complexity: O(n)

class Solution
{
public:
    int maxScoreSightseeingPair(vector<int>& values)
    {
        vector<int> buf(values.size(), 0);
        int sz = values.size();
        buf[0] = 0;
        buf[sz - 1] = values.back() - sz + 1;

        // buf[i] means the maximum values[j] - j, where j > i
        for (int i = sz - 1; i > 0; i--)
        {
            buf[i - 1] = max(buf[i], values[i] - i);
        }

        int result = 0;
        for (int i = 0; i < sz - 1; i++)
        {
            result = max(result, buf[i] + values[i] + i);
        }

        return result;
    }
};
