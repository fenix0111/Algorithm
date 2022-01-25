// Leetcode 1248. Count Number of Nice Subarrays
// https://leetcode.com/problems/count-number-of-nice-subarrays/
// time complexity: O(n)
// space complexity: O(n)

// 1. count the number of even number between current odd number and left odd number/right odd number
// ex. 1 2 2 2 1 2 2, then left[4] = 3 , right[4] = 2
// 2. using queue record the index of odd numbers
// 3. number of nice subarrays = (left[i] + 1) * (right[j] + 1)
// i : left most index of odd number of subarray contains k odd numbers
// j : right most index of odd number of subarray contains k odd numbers

class Solution
{
public:
    int numberOfSubarrays(vector<int>& nums, int k)
    {
        int result = 0;
        int sz = nums.size();
        int* left = (int*)malloc(sizeof(int) * sz);
        int* right = (int*)malloc(sizeof(int) * sz);
        
        int evens = 0;
        for (int i = 0; i < sz; i++)
        {
            if ((nums[i] & 1) == 1)
            {
                left[i] = evens;
                evens = 0;
            }
            else
            {
                evens++;
            }
        }
        
        evens = 0;
        for (int i = sz - 1; i >= 0; i--)
        {
            if ((nums[i] & 1) == 1)
            {
                right[i] = evens;
                evens = 0;
            }
            else
            {
                evens++;
            }
        }
        
        int j = 0;
        queue<int> q;
        
        while (j < sz)
        {
            if ((nums[j] & 1) == 1)
            {
                q.push(j);
                if (q.size() == k)
                {
                    int l = q.front();
                    
                    result += (left[l] + 1) * (right[j] + 1);
                    q.pop();
                }
            }
            j++;
        }
        
        return result;
    }
};
