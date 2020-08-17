// Leetcode 1103. Distribute Candies to People
// https://leetcode.com/problems/distribute-candies-to-people/
// 
// 

class Solution 
{
public:
    vector<int> distributeCandies(int candies, int num_people) 
    {
        vector<int> result(num_people, 0);
        int remain = candies;
        int n = 1;
        int pos = 0;
        
        while (remain > 0)
        {
            int add = n;
            if (remain < n)
            {
                add = remain;
            }
            
            result[pos % num_people] += add;
            remain -= n;
            n++;
            pos++;
        }
        
        return result;
    }
};
