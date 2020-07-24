// Leetcode 393. UTF-8 Validation
// https://leetcode.com/problems/utf-8-validation/
// time complexity: O(n)
// space complexity: O(1)

class Solution 
{
public:
    int getWidth(int data)
    {
        // 247 is 11110111 in binary format
        if (data > 247)
        {
            return -1;
        }
        
        if ((data & 240) == 240)
        {
            return 4;
        }
        
        if ((data & 224) == 224)
        {
            return 3;
        }
        
        if ((data & 192) == 192)
        {
            return 2;
        }
        
        if (data < 128)
        {
            return 1;
        }
        
        return -1;
    }
    
    // test 10xxxxxx
    bool isValid(int data)
    {
        return (data & 128) == 128;
    }
    
    // indicate if each byte has been checked for 2, 3, 4 bytes sequence
    bool allValid = false;
    bool validUtf8(vector<int>& data) 
    {
        int idx = 0;
        while (idx < data.size())
        {
            allValid = false;
            int width = getWidth(data[idx]);
            if (width == 1)
            {
                idx++;
                allValid = true;
                continue;
            }
            
            if (width < 0)
            {
                return false;
            }
            
            for (int i = 0; i < width; i++)
            {
                if (idx + i >= data.size())
                {
                    return false;
                }
                
                if (!isValid(data[idx + i]))
                {
                    return false;
                }
            }
            
            allValid = true;
            idx += width;
        }
        
        return allValid;
    }
};
