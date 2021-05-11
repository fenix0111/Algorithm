// Leetcode 1423. Maximum Points You Can Obtain from Cards
// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
// time complexity: O(n)
// space complexity: O(1)

// using sliding window
// each time we pick up one card from each end
// after k turns, there will be remaining continuous subarray(it could be a empty array when k is equal to size of cards)
// what should we do is minimizing the sum of this subarray

class Solution 
{
public:
    int maxScore(vector<int>& cardPoints, int k) 
    {
        int window = cardPoints.size() - k;
        int score = 0;
        int sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int minScore = sum;
        
        if (window == 0)
        {
            return sum;
        }
        else
        {
            for (int i = 0; i < window; i++)
            {
                score += cardPoints[i];
            }
            
            minScore = score;
            
            for (int i = 0; i < k; i++)
            {
                score -= cardPoints[i];
                score += cardPoints[i + window];
                
                minScore = min(minScore, score);
            }
        }
        
        return sum - minScore;
    }
};
