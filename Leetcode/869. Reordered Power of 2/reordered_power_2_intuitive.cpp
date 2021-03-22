// Leetcode 869. Reordered Power of 2
// https://leetcode.com/problems/reordered-power-of-2/
// time complexity: O(very complex)
// space complexity: O(maximum width of N)

// easy to understand and it works but very slow
class Solution 
{
public:
    bool reorderedPowerOf2(int N) 
    {
        vector<int> digits;
        int num = N;
        while (num > 0)
        {
            int remain = num % 10;
            digits.push_back(remain);
            num /= 10;
        }
        
        sort(digits.begin(), digits.end());
        
        do
        {
            if (digits[0] != 0)
            {
                int reorder = 0;
                for (int i = 0; i < digits.size(); i++)
                {
                    reorder *= 10;
                    reorder += digits[i];
                }

                int log2 = 1;
                while (log2 < reorder)
                {
                    log2 <<= 1;
                }

                if (log2 == reorder)
                {
                    return true;
                }
            }            
        } while (next_permutation(digits.begin(), digits.end()));
        
        return false;
    }
};
