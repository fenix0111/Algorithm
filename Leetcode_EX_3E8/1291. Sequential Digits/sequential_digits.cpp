// Leetcode 1291. Sequential Digits
// https://leetcode.com/problems/sequential-digits/

class Solution 
{
public:
    vector<int> sequentialDigits(int low, int high) 
    {
        int l = 0;
        int h = 0;
        
        int n = low;
        while (n > 0)
        {
            l++;
            n /= 10;
        }
        
        n = high;
        while (n > 0)
        {
            h++;
            n /= 10;
        }
        
        int diff = h - l;
        
        string number = "123456789";
        vector<int> result;
        while (diff >= 0)
        {
            for (int i = 0; i < number.length() - l - diff + 1; i++)
            {
                int num = atoi(number.substr(i, l + diff).c_str());
                if (num >= low && num <= high)
                {
                    result.push_back(num);
                }
            }
            
            diff--;
        }
        
        sort(result.begin(), result.end());
        
        return result;
    }
};
