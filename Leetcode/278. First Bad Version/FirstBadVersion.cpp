// Leetcode 278. First Bad Version
// https://leetcode.com/problems/first-bad-version/description/
// Runtime: 0ms

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution 
{
public:
    int firstBadVersion(int n) 
    {
        // be careful of mid value in binary search, would be overflow if use int, 
        unsigned int b = 0;
        unsigned int e = n;
        unsigned int mid = e / 2;
        
        while (b < e)
        {
            if (isBadVersion(mid))
            {
                e = mid;
                mid = (e + b) / 2; // --> origin of overflow
            }
            else
            {
                b = mid + 1;
                mid = (e + b) / 2;
            }
        }
        
        return e;
    }
};
