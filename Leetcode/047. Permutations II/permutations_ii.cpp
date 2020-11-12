class Solution 
{
public:
    void permute(vector<vector<int>>& result, unordered_set<string>& tbl, vector<int>& nums, int index, string& buf)
    {
        if (index == nums.size())
        {            
            if (tbl.find(buf) == tbl.end())
            {
                result.push_back(nums);
                tbl.insert(buf);
            }
            
            return;
        }
        
        for (int i = index; i < nums.size(); i++)
        {
            int tmp = nums[i];
            nums[i] = nums[index];
            nums[index] = tmp;
            
            char c = buf[i];
            buf[i] = buf[index];
            buf[index] = c;
            
            permute(result, tbl, nums, index + 1, buf);
            
            tmp = nums[i];
            nums[i] = nums[index];
            nums[index] = tmp;
            
            c = buf[i];
            buf[i] = buf[index];
            buf[index] = c;
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        vector<vector<int>> result;
        string buf = "";
        unordered_set<string> tbl;
        for (int n : nums)
        {
            buf.push_back(n + '0');
        }
        
        permute(result, tbl, nums, 0, buf);
        
        return result;
    }
};
