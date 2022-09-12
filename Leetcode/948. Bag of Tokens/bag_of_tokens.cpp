// Leetcode 948. Bag of Tokens
// https://leetcode.com/problems/bag-of-tokens/
// time complexity: O(NlogN)
// space complexity: O(1)

class Solution
{
public:
    int bagOfTokensScore(vector<int>& tokens, int power)
    {
        int points = 0;
        int sz = tokens.size();
        int left = 0;
        int right = sz - 1;
        
        sort(tokens.begin(), tokens.end());
        
        while (left <= right)
        {
            int sum = 0;
            while (left <= right)
            {
                if (sum + tokens[left] > power)
                {
                    break;
                }
                points++;
                sum += tokens[left];
                left++;
            }
            
            power -= sum;
            if (left >= right || points == 0)
            {
                break;
            }
            
            points--;
            power += tokens[right];
            right--;
        }
        
        return points;
    }
};
