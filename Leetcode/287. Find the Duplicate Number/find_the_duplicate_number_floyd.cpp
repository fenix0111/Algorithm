// Leetcode 287. Find the Duplicate Number
// https://leetcode.com/problems/find-the-duplicate-number/
// time complexity: O(N)
// space complexity: O(1)

// using floyd's tortoise and hare algorithm

class Solution 
{
public:
    int findDuplicate(vector<int>& nums) 
    {  
        int T = nums[0];
        int H = nums[0];
        
        do
        {
            T = nums[T];
            H = nums[nums[H]];
        } while (T != H);
        
        T = nums[0];
        
        while (T != H)
        {
            T = nums[T];
            H = nums[H];
        }
        
        return T;
    }
};
