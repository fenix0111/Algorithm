// Leetcode 927. Three Equal Parts
// https://leetcode.com/problems/three-equal-parts/
// time complexity: O(n)
// space complexity: O(1)

class Solution 
{
public:   
    vector<int> threeEqualParts(vector<int>& arr) 
    {
        vector<int> result = {-1, -1};
        int ones = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i])
            {
                ones++;
            }
        }
        
        if (ones == 0)
        {
            result[0] = 0;
            result[1] = arr.size() - 1;
            return result;
        }
        
        if (ones % 3 != 0)
        {
            return result;
        }
        
        int trisect = ones / 3;
        
        int xbeg = 0;
        int xend = 0;
        int ybeg = 0;
        int yend = 0;
        int zbeg = 0;
        int zend = arr.size() - 1;
        ones = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i])
            {
                ones++;
                if (ones == 1)
                {
                    xbeg = i;
                }
                if (ones == trisect)
                {
                    xend = i;
                }
                if (ones == trisect + 1)
                {
                    ybeg = i;
                }
                if (ones == 2 * trisect)
                {
                    yend = i;
                }
                if (ones == 2 * trisect + 1)
                {
                    zbeg = i;
                }
                if (ones == 3 * trisect)
                {
                    zend = i;
                }
            }
        }
        
        int padding = arr.size() - zend - 1;
        int i = xend + padding;
        int j = yend + padding;
        while (i >= xbeg && j >= ybeg)
        {
            if (arr[i] != arr[j])
            {
                return result;
            }
            i--;
            j--;
        }
        
        while (i >= xbeg)
        {
            if (arr[i])
            {
                return result;
            }
            i--;
        }
        
        while (j >= ybeg)
        {
            if (arr[j])
            {
                return result;
            }
            j--;
        }
        
        i = yend + padding;
        j = zend + padding;
        while (i >= ybeg && j >= zbeg)
        {
            if (arr[i] != arr[j])
            {
                return result;
            }
            i--;
            j--;
        }
        
        while (i >= ybeg)
        {
            if (arr[i])
            {
                return result;
            }
            i--;
        }
        
        while (j >= zbeg)
        {
            if (arr[j])
            {
                return result;
            }
            j--;
        }
        
        result[0] = xend + padding;
        result[1] = yend + padding + 1;
        
        return result;
    }
};
