// Leetcode 718. Maximum Length of Repeated Subarray
// https://leetcode.com/problems/maximum-length-of-repeated-subarray/
// time complexity: O(n*m), n is length of nums1, m is length of nums2
// space complexity: O(n*m)

// brute force
class Solution 
{
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) 
    {
        int sz1 = nums1.size();
        int sz2 = nums2.size();
        
        int result = 0;
        vector<vector<int>> tbl(sz1, vector<int>(sz2, 0));
        for (int i = 0; i < sz1; i++)
        {
            for (int j = 0; j < sz2; j++)
            {
                if (nums2[j] == nums1[i])
                {
                    tbl[i][j] = 1;
                    if (j > 0 && i > 0 && nums2[j - 1] == nums1[i - 1])
                    {
                        tbl[i][j] = tbl[i - 1][j - 1] + 1;
                    }
                    
                    result = max(result, tbl[i][j]);
                }
            }
        }
        
        return result;
    }
};
