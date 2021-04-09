// Leecode 953. Verifying an Alien Dictionary
// https://leetcode.com/problems/verifying-an-alien-dictionary/
// time complexity: O(nm), n is length of words, m is length of word
// space complexity: O(1), always need 26 ints

class Solution 
{
public:
    bool isAlienSorted(vector<string>& words, string order) 
    {
        int position[26] = {0};
        for (int i = 0; i < order.length(); i++)
        {
            position[order[i] - 'a'] = i;
        }
        
        for (int i = 0; i < words.size() - 1; i++)
        {
            string& wordX = words[i];
            string& wordY = words[i + 1];
            int ix = 0;
            int iy = 0;
            while (ix < wordX.length() && iy < wordY.length())
            {
                if (position[wordX[ix] - 'a'] < position[wordY[iy] - 'a'])
                {
                    break;
                }
                
                if (position[wordX[ix] - 'a'] > position[wordY[iy] - 'a'])
                {
                    return false;
                }
                
                ix++;
                iy++;
            }
            
            // when the previous word longer than the following word
            if (ix < wordX.length() && iy == wordY.length())
            {
                return false;
            }
        }
        
        return true;
    }
};
