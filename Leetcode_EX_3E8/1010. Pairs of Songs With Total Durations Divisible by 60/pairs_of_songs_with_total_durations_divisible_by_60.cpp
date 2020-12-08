// Leetcode 1010. Pairs of Songs With Total Durations Divisible by 60
// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/time complexity: O(n)
// time complexity: O(n)
// space complexity: O(n)

// save the remainder of each number,
// then find if (60 - remainder) is exists. 
class Solution 
{
public:
    
    int numPairsDivisibleBy60(vector<int>& time) 
    {
        int pairs = 0;
        unordered_map<int, int> idlist;
        int remain = 0;
        int diff = 0;
        for (int i = 0; i < time.size(); i++)
        {
            remain = time[i] % 60;
            diff = remain == 0 ? 0 : 60 - remain;
        
            pairs += idlist[diff];
            idlist[remain]++;
        }
        
        return pairs;
    }
};
