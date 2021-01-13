// Leetcode 881. Boats to Save People
// https://leetcode.com/problems/boats-to-save-people/
// time complexity: O(nlogn)
// space complexity: O(n) because of sorting

// using two pointers
class Solution 
{
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        int l = 0;
        int r = people.size() - 1;
        int result = 0;
        sort(people.begin(), people.end());
        
        while (l < r)
        {
            if (people[l] + people[r] <= limit)
            {
                l++;
            }
            
            r--;
            result++;
        }
        
        if (l == r)
        {
            result++;
        }
        
        return result;
    }
};
