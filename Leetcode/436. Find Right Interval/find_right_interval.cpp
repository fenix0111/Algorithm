// Leetcode 436. Find Right Interval
// https://leetcode.com/problems/find-right-interval/
// time complexity: O(nlogn)
// space complexity: O(n)

class Solution 
{
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) 
    {
        // store the start of interval with its index in array to the map
        map<int, int> M;
        for (int i = 0; i < intervals.size(); i++)
        {
            vector<int>& interval = intervals[i];
            M[interval[0]] = i;
        }
        
        vector<int> ret(intervals.size(), -1);
        for (int i = 0; i < intervals.size(); i++)
        {
            auto it = M.lower_bound(intervals[i][1]);
            if (it != M.end())
            {
                ret[i] = it->second;
            }
        }
        
        return ret;
    }
};
