// faster version

class Solution 
{
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        int counter[1001] = { 0 };
        vector<int> result;
        for (int num : nums1)
        {
            counter[num]++;
        }
        
        for (int num : nums2)
        {
            if (counter[num] > 0)
            {
                counter[num]--;
                result.push_back(num);
            }
        }
        
        return result;
    }
};
