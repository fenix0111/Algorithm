// Leetcode 1. Two Sum
// https://leetcode.com/problems/two-sum/description/
// Runtime: 139ms (Grade F)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int len = nums.size();
        std::vector<int> res;
        for (int i = 0; i < len; i++) 
        {
          for (int j = i + 1; j < len; j++) 
          {
            if (nums.at(i) + nums.at(j) == target) 
            { 
              res.push_back(i);
              res.push_back(j);
              return res;
            }
          }
        }
    }
};
