// Leetcode 209. Minimum Size Subarray Sum
// https://leetcode.com/problems/minimum-size-subarray-sum/description/
// Runtime: 8ms

// one pointer in front, another in rear. 
// front pointer first move forward until sum of range [rear, front] is greater than or equal to s.
// then move rear pointer one step forward.
// repeat above steps until front pointer out of range or rear pointer passed the front pointer.

class Solution 
{
public:
    int minSubArrayLen(int s, vector<int>& nums) 
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        
        int front = 0;
        int rear = 0;
        int ret = INT_MAX;
        int sum = 0;

        while (front < nums.size() && rear <= front)
        {
            if (sum + nums[front] < s)
            {
                sum = sum + nums[front];
                front++;
            }
            else
            {
                if (front - rear < ret)
                {
                    ret = front - rear;
                }
                sum = sum - nums[rear];
                rear++;
            }
        }
        
        if (ret == INT_MAX)
        {
            ret = 0;
        }
        else
        {
            ret = ret + 1;
        }
        
        return ret;
    }
};
