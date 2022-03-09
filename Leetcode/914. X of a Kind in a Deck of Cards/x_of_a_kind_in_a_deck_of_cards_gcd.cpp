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
        
        int _gcd = counter.begin()->second;
        for (auto it = counter.begin(); it != counter.end(); it++)
        {
            _gcd = gcd(_gcd, it->second);
        }
        
        return _gcd != 1;
    }
};
