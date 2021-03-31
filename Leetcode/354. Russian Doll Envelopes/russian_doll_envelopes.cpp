// Leetcode 354. Russian Doll Envelopes
// https://leetcode.com/problems/russian-doll-envelopes/
// time complexity: O(nlogn)
// space complexity: O(n)

// for detailed explanation about longest increasing subsequence: 
// https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/

class Solution 
{
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) 
    {
        // sort by width in ascending order
        // if widths are same, sorting by height in descending order
        // if sorting by height in ascending order, it will affect the final result 
        // because there is chance that encounter several envelopes with same width
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& x, vector<int>& y) {
            if(x[0] == y[0])
                    return x[1] > y[1];
                else
                    return x[0] < y[0];
        });
        
        // after sorting, the problem was transformed to find longest increasing subsequence
        int result = 0;
        int size = envelopes.size();
        vector<int> buf;
        for (int i = 0; i < size; i++)
        {
            int height = envelopes[i][1];
            if (buf.empty() || buf.back() < height)
            {
                buf.push_back(height);
            }
            else
            {
                auto pos = lower_bound(buf.begin(), buf.end(), height);
                *pos = height;
            }
        }
        
        return buf.size();
    }
};
