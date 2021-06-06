// Leetcode 128. Longest Consecutive Sequence
// https://leetcode.com/problems/longest-consecutive-sequence/
// time complexity: O(n)
// space complexity: O(n)

// using set
class Solution 
{
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int> ensemble;
        for (int num : nums)
        {
            ensemble.insert(num);
        }
        
        int result = 0;
        for (int num : ensemble)
        {
            if (ensemble.count(num - 1) == 0)
            {
                int current = num;
                int count = 1;
                while (ensemble.count(current + 1))
                {
                    current++;
                    count++;
                }
                
                result = max(result, count);
            }
        }
        
        return result;
    }
};
