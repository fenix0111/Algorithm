// Leetcode 950. Reveal Cards In Increasing Order
// https://leetcode.com/problems/reveal-cards-in-increasing-order/
// Runtime: 12ms

// not elegant but it works.
// first, sort the deck
// then assign the value in the empty slot in one intervals.

// ex: X1 O O O X2 O X3 (Xn is empty slot)
// after insert into X1, then next one should be inserted into X3
class Solution 
{
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) 
    {
        int sz = deck.size();
        sort(deck.begin(), deck.end());
        vector<int> ret(deck.size(), 0);
        
        int pos = 0;
        ret[pos] = deck[0];
        for (int i = 1; i < sz - 1; i++)
        {
            while (ret[pos] != 0)
            {
                pos++;
                if (pos >= sz)
                {
                    pos = 0;
                }
            }
            
            pos++;
            if (pos >= sz)
            {
                pos = 0;
            }

            while (ret[pos] != 0)
            {
                pos++;
                if (pos >= sz)
                {
                    pos = 0;
                }
            }
            ret[pos] = deck[i];
        }
        
        if (sz > 1)
        {
            while (ret[pos] != 0)
            {
                pos++;
                if (pos >= sz)
                {
                    pos = 0;
                }
            }
            ret[pos] = deck[sz - 1];
        }
        
        return ret;
    }
};
