// 

class Solution
{
public:
    int maxProduct(vector<int>& nums)
    {
        int result = INT_MIN;
        int product = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            product = nums[i] * (product == 0 ? 1 : product);
            result = max(result, product);
        }
        
        product = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            product = nums[i] * (product == 0 ? 1 : product);
            result = max(result, product);
        }
        
        return result;
    }
};
