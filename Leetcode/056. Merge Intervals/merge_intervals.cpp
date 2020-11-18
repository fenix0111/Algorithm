// time complexity: O(nlogn)
// space complexity: O(n)

class Solution 
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        // sorting according to the end time
        sort(intervals.begin(), intervals.end(), [](vector<int>& x, vector<int>& y) -> bool 
             {
                 if (x[1] < y[1])
                 {
                     return true;
                 }
                 else
                 {
                     return x[1] == y[1] && x[0] < y[0];
                 }
             });
        
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); i++)
        {
            int l = result.size() - 1;
            while (!result.empty() && result.back()[1] <= intervals[i][1] && result.back()[0] >= intervals[i][0])
            {
                result.pop_back();
            }
            
            if (result.empty())
            {
                result.push_back(intervals[i]);
            }
            else
            {
                // has a gap between current interval and last interval in the array
                if (intervals[i][0] > result.back()[1])
                {
                    result.push_back(intervals[i]);
                    continue;
                }
                
                int first = min(result.back()[0], intervals[i][0]);
                int second = max(result.back()[1], intervals[i][1]);
                
                vector<int>& v = result.back();
                v[0] = first;
                v[1] = second;
            }
        }
        
        return result;
    }
};
