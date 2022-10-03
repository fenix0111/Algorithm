// Leetcode 1578. Minimum Time to Make Rope Colorful
// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/
// time complexity: O(N)
// space complexity: O(1)

class Solution
{
public:
    int minCost(string colors, vector<int>& neededTime)
    {
        int result = 0;
        int i = 1;
        int sum = neededTime[0];
        int max_time = sum;
        while (i < colors.size())
        {
            if (colors[i] == colors[i - 1])
            {
                max_time = max(max_time, neededTime[i]);
                sum += neededTime[i];
            }
            else
            {
                result += (sum - max_time);
                sum = neededTime[i];
                max_time = neededTime[i];
            }

            i++;
        }

        return result + (sum - max_time);
    }
};
