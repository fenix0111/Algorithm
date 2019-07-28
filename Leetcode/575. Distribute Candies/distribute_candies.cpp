// Leetcode 575. Distribute Candies
// https://leetcode.com/problems/distribute-candies/
// Runtime: 200ms (top tier is under 50ms)

class Solution 
{
public:
    int distributeCandies(vector<int>& candies) 
    {
        int min = INT_MAX;
        int max = INT_MIN;
        
        int ret = 0;
        int sz = candies.size();
        for (int i = 0; i < sz; i++)
        {
            if (candies[i] < min)
                min = candies[i];
            
            if (candies[i] > max)
                max = candies[i];
        }
        
        int offset = max - min + 1;
        bool *tbl = (bool*)malloc(sizeof(bool) * offset);
        for (int i = 0; i < offset; i++)
        {
            tbl[i] = false;
        }
            
        for (int i = 0; i < sz; i++)
        {
            tbl[candies[i] - min] = true;
        }
        
        for (int i = 0; i < offset; i++)
        {
            if (tbl[i])
                ret++;
            
            if (ret == sz / 2)
                break;
        }
        
        return ret;
    }
};
