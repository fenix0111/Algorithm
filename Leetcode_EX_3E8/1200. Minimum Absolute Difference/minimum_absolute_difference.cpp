// Leetcode 1200. Minimum Absolute Difference
// https://leetcode.com/problems/minimum-absolute-difference/
// time complexity: O(NlogN)
// space complexity: O(1) ?

// trivial two passes
class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr)
    {
        int mindiff = INT_MAX;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size() - 1; i++)
        {
            mindiff = min(mindiff, arr[i + 1] - arr[i]);
        }
        
        vector<vector<int>> result;
        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (arr[i + 1] - arr[i] == mindiff)
            {
                result.push_back({arr[i], arr[i + 1]});
            }
        }
        
        return result;
    }
};
