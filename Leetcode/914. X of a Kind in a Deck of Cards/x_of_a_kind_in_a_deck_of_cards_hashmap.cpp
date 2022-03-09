// Leetcode 914. X of a Kind in a Deck of Cards
// https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/

class Solution
{
public:
    bool hasGroupsSizeX(vector<int>& deck)
    {
        unordered_map<int, int> counter;
        for (int n : deck)
        {
            counter[n]++;
        }
        
        int max_count = 0;
        for (auto it = counter.begin(); it != counter.end(); it++)
        {
            max_count = max(max_count, it->second);
        }
        
        for (int i = max_count; i >= 2; i--)
        {
            bool valid = true;
            for (auto it = counter.begin(); it != counter.end(); it++)
            {
                if (it->second % i != 0)
                {
                    valid = false;
                    break;
                }
            }
            
            if (valid)
            {
                return true;
            }
        }
        
        return false;
    }
};
