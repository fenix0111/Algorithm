// Leetcode 744. Find Smallest Letter Greater Than Target
// https://leetcode.com/problems/find-smallest-letter-greater-than-target/
// Runtime: 16ms

// using binary search
class Solution 
{
public:
    char nextGreatestLetter(vector<char>& letters, char target) 
    {
        int l = 0;
        int r = letters.size() - 1;
        int m = r / 2;
        while (l < r)
        {
            if (letters[m] > target)
            {
                r = m - 1;
                m = l + (r - l) / 2;
            }
            else
            {
                l = m + 1;
                m = l + (r - l) / 2;
            }
        }
        
        if (letters[m] <= target)
        {
            if (m == letters.size() - 1)
            {
                m = 0;
            }
            else
            {
                m++;
            }
        }
        
        return letters[m];
    }
};
