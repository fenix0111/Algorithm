// Leetcode 179. Largest Number
// https://leetcode.com/problems/largest-number/description/
// Runtime: 8ms

class Solution 
{
public:
    struct Comparator
    {
        bool operator()(int x, int y)
        {
            // return true if xy greater than yx
            string xy = to_string(x) + to_string(y);
            string yx = to_string(y) + to_string(x);
            
            if (stoull(xy) > stoull(yx))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    } comp;
    
    string largestNumber(vector<int>& nums) 
    {
        vector<string> v;
        string ret;
        if (nums.size() == 0)
            return ret;
        
        sort(nums.begin(), nums.end(), comp);
        
        for (int i  = 0; i < nums.size(); i++)
        {
            // avoid adding leading zeroes
            if (!ret.empty() || nums[i] != 0)
            {
                ret.append(to_string(nums[i]));
            }
        }
        
        // if ret is empty, it means the nums only contains zero(s), so add one zero then return
        if (ret.empty())
        {
            ret.append("0");
        }

        return ret;
    }
};
