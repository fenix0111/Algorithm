// Leetcode 941. Valid Mountain Array
// https://leetcode.com/problems/valid-mountain-array/
// time complexity: O(n)
// space complexity: O(1)

class Solution 
{
public:
    bool validMountainArray(vector<int>& arr) 
    {
        if (arr.size() == 1)
        {
            return false;
        }
        
        int i = 0;
        while (i < arr.size() - 1 && arr[i] < arr[i + 1])
        {
            if (arr[i] == arr[i + 1])
            {
                return false;
            }
            
            i++;
        }
        
        // strictly increasing or strictly descreasing ony
        if (i == arr.size() - 1 || i == 0)
        {
            return false;
        }
        
        while (i < arr.size() - 1 && arr[i] > arr[i + 1])
        {
            if (arr[i] == arr[i + 1])
            {
                return false;
            }
            
            i++;
        }
        
        return i == arr.size() - 1;
    }
};
