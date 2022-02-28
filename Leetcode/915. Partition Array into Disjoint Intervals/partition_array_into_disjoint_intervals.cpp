// Leetcode 915. Partition Array into Disjoint Intervals
// https://leetcode.com/problems/partition-array-into-disjoint-intervals/
// time complexity: O(N)
// space complexity: O(N)

// fundamental idea:
// make two arrays, one store max value until current index (let it called maxval)
// another array store min value until current index (let it called minval)
// ex, nums is [1,1,1,0,6,12]
// then maxval is [1,1,1,1,6,12]
//      minval is [0,0,0,0,6,12]
// index           0 1 2 3 4 5
// we have to find the index i which maxval is less or equal to minval with index i + 1
// in the above example, such index is 3, therefore the answer is 4.

// solution below did a bit optimization, eliminated minval, just use one integer to keep track of max value up to current index 
class Solution
{
public:
    int partitionDisjoint(vector<int>& nums) 
    {
        int sz = nums.size();
        vector<int> minval(sz, 0);
        minval[sz - 1] = nums.back();
        for (int i = sz - 2; i >= 0; i--)
        {
            minval[i] = min(minval[i + 1], nums[i]);
        }
        
        int maxleft = nums[0];
        int result = 0;
        for (int i = 1; i < sz; i++)
        {
            if (maxleft <= minval[i])
            {
                result = i;
                break;
            }
            
            maxleft = max(maxleft, nums[i]);
        }
        
        return result;
    }
};
