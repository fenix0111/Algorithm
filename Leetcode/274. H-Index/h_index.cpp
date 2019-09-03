// Leetcode 274. H-Index
// https://leetcode.com/problems/h-index/
// Runtime: 4ms

class Solution 
{
public:
    int hIndex(vector<int>& citations) 
    {
        int h = 0;
        sort(citations.begin(), citations.end());
        for (int i = citations.size() - 1; i >= 0; i--)
        {
            if (citations[i] == 0)
            {
                continue;
            }
            
            if (citations[i] > h)
            {
                h++;
            }
            else
            {
                break;
            }
        }
        
        return h;
    }
};
