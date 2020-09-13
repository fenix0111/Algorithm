// more concise, one pass solution

class Solution 
{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        vector<vector<int>> result;
        
        int begin = 0;
        int end = intervals.size();
        int ii = newInterval[0];
        int jj = newInterval[1];
        
        // whether have processed newInterval
        bool finished = false;
        for (int i = 0; i < intervals.size(); i++)
        {
            // end before new interval begin
            vector<int>& interval = intervals[i];
            if (newInterval[1] < interval[0])
            {
                if (!finished)
                {
                    finished = true;
                    vector<int> v;
                    v.push_back(ii);
                    v.push_back(jj);
                    result.push_back(v); 
                }
                result.push_back(interval);
                continue;
            }
            
            if (interval[1] < newInterval[0])
            {
                result.push_back(interval);
                continue;
            }
            
            // check begin or end of newInterval is between current interval
            if (newInterval[0] >= interval[0] && newInterval[0] <= interval[1])
            {
                ii = min(interval[0], newInterval[0]);
            }
            
            if (newInterval[1] >= interval[0] && newInterval[1] <= interval[1])
            {
                jj = max(interval[1], newInterval[1]);
                
                if (!finished)
                {
                    finished = true;
                    vector<int> v;
                    v.push_back(ii);
                    v.push_back(jj);
                    result.push_back(v);
                }
                continue;
            }
        }

        // may be intervals is empty, or newInterval is later than last interval
        if (!finished)
        {
            vector<int> v;
            v.push_back(ii);
            v.push_back(jj);
            result.push_back(v);
        }
        return result;
    }
};
