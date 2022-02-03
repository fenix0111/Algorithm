// Leetcode 825. Friends Of Appropriate Ages
// https://leetcode.com/problems/friends-of-appropriate-ages/
// time complexity: O(NlogN)
// space complexity: O(1)

class Solution
{
public:    
    int lowerBound(const vector<int>& data, int begin, int end, int target)
    {
        int b = begin;
        int e = end;
        while (b < e)
        {
            int m = b + (e - b) / 2;
            if (data[m] <= target)
            {
                b = m + 1;
            }
            else
            {
                e = m;
            }
        }
        
        if (b < end && data[b] < target)
        {
            b++;
        }
        
        return b;
    }
    
    int upperBound(const vector<int>& data, int begin, int end, int target)
    {
        int b = begin;
        int e = end;
        while (b < e)
        {
            int m = b + (e - b) / 2;
            if (data[m] <= target)
            {
                b = m + 1;
            }
            else
            {
                e = m;
            }
        }
        
        if (b < end && data[b] <= target)
        {
            b++;
        }
        
        return b;
    }
    
    int numFriendRequests(vector<int>& ages)
    {
        int result = 0;
        int sz = ages.size();
        sort(ages.begin(), ages.end());
        
        for (int i = 0; i < sz; i++)
        {
            int minval = 0.5 * ages[i] + 7;
            
            // search for 0.5 * age[x] + 7 < age[y] <= age[x]
            int lb = lowerBound(ages, 0, sz, minval);
            int ub = upperBound(ages, 0, sz, ages[i]);
            
            if (lb == sz && ub == sz)
            {
                continue;
            }
            
            if (lb > ub)
            {
                continue;
            }
            
            // search for age[y] > 100 && age[x] < 100
            if (ages[i] < 100)
            {
                ub = upperBound(ages, lb, ub, 100);
            }
            
            // exclude ages[i] itself
            if (lb <= i && i < ub)
            {
                result += (ub - lb - 1);
            }
            else
            {
                result += (ub - lb);
            }
        }
        
        return result;
    }
};
