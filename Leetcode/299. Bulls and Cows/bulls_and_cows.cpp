// Leetcode 299. Bulls and Cows
// https://leetcode.com/problems/bulls-and-cows/
// Runtime: 4ms

class Solution 
{
public:
    string getHint(string secret, string guess) 
    {
        int bull = 0;
        int cow = 0;
        int v[10] = { 0 };
        int gv[10] = { 0 };
        
        for (int i = 0; i < secret.size(); i++)
        {
            v[secret[i] - '0']++;
            gv[guess[i] - '0']++;
        }
        
        for (int i = 0; i < secret.size(); i++)
        {
            if (secret[i] == guess[i])
            {
                bull++;
                v[secret[i] - '0']--;
                gv[secret[i] - '0']--;
            }
        }
        
        for (int i = 0; i < secret.size(); i++)
        {
            if (v[guess[i] - '0'] > 0 && gv[guess[i] - '0'] > 0)
            {
                gv[guess[i] - '0']--;
                v[guess[i] - '0']--;
                cow++;
            }
        }
        
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};
