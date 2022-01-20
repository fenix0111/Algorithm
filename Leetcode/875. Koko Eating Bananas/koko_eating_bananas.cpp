// Leetcode 875. Koko Eating Bananas
// https://leetcode.com/problems/koko-eating-bananas/
// time complexity: O(nlogn)
// space complexity: O(1)

// binary search
// when h is 1e9, it's over 100 thousands years
// koko will never see her guard again
class Solution
{
public:
    bool canClear(const vector<int>& piles, int k, int h)
    {
        int time = 0;
        for (int pile : piles)
        {
            // using double here
            // in case of pile is 1000000000 and k is 499999984, it will output 2.0000000640
            // ceil function will spit out 2 instead of 3 when using float
            time += (int)ceil((double)pile / (double)k);
        }
        
        return time <= h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h)
    {
        int minBananas = 1;
        int maxBananas = INT_MIN;
        int result = 0;    
        for (int pile : piles)
        {
            maxBananas = max(maxBananas, pile);
        }
        
        while (minBananas <= maxBananas)
        {
            int k = minBananas + (maxBananas - minBananas) / 2;
            if (canClear(piles, k, h))
            {
                maxBananas = k - 1;
                result = k;
            }
            else
            {
                minBananas = k + 1;
            }
        }
                
        return result;
    }
};
