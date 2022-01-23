// constant space complexity
// similar to sliding window
class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {
        int width = 2;
        vector<int> result;
        
        while (width <= 9)
        {
            int num = 0;
            for (int i = 1; i <= width; i++)
            {
                num *= 10;
                num += i;
            }
            
            if (num >= low && num <= high)
            {
                result.push_back(num);
            }
            
            int offset = width;
            while (offset < 9)
            {
                num -= (offset - width + 1) * pow(10, width - 1);
                num *= 10;
                num += (offset + 1);
                
                if (num >= low && num <= high)
                {
                    result.push_back(num);
                }
                
                offset++;
            }
            
            width++;
        }
        
        return result;
    }
};
