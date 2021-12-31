// Leetcode 838. Push Dominoes
// https://leetcode.com/problems/push-dominoes/
// time complexity: O(n)
// space complexity: O(1)

// have to deal with the domino has not been pushed
class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        int len = dominoes.length();
        string result = dominoes;
        if (len == 1)
        {
            return result;
        }
        
        int i = 0;
        int j = 0;
        while (i < len)
        {
            if (dominoes[i] == '.')
            {
                j = i;
                
                // find for range of dominoes have not been pushed
                while (j < len && dominoes[j] == '.')
                {
                    j++;
                }
                
                int l = i;
                int r = j - 1;
                
                // update dominoe state from both sides simultaneously
                while (l < r)
                {
                    if (l > 0 && result[l - 1] == 'R')
                    {
                        result[l] = 'R';
                        l++;
                    }
                    else
                    {
                        break;
                    }
                    
                    if (r < len - 1 && result[r + 1] == 'L')
                    {
                        result[r] = 'L';
                        r--;
                    }
                    else
                    {
                        break;
                    }
                }
                
                // continue updating
                while (l > 0 && l < r && result[l - 1] == 'R')
                {
                    result[l] = 'R';
                    l++;
                }
                
                while (r > l && r < len - 1 && result[r + 1] == 'L')
                {
                    result[r] = 'L';
                    r--;
                }
                
                // some edge cases
                // domino is in the most left
                if (l == 0 && result[l + 1] == 'L')
                {
                    result[l] = 'L';
                }
                else if (l == len - 1 && result[l - 1] == 'R')
                {
                    // domino is in the most right
                    result[l] = 'R';
                }
                else if (l > 0 && l < len && result[l - 1] == result[l + 1])
                {
                    // domino is in the middle
                    result[l] = result[l - 1];
                }

                i = j + 1;
            }
            else
            {
                i++;
            }
        }
        
        return result;
    }
};
