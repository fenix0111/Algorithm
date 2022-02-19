// Leetcode 1375. Number of Times Binary String Is Prefix-Aligned
// https://leetcode.com/problems/number-of-times-binary-string-is-prefix-aligned/
// time complexity: O(N)
// space complexity: O(1)

class Solution
{
public:
    int numTimesAllBlue(vector<int>& flips)
    {
        int sz = flips.size();        
        int result = 0;
        int right = flips[0];
        int i = 0;
        while (i < sz)
        {
            int flip = flips[i];
            
            if (flip > right)
            {
                right = flip;
            }
            else
            {
                if (right == i + 1)
                {
                    result++;
                    i++;
                    if (i == sz)
                    {
                        break;
                    }
                    
                    right = max(right, flips[i]);
                    continue;
                }
                else
                {
                    right = max(right, flip);
                }
            }
            
            i++;
        }
        
        return result;
    }
};
