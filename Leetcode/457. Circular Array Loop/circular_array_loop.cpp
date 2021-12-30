// Leetcode 457. Circular Array Loop
// https://leetcode.com/problems/circular-array-loop/
// time complexity: O(N2)
// space complexity: O(N)

// straightforward solution
class Solution
{
public:
    bool check(vector<int>& nums, int index)
    {
        int sz = nums.size();
        vector<bool> visited(sz, false);
        int i = index;
        vector<int> path;
        path.push_back(i);
        while (!visited[i])
        {
            visited[i] = true;
            
            // take care of value(here, the nums[i]) 
            // which absolute value is greater than the size of the array
            i = (i + (nums[i] % sz) + sz) % sz;
            if (!path.empty())
            {
                // cycle should contains only positives or negatives
                if (nums[path.back()] * nums[i] < 0)
                {
                    return false;
                }
            }
            
            path.push_back(i);
        }
        
        // check cycle size, cycle should have size greater than 1
        for (int j = 0; j < path.size() - 1; j++)
        {
            if (path[j] == path.back())
            {
                if (path.size() - 1 - j > 1)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        
        return false;
    }
    
    bool circularArrayLoop(vector<int>& nums)
    {
        int sz = nums.size();
        for (int i = 0; i < sz; i++)
        {
            if (check(nums, i))
            {
                return true;
            }
        }
        
        return false;
    }
};
