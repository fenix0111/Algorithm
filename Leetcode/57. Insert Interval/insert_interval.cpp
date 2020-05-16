// Leetcode 57. Insert Interval
// https://leetcode.com/problems/insert-interval/
// time complexity: O(logN + N)
// space complexity: O(1)

int search_begin(vector<vector<int>>& intervals, int begin)
{
    int l = 0;
    int r = intervals.size() - 1;
    int m;
    while (l <= r)
    {
        m = l + (r - l) / 2;
        if (intervals[m][0] <= begin && intervals[m][1] >= begin)
        {
            return m;
        }
        
        if (intervals[m][0] < begin)
        {
            l = m + 1;
        }
        else if (intervals[m][0] > begin)
        {
            r = m - 1;
        }
    }
    
    return m;
}

int search_end(vector<vector<int>>& intervals, int end)
{
    int l = 0;
    int r = intervals.size() - 1;
    int m;
    while (l <= r)
    {
        m = l + (r - l) / 2;
        if (intervals[m][0] <= end && intervals[m][1] >= end)
        {
            return m;
        }
        
        if (intervals[m][1] < end)
        {
            l = m + 1;
        }
        else if (intervals[m][1] > end)
        {
            r = m - 1;
        }
    }
    
    return m;
}

// a bit messy but it works
class Solution 
{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        vector<vector<int>> ret;
        if (intervals.empty())
        {
            ret.push_back(newInterval);
            return ret;
        }
        
        int left = 0;
        int right = 0;
        
        left = search_end(intervals, newInterval[0]);
        right = search_begin(intervals, newInterval[1]);

        // two check point, we will use these check points to build result
        int ll = left;
        int rr = right;
        
        vector<int> newvec;
        newvec.push_back(newInterval[0]);
        newvec.push_back(newInterval[1]);
        
        if (newInterval[0] < intervals[left][0])
        {
            // new interval
            ll = left - 1;
        }
        
        if (newInterval[0] > intervals[left][1])
        {
            ll = left;
        }
        
        if (newInterval[0] >= intervals[left][0] && newInterval[0] <= intervals[left][1])
        {
            // inside interval
            ll = left - 1;
            newvec[0] = intervals[left][0];
        }
        
        ///////////////////////////////////////////////////
        if (newInterval[1] < intervals[right][0])
        {
            // new interval
            rr = right;
        }
        
        if (newInterval[1] > intervals[right][1])
        {
            rr = right + 1;
        }
        
        if (newInterval[1] >= intervals[right][0] && newInterval[1] <= intervals[right][1])
        {
            // inside interval
            rr = right + 1;
            newvec[1] = intervals[right][1];
        }
        
        // build result
        for (int i = 0; i <= ll; i++)
        {
            ret.push_back(intervals[i]);
        }
        
        ret.push_back(newvec);
        
        for (int i = rr; i < intervals.size(); i++)
        {
            ret.push_back(intervals[i]);
        }
        
        return ret;
    }
};
