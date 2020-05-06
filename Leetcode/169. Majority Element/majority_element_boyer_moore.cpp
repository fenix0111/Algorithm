// Leetcode 169. Majority Element
// https://leetcode.com/problems/majority-element/
// Runtime: 40 ms
// Memory: 19.8 MB

// time complexity: O(n)
// space complexity: O(1)

// Boyer–Moore majority vote algorithm
// https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm
class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
    {
        int counter = 0;
        int majority;
        for (int &num : nums)
        {
            if (counter == 0)
            {
                majority = num;
                counter = 1;
            }
            else
            {
                if (majority == num)
                {
                    counter++;
                }
                else
                {
                    counter--;
                }
            }
        }
        
        return majority;
    }
};
