// Leetcode 978. Longest Turbulent Subarray
// https://leetcode.com/problems/longest-turbulent-subarray/
// time complexity: O(n)
// space complexity: O(1)

// have to deal with the case which adjacent number are same
class Solution 
{
public:
    int maxTurbulenceSize(vector<int>& arr) 
    {
        int size = arr.size();
        if (size < 2)
        {
            return 1;
        }
        
        int diff = arr[1] - arr[0];
        int last_begin = 0;
        int result = diff == 0 ? 1 : 2;
        for (int i = 1; i < size - 1; i++)
        {
            int d = arr[i + 1] - arr[i];
            if (diff == 0 || d == 0 || (diff > 0 && d > 0) || (diff < 0 && d < 0))
            {
                if (diff == 0)
                {
                    last_begin = i;
                }
                result = max(result, i - last_begin + 1);
                last_begin = i;
            }
            
            diff = d;
        }
        
        if (diff != 0)
            result = max(result, size - last_begin);
        
        return result;
    }
};
