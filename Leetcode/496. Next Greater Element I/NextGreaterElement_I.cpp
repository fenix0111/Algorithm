// Leetcode 496. Next Greater Element I
// https://leetcode.com/problems/next-greater-element-i/
// Runtime: 8ms

// using map as auxiliary space
class Solution 
{
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        map<int, int> tbl;
        for (int i = 0; i < nums2.size(); i++)
        {
            tbl.insert(pair<int, int>(nums2[i], i));
        }
        
        vector<int> ret(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); i++)
        {
            int pos = tbl.find(nums1[i])->second;
            for (int j = pos; j < nums2.size(); j++)
            {
                if (nums2[j] > nums1[i])
                {
                    ret[i] = nums2[j];
                    break;
                }
            }
        }
        
        return ret;
    }
};
