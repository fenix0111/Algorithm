// Leetcode 350. Intersection of Two Arrays II
// https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
// Runtime: 4ms

class Solution 
{
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> ret;
        int len1 = nums1.size();
        int len2 = nums2.size();
        
        if (len1 < len2)
        {
            ret.reserve(len2);
            multiset<int> tmp;
            for (int i = 0; i < len1; i++)
            {
                tmp.insert(nums1[i]);
            }
            
            for (int i = 0; i < len2; i++)
            {
                auto it = tmp.find(nums2[i]);
                if (it != tmp.end())
                {
                    ret.push_back(nums2[i]);
                    tmp.erase(it);
                }
            }
        }
        else
        {
            ret.reserve(len1);
            multiset<int> tmp;
            for (int i = 0; i < len2; i++)
            {
                tmp.insert(nums2[i]);
            }
            
            for (int i = 0; i < len1; i++)
            {
                auto it = tmp.find(nums1[i]);
                if (it != tmp.end())
                {
                    ret.push_back(nums1[i]);
                    tmp.erase(it);
                }
            }
        }
        
        return ret;
    }
};
